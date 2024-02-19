/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* ファイルサイズの取得. */
size_t get_file_size(const char *path){

	/* 構造体の初期化. */
	struct _stat sst = {0};	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でバイナリファイル入力. */
size_t read_file_binary_cstdio_w(const wchar_t *path, void *bytes, size_t size){

	/* 構造体・ポインタの宣言・初期化. */
	FILE *fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだ文字数ret. */

	/* ファイルを開く. */
	fp = _wfopen(path, L"rb");	/* _wfopenでバイナリ読み込みで開く. */
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