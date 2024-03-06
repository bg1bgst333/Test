/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <string.h>	/* 文字列処理 */
#include <locale.h>	/* ロケール */
#include <sys/stat.h>	/* ファイル状態 */
#include <wchar.h>	/* ワイド文字 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char* path);	/* 関数get_file_sizeの宣言. */
wchar_t* wget_file_wtext_ccs_cstdio(const char* path, wchar_t* wtext, size_t buf_size, const char* ccs);	/* 関数wget_file_wtext_ccs_cstdioの宣言. */

/* main関数の定義 */
int main(void) {

	/* 変数・ポインタの宣言・初期化. */
	size_t file_size_1;	/* size_t型変数file_size_1. */
	size_t file_size_2;	/* size_t型変数file_size_2. */
	size_t file_size_3;	/* size_t型変数file_size_3. */
	size_t file_size_4;	/* sixe_t型変数file_size_4. */
	wchar_t* buf1 = NULL;	/* wchar_t型ポインタbuf1をNULLで初期化. */
	wchar_t* buf2 = NULL;	/* wchar_t型ポインタbuf2をNULLで初期化. */
	wchar_t* buf3 = NULL;	/* wchar_t型ポインタbuf3をNULLで初期化. */
	wchar_t* buf4 = NULL;	/* wchar_t型ポインタbuf4をNULLで初期化. */
	int ret_1 = 0;
	int ret_2 = 0;
	int ret_3 = 0;
	int ret_4 = 0;

	/* "Japanese_Japan.932"ロケールのセット. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleでLC_ALL, "Japanese_Japan.932"をセット. */

	/* test1.txtのサイズ取得. */
	file_size_1 = get_file_size("test1.txt");	/* get_file_sizeで"test1.txt"のサイズ取得. */

	/* メモリの確保. */
	buf1 = (wchar_t*)malloc((file_size_1 + 1) * sizeof(wchar_t));	/* mallocで((file_size_1 + 1) * sizeof(wchar_t))分のメモリ確保. */

	/* "test1.txt"からの入力をbuf1に格納. */
	wget_file_wtext_ccs_cstdio("test1.txt", buf1, file_size_1 + 1, NULL);	/* wget_file_wtext_ccs_cstdioでNULLの"test1.txt"を読み込み. */
	ret_1 = wcslen(buf1);	/* 長さをret_1に格納. */
	buf1[ret_1] = L'\0';	/* NULL終端 */

	/* buf1を出力. */
	printf("buf1 = %ls\n", buf1);	/* printfでbuf1を出力. */

	/* メモリの解放. */
	free(buf1);	/* freeでbuf1を解放. */

	/* test2.txtのサイズ取得. */
	file_size_2 = get_file_size("test2.txt");	/* get_file_sizeで"test2.txt"のサイズ取得. */

	/* メモリの確保. */
	buf2 = (wchar_t*)malloc((file_size_2 + 1) * sizeof(wchar_t));	/* mallocで((file_size_2 + 1) * sizeof(wchar_t))分のメモリ確保. */

	/* "test2.txt"からの入力をbuf2に格納. */
	wget_file_wtext_ccs_cstdio("test2.txt", buf2, file_size_2 + 1, "");	/* wget_file_wtext_ccs_cstdioで""の"test2.txt"を読み込み. */
	ret_2 = wcslen(buf2);	/* 長さをret_2に格納. */
	buf2[ret_2] = L'\0';	/* NULL終端 */

	/* buf2を出力. */
	printf("buf2 = %ls\n", buf2);	/* printfでbuf2を出力. */

	/* メモリの解放. */
	free(buf2);	/* freeでbuf2を解放. */

	/* test3.txtのサイズ取得. */
	file_size_3 = get_file_size("test3.txt");	/* get_file_sizeで"test3.txt"のサイズ取得. */

	/* メモリの確保. */
	buf3 = (wchar_t*)malloc((file_size_3 + 1) * sizeof(wchar_t));	/* mallocで((file_size_3 + 1) * sizeof(wchar_t))分のメモリ確保. */

	/* "test3.txt"からの入力をbuf3に格納. */
	wget_file_wtext_ccs_cstdio("test3.txt", buf3, file_size_3 + 1, "UNICODE");	/* wget_file_wtext_ccs_cstdioで"UNICODE"の"test3.txt"を読み込み. */
	ret_3 = wcslen(buf3);	/* 長さをret_3に格納. */
	buf3[ret_3] = L'\0';	/* NULL終端 */

	/* buf3を出力. */
	printf("buf3 = %ls\n", buf3);	/* printfでbuf3を出力. */

	/* メモリの解放. */
	free(buf3);	/* freeでbuf3を解放. */

	/* test4.txtのサイズ取得. */
	file_size_4 = get_file_size("test4.txt");	/* get_file_sizeで"test4.txt"のサイズ取得. */

	/* メモリの確保. */
	buf4 = (wchar_t*)malloc((file_size_4 + 1) * sizeof(wchar_t));	/* mallocで((file_size_4 + 1) * sizeof(wchar_t))分のメモリ確保. */

	/* "test4.txt"からの入力をbuf4に格納. */
	wget_file_wtext_ccs_cstdio("test4.txt", buf4, file_size_4 + 1, "UTF-8");	/* wget_file_wtext_ccs_cstdioで"UTF-8"の"test4.txt"を読み込み. */
	ret_4 = wcslen(buf4);	/* 長さをret_4に格納. */
	buf4[ret_4] = L'\0';	/* NULL終端 */

	/* buf4を出力. */
	printf("buf4 = %ls\n", buf4);	/* printfでbuf4を出力. */

	/* メモリの解放. */
	free(buf4);	/* freeでbuf4を解放. */

	/* プログラムの終了 */
	return 0; /* 0を返して正常終了. */

}

/* ファイルサイズの取得. */
size_t get_file_size(const char* path) {

	/* 構造体の初期化. */
	struct stat sst = { 0 };	/* stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	stat(path, &sst);	/* statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でワイド文字テキストファイル入力. */
wchar_t* wget_file_wtext_ccs_cstdio(const char* path, wchar_t* wtext, size_t buf_size, const char* ccs) {

	/* 構造体・ポインタの宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	wchar_t* ret;	/* 格納した文字列ポインタret. */
	char mode[256] = "";	/* モードを表すmodeを""で初期化. */

	/* ファイルを開く. */
	if (ccs == NULL || strcmp(ccs, "") == 0) {	/* NULLまたは空の場合. */
		strcpy(mode, "r");	/* strcpyでmodeに"r"をセット. */
	}
	else {	/* それ以外. */
		strcpy(mode, "r, ccs=");	/* strcpyでmodeに"r, ccs="をセット. */
		strcat(mode, ccs);	/* strcatでmodeにccsを連結. */
	}
	fp = fopen(path, mode);	/* fopenでmodeで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルからワイド文字テキストを読み込む. */
		ret = fgetws(wtext, buf_size, fp);	/* fgetwsでfpから入力しwtextに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, NULLを返す. */
	return NULL;	/* returnでNULLを返す. */

}