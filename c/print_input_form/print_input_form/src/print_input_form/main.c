/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* 関数のプロトタイプ宣言 */
void print_line(const char *str); /* 関数print_lineの宣言. */
void trim_end_lf(char str[]); /* 関数trim_end_lfの宣言. */
void print_input_form(const char *form_str, char input_str[], size_t len); /* 関数void_input_formの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char str[256] = {0}; /* char型配列str(長さ256)を{0}で初期化. */

  /* 入力フォームの表示 */
  print_input_form("str: ", str, 256); /* print_input_formで入力フォームを出力し, 入力文字列をstrに格納. */

  /* 入力文字列の出力 */
  print_line(str); /* print_lineでstrを出力. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* 関数print_lineの定義 */
void print_line(const char *str){ /* strを改行付きで標準出力する関数print_line. */

  /* 改行付きで出力. */
  printf("%s\n", str); /* printfでstrに改行を付けて出力. */

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

/* 関数print_input_formの定義 */
void print_input_form(const char *form_str, char input_str[], size_t len){ /* 入力フォームを表示する関数print_input_form. */

  /* 入力フォームを出力. */
  printf("%s", form_str); /* printfでform_strを出力. */

  /* 入力文字列の取得. */
  fgets(input_str, len, stdin); /* fgetsでstdinから読み込んだ文字列をinput_strに格納. */

  /* 改行文字の除去. */
  trim_end_lf(input_str); /* trim_end_lfでinput_strに改行文字があったら除去する. */

}
