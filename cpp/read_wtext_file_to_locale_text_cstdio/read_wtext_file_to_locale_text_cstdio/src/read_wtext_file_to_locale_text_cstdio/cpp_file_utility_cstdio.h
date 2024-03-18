// 二重インクルード防止
#ifndef __CPP_FILE_UTILITY_CSTDIO_H__
#define __CPP_FILE_UTILITY_CSTDIO_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio> // C標準入出力
#include <cstdlib> // C標準ユーティリティ
#include <cstring> // C文字列処理
#include <string> // std::string
#include <locale.h> // ロケール
#include <limits.h> // 限界値

// 関数のプロトタイプ宣言
bool read_wtext_file_to_locale_text_cstdio(const char *path, std::string &text, const char *loc); // 関数read_wtext_file_to_locale_text_cstdioの宣言.

#endif
