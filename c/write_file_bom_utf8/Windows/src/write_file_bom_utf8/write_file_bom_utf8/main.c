/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */

/* 関数のプロトタイプ宣言 */
int write_file_bom_utf8(const char* path);	/* 関数write_file_bom_utf8の宣言. */

/* main関数の定義 */
int main(void) {

	/* 変数の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fwriteの戻り値ret. */
	char str[] = { 0xe3, 0x81, 0x82, 0x00 };	/* char型配列str[]を{0xe3, 0x81, 0x82, 0x00}(UTF-8の"あ")で初期化. */

	/* test1.txtにUTF-8のBOMを書き込む. */
	write_file_bom_utf8("test1.txt");	/* write_file_bom_utf8でtest1.txtにUTF-8のBOMを書き込む. */

	/* test1.txtにUTF8の"あ"を追記. */
	fp = fopen("test1.txt", "ab");	/* fopenで"test1.txt"をバイナリ追加書き込みで開く. */
	if (fp == NULL) {	/* fpがNULLの時. */
		return -1;	/* returnで-1を返す. */
	}
	ret = fwrite(str, sizeof(char), strlen(str), fp);	/* fwriteでfpにstrを追記し, 戻り値はretに格納. */
	fclose(fp);	/* fcloseでfpを閉じる. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* UTF-8のBOMを書き込む. */
int write_file_bom_utf8(const char* path) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	char bom[3] = { 0xef, 0xbb, 0xbf };	/* char型配列bom(長さ3)を{0xef, 0xbb, 0xbf}で初期化. */
	int ret;	/* fwriteの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "wb");	/* fopenでバイナリ書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにバイナリを書き込む. */
		ret = fwrite(bom, sizeof(char), 3, fp);	/* fwriteでfpにbomを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}