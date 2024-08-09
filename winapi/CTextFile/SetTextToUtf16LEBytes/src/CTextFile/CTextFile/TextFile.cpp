// ヘッダのインクルード
// 独自のヘッダ
#include "TextFile.h"	// CTextFile

// テキストのセット.
void CTextFile::SetText(tstring tstrText) {

	// メンバにセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextをセット.

}

// テキストをセットし, UTF-16LEバイト列に変換してバッファにセット.
void CTextFile::SetTextToUtf16LEBytes(tstring tstrText) {

	// テキストをセット.
	SetText(tstrText);

	// UTF-16LEバイト列をバッファにセット.
	Set((BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)

}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName) {

	// BOMなしUTF-16LEとして書き込み.
	Set((BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	return bRet;	// bRetを返す.

}