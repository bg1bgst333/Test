// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// マルチバイト文字列をiconvで指定の文字コードに変換してファイル出力.
bool write_encode_text_file_iconv_cstdio(const char *path, const char *text, const char *enc){

  // "ja_JP.UTF-8"ロケールのセット.
  setlocale(LC_ALL, "ja_JP.UTF-8"); // setlocaleでLC_ALL, "ja_JP.UTF-8"をセット.

  // 変換ディスクリプタの取得.
  iconv_t iconv_dsc = iconv_open(enc, "utf-8"); // iconv_openで"utf-8"からencへの変換ディスクリプタを取得.
  if (iconv_dsc == (iconv_t)-1){ // -1なら.
    perror("iconv_open error!"); // perrorで"iconv_open error!"と詳細をエラー出力.
    return false; // falseを返して異常終了.
  }

  // 変換元文字列の情報.
  size_t src_len = strlen(text); // strlenでtextの長さを取得し, src_lenに格納.
  char *src_ptr = const_cast<char *>(text); // const_castでtextの先頭アドレスをsrc_ptrに格納.

  // 1文字ずつ文字コード変換して書き込み.
  FILE *fp = fopen(path, "wb"); // fopenでpathをバイナリ出力で開く.
  if (fp == NULL){ // NULLなら.
    perror("fopen error!"); // perrorで"fopen error!"と詳細をエラー出力.
    iconv_close(iconv_dsc);
    return false; // falseを返して異常終了.
  }
  size_t total = 0;
  while (total < src_len){
    size_t src_chr_len = mblen(src_ptr, MB_CUR_MAX); // mblenでsrc_ptrの1文字の長さを取得し, src_chr_lenに格納.
    char dest_buf[MB_LEN_MAX] = {0}; // 出力先バッファdest_buf(長さMB_LEN_MAX)を{0}で初期化.
    char *dest_chr_ptr = dest_buf;
    size_t dest_chr_len = MB_LEN_MAX; // 出力先長さdest_chr_lenをMB_LEN_MAXで初期化.
    size_t l = src_chr_len;
    int ret_len = iconv(iconv_dsc, &src_ptr, &l, &dest_chr_ptr, &dest_chr_len); // iconvで変換.
    if (ret_len == -1){ // -1なら.
      perror("iconv error!"); // perrorで"iconv error!"と詳細をエラー出力.
      iconv_close(iconv_dsc); // iconv_closeでiconv_dscを閉じる.
      fclose(fp); // fcloseでfpを閉じる.
      return false; // falseを返して異常終了.
    }
    fwrite(dest_buf, sizeof(char), strlen(dest_buf), fp); // fwriteで書き込み.
    total += src_chr_len;
  }

  // 終了処理.
  iconv_close(iconv_dsc); // iconv_closeでiconv_dscを閉じる.
  fclose(fp); // fcloseでfpを閉じる.
  return 0; // 0を返して正常終了.

}
