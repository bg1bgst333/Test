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

// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::ConvertUtf16LEWithBomBytes(){

	// BOM付きUTF-16LEバイト列をバッファにセット.
	BYTE *pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ワイド文字なので2倍 + BOMが2バイト.
	pByteWithBOM[0] = 0xff;	// 0番目は0xff.
	pByteWithBOM[1] = 0xfe;	// 1番目は0xfe.
	memcpy(pByteWithBOM + 2, (BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// pByteWithBOM + 2以降にコピー.
	Set(pByteWithBOM, (m_tstrText.length() + 1) * 2);	// pByteWithBOMをセット.(サロゲートペアなど非対応.)
	delete[] pByteWithBOM;	// deleteでpByteWithBOMを解放.

}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// BOMの有無を判断して書き込み.
	if (m_Bom == CTextFile::BOM_UTF16LE){	// UTF-16LEのBOMなら.
		ConvertUtf16LEWithBomBytes();	// ConvertUtf16LEWithBomBytesでm_tstrTextをBOM付きUTF-16LEバイト列に変換してバッファにセット.
	}
	else{	// BOM無しなら.
		ConvertUtf16LEBytes();	// ConvertUtf16LEBytesでm_tstrTextをBOM無しUTF-16LEバイト列に変換してバッファにセット.
	}
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	Close();	// 閉じる.
	Clear();	// バッファもクリア.
	return bRet;	// bRetを返す.

}