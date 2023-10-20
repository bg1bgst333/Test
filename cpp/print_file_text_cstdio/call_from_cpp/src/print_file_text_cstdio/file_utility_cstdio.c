/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h" /* ファイルユーティリティ(C標準入出力) */

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int print_file_text_cstdio(const char *path, const char *text){

  /* 変数・構造体・ポインタの初期化 */
  FILE *fp = NULL; /* ファイルポインタをNULLで初期化. */
  int ret = 0; /* 書き込んだバイト数retを0で初期化. */

  /* ファイルを開く. */
  fp = fopen(path, "w"); /* fopenでテキスト書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにテキストを書き込む. */
    ret = fprintf(fp, "%s", text); /* fprintfでfpにtextを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* 書き込んだバイト数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
