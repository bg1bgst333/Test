// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main() {

	// test.txtにUTF-16BEのBOMを書き込む.
	write_file_bom_utf16be("test.txt");	// write_file_bom_utf16beでtest.txtにUTF-16BEのBOMを書き込む.

	// test.txtに"あいうえお\r\nかきくけこ\r\nさしすせそ"をワイド文字テキスト(UTF-16BE)としてファイル追記.
	append_wtext_file_binary_utf16be_cstdio("test.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ");	// append_wtext_file_binary_utf16be_cstdioでファイル追記.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}