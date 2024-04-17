/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void swap_2bytes(char *byte1, char *byte2);	/* 関数swap_2bytesの宣言. */

/* main関数の定義 */
int main(void){

	/* 変数の初期化. */
	char a = 'a';	/* char型変数aを'a'で初期化. */
	char b = 'b';	/* char型変数bを'b'で初期化. */

	/* aとbの出力. */
	printf("a = \'%c\'\n", a);	/* aを出力. */
	printf("b = \'%c\'\n", b);	/* bを出力. */

	/* "-----"を出力. */
	printf("-----\n");

	/* スワップ */
	swap_2bytes(&a, &b);	/* swap_2bytesでaとbの値を入れ替える. */

	/* aとbの出力. */
	printf("a = \'%c\'\n", a);	/* aを出力. */
	printf("b = \'%c\'\n", b);	/* bを出力. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* 2つのバイト値を入れ替える. */
void swap_2bytes(char *byte1, char *byte2){

	/* 変数の宣言 */
	char temp;	/* char型一時変数temp. */

	/* byte1の指す値とbyte2の指す値を入れ替える. */
	temp = *byte1;	/* byte1の指す値をtempに代入. */
	*byte1 = *byte2;	/* byte2の指す値をbyte1に代入. */
	*byte2 = temp;	/* tempの値をbyte2の指す値に代入. */

}