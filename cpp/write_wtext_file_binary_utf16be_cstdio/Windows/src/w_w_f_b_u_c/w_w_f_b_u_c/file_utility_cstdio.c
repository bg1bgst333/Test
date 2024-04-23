/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* 2つのバイト値を入れ替える. */
void swap_2bytes(char* byte1, char* byte2) {

	/* 変数の宣言 */
	char temp;	/* char型一時変数temp. */

	/* byte1の指す値とbyte2の指す値を入れ替える. */
	temp = *byte1;	/* byte1の指す値をtempに代入. */
	*byte1 = *byte2;	/* byte2の指す値をbyte1に代入. */
	*byte2 = temp;	/* tempの値をbyte2の指す値に代入. */

}

/* バイト列のエンディアン変換(bigならlittle, littleならbig.) */
int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len) {

	/* 変数の初期化 */
	int half = 0;	/* 長さの半分harfを0で初期化. */
	int i = 0;	/* ループ用変数iを0で初期化. */
	int a, b;	/* 入れ替え用一時変数a, b. */

	/* 長さが奇数の場合はエラー. */
	if (len % 2) {	/* 奇数. */
		return -1;	/* -1を返す. */
	}

	/* エンディアン変換 */
	half = len / 2;	/* lenの半分の長さをhalfに代入. */
	for (i = 0; i < half; i++) {	/* halfの前まで繰り返す. */
		*(dest + 2 * i) = *(src + 2 * i);
		*(dest + 2 * i + 1) = *(src + 2 * i + 1);
		swap_2bytes(dest + 2 * i, dest + 2 * i + 1);
	}

	/* 正常終了 */
	return 0;	/* 0を返す. */

}