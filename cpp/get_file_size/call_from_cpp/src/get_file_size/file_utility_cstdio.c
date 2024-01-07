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
