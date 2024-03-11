// ヘッダのインクルード
// 独自のヘッダ
#include "file_utility_cstdio.h" // ファイルユーティリティ(C標準入出力)
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)
#include <iostream>
// iconvで指定の文字コードからテキストファイル入力.
bool read_decode_text_file_iconv_cstdio(const char *path, std::string &text, const char *dec){

  // decのロケールにセット.
  char loc[256] = "ja_JP.";
  strcat(loc, dec);
  setlocale(LC_ALL, loc); // setlocaleでLC_ALL, locをセット.

  // 変換ディスクリプタの取得.
  iconv_t iconv_dsc = iconv_open("utf-8", dec); // iconv_openでdecから"utf-8"への変換ディスクリプタを取得.
  if (iconv_dsc == (iconv_t)-1){ // -1なら.
    setlocale(LC_ALL, "ja_JP.UTF-8");
    perror("iconv_open error!"); // perrorで"iconv_open error!"と詳細をエラー出力.
    return false; // falseを返して異常終了.
  }

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
    iconv_close(iconv_dsc); // iconv_closeでiconv_dscを閉じる.
    return false; // falseを返して異常終了.
  }
  buf[ret] = '\0'; // 末尾に'\0'をセット.

  // 変換元文字列の情報.
  size_t src_len = strlen(buf); // strlenでtextの長さを取得し, src_lenに格納.
  char *src_ptr = const_cast<char *>(buf); // const_castでbufの先頭アドレスをsrc_ptrに格納.

  // 1文字ずつ変換.
  size_t total = 0;
  while (total < src_len){
    size_t src_chr_len = mblen(src_ptr, MB_CUR_MAX); // mblenでsrc_ptrの1文字の長さを取得し, src_chr_lenに格納.
    char dest_buf[MB_LEN_MAX] = {0}; // 出力先バッファdest_buf(長さMB_LEN_MAX)を{0}で初期化.
    char *dest_chr_ptr = dest_buf;
    size_t dest_chr_len = MB_LEN_MAX; // 出力先長さdest_chr_lenをMB_LEN_MAXで初期化.
    size_t l = src_chr_len;
    int ret_len = iconv(iconv_dsc, &src_ptr, &l, &dest_chr_ptr, &dest_chr_len); // iconvで変換.
    if (ret_len == -1){ // -1なら.
      setlocale(LC_ALL, "ja_JP.UTF-8");
      perror("iconv error!"); // perrorで"iconv error!"と詳細をエラー出力.
      delete[] buf; // delete[]でbufを解放.
      iconv_close(iconv_dsc); // iconv_closeでiconv_dscを閉じる.
      return false; // falseを返して異常終了.
    }
    dest_chr_ptr[dest_chr_len] = '\0';
    text += dest_buf;
    memset(dest_chr_ptr, '\0', dest_chr_len + 1);
    total += src_chr_len;
  }

  // 終了処理.
  setlocale(LC_ALL, "ja_JP.UTF-8"); 
  iconv_close(iconv_dsc); // iconv_closeでiconv_dscを閉じる.
  delete[] buf; // delete[]でbufを解放.
  return 0; // 0を返して正常終了.

}
