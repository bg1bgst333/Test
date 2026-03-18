// ヘッダのインクルード
// 既定のヘッダ
#include <iostream>	// C++標準入出力
// 独自のヘッダ
#include "LexicalAnalyzer.h"	// CLexicalAnalyzer
#include "TextFile.h"	// CTextFile

// 解析を実行するメンバ関数Analyze.
BOOL CLexicalAnalyzer::Analyze(tstring tstrSourceFileName) {

	// 戻り値として返す値の初期化.
	BOOL bRet = FALSE;

	// メンバのセット.
	m_tstrSourceFileName = tstrSourceFileName;	// tstrSourceFileNameをm_tstrSourceFileNameにセット.

	// トークンリストのクリア.
	m_vectstrTokenList.clear();	// m_vectstrTokenListをクリア.

	// "CLexicalAnalyzer::Analyze!"と表示.
	std::wcout << _T("CLexicalAnalyzer::Analyze!") << std::endl;	// "CLexicalAnalyzer::Analyze!"を出力.

	// ソースコードファイルを読み込み, 出力.
	CTextFile* pTextFile = new CTextFile();	// CTextFileオブジェクトを作成し,  ポインタをpTextFileに格納.
	if (pTextFile->Read(m_tstrSourceFileName.c_str())) {	// pTextFile->Readで読み込み.

		// 読み込んだテキストを出力.
		//std::wcout << _T("----- start -----") << std::endl;	// "----- start -----"と出力.
		//std::wcout << pTextFile->m_tstrText << std::endl;	// pTextFile->m_tstrTextの内容を出力.
		//std::wcout << _T("----- end -----") << std::endl;	// "----- end -----"と出力.

		// 1文字ずつチェック.
		tstring tstrToken = _T("");	// 文字列トークンを""で初期化.
		// 分解.
		for (unsigned int i = 0; i < pTextFile->m_tstrText.length(); i++) {	// 文字列長繰り返す.
			unsigned int ch = pTextFile->m_tstrText.c_str()[i];	// i番目をchに格納.
			if ((ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A)) {	// アルファベットの場合.
				tstrToken = tstrToken + pTextFile->m_tstrText.at(i);	// i番目を連結.
			}
			else if (ch > 0xff) {	// 2バイト文字の場合もアルファベットと同じ.(ソースコードの文字コード関係なくワイド文字(UTF16)として読み込まれるため日本語の判定が比較的容易.)
				// 先頭に"<WCS>"と付ける場合がある.
				if (tstrToken == _T("")) {	// tstrTokenが空.
					tstrToken = _T("<WCS>");	// "<WCS>"を代入.
				}
				else {	// そうでない場合でもありえる.
					unsigned int top = tstrToken.c_str()[0];	// トークンのワイド文字の先頭のASCIIコードを取得.
					if ((top >= 0x41 && top <= 0x5A) || (top >= 0x61 && top <= 0x7A)) {	// アルファベットの場合.
						tstrToken = _T("<WCS>") + tstrToken;	// 先頭に"<WCS>"を付ける.
					}
					// それ以外で例えば"aあaあ"の場合, "aあ"の時点で"<WCS>aあ"でトークンが保持されているので, このあとの"a"はそのまま連結, そのあとの"あ"はトークン先頭が"<"なので, 結果的に先頭に"<WCS>"付加もされず"あ"が連結される.
				}
				tstrToken = tstrToken + pTextFile->m_tstrText.at(i);	// i番目を連結.
			}
			else if (ch == 0x20) {	// スペース.
				if (tstrToken != _T("")) {	// 文字列が入っている.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenListに追加.
				}
				m_vectstrTokenList.push_back(_T("<Space>"));	// "<Space>"を追加.
				tstrToken = _T("");	// ""でリセット.
			}
			else if (ch == 0x0d) {	// CR.
				if (tstrToken != _T("")) {	// 文字列が入っている.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenListに追加.
				}
				m_vectstrTokenList.push_back(_T("<CR>"));	// "<CR>"を追加.
				tstrToken = _T("");	// ""でリセット.
			}
			else if (ch == 0x0a) {	// LF.
				if (tstrToken != _T("")) {	// 文字列が入っている.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenListに追加.
				}
				m_vectstrTokenList.push_back(_T("<LF>"));	// "<LF>"を追加.
				tstrToken = _T("");	// ""でリセット.
			}
			else {	// 記号その他.
				if (tstrToken != _T("")) {	// 文字列が入っている.
					m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenListに追加.
				}
				TCHAR tch[2] = { 0 };	// tchの初期化.
				tch[0] = pTextFile->m_tstrText.at(i);	// i番目をtchに格納.
				tstring ts = tch;	// tsにtchを格納.
				m_vectstrTokenList.push_back(ts);	// tsを追加.
				tstrToken = _T("");	// ""でリセット.
			}
		}
		// 最後の分を出力.
		if (tstrToken != _T("")) {	// 文字列が入っている.
			m_vectstrTokenList.push_back(tstrToken);	// m_vectstrTokenListに追加.
		}
		// トークン一覧を出力.
		for (unsigned int i = 0; i < m_vectstrTokenList.size(); i++) { // トークンリスト分繰り返す.
			// ワイド文字はコンソール出力が厳しいので, 出力が簡単なモノを代理で出力.
			if (m_vectstrTokenList[i].find(_T("<WCS>")) != std::string::npos) {	// "<WCS>"があった場合.
				std::wcout << _T("<WCS>") << std::endl;	// "<WCS>"を出力.
			}
			else {	// それ以外.
				std::wcout << m_vectstrTokenList[i] << std::endl;	// i番目を出力.
			}
		}
		bRet = TRUE;

	}
	else {	// 読み込み失敗.

		// 失敗出力.
		std::wcout << _T("Read Failure!") << std::endl;	// "Read Failure!"と出力.
		bRet = FALSE;

	}
	delete pTextFile;	// pTextFileを解放.

	// 戻り値を返す.
	return bRet;

}