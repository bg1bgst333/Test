/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "file_utility_cstdio.h" /* ファイルユーティリティ(C標準入出力) */

/* ファイルサイズの取得. */
size_t get_file_size(const char *path){

  /* 構造体の初期化. */
  struct stat sst = {0}; /* stat構造体sstを{0}で初期化. */

  /* ファイル情報の取得. */
  stat(path, &sst); /* statでpathで示されたファイルの情報をsstに格納. */

  /* ファイルサイズを返す. */
  return sst.st_size; /* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でテキストファイル入力. */
int scan_file_text_cstdio(const char *path, char *text){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* 格納した変数の数retを0に初期化. */

  /* ファイルを開く. */
  fp = fopen(path, "r"); /* fopenでテキスト読み込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルからテキストを読み込む. */
    ret = fscanf(fp, "%s", text); /* fscanfでfpから入力しtextに格納, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* 格納した変数の数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
