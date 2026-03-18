// 二重インクルード防止
#ifndef __LEXICAL_ANALYZER_H__
#define __LEXICAL_ANALYZER_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <tchar.h>	// TCHAR型
#include <string>	// std::string
#include <vector>	// std::vector
#include <windows.h>	// 標準WindowsAPI

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// 字句解析クラスCLexicalAnalyzer
class CLexicalAnalyzer {

	// privateメンバ
	private:

		// privateメンバ変数
		tstring m_tstrSourceFileName;	// ソースファイル名
		std::vector<tstring> m_vectstrTokenList;	// トークンリスト

	// publicメンバ
	public:

		// publicメンバ関数
		BOOL Analyze(tstring tstrSourceFileName);	// 解析を実行するメンバ関数Analyze.

};

#endif
