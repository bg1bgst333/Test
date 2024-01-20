// ヘッダファイルのインクルード
extern "C"{ // C言語として解釈する.
  #include "file_utility_cstdio.h" // ファイルユーティリティ(C標準入出力)
}
#include <iostream> // C++標準入出力
#include <locale.h> // ロケール

// main関数の定義
int main(){

  // test1.txtのサイズ取得.
  size_t file_size_1 = get_file_size("test1.txt"); // get_file_sizeで"test1.txt"のサイズ取得.

  // file_size_1を出力.
  std::cout << "file_size_1 = " << file_size_1 << std::endl; // 出力演算子でfile_size_1を出力.

  // メモリの確保.
  char *buf1 = new char[file_size_1 + 1]; // newで(file_size_1 + 1)分のメモリ確保.

  // "C"ロケールのセット.
  setlocale(LC_ALL, "C"); // setlocaleでLC_ALL, "C"をセット.

  // "test1.txt"からの入力をbuf1に格納.
  scan_file_text_cstdio("test1.txt", buf1); // scan_file_text_cstdioで"test1.txt"を読み込み.

  // buf1を出力.
  std::cout << "buf1 = " << buf1 << std::endl; // 出力演算子でbuf1を出力.

  // buf1を解放.
  delete [] buf1; // delete [] でbuf1を解放.

  // test2.txtのサイズ取得.
  size_t file_size_2 = get_file_size("test2.txt"); // get_file_sizeで"test2.txt"のサイズ取得.

  // file_size_2を出力.
  std::cout << "file_size_2 = " << file_size_2 << std::endl; // 出力演算子でfile_size_2を出力.

  // メモリの確保.
  char *buf2 = new char[file_size_2 + 1]; // newで(file_size_2 + 1)分のメモリ確保.

  // "ja_JP.UTF-8"ロケールのセット.
  setlocale(LC_ALL, "ja_JP.UTF-8"); // setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.  // "ja_JP.UTF-8"ロケールのセット.

  // "test2.txt"からの入力をbuf2に格納.
  scan_file_text_cstdio("test2.txt", buf2); // scan_file_text_cstdioで"test2.txt"を読み込み.

  // buf2を出力.
  std::cout << "buf2 = " << buf2 << std::endl; // 出力演算子でbuf2を出力.

  // buf2を解放.
  delete [] buf2; // delete [] でbuf2を解放.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
