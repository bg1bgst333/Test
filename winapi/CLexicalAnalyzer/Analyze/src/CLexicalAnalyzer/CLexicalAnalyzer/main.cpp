// ヘッダファイルのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <stdio.h>	// 標準入出力
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer

// _tmain関数の定義
int _tmain(int argc, TCHAR* argv[]) {	// main関数のTCHAR版.


	// 字句解析オブジェクトの作成.
	CLexicalAnalyzer* pLexicalAnalyzer = new CLexicalAnalyzer();	// CLexicalAnalyzerオブジェクトを作成し, ポインタpLexicalAnalyzerに格納.

	// 字句解析.
	pLexicalAnalyzer->Analyze(argv[1]);	// pLexicalAnalyzer->Analyzeでargv[1]にあるソースを解析.

	// 字句解析オブジェクトの解放.
	delete pLexicalAnalyzer;	// pLexicalAnalyzerを解放.

	// プログラムの終了
	return 0;	// returnで0を返して正常終了.

}