#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"
#include "file_op.h"
#include "hex_bin_convert.h"


int main()
{
    /*var define*/
    int ret = 0;
    int choice = 0;
    int choice2 = 0;
    char *p_source = NULL;
    char *p_dest = NULL;
    char source[4096 * 10] = {0};
    char dest[4096 * 10] = {0};
    char file_name[512] = {0};
    char target_file_name[512] = {0};

    size_t file_size = 0;
    size_t target_file_size = 0;
    size_t target_size = 0;

    printf("\n\nhex binary convert,take a choice...\n");
    printf("-----------------------------------\n");
    printf("1. hex to binary\n");
    printf("2. binary to hex\n");
    printf("3. hex to binary --from file \n");
    printf("4. binary to hex --from file\n\n");
    scanf("%d", &choice);
    wipe_stdin();


    putchar(10);
    printf("******** take a choice... ********\n");
    printf("-----------------------------------\n");
    printf("1. write result to screen\n");
    printf("2. write result to file\n");
    scanf("%d", &choice2);
    wipe_stdin();
    if (choice2 == 2)
    {
        printf("target file name: ");
        scanf("%s", target_file_name);
        wipe_stdin();
    }



    switch (choice)
    {
    case 1:
        printf("input hex data(to binary):\n");
        scanf("%s", source);
        wipe_stdin();

        /*convert*/
        ret = hex_to_bin(source, strlen(source), dest);
        if (ret)
        {
            printf("hex_to_bin failed ret=%d\n", ret);
            goto err;
        }
        target_size = strlen(source) >> 1;
        break;

    case 2:
        printf("input binary data(to hex):\n");
        scanf("%s", source);
        wipe_stdin();

        /*convert*/
        ret = bin_to_hex(source, strlen(source), dest);
        if (ret)
        {
            printf("bin_to_hex failed ret=%d\n", ret);
            goto err;
        }
        target_size = strlen(source) << 1;
        break;

    case 3:
    case 4:
        printf("source file name: ");
        scanf("%s", file_name);
        wipe_stdin();

        file_size = get_file_size(file_name);
        if (file_size < 0)
        {
            printf("get_file_size failed,ret=%d\n", file_size);
            return OPEN_FILE_FAILED;
        }

        if (choice == 3)
            target_file_size = file_size >> 1;
        else
            target_file_size = file_size << 1;

        p_source = malloc(file_size);
        p_dest = malloc(target_file_size);
        memset(p_source, 0, file_size);
        memset(p_dest, 0, target_file_size);

        /*read source file*/
        ret = read_file(p_source, &file_size, file_name, "rb");
        if (ret)
        {
            printf("read file failed,ret = %d\n", ret);
            goto err;
        }

        if (choice == 3)
        {
            ret = hex_to_bin(p_source, file_size, p_dest);
            if (ret)
            {
                printf("hex_to_bin failed ret=%d\n", ret);
                goto err;
            }
        }
        else
        {
            ret = bin_to_hex(p_source, file_size, p_dest);
            if (ret)
            {
                printf("bin_to_hex failed ret=%d\n", ret);
                goto err;
            }
        }

        break;
    default:
        printf("take a wrong choice\n");
        return -1;
    }


    /*output*/
    if (choice2 == 1)
    {
        printf("\nconvert output:\n%s", p_dest ? p_dest : dest);
    }
    else if (choice2 == 2) /*写文件*/
    {
        ret = write_file(p_dest ? p_dest : dest, p_dest ? target_file_size : target_size, target_file_name, "wb");
        if (ret)
        {
            printf("write_file failed,ret = %d\n", ret);
            goto err;
        }
    }

    putchar(10);
    putchar(10);

    /*success*/
    ret = 0;

err:
    if (p_source)
        free(p_source);
    if (p_dest)
        free(p_dest);
    return ret;
}
