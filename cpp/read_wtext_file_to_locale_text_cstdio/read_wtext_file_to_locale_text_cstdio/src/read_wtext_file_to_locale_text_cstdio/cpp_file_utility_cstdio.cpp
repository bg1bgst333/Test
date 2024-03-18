// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h" // ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// ファイル入力で読み込んだワイド文字列を指定のロケールのマルチバイト文字列に変換.
bool read_wtext_file_to_locale_text_cstdio(const char *path, std::string &text, const char *loc){

  // ファイルサイズの取得.
  size_t file_size = get_file_size(path); // get_file_sizeでpathのfile_sizeを取得.

  // メモリの確保.
  char *buf = new char[file_size + 1]; // newで(file_size_1 + 1)分のメモリ確保.

  // ファイル読み込み.
  int ret = read_file_binary_cstdio(path, buf, file_size + 1); // read_file_binary_cstdioでpathを読み込み.
  if (ret == -1){ // -1なら.
    setlocale(LC_ALL, "ja_JP.UTF-8");
    perror("read_file_binary_cstdio error!"); // perrorで"read_file_binary_cstdio error!"と詳細をエラー出力.
    delete[] buf; // delete[]でbufを解放.
    return false; // falseを返して異常終了.
  }
  buf[ret] = '\0'; // 末尾に'\0'をセット.

  // ロケールのセット.
  setlocale(LC_ALL, loc); // setlocaleでLC_ALL, locをセット.

  // 1文字ずつ変換.
  wchar_t *wc_ptr = NULL;
  char *buf_ptr = NULL;
  char c[MB_LEN_MAX + 1] = {0};
  int len = 0;
  buf_ptr = buf;
  wc_ptr = (wchar_t *)buf_ptr;
  int wlen = file_size / 4;
  for (int i = 0; i < wlen; i++){
    len = wctomb(c, *wc_ptr);
    wc_ptr++;
    text = text + c;
    memset(c, 0, MB_LEN_MAX + 1);
  }

  // 終了処理.
  setlocale(LC_ALL, "ja_JP.UTF-8");
  delete[] buf;
  return true;

}
