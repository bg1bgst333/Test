/* ヘッダファイルのインクルード */
#include <unistd.h> /* UNIX標準 */

/* 関数のプロトタイプ宣言 */
void stdin_to_stdout(void); /* 関数stdin_to_stdoutの宣言 */

/* main関数の定義 */
int main(void){

  /* 標準入力を読み込んで標準出力に書き込む. */
  stdin_to_stdout(); /* stdin_to_stdoutで標準入力を読み込んで標準出力に書き込む. */

  /* プログラムの終了 */
  return 0; /* 0を返して正常終了. */

}

/* 標準入力を読み込んで標準出力に書き込む. */
void stdin_to_stdout(void){

  /* 変数・配列の宣言 */
  ssize_t n; /* 読み込んだバイト数n. */
  char buf[1024]; /* バッファbuf. */

  /* readで読み込んだ量が正ならwriteで書き込む. */
  while ((n = read(0, buf, sizeof(buf))) > 0){ /* nが正なら繰り返す. */
    write(1, buf, n); /* n書き込む. */
  }

}
