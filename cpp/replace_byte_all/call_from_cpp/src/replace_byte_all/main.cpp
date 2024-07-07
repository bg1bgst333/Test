// ヘッダファイルのインクルード
extern "C"{ // C言語として解釈する.
  #include "string_utility_cstring.h" // 文字列ユーティリティ(C文字列処理)
}

// main関数の定義
int main(){

  // 配列の初期化.
  char bytes[] = {0xa, 0xd, 0, 0xd, 0xd};

  // みつかった全てを置換.
  int ret = replace_byte_all(bytes, 5, 0xd, 0);
  for (int i = 0;  i < 5; i++){
    printf("bytes[%d] = 0x%x\n", i, bytes[i]);
  }
  printf("ret = %d\n", ret);

  // プログラムの終了.
  return 0;

}
