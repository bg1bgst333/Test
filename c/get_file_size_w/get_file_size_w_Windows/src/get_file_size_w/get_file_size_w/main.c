/* ヘッダファイルのインクルード */
#include <stdio.h>		/* 標準入出力 */
#include <sys/types.h>	/* 派生型 */
#include <sys/stat.h>	/* ファイル状態 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size_w(const wchar_t *path);	/* 関数get_file_size_wの宣言 */

/* main関数の定義 */
int main(void){

	/* ファイルサイズの取得. */
	size_t file_size = get_file_size_w(L"test.txt");	/* get_file_size_wで"test.txt"のファイルサイズを取得. */

	/* file_sizeを出力. */
	printf("file_size = %d\n", file_size);	/* printfでfile_sizeを取得. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* ファイルサイズの取得 */
size_t get_file_size_w(const wchar_t *path){

	/* 構造体の初期化. */
	struct _stat sst = {0};	/* _stat構造体sstを{0}で初期化. */

	/* ファイル情報の取得. */
	_wstat(path, &sst);	/* _wstatでpathで示されたファイルの情報をsstに格納. */

	/* ファイルサイズを返す. */
	return sst.st_size;	/* returnでsst.st_sizeを返す. */

}