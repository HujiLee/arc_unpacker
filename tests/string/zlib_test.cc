#include "util/zlib.h"
#include "test_support/eassert.h"

void test_zlib_inflate()
{
    std::string input(
        "\x78\xda\xcb\xc9\x4c\x4b\x55\xc8"
        "\x2c\x56\x48\xce\x4f\x49\xe5\x02"
        "\x00\x20\xc1\x04\x62\x0a",
        21);

    eassert(zlib_inflate(input) == "life is code\n");
}

int main(void)
{
    test_zlib_inflate();
    return 0;
}
