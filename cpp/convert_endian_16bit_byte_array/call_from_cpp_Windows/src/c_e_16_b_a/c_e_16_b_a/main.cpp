// ヘッダファイルのインクルード
// 既定のヘッダ
#include <cstdio>	// C標準入出力
// 独自のヘッダ
extern "C"{	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// main関数の定義
int main(void){

	// 変数・配列・構造体の宣言・初期化
	char japanese_str_converted[11];	// 変換後のchar型日本語文字配列(長さ11)japanese_str_converted.
	char bom_utf16be[2] = {0xfe, 0xff};
	FILE *fp = NULL;

	// 日本語文字列の16bitエンディアン変換.
	convert_endian_16bit_byte_array((const char *)L"あいうえお", japanese_str_converted, 10);	// convert_endian_16bit_byte_arrayで16bitエンディアン変換.
	japanese_str_converted[10] = '\0';	// NULL終端.

	// 日本語のjapanese_str_convertedを保存.
	fp = fopen("test.txt", "wb");
	if (fp == NULL){
		return -1;
	}
	fwrite(bom_utf16be, sizeof(char), 2, fp);
	fwrite(japanese_str_converted, sizeof(char), 10, fp);
	fclose(fp);

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}