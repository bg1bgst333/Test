// ヘッダファイルのインクルード
extern "C" {	// C言語として解釈する.
	#include "string_utility_cstring.h"	// 文字列ユーティリティ(C文字列処理)
}

// main関数の定義
int main() {

	// 変数の宣言・配列の初期化.
	wchar_t wbytes[] = { L'A', L'|', L'C', L'|', L'|' };
	int ret;
	int i;

	// みつかった全てを置換.
	ret = replace_wbyte_all(wbytes, 5, L'|', L'\0');
	for (i = 0; i < 5; i++) {
		wprintf(L"wbytes[%d] = 0x%x\n", i, wbytes[i]);
	}
	wprintf(L"ret = %d\n", ret);

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}