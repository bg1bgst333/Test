// 二重インクルード防止
#ifndef __SYNTAX_ANALYZER_H__
#define __SYNTAX_ANALYZER_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <string>	// std::string
#include <vector>	// std::vector
#include <windows.h>	// 標準WindowsAPI
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// 構文解析クラスCSyntaxAnalyzer
class CSyntaxAnalyzer{

	// publicメンバ
	public:

		// コンストラクタとデストラクタ
		CSyntaxAnalyzer(){};	// コンストラクタCSyntaxAnalyzer
		virtual ~CSyntaxAnalyzer(){};	// デストラクタ~CSyntaxAnalyzer
		// publicメンバ関数
		BOOL Analyze(CLexicalAnalyzer *pLA);	// 解析を実行するメンバ関数Analyze.

};

#endif