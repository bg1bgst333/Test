/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */

/* 関数のプロトタイプ宣言 */
void print_line(const char *str); /* 関数print_lineの宣言. */

/* main関数の定義 */
int main(void){

  /* print_lineで改行付き出力. */
  print_line("ABCDE"); /* print_lineで"ABCDE"と出力し, 改行もする. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* 関数print_lineの定義 */
void print_line(const char *str){ /* strを改行付きで標準出力する関数print_line. */

  /* 改行付きで出力. */
  printf("%s\n", str); /* printfでstrに改行を付けて出力. */

}
