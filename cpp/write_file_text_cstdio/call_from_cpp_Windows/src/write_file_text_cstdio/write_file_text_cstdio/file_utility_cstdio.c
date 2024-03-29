/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int write_file_text_cstdio(const char* path, const char* text, size_t len) {

	/* 変数・構造体の宣言・初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret;	/* fwriteの戻り値ret. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fwrite(text, sizeof(char), len, fp);	/* fwriteでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}