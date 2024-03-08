// ヘッダのインクルード
// 独自のヘッダ
#include "cpp_file_utility_cstdio.h" // C++ファイルユーティリティ(C標準入出力)

// 指定のロケールのマルチバイト文字列をワイド文字列に変換してファイル出力.
bool write_wtext_file_from_locale_text_cstdio(const char *path, const char *text, const char *loc){

  // 初期化.
  wchar_t wtext[6] = {0};
  wchar_t *wtext_ptr = wtext;
  int temp = mbtowc(wtext_ptr, NULL, 0);

  // ロケールのセット.
  setlocale(LC_ALL, loc); // setlocaleでLC_ALL, locをセット.

  // 1文字ずつ変換して書き込み.
  FILE *fp = fopen(path, "wb"); // fopenでpathをバイナリ出力で開く.
  if (fp == NULL){ // NULLなら.
    perror("fopen error!"); // perrorで"fopen error!"と詳細をエラー出力.
    return false; // falseを返して異常終了.
  }
  char *text_ptr = const_cast<char *>(text);
  int length = 0;
  int text_len = strlen(text);
  int i = 0;
  while (i < text_len){
    length = mblen(text_ptr, MB_CUR_MAX);
    temp = mbtowc(wtext, text_ptr, length);
    wtext[1] = L'\0';
    fwrite(wtext, sizeof(wchar_t), 1, fp); // fwriteで書き込み.
    text_ptr += length;
    i += length;
  }
  fclose(fp); // fcloseでfpを閉じる.

  // 成功.
  return true; // trueを返す.

}
