// ヘッダファイルのインクルード
extern "C" {	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// main関数
int main() {

	// 変数・構造体の宣言・初期化.
	FILE* fp = NULL;	// ファイルポインタfpをNULLで初期化.
	char bytes[2] = { 0x42, 0x30 };	// char型配列bytes(長さ2)を{0x42, 0x30}で初期化.
	int ret;	// fwriteの戻り値ret.

	// test1.txtにUTF-16LEのBOMを書き込む.
	write_file_bom_utf16le("test1.txt");	// write_file_bom_utf16leでtest1.txtにUTF-16LEのBOMを書き込む.

	// test1.txtにUTF16-LEの"あ"を追記.
	fp = fopen("test1.txt", "ab");	// fopenで"test1.txt"をバイナリ追加書き込みで開く.
	if (fp == NULL) {	// fpがNULLの時.
		return -1;	// returnで-1を返す.
	}
	ret = fwrite(bytes, sizeof(char), 2, fp);	// fwriteでfpにbytesを追記し, 戻り値はretに格納.
	fclose(fp);	// fcloseでfpを閉じる.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}