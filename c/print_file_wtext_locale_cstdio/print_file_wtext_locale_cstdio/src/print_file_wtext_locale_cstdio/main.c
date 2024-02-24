/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <wchar.h> /* ワイド文字 */
#include <locale.h> /* ロケール */
#include <string.h> /* 文字列処理 */

/* 関数のプロトタイプ宣言 */
int print_file_wtext_locale_cstdio(const char *path, const wchar_t *wtext, const char *locale); /* 関数print_file_wtext_locale_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  wchar_t japanese_wstr[] = L"あいうえお\nかきくけこ\nさしすせそ"; /* '\n'が含まれた日本語文字列. */

  /* ロケール"ja_JP.UTF-8"のセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* japanese_wstrを"ja_JP.UTF-8"で"test1.txt"に出力. */
  print_file_wtext_locale_cstdio("test1.txt", japanese_wstr, "ja_JP.UTF-8"); /* print_file_wtext_locale_cstdioでjapanese_wstrを"ja_JP.UTF-8"で"test1.txt"に出力. */

  /* japanese_wstrを"ja_JP.EUC-JP"で"test2.txt"に出力. */
  print_file_wtext_locale_cstdio("test2.txt", japanese_wstr, "ja_JP.EUC-JP"); /* print_file_wtext_locale_cstdioでjapanese_wstrを"ja_JP.EUC-JP"で"test2.txt"に出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* C標準入出力ライブラリ関数でワイド文字テキストファイル出力. */
int print_file_wtext_locale_cstdio(const char *path, const wchar_t *wtext, const char *locale){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* 書き込んだバイト数retを0に初期化. */
  char old_locale[256] = {0}; /* 以前のロケールold_localeを{0}で初期化. */

  /* 以前のロケールを取得. */
  strcpy(old_locale, setlocale(LC_ALL, NULL)); /* setlocaleで第2引数にNULLを指定し, 戻り値をold_localeにコピー. */

  /* 指定ロケールをセット. */
  setlocale(LC_ALL, locale); /* setlocaleでLC_ALL, localeをセット. */

  /* ファイルを開く. */
  fp = fopen(path, "w"); /* fopenでテキスト書き込みで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにワイド文字テキストを書き込む. */
    ret = fprintf(fp, "%ls", wtext); /* fprintfでfpにwtextを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* ロケールを元に戻す. */
    setlocale(LC_ALL, old_locale); /* setlocaleでLC_ALL, old_localeをセット. */

    /* 書き込んだバイト数retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ロケールを元に戻す. */
  setlocale(LC_ALL, old_locale); /* setlocaleでLC_ALL, old_localeをセット. */

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
