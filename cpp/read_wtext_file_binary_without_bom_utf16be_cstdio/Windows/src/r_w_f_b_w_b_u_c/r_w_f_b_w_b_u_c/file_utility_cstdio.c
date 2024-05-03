/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h"	/* ファイルユーティリティ(C標準入出力) */

/* ファイルサイズの取得. */
size_t get_file_size(const char *path){

  /* 構造体の初期化. */
  struct _stat sst = {0};	/* _stat構造体sstを{0}で初期化. */

  /* ファイル情報の取得. */
  _stat(path, &sst);	/* _statでpathで示されたファイルの情報をsstに格納. */

  /* ファイルサイズを返す. */
  return sst.st_size;	/* returnでsst.st_sizeを返す. */

}

/* UTF-16BEのBOMがあるか判定する. */
int is_file_bom_utf16be(const char *path){

	/* 変数・構造体の宣言・初期化. */
	FILE *fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	size_t ret;	/* 読み込んだバイト数ret. */
	char bom[2] = {0};	/* char型配列bom(長さ2)を{0}で初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "rb");	/* fopenでバイナリ読み込みで開く. */
	if (fp != NULL){	/* fpがNULLでない時. */

		/* ファイルからバイナリを読み込む. */
		ret = fread(bom, sizeof(char), 2, fp);	/* freadでfpから入力しbomに格納, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* BOMがUTF-16BEか判定. */
		if (bom[0] == (char)0xfe && bom[1] == (char)0xff){	/* 0番目が0xfe, 1番目が0xffなら. */
			return 1;	/* 1を返す. */
		}
		else{	/* それ以外. */
			return 0;	/* 0を返す. */
		}

	}

	/* ファイルを開けない場合は, 0を返す. */
	return 0;	/* returnで0を返す. */

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