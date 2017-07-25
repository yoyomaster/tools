#include <stdio.h>
#include "file_op.h"
#include "error.h"


int read_file(void *content, size_t *size, char *file, char *mode)
{
    /*var define*/
    FILE *fp = NULL;
    size_t len = 0;
    long file_size = 0;

    /*params check*/
    if (!content || !size || !file || !mode)
    {
        printf("read_file params error\n");
        return PARAMS_ERROR;
    }

    /*open file*/
    fp = fopen(file, mode);
    if (!fp)
    {
        printf("fopen %s failed\n", file);
        return OPEN_FILE_FAILED;
    }

    /*file size*/
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /*read from file*/
    len = fread(content, 1, file_size, fp);
    fclose(fp);
    if (len != file_size)
    {
        printf("read data missed,real:[%dByte],read:[%dByte]", file_size, len);
        return FREAD_FAILED;
    }

    *size = len;

    return 0;
}


int write_file(void *content, size_t size, char *file, char *mode)
{
    /*var define*/
    FILE *fp = NULL;
    size_t len = 0;

    /*param check*/
    if (!content || !file || !mode || !size)
    {
        printf("write_file params illegal\n");
        return PARAMS_ERROR;
    }

    /*open file*/
    fp = fopen(file, mode);
    if (!fp)
    {
        printf("fopen %s failed\n", file);
        return OPEN_FILE_FAILED;
    }

    /*write to file*/
    len = fwrite(content, 1, size, fp);
    fclose(fp);
    if (len != size)
    {
        printf("write data missed,real:[%dByte],write:[%dByte]", size, len);
        return FWRITE_FAILED;
    }

    return 0;
}


int get_file_size(char *file)
{
    /*var define*/
    FILE *fp = NULL;
    int size = 0;

    /*params check*/
    if (!file)
    {
        printf("file_size params illegal!\n");
        return PARAMS_ERROR;
    }

    /*open file*/
    fp = fopen(file, "rb");
    if (!fp)
    {
        printf("fopen %s failed\n", file);
        return OPEN_FILE_FAILED;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fclose(fp);

    return size;
}


void wipe_stdin()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}


