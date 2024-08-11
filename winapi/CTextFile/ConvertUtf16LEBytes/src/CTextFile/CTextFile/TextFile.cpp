// ヘッダのインクルード
// 独自のヘッダ
#include "TextFile.h"	// CTextFile

// テキストのセット.
void CTextFile::SetText(tstring tstrText){

	// メンバにセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextをセット.

}

// テキストをUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::ConvertUtf16LEBytes(){

	// UTF-16LEバイト列をバッファにセット.
	Set((BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)

}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// BOMなしUTF-16LEとして書き込み.
	ConvertUtf16LEBytes();	// ConvertUtf16LEBytesでm_tstrTextをUTF-16LEバイト列に変換してバッファにセット.
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	Close();	// 閉じる.
	Clear();	// バッファもクリア.
	return bRet;	// bRetを返す.

}