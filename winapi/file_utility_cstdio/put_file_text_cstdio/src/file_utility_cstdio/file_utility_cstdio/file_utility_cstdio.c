/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int print_file_text_cstdio(const char* path, const char* text) {

	/* 変数・構造体・ポインタの初期化 */
	FILE* fp = NULL;	/* ファイルポインタをNULLで初期化. */
	int ret = 0;	/* 書き込んだバイト数retを0で初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fprintf(fp, "%s", text);	/* fprintfでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* 書き込んだバイト数retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* ファイルサイズの取得. */
size_t get_file_size(const char* path) {

	/* 構造体の初期化. */
	struct _stat sst = { 0 };	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル入力. */
int scan_file_text_cstdio(const char* path, char* text) {

	/* 変数・構造体の初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret = 0;	/* 格納した変数の数retを0に初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "r");	/* fopenでテキスト読み込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからテキストを読み込む. */
		ret = fscanf(fp, "%s", text);	/* fscanfでfpから入力しtextに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* 格納した変数の数retを返す. */
		return ret; /* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int put_file_text_cstdio(const char* path, const char* text) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fputsの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fputs(text, fp);	/* fputsでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* fputsが成功ならretは0. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}