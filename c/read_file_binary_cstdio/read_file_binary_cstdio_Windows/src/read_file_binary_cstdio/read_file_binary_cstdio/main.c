/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <stdlib.h>	/* 標準ユーティリティ */
#include <string.h>	/* 文字列処理 */
#include <locale.h>	/* ロケール */
#include <sys/stat.h>	/* ファイル状態 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char *path);	/* 関数get_file_sizeの宣言. */
size_t read_file_binary_cstdio(const char *path, void *bytes, size_t size);	/* 関数read_file_binary_cstdioの宣言. */

/* main関数の定義 */
int main(void){

	/* 変数・ポインタの宣言・初期化. */
	size_t file_size_1;	/* size_t型変数file_size_1. */
	size_t file_size_2;	/* size_t型変数file_size_2. */
	char *buf1 = NULL;	/* char型ポインタbuf1をNULLで初期化. */
	char *buf2 = NULL;	/* char型ポインタbuf2をNULLで初期化. */
	int ret1;
	int ret2;

	/* test1.txtのサイズ取得. */
	file_size_1 = get_file_size("test1.txt");	/* get_file_sizeで"test1.txt"のサイズ取得. */

	/* メモリの確保. */
	buf1 = (char *)malloc((file_size_1 + 1) * sizeof(char));	/* mallocで(file_size_1 + 1)分のメモリ確保. */

	/* "C"ロケールのセット. */
	setlocale(LC_ALL, "C");	/* setlocaleでLC_ALL, "C"をセット. */

	/* "test1.txt"からの入力をbuf1に格納. */
	ret1 = read_file_binary_cstdio("test1.txt", buf1, file_size_1 + 1);	/* read_file_binary_cstdioで"test1.txt"を読み込み. */
	buf1[ret1] = '\0';	/* 末尾に'\0'をセット. */

	/* buf1を出力. */
	fwrite(buf1, sizeof(char), ret1, stdout);	/* fwriteでbuf1をret1の分だけstdoutで出力. */
 
	/* メモリの解放. */
	free(buf1);	/* freeでbuf1を解放. */

	/* 改行出力. */
	printf("\n"); /* printfで"\n"を出力. */

	/* test2.txtのサイズ取得. */
	file_size_2 = get_file_size("test2.txt");	/* get_file_sizeで"test2.txt"のサイズ取得. */

	/* メモリの確保. */
	buf2 = (char *)malloc((file_size_2 + 1) * sizeof(char));	/* mallocで(file_size_2 + 1)分のメモリ確保. */

	/* "Japanese_Japan.932"ロケールのセット. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleでLC_ALL, "Japanese_Japan.932"をセット. */

	/* "test2.txt"からの入力をbuf2に格納. */
	ret2 = read_file_binary_cstdio("test2.txt", buf2, file_size_2 + 1);	/* read_file_binary_cstdioで"test2.txt"を読み込み. */
	buf2[ret2] = '\0';	/* 末尾に'\0'をセット. */

	/* buf2を出力. */
	/* fwrite(buf2, sizeof(char), ret2, stdout); */	/* fwriteでbuf2をret2の分だけstdoutで出力. */
	fprintf(stdout, "%s", buf2);
	fprintf(stdout, " %s", buf2 + strlen(buf2) + 1);

	/* メモリの解放. */
	free(buf2); /* freeでbuf2を解放. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* ファイルサイズの取得 */
size_t get_file_size(const char *path){

	/* 構造体の初期化. */
	struct _stat sst = {0};	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル入力. */
size_t read_file_binary_cstdio(const char *path, void *bytes, size_t size){

	/* 構造体・ポインタの宣言・初期化. */
	FILE *fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだ文字数ret. */

	/* ファイルを開く. */
	fp = fopen(path, "rb");	/* fopenでバイナリ読み込みで開く. */
	if (fp != NULL){	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bytes, sizeof(char), size, fp);	/* freadでfpから入力しbytesに格納, 戻り値はretに格納. */
		
		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */
	
	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}