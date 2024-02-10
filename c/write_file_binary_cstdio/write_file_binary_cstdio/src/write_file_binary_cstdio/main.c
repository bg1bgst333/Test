/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */

/* 関数のプロトタイプ宣言 */
int write_file_binary_cstdio(const char *path, const void *bytes, size_t size); /* 関数write_file_binary_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  char ascii_str[] = "ABC DE\nFGH\0IJ\nKLMNO"; /* ' 'と'\n'と'\0'が含まれたASCII文字列. */
  char japanese_str[] = "あいう えお\nかきく\0けこ\nさしすせそ"; /* ' 'と'\n'と'\0'が含まれた日本語文字列. */

  /* ascii_strを"test1.txt"に出力. */
  write_file_binary_cstdio("test1.txt", ascii_str, 19); /* write_file_binary_cstdioでascii_strを"test1.txt"に出力. */

  /* "ja_JP.UTF-8"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* japanese_strを"test2.txt"に出力. */
  write_file_binary_cstdio("test2.txt", japanese_str, 49); /* write_file_binary_cstdioでjapanese_strを"test2.txt"に出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* C標準入出力ライブラリ関数でバイナリファイル出力. */
int write_file_binary_cstdio(const char *path, const void *bytes, size_t size){

  /* 変数・構造体の宣言・初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret; /* fwriteの戻り値ret. */

  /* ファイルを開く. */
  fp = fopen(path, "wb"); /* fopenでバイナリ書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにバイナリを書き込む. */
    ret = fwrite(bytes, sizeof(char), size, fp); /* fwriteでfpにbytesを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
