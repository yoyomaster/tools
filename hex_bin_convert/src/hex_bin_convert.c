#include <stdio.h>
#include "hex_bin_convert.h"
#include "error.h"

static const char hex_digits[] = "0123456789abcdef";

static int ASCIToNum(char ascii)
{
    if (ascii < 65)
        return ascii - 48;
    else if (ascii < 97)
        return ascii - 55;
    else
        return ascii - 87;
}

typedef struct Num {

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    unsigned char data1: 4;
    unsigned char data2: 4;
#else
    unsigned char data2: 4;
    unsigned char data1: 4;
#endif

} Num;


int bin_to_hex(const char *src, size_t size, char *dest)
{
    /*var define*/
    size_t i = 0;

    /*params check*/
    if (!src || !dest)
    {
        fprintf(stderr, "bin_to_hex params error\n");
        return PARAMS_ERROR;
    }

    /*convert*/
    for (; i < size; i++)
    {
        dest[2 * i] = hex_digits[(src[i] & 0xf0) >> 4];
        dest[2 * i + 1] = hex_digits[src[i] & 0x0f];
    }
    return 0;
}



int hex_to_bin(const char *src, size_t size, char *dest)
{
    /*var define*/
    size_t i = 0;
    Num num;

    /*params check*/
    if (!src || !dest)
    {
        fprintf(stderr, "hex_to_bin params error\n");
        return PARAMS_ERROR;
    }

    /*convert*/
    for (; i < size; i += 2)
    {
        num.data1 = ASCIToNum(src[i]);
        num.data2 = ASCIToNum(src[i + 1]);
        dest[i >> 1] = *(char*)&num;
    }
    return 0;
}
