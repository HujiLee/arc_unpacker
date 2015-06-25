#include <cassert>
#include "util/sound.h"

struct Sound::Priv
{
    size_t channel_count;
    size_t bytes_per_sample;
    size_t sample_rate;
    std::string samples;
    size_t sample_count;
};

Sound::Sound() : p(new Priv())
{
}

Sound::~Sound()
{
}

std::unique_ptr<Sound> Sound::from_samples(
    size_t channel_count,
    size_t bytes_per_sample,
    size_t sample_rate,
    const std::string &samples)
{
    std::unique_ptr<Sound> sound(new Sound);
    sound->p->channel_count = channel_count;
    sound->p->bytes_per_sample = bytes_per_sample;
    sound->p->sample_rate = sample_rate;
    sound->p->samples = samples;
    return sound;
}

std::unique_ptr<File> Sound::create_file(const std::string &name) const
{
    size_t block_align = p->channel_count * p->bytes_per_sample;
    size_t byte_rate = block_align * p->sample_rate;
    size_t bits_per_sample = p->bytes_per_sample * 8;

    std::unique_ptr<File> output_file(new File);

    output_file->io.write("RIFF", 4);
    output_file->io.write("\x00\x09\x00\x00", 4);
    output_file->io.write("WAVE", 4);
    output_file->io.write("fmt ", 4);
    output_file->io.write_u32_le(16);
    output_file->io.write_u16_le(1);
    output_file->io.write_u16_le(p->channel_count);
    output_file->io.write_u32_le(p->sample_rate);
    output_file->io.write_u32_le(byte_rate);
    output_file->io.write_u16_le(block_align);
    output_file->io.write_u16_le(bits_per_sample);
    output_file->io.write("data", 4);
    output_file->io.write_u32_le(p->sample_count);
    output_file->io.write(p->samples);
    output_file->io.seek(4);
    output_file->io.write_u32_le(output_file->io.size());

    output_file->name = name;
    output_file->change_extension("wav");
    return output_file;
}
