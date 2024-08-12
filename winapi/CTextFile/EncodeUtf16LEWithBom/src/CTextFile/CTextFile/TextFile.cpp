// ヘッダのインクルード
// 独自のヘッダ
#include "TextFile.h"	// CTextFile

// テキストのセット.
void CTextFile::SetText(tstring tstrText){

	// メンバにセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextをセット.

}

// テキストをUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16LE(){

	// UTF-16LEバイト列をバッファにセット.
	Set((BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)

}

// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16LEWithBom(){

	// BOM付きUTF-16LEバイト列をバッファにセット.
	BYTE *pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ワイド文字なので2倍 + BOMが2バイト.
	pByteWithBOM[0] = 0xff;	// 0番目は0xff.
	pByteWithBOM[1] = 0xfe;	// 1番目は0xfe.
	memcpy(pByteWithBOM + 2, (BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// pByteWithBOM + 2以降にコピー.
	Set(pByteWithBOM, (m_tstrText.length() + 1) * 2);	// pByteWithBOMをセット.(サロゲートペアなど非対応.)
	delete[] pByteWithBOM;	// deleteでpByteWithBOMを解放.

}

// テキストをShift_JISバイト列に変換に変換してバッファにセット.
BOOL CTextFile::ConvertShiftJisBytes(){

	// Shift_JISバイト列をバッファにセット.
	int iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0){	// 失敗.
		return FALSE;
	}
	BYTE *pBytes = new BYTE[iLen];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytesを0で埋める.
	iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, (char *)pBytes, iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0){	// 失敗.
		delete [] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytesをiLen - 1分セット.
	delete [] pBytes;	// delete [] でpBytesを解放.
	return TRUE;
	
}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// 文字コードを判断して書き込み.
	if (m_Encoding == CTextFile::ENCODING_UTF_16LE){	// UTF-16LEなら.
		// BOMの有無を判断して書き込み.
		if (m_Bom == CTextFile::BOM_UTF16LE){	// UTF-16LEのBOMなら.
			EncodeUtf16LEWithBom();	// EncodeUtf16LEWithBomでm_tstrTextをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		}
		else{	// BOM無しなら.
			EncodeUtf16LE();	// EncodeUtf16LEでm_tstrTextをBOM無しUTF-16LEバイト列に変換してバッファにセット.
		}
	}
	else{	// それ以外.
		// 最終的にShift_JISにする.
		BOOL bRet = ConvertShiftJisBytes();	// ConvertShiftJisBytesでm_tstrTextをShift_JISバイト列に変換してバッファにセット.
		if (!bRet){	// 失敗
			Close();	// 閉じる.
			Clear();	// バッファもクリア.
			return FALSE;	// FALSEを返す.
		}
	}
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	Close();	// 閉じる.
	Clear();	// バッファもクリア.
	return bRet;	// bRetを返す.

}