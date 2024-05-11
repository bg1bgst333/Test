/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int is_file_bom_utf8(const char *path);	/* 関数is_file_bom_utf8の宣言. */

/* main関数の定義 */
int main(void){

	/* 変数の宣言 */
	int ret;	/* int型変数ret. */
	
	/* test1.txtにUTF-8のBOMがあるか判定する. */
	ret = is_file_bom_utf8("test1.txt");	/* is_file_bom_utf8で"test1.txt"にUTF-8のBOMがあるか判定する. */
	if (ret == 1){	/* retが1. */
		printf("UTF-8\n");	/* "UTF-8"と出力. */
	}
	else{	/* retが0. */
		printf("Not UTF-8\n");	/* "Not UTF-8"と出力. */
	}
	
	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* UTF-8のBOMがあるか判定する. */
int is_file_bom_utf8(const char *path){

	/* 変数・構造体の宣言・初期化. */
	FILE *fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだバイト数ret. */
	char bom[3] = {0};	/* char型配列bom(長さ3)を{0}で初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "rb");	/* fopenでバイナリ読み込みで開く. */
	if (fp != NULL){	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bom, sizeof(char), 3, fp);	/* freadでfpから入力しbomに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* BOMがUTF-8か判定. */
		if (bom[0] == (char)0xef && bom[1] == (char)0xbb && bom[2] == (char)0xbf){	/* 0番目が0xef, 1番目が0xbbなら, 2番目が0xbfなら. */
			return 1;	/* 1を返す. */
		}
		else{	/* それ以外. */
			return 0;	/* 0を返す. */
		}

	}
	
	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}