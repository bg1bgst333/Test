/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */
#include <sys/stat.h> /* ファイル状態 */
#include <iconv.h> /* 文字コード変換 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char *path); /* 関数get_file_sizeの宣言. */
int scan_file_text_cstdio(const char *path, char *text); /* 関数scan_file_text_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 変数・ポインタの宣言・初期化. */
  size_t file_size_0; /* size_t型変数file_size_0. */
  size_t file_size_1; /* size_t型変数file_size_1. */
  size_t file_size_2; /* size_t型変数file_size_2. */
  char *buf0 = NULL; /* char型ポインタbuf0をNULLで初期化. */
  char *buf1 = NULL; /* char型ポインタbuf1をNULLで初期化. */
  char *buf2 = NULL; /* char型ポインタbuf2をNULLで初期化. */
  iconv_t iconv_dsc;
  char src_buf[256] = {0};
  char *src_ptr = NULL;
  char dest_buf[256] = {0};
  char *dest_ptr = NULL;
  size_t src_len = 0;
  size_t dest_len = 0;
  size_t ret_len = 0;

  /* test1.txtのサイズ取得. */
  file_size_0 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf0 = (char *)malloc((file_size_0 + 1) * sizeof(char)); /* mallocで(file_size_0 + 1)分のメモリ確保. */

  /* "test1.txt"からの入力をbuf0に格納. */
  scan_file_text_cstdio("test1.txt", buf0); /* scan_file_text_cstdioで"test1.txt"を読み込み. */

  /* buf0を出力. */
  printf("buf0 = %s\n", buf0); /* printfでbuf0を出力. */

  /* メモリの解放. */
  free(buf0); /* freeでbuf0を解放. */

  /* "ja_JP.UTF-8"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* test1.txtのサイズ取得. */
  file_size_1 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf1 = (char *)malloc((file_size_1 + 1) * sizeof(char)); /* mallocで(file_size_1 + 1)分のメモリ確保. */

  /* "test1.txt"からの入力をbuf1に格納. */
  scan_file_text_cstdio("test1.txt", buf1); /* scan_file_text_cstdioで"test1.txt"を読み込み. */

  /* buf1を出力. */
  printf("buf1 = %s\n", buf1); /* printfでbuf1を出力. */
 
  /* メモリの解放. */
  free(buf1); /* freeでbuf1を解放. */

  /* "ja_JP.EUC-JP"ロケールのセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* test2.txtのサイズ取得. */
  file_size_2 = get_file_size("test2.txt"); /* get_file_sizeで"test2.txt"のサイズ取得. */

  /* メモリの確保. */
  buf2 = (char *)malloc((file_size_2 + 1) * sizeof(char)); /* mallocで(file_size_2 + 1)分のメモリ確保. */

  /* "test2.txt"からの入力をbuf2に格納. */
  scan_file_text_cstdio("test2.txt", buf2); /* scan_file_text_cstdioで"test2.txt"を読み込み. */

  /* buf2を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2を出力. */

  /* 変換ディスクリプタの取得. */
  iconv_dsc = iconv_open("UTF-8", "EUC-JP"); /* iconv_openで"EUC-JP"から"UTF-8"への変換ディスクリプタを取得. */
  if (iconv_dsc == (iconv_t)-1){ /* -1なら. */
    printf("iconv_open error!\n"); /* "iconv_open error!"を出力. */
    free(buf2);
    return -1; /* -1を返して異常終了. */
  }

  /* 文字コード変換. */
  strcpy(src_buf, buf2);
  src_ptr = src_buf;
  src_len = strlen(src_buf);
  dest_ptr = dest_buf;
  dest_len = sizeof(dest_buf);
  ret_len = iconv(iconv_dsc, &src_ptr, &src_len, &dest_ptr, &dest_len); /* iconvで変換. */
  if (ret_len == -1){ /* -1なら. */
    printf("iconv error!\n"); /* "iconv error!"と出力. */
    free(buf2);
    return -2; /* -2を返して異常終了. */
  }

  /* dest_bufを出力. */
  printf("dest_buf = %s\n", dest_buf); /* printfでdest_bufを出力. */

  /* 変換ディスクリプタを閉じる. */
  iconv_close(iconv_dsc); /* iconv_closeでiconv_dscを閉じる. */

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
