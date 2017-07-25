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

/**
 * [write_file      写文件]
 * @param  content [写入文件的数据]
 * @param  size    [写入文件的数据 size]
 * @param  file    [写入的文件]
 * @param  mode    [文件的打开方式 "r","rb" ....]
 * @return         [0 success]
 */
int write_file(void *content, size_t size, char *file, char *mode);

/**
 * [file_size    文件size]
 * @param  file [文件]
 * @return      [文件size, 小于0则为错误码]
 */
int get_file_size(char *file);

/**
 * [wipe_stdin 清空stdin缓存]
 */
void wipe_stdin();

#endif