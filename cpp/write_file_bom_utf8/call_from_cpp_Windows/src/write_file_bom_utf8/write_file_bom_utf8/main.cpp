// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <string.h>	// 文字列処理
// 独自のヘッダファイル
extern "C"{	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// main関数の定義
int main(void){

	// 変数の宣言・初期化
	FILE *fp = NULL;	// ファイルポインタfpをNULLで初期化.
	int ret;	// fwriteの戻り値ret.
	char str[] = {0xe3, 0x81, 0x82, 0x00};	// char型配列str[]を{0xe3, 0x81, 0x82, 0x00}(UTF-8の"あ")で初期化.

	// test1.txtにUTF-8のBOMを書き込む.
	write_file_bom_utf8("test1.txt");	// write_file_bom_utf8でtest1.txtにUTF-8のBOMを書き込む.

	// test1.txtにUTF8の"あ"を追記.
	fp = fopen("test1.txt", "ab");	// fopenで"test1.txt"をバイナリ追加書き込みで開く.
	if (fp == NULL){	// fpがNULLの時.
		return -1;	// returnで-1を返す.
	}
	ret = fwrite(str, sizeof(char), strlen(str), fp);	// fwriteでfpにstrを追記し, 戻り値はretに格納.
	fclose(fp);	// fcloseでfpを閉じる.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}