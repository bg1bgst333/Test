// ヘッダファイルのインクルード
extern "C"{	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}
#include <cstdio>	// C標準入出力
#include <iostream>	// C++標準入出力
#include <locale.h>	// ロケール

// main関数の定義
int main(){

	// test1.txtのサイズ取得.
	size_t file_size_1 = get_file_size("test1.txt");	// get_file_sizeで"test1.txt"のサイズ取得.

	// file_size_1を出力.
	std::cout << "file_size_1 = " << file_size_1 << std::endl;	// 出力演算子でfile_size_1を出力.

	// メモリの確保.
	char *buf1 = new char[file_size_1 + 1];	// newで(file_size_1 + 1)分のメモリ確保.

	// "C"ロケールのセット.
	setlocale(LC_ALL, "C");	// setlocaleでLC_ALL, "C"をセット.

	// "test1.txt"からの入力をbuf1に格納.
	int ret1 = read_file_text_cstdio("test1.txt", buf1, file_size_1 + 1);	// read_file_text_cstdioで"test1.txt"を読み込み.
	buf1[ret1] = '\0';	// 末尾に'\0'をセット.
	
	// buf1を出力.
	fwrite(buf1, sizeof(char), ret1, stdout);	// fwriteでbuf1を(file_size_1 + 1)の分だけstdoutで出力.
 
	// buf1を解放.
	delete [] buf1;	// delete [] でbuf1を解放.
	
	// 改行
	std::cout << std::endl;

	// test2.txtのサイズ取得.
	size_t file_size_2 = get_file_size("test2.txt");	// get_file_sizeで"test2.txt"のサイズ取得.

	// file_size_2を出力.
	std::cout << "file_size_2 = " << file_size_2 << std::endl;	// 出力演算子でfile_size_2を出力.

	// メモリの確保.
	char *buf2 = new char[file_size_2 + 1];	// newで(file_size_2 + 1)分のメモリ確保.

	// "Japanese_Japan.932"ロケールのセット.
	setlocale(LC_ALL, "Japanese_Japan.932");	// setlocaleでLC_ALL, "Japanese_Japan.932"をセット.
	
	// "test2.txt"からの入力をbuf2に格納.
	int ret2 = read_file_text_cstdio("test2.txt", buf2, file_size_2 + 1);	// read_file_text_cstdioで"test2.txt"を読み込み.
	buf2[ret2] = '\0';	// 末尾に'\0'をセット.

	// buf2を出力.
	//fwrite(buf2, sizeof(char), ret2, stdout);	// fwriteでbuf2をret2の分だけstdoutで出力.
	fprintf(stdout, "%s", buf2);
	fprintf(stdout, " %s", buf2 + strlen(buf2) + 1);

	// buf2を解放.
	delete [] buf2;	// delete [] でbuf2を解放.

	// プログラムの終了
	return 0;	// 0を返して正常終了.

}