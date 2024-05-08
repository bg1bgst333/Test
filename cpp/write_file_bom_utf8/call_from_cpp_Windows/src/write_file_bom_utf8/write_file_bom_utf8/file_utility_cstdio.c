/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

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