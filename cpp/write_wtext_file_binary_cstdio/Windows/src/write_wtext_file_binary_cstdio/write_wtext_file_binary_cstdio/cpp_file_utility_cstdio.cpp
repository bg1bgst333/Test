// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// 指定のワイド文字列をバイナリモードで書き込む.
int write_wtext_file_binary_cstdio(const char* path, const wchar_t* wtext) {

	// 変数・構造体の宣言・初期化.
	FILE* fp = NULL;	// ファイルポインタfpをNULLで初期化.
	int ret;	// fwriteの戻り値ret.

	// ファイルを開く.
	fp = fopen(path, "wb");	// fopenでバイナリ書き込みで開く.
	if (fp != NULL) {	// fpがNULLでない時.

		// ファイルにワイド文字列を書き込む.
		ret = fwrite(wtext, sizeof(wchar_t), wcslen(wtext), fp);	// fwriteでfpにwtextを出力し, 戻り値はretに格納.

		// fpを閉じる.
		fclose(fp);	// fcloseでfpを閉じる.

		// retを返す.
		return ret;	// returnでretを返す.

	}

	// ファイルを開けない場合は, -1を返す.
	return -1;	// returnで-1を返す.

}