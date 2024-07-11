/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */

/* 関数のプロトタイプ宣言 */
int replace_byte_all(char* bytes, int size, char before, char after);	/* 関数replace_byte_allの宣言. */

/* main関数の定義 */
int main(void) {

	/* 配列の初期化. */
	char bytes1[] = "ABBCB";
	char bytes2[] = { 0xa, 0xd, 0, 0xd, 0xd };
	int ret1;
	int ret2;
	int i;

	/* みつかった全てを置換. */
	ret1 = replace_byte_all(bytes1, 5, 'B', 'X');
	printf("bytes1 = %s\n", bytes1);
	printf("ret1 = %d\n", ret1);

	/* バイト列だから文字列じゃなくてもできる. */
	ret2 = replace_byte_all(bytes2, 5, 0xd, 0);
	for (i = 0; i < 5; i++) {
		printf("bytes2[%d] = 0x%x\n", i, bytes2[i]);
	}
	printf("ret2 = %d\n", ret2);

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

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