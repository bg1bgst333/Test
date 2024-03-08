// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main(){

  // "test1.txt"に"あA\r\nいa\r\nう123"をワイド文字でファイル出力.
  write_wtext_file_from_locale_text_cstdio("test1.txt", "あA\r\nいa\r\nう123", "ja_JP.UTF-8"); // write_wtext_file_from_locale_text_cstdioでファイル出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
