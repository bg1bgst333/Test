/* ヘッダファイルのインクルード */
#include <stdio.h> /* 標準入出力 */
#include <string.h> /* 文字列処理 */

/* 関数のプロトタイプ宣言 */
void trim_end_lf(char str[]); /* 関数trim_end_lfの宣言. */

/* main関数の定義 */
int main(void){

  /* 配列の初期化 */
  char str[] = "ABCDE\n"; /* char型配列str[]を"ABCDE\n"で初期化. */

  /* strを'['と']'で囲んで出力. */
  printf("str = [%s]\n", str); /* printfでstrを'['と']'で囲んで出力. */

  /* trim_end_lfで末尾の改行を除去する. */
  trim_end_lf(str); /* trim_end_lfでstrの末尾の改行を除去. */

  /* 再びstrを'['と']'で囲んで出力. */
  printf("str = [%s]\n", str); /* printfでstrを'['と']'で囲んで出力. */

  /* 改行が無い場合は実行されない. */
  trim_end_lf(str); /* trim_end_lfでstrの末尾の改行を除去. */

  /* 再びstrを'['と']'で囲んで出力. */
  printf("str = [%s]\n", str); /* printfでstrを'['と']'で囲んで出力. */

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
