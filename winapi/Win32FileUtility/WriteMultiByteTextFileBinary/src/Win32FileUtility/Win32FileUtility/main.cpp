// ヘッダのインクルード
// 独自のヘッダ
#include "Win32FileUtility.h"	// Win32ファイルユーティリティ

// main関数の定義
int main(){

	// 変数の宣言
	DWORD dwLen;	// 書き込んだ長さdwLen.

	// UTF-8(BOMなし)書き込み.
	WriteMultiByteTextFileBinary("test1.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ", CP_UTF8, &dwLen);

	// Shift_JIS書き込み.
	WriteMultiByteTextFileBinary("test2.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ", CP_ACP, &dwLen);

	// EUC-JP(20932)書き込み.
	WriteMultiByteTextFileBinary("test3.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ", 20932, &dwLen);

	// ISO-2022-JP(JIS)(50220)書き込み.
	WriteMultiByteTextFileBinary("test4.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ", 50220, &dwLen);

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}