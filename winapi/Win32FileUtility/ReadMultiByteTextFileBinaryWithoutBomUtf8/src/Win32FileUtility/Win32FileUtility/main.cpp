// ヘッダのインクルード
// 既定のヘッダファイル
#include <locale.h>	// ロケール
// 独自のヘッダ
#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
#include "Win32FileUtility.h"	// Win32ファイルユーティリティ

// main関数の定義
int main(){

	// 変数の宣言
	DWORD dwLen;	// 書き込んだ長さdwLen.
	int ret;	// int型変数ret.

	// ロケールセット.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// test.txtにUTF-8のBOMがあるか判定する.
	ret = is_file_bom_utf8("test.txt");	// is_file_bom_utf8で"test.txt"にUTF-8のBOMがあるか判定する.
	if (ret == 1){	// retが1.
		// BOM以外を取り出す.
		std::wstring wstr;
		ReadMultiByteTextFileBinaryWithoutBomUtf8("test.txt", wstr, &dwLen);	// ReadMultiByteTextFileBinaryWithoutBomUtf8で"test.txt"のBOM以外を読み込む.
		printf("%ls\n", wstr.c_str());
	}

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}