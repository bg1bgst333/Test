// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// 指定のワイド文字列をバイナリモードで追加書き込みする.
int append_wtext_file_binary_cstdio(const char* path, const wchar_t* wtext) {

	// 変数・構造体の宣言・初期化.
	FILE* fp = NULL;	// ファイルポインタfpをNULLで初期化.
	int ret;	// fwriteの戻り値ret.

	// ファイルを開く.
	fp = fopen(path, "ab");	// fopenでバイナリ追加書き込みで開く.
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

// 指定のワイド文字列をUTF-16BEでバイナリモードで追加書き込みする.
int append_wtext_file_binary_utf16be_cstdio(const char *path, const wchar_t *wtext){

	// 16bitエンディアン変換.
	size_t wlen = wcslen(wtext);
	char *converted = new char[wlen * 2 + 2];
	convert_endian_16bit_byte_array((char *)wtext, converted, wlen * 2);
	converted[wlen * 2] = '\0';
	converted[wlen * 2 + 1] = '\0';

	// ファイルに書き込む.
	int ret = append_wtext_file_binary_cstdio(path, (wchar_t *)converted);
	delete [] converted;
	return ret;

}