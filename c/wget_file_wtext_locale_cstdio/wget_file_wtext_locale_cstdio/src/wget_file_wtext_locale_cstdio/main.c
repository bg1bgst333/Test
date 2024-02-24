/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */
#include <sys/stat.h> /* ファイル状態 */
#include <wchar.h> /* ワイド文字 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char *path); /* 関数get_file_sizeの宣言. */
wchar_t * wget_file_wtext_locale_cstdio(const char *path, wchar_t *text, size_t buf_size, const char *locale); /* 関数wget_file_wtext_locale_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 変数・ポインタの宣言・初期化. */
  size_t file_size_1; /* size_t型変数file_size_1. */
  size_t file_size_2; /* size_t型変数file_size_2. */
  wchar_t *buf1 = NULL; /* wchar_t型ポインタbuf1をNULLで初期化. */
  wchar_t *buf2 = NULL; /* wchar_t型ポインタbuf2をNULLで初期化. */
  int ret_1 = 0;
  int ret_2 = 0;

  /* "ja_JP.UTF-8"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* test1.txtのサイズ取得. */
  file_size_1 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf1 = (wchar_t *)malloc((file_size_1 + 1) * sizeof(wchar_t)); /* mallocで((file_size_1 + 1) * sizeof(wchar_t))分のメモリ確保. */

  /* "test1.txt"からの入力をbuf1に格納. */
  wget_file_wtext_locale_cstdio("test1.txt", buf1, file_size_1 + 1, "ja_JP.UTF-8"); /* wget_file_wtext_locale_cstdioで"ja_JP.UTF-8"の"test1.txt"を読み込み. */
  ret_1 = wcslen(buf1); /* 長さをret_1に格納. */
  buf1[ret_1] = L'\0'; /* NULL終端 */

  /* buf1を出力. */
  printf("buf1 = %ls\n", buf1); /* printfでbuf1を出力. */

  /* メモリの解放. */
  free(buf1); /* freeでbuf1を解放. */

  /* test2.txtのサイズ取得. */
  file_size_2 = get_file_size("test2.txt"); /* get_file_sizeで"test2.txt"のサイズ取得. */

  /* メモリの確保. */
  buf2 = (wchar_t *)malloc((file_size_2 + 1) * sizeof(wchar_t)); /* mallocで((file_size_2 + 1) * sizeof(wchar_t))分のメモリ確保. */

  /* "test2.txt"からの入力をbuf2に格納. */
  wget_file_wtext_locale_cstdio("test2.txt", buf2, file_size_2 + 1, "ja_JP.EUC-JP"); /* wget_file_wtext_locale_cstdioで"ja_JP.EUC-JP"の"test2.txt"を読み込み. */
  ret_2 = wcslen(buf2); /* 長さをret_2に格納. */
  buf2[ret_2] = L'\0'; /* NULL終端 */

  /* buf2を出力. */
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
wchar_t * wget_file_wtext_locale_cstdio(const char *path, wchar_t *text, size_t buf_size, const char *locale){

  /* 構造体・ポインタの宣言・初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  wchar_t *ret; /* 格納した文字列ポインタret. */
  char old_locale[256] = {0}; /* 以前のロケールold_localeを{0}で初期化. */

  /* 以前のロケールを取得. */
  strcpy(old_locale, setlocale(LC_ALL, NULL)); /* setlocaleで第2引数にNULLを指定し, 戻り値をold_localeにコピー. */

  /* 指定ロケールをセット. */
  setlocale(LC_ALL, locale); /* setlocaleでLC_ALL, localeをセット. */

  /* ファイルを開く. */
  fp = fopen(path, "r"); /* fopenでテキスト読み込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルからワイド文字テキストを読み込む. */
    ret = fgetws(text, buf_size, fp); /* fgetwsでfpから入力しwtextに格納, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* ロケールを元に戻す. */
    setlocale(LC_ALL, old_locale); /* setlocaleでLC_ALL, old_localeをセット. */

    /* retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ロケールを元に戻す. */
  setlocale(LC_ALL, old_locale); /* setlocaleでLC_ALL, old_localeをセット. */

  /* ファイルを開けない場合は, NULLを返す. */
  return NULL; /* returnでNULLを返す. */

}
