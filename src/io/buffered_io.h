#pragma once

#include <memory>
#include "io/io.h"

namespace au {
namespace io {

    class BufferedIO final : public IO
    {
    public:
        BufferedIO();
        BufferedIO(const char *buffer, size_t buffer_size);
        BufferedIO(const bstr &buffer);
        BufferedIO(IO &other_io, size_t size);
        BufferedIO(IO &other_io);
        ~BufferedIO();

        size_t size() const override;
        size_t tell() const override;
        IO &seek(size_t offset) override;
        IO &skip(int offset) override;
        void truncate(size_t new_size) override;

        using IO::read;
        void read(void *destination, size_t size) override;

        using IO::write;
        void write(const void *source, size_t size) override;

        void reserve(size_t count);

    private:
        struct Priv;
        std::unique_ptr<Priv> p;
    };

} }
