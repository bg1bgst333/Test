// ヘッダファイルのインクルード
extern "C" {	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

// main関数
int main() {

	// 変数の宣言
	int ret;	// int型変数ret.

	// test1.txtにUTF-16BEのBOMがあるか判定する.
	ret = is_file_bom_utf16be("test1.txt");	// is_file_bom_utf16beで"test1.txt"にUTF-16BEのBOMがあるか判定する.
	if (ret == 1) {	// retが1.
		printf("UTF-16BE\n");	// "UTF-16BE"と出力.
	}
	else {	// retが0.
		printf("Not UTF-16BE\n");	// "Not UTF-16BE"と出力.
	}


	// プログラムの終了
	return 0;	// 0を返して正常終了.

}