// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <iostream>	// C++標準入出力
// 独自のヘッダ
#include "string_utility_cppstring.h"	// 文字列ユーティリティ(C++ std::string)

// main関数の定義
int main() {

	// オブジェクトの宣言
	tstring target = _T("AAAabcBBBabcCCCabc");	// 対象
	tstring before = _T("abc");	// 変換前
	tstring after = _T("xyz");	// 変換後

	// みつかった全てを置換.
	int c = replace_tstring_all(target, before, after);	// replace_tstring_allで全て置換.
	std::wcout << _T("target = ") << target << std::endl;	// targetを出力.
	std::wcout << _T("c = ") << c << std::endl;	// cを出力.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}