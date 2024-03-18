// ヘッダのインクルード
// 既定のヘッダ
#include <iostream> // C++標準入出力
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main(){

  // "UTF-32"の"test1.txt"を"UTF-8"文字列として読み込む.
  std::string text1 = ""; // std::stringのtext1を""で初期化.
  read_wtext_file_to_locale_text_cstdio("test1.txt", text1, "ja_JP.UTF-8"); // read_wtext_file_to_locale_text_cstdioでファイル入力.
  std::cout << text1 << std::endl; // text1を出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
