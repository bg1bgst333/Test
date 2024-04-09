/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
/* この場合, こういった書き方じゃないとコンパイルエラーになる模様. */
#ifdef __cplusplus
extern "C" {
#endif
	int write_file_bom_utf16le(const char* path);	/* 関数write_file_bom_utf16leの宣言. */
#ifdef __cplusplus
}
#endif
#endif