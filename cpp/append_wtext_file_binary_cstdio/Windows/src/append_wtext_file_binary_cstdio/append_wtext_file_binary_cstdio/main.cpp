// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main() {

	// test.txtにUTF-16LEのBOMを書き込む.
	write_file_bom_utf16le("test.txt");	// write_file_bom_utf16leでtest.txtにUTF-16LEのBOMを書き込む.

	// test.txtに"あいうえお\r\nかきくけこ\r\nさしすせそ"をワイド文字テキスト(UTF-16LE)としてファイル追記.
	append_wtext_file_binary_cstdio("test.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ");	// append_wtext_file_binary_cstdioでファイル追記.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}