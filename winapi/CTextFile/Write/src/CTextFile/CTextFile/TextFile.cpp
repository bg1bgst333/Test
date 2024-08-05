// ヘッダのインクルード
// 独自のヘッダ
#include "TextFile.h"	// CTextFile

// テキストのセット.
void CTextFile::SetText(tstring tstrText){

	// メンバにセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextをセット.

}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// BOMなしUTF-16LEとして書き込み.
	Set((BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	return bRet;	// bRetを返す.

}