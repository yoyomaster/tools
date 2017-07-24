#ifndef _FILE_OP_H_
#define _FILE_OP_H_

/**
 * [read_file       读文件]
 * @param  content [读取到的数据(out)]
 * @param  size    [读取到的数据size(out)]
 * @param  file    [读取的文件]
 * @param  mode    [读取的mode  "r","rb" ....]
 * @return         [0 success]
 */
int read_file(void *content, size_t *size, char *file, char *mode);

#endif