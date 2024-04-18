// ヘッダファイルのインクルード
// 既定のヘッダ
#include <cstdio>	// C標準入出力
// 独自のヘッダ
extern "C"{	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// main関数の定義
int main(void){

	// 変数の初期化.
	char a = 'a';	// char型変数aを'a'で初期化.
	char b = 'b';	// char型変数bを'b'で初期化.

	// aとbの出力.
	printf("a = \'%c\'\n", a);	// aを出力.
	printf("b = \'%c\'\n", b);	// bを出力.

	// "-----"を出力.
	printf("-----\n");

	// スワップ
	swap_2bytes(&a, &b);	// swap_2bytesでaとbの値を入れ替える.

	// aとbの出力.
	printf("a = \'%c\'\n", a);	// aを出力.
	printf("b = \'%c\'\n", b);	// bを出力.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}