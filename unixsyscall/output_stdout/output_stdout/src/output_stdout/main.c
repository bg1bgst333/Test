/* ヘッダファイルのインクルード */
#include <string.h> /* 文字列処理 */
#include <unistd.h> /* UNIX標準 */

/* 関数のプロトタイプ宣言 */
void output_stdout(const char *str); /* 関数output_stdoutの宣言 */

/* main関数の定義 */
int main(void){

  /* "ABCDE"を標準出力に出力する. */
  output_stdout("ABCDE\n"); /* output_stdoutで"ABCDE"を標準出力に出力する. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */
}

/* 指定の文字列を標準出力に出力. */
void output_stdout(const char *str){

  /* 標準出力にstrを書き込む. */
  write(1, str, strlen(str)); /* writeで標準出力(1)にstrを書き込む. */

}
