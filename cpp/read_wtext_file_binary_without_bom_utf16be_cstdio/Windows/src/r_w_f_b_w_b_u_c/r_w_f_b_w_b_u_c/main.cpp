// ヘッダのインクルード
// 既定のヘッダ
#include <locale.h>	// ロケール
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main() {

	// 変数の宣言
	int ret;	// int型変数ret.
	std::wstring wtext;	// std::wstringオブジェクトwtext.

	// ロケールセット.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// test.txtにUTF-16BEのBOMがあるか判定する.
	ret = is_file_bom_utf16be("test.txt");	// is_file_bom_utf16beで"test.txt"にUTF-16BEのBOMがあるか判定する.
	if (ret == 1) {	// retが1.
		// BOM以外を取り出す.
		read_wtext_file_binary_without_bom_utf16be_cstdio("test.txt", wtext);	// read_wtext_file_binary_without_bom_utf16be_cstdioで"test.txt"を読み込む.
		// wtextの出力.
		printf("%ls\n", wtext.c_str());
	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}