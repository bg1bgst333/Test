/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* UTF-16BEのBOMがあるか判定する. */
int is_file_bom_utf16be(const char* path) {

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

		/* BOMがUTF-16BEか判定. */
		if (bom[0] == (char)0xfe && bom[1] == (char)0xff) {	/* 0番目が0xfe, 1番目が0xffなら. */
			return 1;	/* 1を返す. */
		}
		else {	/* それ以外. */
			return 0;	/* 0を返す. */
		}

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

}