// ヘッダのインクルード
// 既定のヘッダ
#include <locale>	// ロケール
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main(){

	// オブジェクトの宣言
	std::wstring wstr;	// std::wstringオブジェクトwstr

	// ロケールセット.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// "test.txt"を読み込んで内容をwstrに格納する.
	read_wtext_file_binary_utf16be_cstdio("test.txt", wstr);	// read_wtext_file_binary_utf16be_cstdioでファイル入力.

	// wstrの出力.
	printf("%ls\n", wstr.c_str());

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}