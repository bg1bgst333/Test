/* ヘッダファイルのインクルード */
/* 独自のヘッダファイル */
#include "string_utility_cstring.h" /* 文字列ユーティリティ(C文字列処理) */

/* 長さsizeのバイト列bytesの最初にみつかったbeforeをafterに置換. */
int replace_byte(char *bytes, int size, char before, char after){

  /* 変数の宣言 */
  int i;

  /* beforeがみつかるまで探す. */
  for (i = 0; i < size; i++){
    if (*(bytes + i) == before){
      *(bytes + i) = after; /* afterに置換. */
      return i; /* iを返す. */
    }
  }

  /* みつからない場合は-1. */
  return -1;

}
