/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */

/* 関数のプロトタイプ宣言 */
int write_file_binary_cstdio_w(const wchar_t *path, const void *bytes, size_t size);	/* 関数write_file_binary_cstdio_wの宣言. */

#endif
