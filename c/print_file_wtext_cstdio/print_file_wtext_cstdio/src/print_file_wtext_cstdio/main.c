/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <wchar.h> /* ワイド文字 */
#include <locale.h> /* ロケール */

/* 関数のプロトタイプ宣言 */
int print_file_wtext_cstdio(const char *path, const wchar_t *wtext); /* 関数print_file_wtext_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  wchar_t japanese_wstr[] = L"あいうえお\nかきくけこ\nさしすせそ"; /* '\n'が含まれた日本語文字列. */

  /* japanese_wstrを"test1.txt"に出力. */
  print_file_wtext_cstdio("test1.txt", japanese_wstr); /* print_file_wtext_cstdioでjapanese_wstrを"test1.txt"に出力. */

  /* ロケール"ja_JP.UTF-8"のセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* japanese_wstrを"test2.txt"に出力. */
  print_file_wtext_cstdio("test2.txt", japanese_wstr); /* print_file_wtext_cstdioでjapanese_wstrを"test2.txt"に出力. */

  /* ロケール"ja_JP.EUC-JP"のセット. */
  setlocale(LC_ALL, "ja_JP.EUC-JP"); /* setlocaleでLC_ALL, "ja_JP.EUC-JP"をセット. */

  /* japanese_wstrを"test3.txt"に出力. */
  print_file_wtext_cstdio("test3.txt", japanese_wstr); /* print_file_wtext_cstdioでjapanese_wstrを"test3.txt"に出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* C標準入出力ライブラリ関数でワイド文字テキストファイル出力. */
int print_file_wtext_cstdio(const char *path, const wchar_t *wtext){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* 書き込んだバイト数retを0に初期化. */

  /* ファイルを開く. */
  fp = fopen(path, "w"); /* fopenでテキスト書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにワイド文字テキストを書き込む. */
    ret = fprintf(fp, "%ls", wtext); /* fprintfでfpにwtextを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* 書き込んだバイト数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
