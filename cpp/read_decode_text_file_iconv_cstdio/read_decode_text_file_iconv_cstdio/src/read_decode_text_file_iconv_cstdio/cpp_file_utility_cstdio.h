// 二重インクルード防止
#ifndef __CPP_FILE_UTILITY_CSTDIO_H__
#define __CPP_FILE_UTILITY_CSTDIO_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <cstdio> // C標準入出力
#include <cstdlib> // C標準ユーティリティ
#include <cstring> // C文字列処理
#include <string> // std::string
#include <iconv.h> // 文字コード変換
#include <locale.h> // ロケール
#include <limits.h> // 限界値

// 関数のプロトタイプ宣言
bool read_decode_text_file_iconv_cstdio(const char *path, std::string &text, const char *dec); // 関数read_decode_text_file_iconv_cstdioの宣言.

#endif
