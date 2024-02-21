/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */
#include <sys/stat.h> /* ファイル状態 */
#include <wchar.h> /* ワイド文字 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char *path); /* 関数get_file_sizeの宣言. */
int scan_file_wtext_cstdio(const char *path, wchar_t *wtext); /* 関数scan_file_wtext_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 変数・ポインタの宣言・初期化. */
  size_t file_size_0; /* size_t型変数file_size_0. */
  size_t file_size_1; /* size_t型変数file_size_1. */
  size_t file_size_2; /* size_t型変数file_size_2. */
  wchar_t *buf0 = NULL; /* wchar_t型ポインタbuf0をNULLで初期化. */
  wchar_t *buf1 = NULL; /* wchar_t型ポインタbuf1をNULLで初期化. */
  wchar_t *buf2 = NULL; /* wchar_t型ポインタbuf2をNULLで初期化. */
  int ret_0 = 0;
  int ret_1 = 0;
  int ret_2 = 0;

  /* test1.txtのサイズ取得. */
  file_size_0 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf0 = (wchar_t *)malloc((file_size_0 + 1) * sizeof(wchar_t)); /* mallocで((file_size_0 + 1) * sizeof(wchar_t))分のメモリ確保. */

  /* "test1.txt"からの入力をbuf0に格納. */
  scan_file_wtext_cstdio("test1.txt", buf0); /* scan_file_wtext_cstdioで"test1.txt"を読み込み. */
  ret_0 = wcslen(buf0); /* 長さをret_0に格納. */
  buf0[ret_0] = L'\0'; /* NULL終端 */

  /* buf0を出力. */
  printf("buf0 = %ls\n", buf0); /* printfでbuf0を出力. */

  /* メモリの解放. */
  free(buf0); /* freeでbuf0を解放. */

  /* "ja_JP.UTF-8"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* test1.txtのサイズ取得. */
  file_size_1 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf1 = (wchar_t *)malloc((file_size_1 + 1) * sizeof(wchar_t)); /* mallocで((file_size_1 + 1) * sizeof(wchar_t))分のメモリ確保. */

  /* "test1.txt"からの入力をbuf1に格納. */
  scan_file_wtext_cstdio("test1.txt", buf1); /* scan_file_wtext_cstdioで"test1.txt"を読み込み. */
  ret_1 = wcslen(buf1); /* 長さをret_1に格納. */
  buf1[ret_1] = L'\0'; /* NULL終端 */

  /* buf1を出力. */
  printf("buf1 = %ls\n", buf1); /* printfでbuf1を出力. */

  /* メモリの解放. */
  free(buf1); /* freeでbuf1を解放. */

  /* "ja_JP.EUC-JP"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* test2.txtのサイズ取得. */
  file_size_2 = get_file_size("test2.txt"); /* get_file_sizeで"test2.txt"のサイズ取得. */

  /* メモリの確保. */
  buf2 = (wchar_t *)malloc((file_size_2 + 1) * sizeof(wchar_t)); /* mallocで((file_size_2 + 1) * sizeof(wchar_t))分のメモリ確保. */

  /* "test2.txt"からの入力をbuf2に格納. */
  scan_file_wtext_cstdio("test2.txt", buf2); /* scan_file_wtext_cstdioで"test2.txt"を読み込み. */
  ret_2 = wcslen(buf2); /* 長さをret_2に格納. */
  buf2[ret_2] = L'\0'; /* NULL終端 */

  /* buf2を出力. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* これがないと出力されない. */
  printf("buf2 = %ls\n", buf2); /* printfでbuf2を出力. */

  /* メモリの解放. */
  free(buf2); /* freeでbuf2を解放. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* ファイルサイズの取得. */
size_t get_file_size(const char *path){

  /* 構造体の初期化. */
  struct stat sst = {0}; /* stat構造体sstを{0}で初期化. */

  /* ファイル情報の取得. */
  stat(path, &sst); /* statでpathで示されたファイルの情報をsstに格納. */

  /* ファイルサイズを返す. */
  return sst.st_size; /* returnでsst.st_sizeを返す. */

}

/* C標準入出力ライブラリ関数でワイド文字テキストファイル入力. */
int scan_file_wtext_cstdio(const char *path, wchar_t *wtext){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* 格納した変数の数retを0に初期化. */

  /* ファイルを開く. */
  fp = fopen(path, "r"); /* fopenでテキスト読み込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルからワイド文字テキストを読み込む. */
    ret = fscanf(fp, "%ls", wtext); /* fscanfでfpから入力しwtextに格納, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* 格納した変数の数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
