/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* 関数のプロトタイプ宣言 */
void swap_2bytes(char* byte1, char* byte2);	/* 関数swap_2bytesの宣言. */
int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len);	/* 関数convert_endian_16bit_byte_arrayの宣言. */

#endif