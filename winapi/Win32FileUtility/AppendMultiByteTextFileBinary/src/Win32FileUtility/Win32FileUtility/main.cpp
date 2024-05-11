// ヘッダファイルのインクルード
// 独自のヘッダファイル
extern "C" {	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}
#include "Win32FileUtility.h"	// Win32ファイルユーティリティ

// main関数の定義
int main() {

	// 変数の宣言
	DWORD dwLen;	// 書き込んだ長さdwLen.

	// test.txtにUTF-8のBOMを書き込む.
	write_file_bom_utf8("test.txt");	// write_file_bom_utf8でtest.txtにUTF-8のBOMを書き込む.

	// UTF-8(BOMなし)書き込み.
	AppendMultiByteTextFileBinary("test.txt", L"あいうえお\r\nかきくけこ\r\nさしすせそ", CP_UTF8, &dwLen);

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}