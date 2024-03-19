/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
int write_file_bom_utf16le(const char *path); /* 関数write_file_bom_utf16leの宣言. */

/* main関数の定義 */
int main(void){

  /* test1.txtにUTF-16LEのBOMを書き込む. */
  write_file_bom_utf16le("test1.txt"); /* write_file_bom_utf16leでtest1.txtにUTF-16LEのBOMを書き込む. */

  /* test1.txtにUTF16-LEの"あ"を追記. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  char bytes[2] = {0x42, 0x30}; /* char型配列bytes(長さ2)を{0x42, 0x30}で初期化. */
  int ret; /* fwriteの戻り値ret. */
  fp = fopen("test1.txt", "ab"); /* fopenで"test1.txt"をバイナリ追加書き込みで開く. */
  if (fp == NULL){ /* fpがNULLの時. */
    return -1; /* returnで-1を返す. */
  }
  ret = fwrite(bytes, sizeof(char), 2, fp); /* fwriteでfpにbytesを追記し, 戻り値はretに格納. */
  fclose(fp); /* fcloseでfpを閉じる. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* UTF-16LEのBOMを書き込む. */
int write_file_bom_utf16le(const char *path){

  /* 変数・構造体の宣言・初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  char bom[2] = {0xff, 0xfe}; /* char型配列bom(長さ2)を{0xff, 0xfe}で初期化. */
  int ret; /* fwriteの戻り値ret. */

  /* ファイルを開く. */
  fp = fopen(path, "wb"); /* fopenでバイナリ書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにバイナリを書き込む. */
    ret = fwrite(bom, sizeof(char), 2, fp); /* fwriteでfpにbomを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
