/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "string_utility_cstring.h"	/* 文字列ユーティリティ(C文字列処理) */

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