#include <stdio.h>
#include <string.h>
#include "hex_bin_convert.h"

int main()
{
    char str1[] = "616263646566414243444546";
    char _str1[] = "\xB1\xb2\x12";
    char str2[1024] = {0};
    char _str2[1024] = {0};
    int ret = 0;

    ret = hex_to_bin(str1, strlen(str1), str2);
    printf("ret = %d\n", ret);
    printf("str2=%s\n", str2);

    ret = bin_to_hex(_str1, strlen(_str1), _str2);
    printf("ret = %d\n", ret);
    printf("_str2=%s\n", _str2);

    return 0;
}