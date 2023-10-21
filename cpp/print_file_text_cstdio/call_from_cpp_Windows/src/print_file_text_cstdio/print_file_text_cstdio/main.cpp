// ヘッダファイルのインクルード
extern "C" {	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// C標準ライブラリ
#include <locale.h>	// ロケール

// main関数
int main() {

	// 配列の初期化.
	char ascii_str[] = "ABCDE\nFGHIJ\nKLMNO";	// '\n'が含まれたASCII文字列.
	char japanese_str[] = "あいうえお\nかきくけこ\nさしすせそ";	// '\n'が含まれた日本語文字列.

	// ascii_strを"test1.txt"に出力.
	print_file_text_cstdio("test1.txt", ascii_str);	// print_file_text_cstdioでascii_strを"test1.txt"に出力.

	// "Japanese_Japan.932"ロケールのセット.
	setlocale(LC_ALL, "Japanese_Japan.932");	// setlocaleでLC_ALL, "Japanese_Japan.932"をセット.

	// japanese_strを"test2.txt"に出力.
	print_file_text_cstdio("test2.txt", japanese_str);	// print_file_text_cstdioでjapanese_strを"test2.txt"に出力.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}