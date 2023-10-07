/* ヘッダファイルのインクルード */
#include <stdio.h>	/* 標準入出力 */
#include <string.h>	/* 文字列処理 */
#include <locale.h>	/* ロケール */

/* 関数のプロトタイプ宣言 */
int print_file_text_cstdio(const char* path, const char* text);	/* 関数print_file_text_cstdioの宣言. */

/* main関数の定義 */
int main(void) {

	/* 配列の初期化. */
	char ascii_str[] = "ABCDE\nFGHIJ\nKLMNO"; /* '\n'が含まれたASCII文字列. */
	char japanese_str[] = "あいうえお\nかきくけこ\nさしすせそ"; /* '\n'が含まれた日本語文字列. */

	/* ascii_strを"test1.txt"に出力. */
	print_file_text_cstdio("test1.txt", ascii_str);	/* print_file_text_cstdioでascii_strを"test1.txt"に出力. */

	/* japanese_strを"test2.txt"に出力. */
	print_file_text_cstdio("test2.txt", japanese_str);	/* print_file_text_cstdioでjapanese_strを"test2.txt"に出力. */

	/* "C"ロケールのセット. */
	setlocale(LC_ALL, "C");	/* setlocaleでLC_ALL, "C"をセット. */

	/* japanese_strを"test3.txt"に出力. */
	print_file_text_cstdio("test3.txt", japanese_str);	/* print_file_text_cstdioでjapanese_strを"test3.txt"に出力. */

	/* "Japanese_Japan.932"ロケールのセット. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocaleでLC_ALL, "Japanese_Japan.932"をセット. */

	/* japanese_strを"test4.txt"に出力. */
	print_file_text_cstdio("test4.txt", japanese_str);	/* print_file_text_cstdioでjapanese_strを"test4.txt"に出力. */

	/* プログラムの終了 */
	return 0;	/* 0を返して正常終了. */

}

/* C標準入出力ライブラリ関数でテキストファイル出力. */
int print_file_text_cstdio(const char* path, const char* text) {

	/* 変数・構造体の初期化. */
	FILE* fp = NULL;	/* ファイルポインタfpをNULLで初期化. */
	int ret = 0;	/* 書き込んだバイト数retを0に初期化. */

	/* ファイルを開く. */
	fp = fopen(path, "w");	/* fopenでテキスト書き込みで開く. */
	if (fp != NULL) {	/* fpがNULLでない時. */

		/* ファイルにテキストを書き込む. */
		ret = fprintf(fp, "%s", text);	/* fprintfでfpにtextを出力し, 戻り値はretに格納. */

		/* fpを閉じる. */
		fclose(fp);	/* fcloseでfpを閉じる. */

		/* 書き込んだバイト数retを返す. */
		return ret;	/* returnでretを返す. */

	}

	/* ファイルを開けない場合は, -1を返す. */
	return -1;	/* returnで-1を返す. */

}