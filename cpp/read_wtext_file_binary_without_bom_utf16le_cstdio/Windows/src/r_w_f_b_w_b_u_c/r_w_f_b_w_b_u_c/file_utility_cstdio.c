/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* ファイルサイズの取得. */
size_t get_file_size(const char* path) {

	/* 構造体の初期化. */
	struct _stat sst = { 0 };	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* UTF-16LEのBOMがあるか判定する. */
int is_file_bom_utf16le(const char* path) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだバイト数ret. */
	char bom[2] = { 0 };	/* char型配列bom(長さ2)を{0}で初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "rb");	/* fopenでバイナリ読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bom, sizeof(char), 2, fp);	/* freadでfpから入力しbomに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* BOMがUTF-16LEか判定. */
		if (bom[0] == (char)0xff && bom[1] == (char)0xfe) {	/* 0番目が0xff, 1番目が0xfeなら. */
			return 1;	/* 1を返す. */
		}
		else {	/* それ以外. */
			return 0;	/* 0を返す. */
		}

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}