/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "string_utility_cstring.h"	/* 文字列ユーティリティ(C文字列処理) */

/* 長さsizeのバイト列bytesのみつかった全てのbeforeをafterに置換. */
int replace_byte_all(char* bytes, int size, char before, char after) {

	/* 変数の宣言・初期化. */
	int i;
	int total = 0;

	/* 最後まで探す. */
	for (i = 0; i < size; i++) {
		if (*(bytes + i) == before) {
			*(bytes + i) = after;	/* afterに置換. */
			total++;
		}
	}

	/* みつかった数を返す. */
	return total;

}