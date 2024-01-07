// ヘッダファイルのインクルード
extern "C"{ // C言語として解釈する.
  #include "file_utility_cstdio.h" // ファイルユーティリティ(C標準入出力)
}
#include <iostream> // C++標準入出力

// main関数の定義
int main(){

  // ファイルサイズの取得.
  size_t file_size = get_file_size("test.txt"); // get_file_sizeで"test.txt"のファイルサイズを取得.

  // file_sizeを出力.
  std::cout << "file_size = " << file_size << std::endl; // 出力演算子でfile_sizeを出力.
  
  // プログラムの終了
  return 0; // 0を返して正常終了.

}
