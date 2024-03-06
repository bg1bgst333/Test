// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// main関数の定義
int main(){

  // "test1.txt"に"あA\r\nいa\r\nう123"を"Shift_JIS"でファイル出力.
  write_encode_text_file_iconv_cstdio("test1.txt", "あA\r\nいa\r\nう123", "Shift_JIS"); // write_encode_text_file_iconv_cstdioでファイル出力.

  // "test2.txt"に"あA\r\nいa\r\nう123"を"EUC-JP"でファイル出力.
  write_encode_text_file_iconv_cstdio("test2.txt", "あA\r\nいa\r\nう123", "EUC-JP"); // write_encode_text_file_iconv_cstdioでファイル出力.

  // "test3.txt"に"あA\r\nいa\r\nう123"を"ISO-2022-JP"でファイル出力.
  write_encode_text_file_iconv_cstdio("test3.txt", "あA\r\nいa\r\nう123", "ISO-2022-JP"); // write_encode_text_file_iconv_cstdioでファイル出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}
