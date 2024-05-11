/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int write_file_bom_utf8(const char* path);	/* 関数write_file_bom_utf8の宣言. */

#endif