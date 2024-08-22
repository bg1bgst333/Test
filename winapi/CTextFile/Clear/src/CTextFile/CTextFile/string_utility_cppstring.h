// 二重インクルード防止
#ifndef __STRING_UTILITY_CPPSTRING_H__
#define __STRING_UTILITY_CPPSTRING_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// 関数のプロトタイプ宣言
int replace_tstring_all(tstring& target, const tstring& before, const tstring& after);	// tstring文字列targetの部分文字列beforeを全てafterに置換.

#endif