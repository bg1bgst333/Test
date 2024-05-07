// ヘッダのインクルード
// 既定のヘッダファイル
#include <locale.h>	// ロケール
// 独自のヘッダ
#include "Win32FileUtility.h"	// Win32ファイルユーティリティ

// main関数の定義
int main(){

	// 変数の宣言
	DWORD dwLen;	// 書き込んだ長さdwLen.

	// ロケールセット.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// UTF-8(BOMなし)読み込み.
	std::wstring wstr1;
	ReadMultiByteTextFileBinary("test1.txt", wstr1, CP_UTF8, &dwLen);
	printf("wstr1 = %ls\n", wstr1.c_str());

	// Shift_JIS読み込み.
	std::wstring wstr2;
	ReadMultiByteTextFileBinary("test2.txt", wstr2, CP_ACP, &dwLen);
	printf("wstr2 = %ls\n", wstr2.c_str());

	// EUC-JP(20932)読み込み.
	std::wstring wstr3;
	ReadMultiByteTextFileBinary("test3.txt", wstr3, 20932, &dwLen);
	printf("wstr3 = %ls\n", wstr3.c_str());

	// ISO-2022-JP(JIS)(50220)読み込み.
	std::wstring wstr4;
	ReadMultiByteTextFileBinary("test4.txt", wstr4, 50220, &dwLen);
	printf("wstr4 = %ls\n", wstr4.c_str());

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}