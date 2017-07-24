#ifndef _HEX_BIN_CONVERT_H_
#define _HEX_BIN_CONVERT_H_


/**
 * [bin_to_hex   bin to hex]
 * @param  src  [数据源]
 * @param  size [数据源 size]
 * @param  dest [目标]
 * @return      [0 success]
 */
int bin_to_hex(const char *src, size_t size, char *dest);

/**
 * [hex_to_bin   hex to bin]
 * @param  src  [数据源]
 * @param  size [数据源 size]
 * @param  dest [目标]
 * @return      [0 success]
 */
int hex_to_bin(const char *src, size_t size, char *dest);

#endif
