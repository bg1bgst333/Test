/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <locale.h> /* ロケール */
#include <string.h> /* 文字列処理 */
#include <wchar.h> /* ワイド文字 */

/* 関数のプロトタイプ宣言 */
int wput_file_wtext_ccs_cstdio(const char *path, const wchar_t *wtext, const char *ccs); /* 関数wput_file_wtext_ccs_cstdioの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化. */
  wchar_t japanese_wstr[] = L"あいうえお\nかきくけこ\nさしすせそ"; /* '\n'が含まれた日本語文字列. */

  /* ロケール"ja_JP.UTF-8"のセット. */
  setlocale(LC_ALL, "ja_JP.UTF-8"); /* setlocaleでLC_ALL, "ja_JP.UTF-8"をセット. */

  /* japanese_wstrを"UTF-8"で"test1.txt"に出力. */
  wput_file_wtext_ccs_cstdio("test1.txt", japanese_wstr, "UTF-8"); /* wput_file_wtext_ccs_cstdioでjapanese_wstrを"UTF-8"で"test1.txt"に出力. */

  /* japanese_wstrを"EUC-JP"で"test2.txt"に出力. */
  wput_file_wtext_ccs_cstdio("test2.txt", japanese_wstr, "EUC-JP"); /* wput_file_wtext_ccs_cstdioでjapanese_wstrを"EUC-JP"で"test2.txt"に出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int wput_file_wtext_ccs_cstdio(const char *path, const wchar_t *wtext, const char *ccs){

  /* 変数・構造体の初期化. */
  FILE *fp = NULL; /* ファイルポインタfpをNULLで初期化. */
  int ret = 0; /* retを0に初期化. */
  char mode[256] = "w,ccs="; /* モードを表すmodeを"w,css="で初期化. */

  /* ファイルを開く. */
  strcat(mode, ccs); /* strcatでmodeにccsを連結. */  
  fp = fopen(path, mode); /* fopenでmodeで開く. */
  if (fp != NULL){ /* fpがNULLでない時. */

    /* ファイルにワイド文字テキストを書き込む. */
    ret = fputws(wtext, fp); /* fputwsでfpにwtextを出力し, 戻り値はretに格納. */

    /* fpを閉じる. */
    fclose(fp); /* fcloseでfpを閉じる. */

    /* retを返す. */
    return ret; /* returnでretを返す. */

  }

  /* ファイルを開けない場合は, -1を返す. */
  return -1; /* returnで-1を返す. */

}
