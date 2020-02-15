/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */
#include <time.h> /* UNIX時間 */

/* 関数のプロトタイプ宣言 */
void trim_end_lf(char str[]); /* 関数trim_end_lfの宣言. */
void get_time_now_string(char now_str[], size_t len); /* 関数get_time_now_stringの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char now_str[256] = {0}; /* char型配列now_str(長さ256)を{0}で初期化. */

  /* 時刻文字列の取得. */
  get_time_now_string(now_str, 256); /* get_time_now_stringで時刻文字列の取得. */

  /* 時刻文字列の出力. */
  printf("now_str = %s\n", now_str); /* now_strを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* 関数trim_end_lfの定義 */
void trim_end_lf(char str[]){ /* strの末尾の改行を除去する関数trim_end_lf. */

  /* 変数の宣言 */
  size_t len; /* strの長さlen. */

  /* strの長さを取得. */
  len = strlen(str); /* strlenでstrの長さを取得し, lenに格納. */

  /* 末尾に'\n'があったら, '\0'に置き換える. */
  if (str[len - 1] == '\n'){ /* len - 1番目が'\n'なら. */
    str[len - 1] = '\0'; /* str[len - 1]に'\n'を格納. */
  }

}

/* 関数get_time_now_stringの定義 */
void get_time_now_string(char now_str[], size_t len){ /* 現在時刻文字列を返す関数get_time_now_string. */

  /* 変数とポインタの宣言 */
  time_t t; /* 取得したUNIX時間を格納しておくt. */
  char *now_str_ptr; /* 時刻文字列へのポインタnow_str_ptr. */
  size_t now_str_len; /* 長さnow_str_len. */

  /* 現在のUNIX時間の取得. */
  t = time(NULL); /* timeで現在のUNIX時間を取得. */

  /* UNIX時間を時刻文字列に変換. */
  now_str_ptr = ctime(&t); /* ctimeでUNIX時間tを時刻文字列に変換, now_str_ptrにそれを返す. */

  /* 時刻文字列の長さを取得. */
  now_str_len = strlen(now_str_ptr); /* strlenでnow_str_ptrの長さを取得し, now_str_lenに格納. */

  /* lenが大きいなら, now_str_lenの分だけコピー.そうでないならlen - 1の分だけコピー. */
  if (len > now_str_len){ /* lenが大きい. */
    strncpy(now_str, now_str_ptr, now_str_len); /* now_str_lenの分コピー. */
    now_str[now_str_len] = '\0'; /* NULL終端. */
  }
  else{ /* now_str_len以下. */
    strncpy(now_str, now_str_ptr, len - 1); /* len - 1の分コピー. */
    now_str[len - 1] = '\0'; /* NULL終端. */
  }

  /* 改行文字の除去. */
  trim_end_lf(now_str); /* trim_end_lfでnow_strに改行文字があったら除去する. */

}
