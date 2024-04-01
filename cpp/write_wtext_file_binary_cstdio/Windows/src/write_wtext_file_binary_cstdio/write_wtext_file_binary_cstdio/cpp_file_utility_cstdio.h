// 二重インクルード防止
#ifndef __CPP_FILE_UTILITY_CSTDIO_H__
#define __CPP_FILE_UTILITY_CSTDIO_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio>	// C標準入出力
#include <cstring>	// C文字列処理

// 関数のプロトタイプ宣言
int write_wtext_file_binary_cstdio(const char *path, const wchar_t *wtext);	// 関数write_wtext_file_binary_cstdioの宣言.

#endif