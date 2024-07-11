/* 二重インクルード防止 */
#ifndef __STRING_UTILITY_CSTRING_H__
#define __STRING_UTILITY_CSTRING_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */

/* 関数のプロトタイプ宣言 */
int replace_byte_all(char* bytes, int size, char before, char after);	/* 関数replace_byte_allの宣言. */

#endif