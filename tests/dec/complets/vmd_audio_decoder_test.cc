// Copyright (C) 2016 by rr-
//
// This file is part of arc_unpacker.
//
// arc_unpacker is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// arc_unpacker is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with arc_unpacker. If not, see <http://www.gnu.org/licenses/>.

#include "dec/complets/vmd_audio_decoder.h"
#include "test_support/catch.h"
#include "test_support/decoder_support.h"
#include "test_support/file_support.h"

using namespace au;
using namespace au::dec::complets;

TEST_CASE("Complets VMD audio files", "[dec]")
{
    // Dumb test, but still a test
    const auto decoder = VmdAudioDecoder();
    io::File input_file(
        "test.vmd", "\x1A\x1E\x95\x96\x80\x90\x81\x8A\x88\x95\xD6"_b);
    const io::File expected_file("test.mp3", "\xFF\xFBpseudomp3"_b);
    const auto actual_file = tests::decode(decoder, input_file);
    tests::compare_files(*actual_file, expected_file, true);
}
