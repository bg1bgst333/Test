/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* 2つのバイト値を入れ替える. */
void swap_2bytes(char *byte1, char *byte2){

	/* 変数の宣言 */
	char temp;	/* char型一時変数temp. */

	/* byte1の指す値とbyte2の指す値を入れ替える. */
	temp = *byte1;	/* byte1の指す値をtempに代入. */
	*byte1 = *byte2;	/* byte2の指す値をbyte1に代入. */
	*byte2 = temp;	/* tempの値をbyte2の指す値に代入. */

}