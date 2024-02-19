/* 二重インクルード防止 */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* ヘッダファイルのインクルード */
/* 既定のヘッダファイル */
#include <stdio.h>	/* 標準入出力 */
#include <sys/stat.h>	/* ファイル状態 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char* path);	/* 関数get_file_sizeの宣言. */
size_t read_file_binary_cstdio_w(const wchar_t* path, void* bytes, size_t size);	/* 関数read_file_binary_cstdio_wの宣言. */

#endif