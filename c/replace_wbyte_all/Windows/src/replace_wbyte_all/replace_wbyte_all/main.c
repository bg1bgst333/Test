/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int replace_wbyte_all(wchar_t* wbytes, int wblen, wchar_t before, wchar_t after);	/* 関数replace_wbyte_allの宣言. */

/* main関数の定義 */
int main(void) {

	/* 変数の宣言・配列の初期化. */
	wchar_t wbytes[] = { L'A', L'|', L'C', L'|', L'|' };
	int ret;
	int i;

	/* みつかった全てを置換 */
	ret = replace_wbyte_all(wbytes, 5, L'|', L'\0');
	for (i = 0; i < 5; i++) {
		wprintf(L"wbytes[%d] = 0x%x\n", i, wbytes[i]);
	}
	wprintf(L"ret = %d\n", ret);

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* 長さwblenのワイドバイト列wbytesのみつかった全てのbeforeをafterに置換. */
int replace_wbyte_all(wchar_t* wbytes, int wblen, wchar_t before, wchar_t after) {

	/* 変数の宣言・初期化. */
	int i;
	int total = 0;

	/* 最後まで探す. */
	for (i = 0; i < wblen; i++) {
		if (*(wbytes + i) == before) {
			*(wbytes + i) = after;	/* afterに置換. */
			total++;
		}
	}

	/* みつかった数を返す. */
	return total;

}