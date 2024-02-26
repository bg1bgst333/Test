/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <stdlib.h> /* 標準ユーティリティ */
#include <string.h> /* 文字列処理 */
#include <locale.h> /* ロケール */
#include <sys/stat.h> /* ファイル状態 */
#include <wchar.h> /* ワイド文字 */

/* 関数のプロトタイプ宣言 */
size_t get_file_size(const char *path); /* 関数get_file_sizeの宣言. */
int wscan_file_text_ccs_cstdio(const char *path, char *text, const char *ccs); /* 関数wscan_file_text_ccs_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 変数・ポインタの宣言・初期化. */
  size_t file_size_1; /* size_t型変数file_size_1. */
  size_t file_size_2; /* size_t型変数file_size_2. */
  char *buf1 = NULL; /* char型ポインタbuf1をNULLで初期化. */
  char *buf2 = NULL; /* char型ポインタbuf2をNULLで初期化. */
  int ret_1 = 0;
  int ret_2 = 0;

  /* ロケール"ja_JP.UTF-8"のセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* test1.txtのサイズ取得. */
  file_size_1 = get_file_size("test1.txt"); /* get_file_sizeで"test1.txt"のサイズ取得. */

  /* メモリの確保. */
  buf1 = (char *)malloc((file_size_1 + 1) * sizeof(char)); /* mallocで((file_size_1 + 1) * sizeof(char))分のメモリ確保. */

  /* "test1.txt"からの入力をbuf1に格納. */
  wscan_file_text_ccs_cstdio("test1.txt", buf1, "UTF-8"); /* wscan_file_text_ccs_cstdioで"UTF-8"の"test1.txt"を読み込み. */
  ret_1 = strlen(buf1); /* 長さをret_1に格納. */
  buf1[ret_1] = '\0'; /* NULL終端 */

  /* buf1を出力. */
  printf("buf1 = %s\n", buf1); /* printfでbuf1を出力. */

  /* メモリの解放. */
  free(buf1); /* freeでbuf1を解放. */

  /* test2.txtのサイズ取得. */
  file_size_2 = get_file_size("test2.txt"); /* get_file_sizeで"test2.txt"のサイズ取得. */

  /* メモリの確保. */
  buf2 = (char *)malloc((file_size_2 + 1) * sizeof(char)); /* mallocで((file_size_2 + 1) * sizeof(char))分のメモリ確保. */

  /* "test2.txt"からの入力をbuf2に格納. */
  wscan_file_text_ccs_cstdio("test2.txt", buf2, "EUC-JP"); /* wscan_file_text_ccs_cstdioで"EUC-JP"の"test2.txt"を読み込み. */
  ret_2 = strlen(buf2); /* 長さをret_2に格納. */
  buf2[ret_2] = '\0'; /* NULL終端 */

  /* buf2を出力. */
  printf("buf2 = %s\n", buf2); /* printfでbuf2を出力. */

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
int wscan_file_text_ccs_cstdio(const char *path, char *text, const char *ccs){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* 格納した変数の数retを0に初期化. */
  char mode[256] = "r,ccs="; /* モードを表すmodeを"r,ccs="で初期化. */

  /* ファイルを開く. */
  strcat(mode, ccs); /* strcatでmodeにccsを連結. */
  fp = fopen(path, mode); /* fopenでmodeで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルからテキストを読み込む. */
    ret = fwscanf(fp, L"%s", text); /* fscanfでfpから入力しtextに格納, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* 格納した変数の数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
