// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h"	// C++ファイルユーティリティ(C標準入出力)

// 指定のwtextにバイナリモードで読み込んだワイド文字列を格納する.
int read_wtext_file_binary_cstdio(const char* path, std::wstring& wtext) {

	// 変数・構造体の宣言・初期化.
	FILE* fp = NULL;	// ファイルポインタfpをNULLで初期化.
	int ret;	// freadの戻り値.

	// ファイルサイズの取得.
	size_t file_size = get_file_size(path);	// get_file_sizeでpathのfile_sizeを取得.

	// ファイルサイズが奇数ならエラー.
	if (file_size % 2 != 0) {	// 2で割った余りが0でない.
		return -1;	// -1を返して異常終了.
	}

	// バッファを確保.
	wchar_t* wbuf = new wchar_t[(file_size / 2) + 1];	// newで要素数が(file_size / 2) + 1のwchar_t動的配列を確保.

	// ファイルを開く.
	fp = fopen(path, "rb");	// fopenでバイナリ読み込みで開く.
	if (fp != NULL) {	// fpがNULLでない時.

		// ファイルからワイド文字列を読み込む.
		ret = fread(wbuf, sizeof(wchar_t), (file_size / 2), fp);	// freadでfpから入力された文字列をwbufに格納し, 戻り値はretに格納.
		wbuf[ret] = L'\0';	// NULL終端.

		// fpを閉じる.
		fclose(fp);	// fcloseでfpを閉じる.

		// wbufをwtextに代入.
		wtext = wbuf;

		// wbufの解放.
		delete[] wbuf;	// delete[]でwbufを解放.

		// retを返す.
		return ret;	// returnでretを返す.

	}

	// wbufの解放.
	delete[] wbuf;	// delete[]でwbufを解放.

	// -1を返す.
	return -1;	// returnで-1を返す.

}

// 指定のwtextにバイナリモードで読み込んだUTF-16BEのワイド文字列を格納する.
int read_wtext_file_binary_utf16be_cstdio(const char* path, std::wstring& wtext) {

	// ファイルから読み込む.
	std::wstring src;
	int ret = read_wtext_file_binary_cstdio(path, src);
	if (ret != -1) {
		char* converted = new char[src.length() * 2 + 2];
		convert_endian_16bit_byte_array((const char*)src.c_str(), converted, src.length() * 2);
		converted[src.length() * 2] = '\0';
		converted[src.length() * 2 + 1] = '\0';
		wtext = (wchar_t*)converted;
		delete[] converted;
		return wtext.length();
	}

	// -1を返す.
	return -1;	// returnで-1を返す.

}