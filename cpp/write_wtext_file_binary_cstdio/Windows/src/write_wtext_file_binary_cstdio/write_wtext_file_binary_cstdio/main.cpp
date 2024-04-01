// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main(){

	// "test.txt"に"あいうえお\r\nかきくけこ\r\nさしすせそ"をワイド文字テキスト(UTF-16LE)としてファイル出力.
	write_wtext_file_binary_cstdio("test.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ");	// write_wtext_file_binary_cstdioでファイル出力.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}