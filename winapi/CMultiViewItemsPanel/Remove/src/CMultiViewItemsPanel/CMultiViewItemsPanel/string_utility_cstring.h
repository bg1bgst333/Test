/* 二重インクルード防止 */
#ifndef __STRING_UTILITY_CSTRING_H__
#define __STRING_UTILITY_CSTRING_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int replace_wbyte_all(wchar_t* wbytes, int wblen, wchar_t before, wchar_t after);	/* 関数replace_wbyte_allの宣言. */

#endif