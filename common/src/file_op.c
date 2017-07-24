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

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    len = fread(content, 1, file_size, fp);
    if (len != file_size)
    {
        printf("read data missed,real:[%dByte],read:[%dByte]", file_size, len);
        return -3;
    }

    fclose(fp);
    *size = len;

    return 0;
}