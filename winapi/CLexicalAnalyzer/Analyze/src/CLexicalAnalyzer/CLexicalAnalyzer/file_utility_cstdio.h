/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
/* この場合, こういった書き方じゃないとコンパイルエラーになる模様. */
#ifdef __cplusplus
extern "C" {
#endif
	void swap_2bytes(char* byte1, char* byte2);	/* 関数swap_2bytesの宣言. */
	int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len);	/* 関数convert_endian_16bit_byte_arrayの宣言. */
#ifdef __cplusplus
}
#endif
#endif