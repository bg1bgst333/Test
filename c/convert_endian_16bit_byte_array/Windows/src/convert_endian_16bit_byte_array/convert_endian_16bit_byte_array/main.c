/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void swap_2bytes(char *byte1, char *byte2);	/* 関数swap_2bytesの宣言. */
int convert_endian_16bit_byte_array(const char *src, char *dest, size_t len);	/* 関数convert_endian_16bit_byte_arrayの宣言. */

/* main関数の定義 */
int main(void){

	/* 変数・配列・構造体の宣言・初期化 */
	char japanese_str_converted[11];	/* 変換後のchar型日本語文字配列(長さ11)japanese_str_converted. */
	char bom_utf16be[2] = {0xfe, 0xff};
	FILE *fp = NULL;

	/* 日本語文字列の16bitエンディアン変換. */
	convert_endian_16bit_byte_array(L"あいうえお", japanese_str_converted, 10);	/* convert_endian_16bit_byte_arrayで16bitエンディアン変換. */
	japanese_str_converted[10] = '\0'; /* NULL終端. */

	/* 日本語のjapanese_str_convertedを保存. */
	fp = fopen("test.txt", "wb");
	if (fp == NULL){
		return -1;
	}
	fwrite(bom_utf16be, sizeof(char), 2, fp);
	fwrite(japanese_str_converted, sizeof(char), 10, fp);
	fclose(fp);

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

/* バイト列のエンディアン変換(bigならlittle, littleならbig.) */
int convert_endian_16bit_byte_array(const char *src, char *dest, size_t len){

	/* 変数の初期化 */
	int half = 0;	/* 長さの半分harfを0で初期化. */
	int i = 0;	/* ループ用変数iを0で初期化. */
	int a, b;	/* 入れ替え用一時変数a, b. */

	/* 長さが奇数の場合はエラー. */
	if (len % 2){	/* 奇数. */
		return -1;	/* -1を返す. */
	}

	/* エンディアン変換 */
	half = len / 2;	/* lenの半分の長さをhalfに代入. */
	for (i = 0; i < half; i++){	/* halfの前まで繰り返す. */
		*(dest + 2 * i) = *(src + 2 * i);
		*(dest + 2 * i + 1) = *(src + 2 * i + 1);
		swap_2bytes(dest + 2 * i, dest + 2 * i + 1);
	}

	/* 正常終了 */
	return 0;	/* 0を返す. */

}