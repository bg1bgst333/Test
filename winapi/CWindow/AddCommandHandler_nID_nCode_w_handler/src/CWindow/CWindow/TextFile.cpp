// ヘッダのインクルード
// 既定のヘッダ
#include <mlang.h>	// 多言語
// 独自のヘッダ
#include "TextFile.h"	// CTextFile
#include "string_utility_cppstring.h"	// 文字列ユーティリティ(C++文字列処理)
#include "file_utility_cstdio.h"	// ファイルユーティリティ(Cファイル処理)

// テキストのセット.
void CTextFile::SetText(tstring tstrText) {

	// メンバにセット.
	m_tstrText = tstrText;	// m_tstrTextにtstrTextをセット.

}

// テキストをUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16LE() {

	// UTF-16LEバイト列をバッファにセット.
	Set((BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Setで文字列をバッファにセット(UTF-16LEなので長さは2倍.)

}

// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16LEWithBom() {

	// BOM付きUTF-16LEバイト列をバッファにセット.
	BYTE* pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ワイド文字なので2倍 + BOMが2バイト.
	pByteWithBOM[0] = 0xff;	// 0番目は0xff.
	pByteWithBOM[1] = 0xfe;	// 1番目は0xfe.
	memcpy(pByteWithBOM + 2, (BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// pByteWithBOM + 2以降にコピー.
	Set(pByteWithBOM, (m_tstrText.length() + 1) * 2);	// pByteWithBOMをセット.(サロゲートペアなど非対応.)
	delete[] pByteWithBOM;	// deleteでpByteWithBOMを解放.

}

// テキストをUTF-16BEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16BE() {

	// バイト列を入れ替える.
	BYTE* pByte = new BYTE[m_tstrText.length() * 2];
	convert_endian_16bit_byte_array((char*)m_tstrText.c_str(), (char*)pByte, m_tstrText.length() * 2);
	Set(pByte, m_tstrText.length() * 2);
	delete[] pByte;

}

// テキストをBOM付きUTF-16BEバイト列に変換してバッファにセット.
void CTextFile::EncodeUtf16BEWithBom() {

	// BOM付きUTF-16BEバイト列をバッファにセット.
	BYTE* pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ワイド文字なので2倍 + BOMが2バイト.
	pByteWithBOM[0] = 0xfe;	// 0番目は0xfe.
	pByteWithBOM[1] = 0xff;	// 1番目は0xff.
	convert_endian_16bit_byte_array((char*)m_tstrText.c_str(), (char*)pByteWithBOM + 2, m_tstrText.length() * 2);
	Set(pByteWithBOM, m_tstrText.length() * 2 + 2);
	delete[] pByteWithBOM;

}

// テキストをUTF-8バイト列に変換してバッファにセット.
BOOL CTextFile::EncodeUtf8() {

	// UTF-8バイト列をバッファにセット.
	int iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytesを0で埋める.
	iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytesをiLen - 1分セット.
	delete[] pBytes;	// delete [] でpBytesを解放.
	return TRUE;

}

// テキストをBOM付きUTF-8バイト列に変換してバッファにセット.
BOOL CTextFile::EncodeUtf8WithBom() {

	// BOM付きUTF-8バイト列をバッファにセット.
	int iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen + 3];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes + 3, sizeof(BYTE) * iLen);	// pBytes + 3の位置から0で埋める.
	iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, (char*)(pBytes + 3), iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	pBytes[0] = 0xef;	// BOM1文字目(0xEF)
	pBytes[1] = 0xbb;	// BOM2文字目(0xBB)
	pBytes[2] = 0xbf;	// BOM3文字目(0xBF)
	Set(pBytes, iLen - 1 + 3);	// pBytesをiLen - 1 + 3分セット.
	delete[] pBytes;	// delete [] でpBytesを解放.
	return TRUE;

}

// テキストをShift_JISバイト列に変換してバッファにセット.
BOOL CTextFile::EncodeShiftJis() {

	// Shift_JISバイト列をバッファにセット.
	int iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytesを0で埋める.
	iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytesをiLen - 1分セット.
	delete[] pBytes;	// delete [] でpBytesを解放.
	return TRUE;

}

// テキストをEUC-JPバイト列に変換してバッファにセット.
BOOL CTextFile::EncodeEucJp() {

	// EUC-JPバイト列をバッファにセット.
	int iLen = WideCharToMultiByte(20932, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytesを0で埋める.
	iLen = WideCharToMultiByte(20932, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytesをiLen - 1分セット.
	delete[] pBytes;	// delete [] でpBytesを解放.
	return TRUE;

}

// テキストをJISバイト列に変換してバッファにセット.
BOOL CTextFile::EncodeJis() {

	// JISバイト列をバッファにセット.
	int iLen = WideCharToMultiByte(50220, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// 変換に必要なバッファの長さを取得.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// バイト列を格納する配列pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytesを0で埋める.
	iLen = WideCharToMultiByte(50220, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ワイド文字からマルチバイト文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] pBytes;	// delete [] でpBytesを解放.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytesをiLen - 1分セット.
	delete[] pBytes;	// delete [] でpBytesを解放.
	return TRUE;

}

// 改行コードの変換.
void CTextFile::ConvertNewLine(NEW_LINE dest, NEW_LINE src) {

	// 改行コードを置き換える.
	tstring before;	// 置換前before.
	if (src == CTextFile::NEW_LINE_CRLF) {	// CRLF
		before = _T("\r\n");	// beforeに"\r\n"をセット.
	}
	else if (src == CTextFile::NEW_LINE_LF) {	// LF
		before = _T("\n");	// beforeに"\n"をセット.
	}
	else if (src == CTextFile::NEW_LINE_CR) {	// CR
		before = _T("\r");	// beforeに"\r"をセット.
	}
	tstring after;	// 置換後after.
	if (dest == CTextFile::NEW_LINE_CRLF) {	// CRLF
		after = _T("\r\n");	// afterに"\r\n"をセット.
	}
	else if (dest == CTextFile::NEW_LINE_LF) {	// LF
		after = _T("\n");	// afterに"\n"をセット.
	}
	else if (dest == CTextFile::NEW_LINE_CR) {	// CR
		after = _T("\r");	// afterに"\r"をセット.
	}
	if (before != after) {	// beforeとafterが違う時.
		replace_tstring_all(m_tstrText, before, after);	// replace_tstring_allで置換.
	}

}

// 指定のテキストファイルに全部一斉書き込み.
BOOL CTextFile::Write(LPCTSTR lpctszFileName) {

	// 改行コードのチェック.(CRLFなら変更しない.)
	if (m_NewLine == NEW_LINE_CR) {	// CR.
		ConvertNewLine(NEW_LINE_CR, NEW_LINE_CRLF);	// ConverNewLineでCRLFからCRに変換.
	}
	else if (m_NewLine == NEW_LINE_LF) {	// LF.
		ConvertNewLine(NEW_LINE_LF, NEW_LINE_CRLF);	// ConverNewLineでCRLFからLFに変換.
	}

	// 文字コードを判断して書き込み.
	if (m_Encoding == CTextFile::ENCODING_UTF_16LE) {	// UTF-16LEなら.
		// BOMの有無を判断して書き込み.
		if (m_Bom == CTextFile::BOM_UTF16LE) {	// UTF-16LEのBOMなら.
			EncodeUtf16LEWithBom();	// EncodeUtf16LEWithBomでm_tstrTextをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		}
		else {	// BOM無しなら.
			EncodeUtf16LE();	// EncodeUtf16LEでm_tstrTextをBOM無しUTF-16LEバイト列に変換してバッファにセット.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_UTF_16BE) {	// UTF-16BEなら.
		// BOMの有無を判断して書き込み.
		if (m_Bom == CTextFile::BOM_UTF16BE) {	// UTF-16BEのBOMなら.
			EncodeUtf16BEWithBom();	// EncodeUtf16BEWithBomでm_tstrTextをBOM付きUTF-16BEバイト列に変換してバッファにセット.
		}
		else {	// BOM無しなら.
			EncodeUtf16BE();	// EncodeUtf16BEでm_tstrTextをBOM無しUTF-16BEバイト列に変換してバッファにセット.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_UTF_8) {	// UTF-8なら.
		// BOMの有無を判断して書き込み.
		if (m_Bom == CTextFile::BOM_UTF8) {	// UTF-8のBOMなら.
			BOOL bRet = EncodeUtf8WithBom();	// EncodeUtf8WithBomでm_tstrTextをBOM付きUTF-8バイト列に変換してバッファにセット.
			if (!bRet) {	// 失敗
				Close();	// 閉じる.
				Clear();	// バッファもクリア.
				return FALSE;	// FALSEを返す.
			}
		}
		else {	// BOM無しなら.
			BOOL bRet = EncodeUtf8();	// EncodeUtf8でm_tstrTextをUTF-8バイト列に変換してバッファにセット.
			if (!bRet) {	// 失敗
				Close();	// 閉じる.
				Clear();	// バッファもクリア.
				return FALSE;	// FALSEを返す.
			}
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_SHIFT_JIS) {	// Shift_JISなら.
		// Shift_JISにする.
		BOOL bRet = EncodeShiftJis();	// EncodeShiftJisでm_tstrTextをShift_JISバイト列に変換してバッファにセット.
		if (!bRet) {	// 失敗
			Close();	// 閉じる.
			Clear();	// バッファもクリア.
			return FALSE;	// FALSEを返す.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_EUC_JP) {	// EUC-JPなら.
		// EUC-JPにする.
		BOOL bRet = EncodeEucJp();	// EncodeEucJpでm_tstrTextをEUC-JPバイト列に変換してバッファにセット.
		if (!bRet) {	// 失敗
			Close();	// 閉じる.
			Clear();	// バッファもクリア.
			return FALSE;	// FALSEを返す.
		}
	}
	else {	// それ以外.
		// 最終的にJISにする.
		BOOL bRet = EncodeJis();	// EncodeJisでm_tstrTextをJISバイト列に変換してバッファにセット.
		if (!bRet) {	// 失敗
			Close();	// 閉じる.
			Clear();	// バッファもクリア.
			return FALSE;	// FALSEを返す.
		}
	}

	// 書き込み.
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Writeで書き込み.
	Close();	// 閉じる.
	Clear();	// バッファもクリア.
	return bRet;	// bRetを返す.

}

// BOMのチェック.
CTextFile::BOM CTextFile::CheckBom() {

	// BOMの判定.
	if (m_dwSize >= 3 && m_pBytes[0] == 0xef && m_pBytes[1] == 0xbb && m_pBytes[2] == 0xbf) {	// UTF-8の場合.
		m_Bom = BOM_UTF8;	// BOM_UTF8をセット.
	}
	else if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LEの場合.
		m_Bom = BOM_UTF16LE;	// BOM_UTF16LEをセット.
	}
	else if (m_dwSize >= 2 && m_pBytes[0] == 0xfe && m_pBytes[1] == 0xff) {	// UTF-16BEの場合.
		m_Bom = BOM_UTF16BE;	// BOM_UTF16BEをセット.
	}
	else {	// それ以外はBOMなし.
		m_Bom = BOM_NONE;	// BOM_NONEをセット.
	}
	return m_Bom;	// m_Bomを返す.

}

// BOM付きUTF-16LEのバイト列をテキストにデコード.
void CTextFile::DecodeUtf16LEWithBom() {

	// BOM付きUTF-16LE形式のバイト列をtstringに変換.
	int iWithOutBom = m_dwSize - 2;	// BOM2バイト分を引く.
	if (iWithOutBom <= 0) {	// 0バイト以下.
		m_tstrText = _T("");	// 空文字列になる.
	}
	else {	// 1文字以上(2バイト以上で必ず偶数バイト.)はある.
		TCHAR* ptszText = new TCHAR[iWithOutBom / 2 + 1];	// iWithOutBomは0以上の偶数になる.
		wmemset(ptszText, _T('\0'), iWithOutBom / 2 + 1);	// wmemsetでptszTextを_T('\0')で埋める.
		wmemcpy(ptszText, ((wchar_t*)m_pBytes) + 1, iWithOutBom / 2);	// 1文字(2バイト分)後ろから(iWithOutBom / 2)の分コピー.
		m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
		delete[] ptszText;	// delete[]でptsztextを解放.
	}

}

// BOM付きUTF-16BEのバイト列をテキストにデコード.
void  CTextFile::DecodeUtf16BEWithBom() {

	// BOM付きUTF-16BE形式のバイト列をtstringに変換.
	int iWithOutBom = m_dwSize - 2;	// BOM2バイト分を引く.
	if (iWithOutBom <= 0) {	// 0バイト以下.
		m_tstrText = _T("");	// 空文字列になる.
	}
	else {	// 1文字以上(2バイト以上で必ず偶数バイト.)はある.
		BYTE* pReversed = new BYTE[m_dwSize];	// 入れ替えたバイト列用メモリ確保.
		convert_endian_16bit_byte_array((const char*)m_pBytes, (char*)pReversed, m_dwSize);	// エンディアン入れ替え.
		TCHAR* ptszText = new TCHAR[iWithOutBom / 2 + 1];	// iWithOutBomは0以上の偶数になる.
		wmemset(ptszText, _T('\0'), iWithOutBom / 2 + 1);	// wmemsetでptszTextを_T('\0')で埋める.
		wmemcpy(ptszText, ((wchar_t*)pReversed) + 1, iWithOutBom / 2);	// 1文字(2バイト分)後ろから(iWithOutBom / 2)の分コピー.
		m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
		delete[] ptszText;	// delete[]でptsztextを解放.
		delete[] pReversed;	// delete[]でpReversedを解放.
	}

}

// BOM付きUTF-8のバイト列をテキストにデコード.
BOOL CTextFile::DecodeUtf8WithBom() {

	// BOM付きUTF-8バイト列をテキストに変換.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)(m_pBytes + 3), -1, NULL, NULL);	// MultiByteToWideCharでバイト列の変換に必要なバッファの長さiLenを求める.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLenの分のTCHAR動的配列を用意し, ポインタをptszTextに格納.
	wmemset(ptszText, _T('\0'), iLen);	// wmemsetでptszTextを_T('0')で埋める.
	iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)(m_pBytes + 3), -1, ptszText, iLen);	// MultiByteToWideCharでマルチバイト文字からワイド文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] ptszText;	// delete [] でptszTextを解放.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
	delete[] ptszText;	// delete [] でptszTextを解放.
	return TRUE;

}

// Shift_JISのバイト列をテキストにデコード.
BOOL CTextFile::DecodeShiftJis() {

	// Shift_JISバイト列をテキストに変換.
	int iLen = MultiByteToWideChar(CP_ACP, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideCharでバイト列の変換に必要なバッファの長さiLenを求める.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLenの分のTCHAR動的配列を用意し, ポインタをptszTextに格納.
	wmemset(ptszText, _T('\0'), iLen);	// wmemsetでptszTextを_T('0')で埋める.
	iLen = MultiByteToWideChar(CP_ACP, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideCharでマルチバイト文字からワイド文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] ptszText;	// delete [] でptszTextを解放.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
	delete[] ptszText;	// delete [] でptszTextを解放.
	return TRUE;

}

// UTF-8のバイト列をテキストにデコード.
BOOL CTextFile::DecodeUtf8() {

	// UTF-8バイト列をテキストに変換.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideCharでバイト列の変換に必要なバッファの長さiLenを求める.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLenの分のTCHAR動的配列を用意し, ポインタをptszTextに格納.
	wmemset(ptszText, _T('\0'), iLen);	// wmemsetでptszTextを_T('0')で埋める.
	iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideCharでマルチバイト文字からワイド文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] ptszText;	// delete [] でptszTextを解放.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
	delete[] ptszText;	// delete [] でptszTextを解放.
	return TRUE;

}

// EUC-JPのバイト列をテキストにデコード.
BOOL CTextFile::DecodeEucJp() {

	// EUC-JPバイト列をテキストに変換.
	int iLen = MultiByteToWideChar(20932, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideCharでバイト列の変換に必要なバッファの長さiLenを求める.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLenの分のTCHAR動的配列を用意し, ポインタをptszTextに格納.
	wmemset(ptszText, _T('\0'), iLen);	// wmemsetでptszTextを_T('0')で埋める.
	iLen = MultiByteToWideChar(20932, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideCharでマルチバイト文字からワイド文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] ptszText;	// delete [] でptszTextを解放.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
	delete[] ptszText;	// delete [] でptszTextを解放.
	return TRUE;

}

// JISのバイト列をテキストにデコード.
BOOL CTextFile::DecodeJis() {

	// JISバイト列をテキストに変換.
	int iLen = MultiByteToWideChar(50220, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideCharでバイト列の変換に必要なバッファの長さiLenを求める.
	if (iLen <= 0) {	// 失敗.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLenの分のTCHAR動的配列を用意し, ポインタをptszTextに格納.
	wmemset(ptszText, _T('\0'), iLen);	// wmemsetでptszTextを_T('0')で埋める.
	iLen = MultiByteToWideChar(50220, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideCharでマルチバイト文字からワイド文字への変換.
	if (iLen <= 0) {	// 失敗.
		delete[] ptszText;	// delete [] でptszTextを解放.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrTextにptszTextをセット.
	delete[] ptszText;	// delete [] でptszTextを解放.
	return TRUE;

}

// バイト列から文字コードを推測.
BOOL CTextFile::DetectEncoding() {

	// COMの初期化.
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr)) {
		m_Encoding = ENCODING_NONE;
		return FALSE;
	}

	// IMultiLanguage2インターフェイスの生成.
	IMultiLanguage2* pMultiLang2 = NULL;
	HRESULT hr2 = CoCreateInstance(CLSID_CMultiLanguage, 0, CLSCTX_INPROC_SERVER, IID_IMultiLanguage2, (LPVOID*)&pMultiLang2);
	if (FAILED(hr2)) {
		CoUninitialize();
		m_Encoding = ENCODING_NONE;
		return FALSE;
	}

	// 文字コード検出.
	int len = m_dwSize;
	DetectEncodingInfo dei[10];
	int num = 10;
	HRESULT hr3 = pMultiLang2->DetectInputCodepage(MLDETECTCP_NONE, 0, (CHAR*)m_pBytes, &len, dei, &num);
	if (FAILED(hr3)) {
		pMultiLang2->Release();
		CoUninitialize();
		m_Encoding = ENCODING_NONE;
		return FALSE;
	}

	// 終了処理.
	pMultiLang2->Release();
	CoUninitialize();
	if (dei[0].nCodePage == 932) {	// Shift_JIS
		m_Encoding = ENCODING_SHIFT_JIS;
		return TRUE;
	}
	else if (dei[0].nCodePage == 65001) {	// UTF-8
		m_Encoding = ENCODING_UTF_8;
		return TRUE;
	}
	else if (dei[0].nCodePage == 50220) {	// JIS
		m_Encoding = ENCODING_JIS;
		return TRUE;
	}
	else if (dei[0].nCodePage == 51932) {	// EUC-JP
		m_Encoding = ENCODING_EUC_JP;
		return TRUE;
	}
	else {	// 不明
		m_Encoding = ENCODING_NONE;
		return TRUE;
	}

}

// UTF-8かどうか判定する.
BOOL CTextFile::IsUtf8(const unsigned char* lpcszStr, size_t uiLen) {

	// UTF-8の文字コード範囲に基づいて1文字ずつチェック.
	size_t i = 0;
	while (i < uiLen) {
		if ((lpcszStr[i] & 0x80) == 0) {	// 1バイト文字.(ASCII)
			i++;	// 1進む.
		}
		else if ((lpcszStr[i] & 0xe0) == 0xc0) {	// 2バイト文字.
			if (i + 1 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80) {
				return FALSE;	// 範囲外.
			}
			i += 2;	// 2進む.
		}
		else if ((lpcszStr[i] & 0xf0) == 0xe0) {	// 3バイト文字.
			if (i + 2 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80 || (lpcszStr[i + 2] & 0xc0) != 0x80) {
				return FALSE;	// 範囲外.
			}
			i += 3;	// 3進む.
		}
		else if ((lpcszStr[i] & 0xf8) == 0xf0) {	// 4バイト文字.
			if (i + 3 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80 || (lpcszStr[i + 2] & 0xc0) != 0x80 || (lpcszStr[i + 3] & 0xc0) != 0x80) {
				return FALSE;	// 範囲外.
			}
			i += 4;	// 4進む.
		}
		else {	// それ以外.
			return FALSE;	// 範囲外.
		}
	}
	return TRUE;	// 全て範囲内.

}

// Shift_JISかどうか判定する.
BOOL CTextFile::IsShiftJis(const unsigned char* lpcszStr, size_t uiLen) {

	// Shift_JISの文字コード範囲に基づいて1文字ずつチェック.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] <= 0x7f) {	// 1バイト文字.(ASCII)
			i++;	// 1進む.
		}
		else if (lpcszStr[i] >= 0x81 && lpcszStr[i] <= 0x9f) {	// Shift_JIS確定.
			if (i + 1 >= uiLen) {
				return FALSE;	// 無効.
			}
			unsigned char next = lpcszStr[i + 1];
			if ((next >= 0x40 && next <= 0x7e) || (next >= 0x80 && next <= 0xfc)) {	//	2バイト目がShift_JISの範囲.
				i += 2;	// 2進む.
			}
			else {
				return FALSE;	// 範囲外.
			}
		}
		else if (lpcszStr[i] >= 0xa1 && lpcszStr[i] <= 0xfe) {	// 未確定.
			if (i + 1 >= uiLen) {
				return FALSE;	// 無効.
			}
			unsigned char next = lpcszStr[i + 1];
			if (next >= 0xa1 && next <= 0xfe) {	// EUC-JPの2バイト目なので無効.
				return FALSE;
			}
			else if ((next >= 0x40 && next <= 0x7e) || (next >= 0x80 && next <= 0xfc)) {	//	2バイト目がShift_JISの範囲.
				i += 2;	// 2進む.
			}
			else {
				return FALSE;	// 範囲外.
			}
		}
		else {	// それ以外.
			return FALSE;	// 範囲外.
		}
	}
	return TRUE;	// 全て範囲内.

}

// EUC-JPかどうか判定する.
BOOL CTextFile::IsEucJp(const unsigned char* lpcszStr, size_t uiLen) {

	// EUC-JPの文字コード範囲に基づいて1文字ずつチェック.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] <= 0x7f) {	// 1バイト文字.(ASCII)
			i++;	// 1進む.
		}
		else if (lpcszStr[i] == 0x8e) {	// 2バイト文字.(半角カタカナ)
			if (i + 1 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xdf)) {
				return FALSE;
			}
			i += 2;
		}
		else if (lpcszStr[i] == 0x8f) {	// 3バイト文字.(JIS補助漢字)
			if (i + 2 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xfe) || (lpcszStr[i + 2] < 0xa1 || lpcszStr[i + 2] > 0xfe)) {
				return FALSE;
			}
			i += 3;
		}
		else if (lpcszStr[i] >= 0xa1 && lpcszStr[i] <= 0xfe) {	// 2バイト文字.(全角)
			if (i + 1 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xfe)) {
				return FALSE;
			}
			i += 2;
		}
		else {
			return FALSE;	// 範囲外.
		}
	}
	return TRUE;	// 全て範囲内.

}

// JISかどうか判定する.
BOOL CTextFile::IsJis(const unsigned char* lpcszStr, size_t uiLen) {

	// JISの文字コード範囲に基づいて1文字ずつチェック.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] == 0x1b) {	// エスケープ文字の検出.
			if (i + 2 >= uiLen) {
				return FALSE;	// 無効.
			}
			if ((lpcszStr[i + 1] == '(' && (lpcszStr[i + 2] == 'B' || lpcszStr[i + 2] == 'J'))
				|| (lpcszStr[i + 1] == '$' && (lpcszStr[i + 2] == '@' || lpcszStr[i + 2] == 'B'))
				|| (lpcszStr[i + 1] == '(' && lpcszStr[i + 2] == 'I')) {
				i += 3;
				continue;	// 有効なエスケープシーケンスをスキップ.
			}
			else {
				return FALSE;	// 無効.
			}
		}
		if (lpcszStr[i] <= 0x7f) {	// ASCII文字はそのまま進める.
			i++;
		}
		else {
			return FALSE;	// 無効.
		}
	}
	return TRUE;	// 全て範囲内.

}

// 改行のチェック.
CTextFile::NEW_LINE CTextFile::CheckNewLine() {

	// まずCR('\r')を探す.
	size_t f = m_tstrText.find_first_of(_T('\r'));	// '\r'の位置をfに格納.
	if (f != -1) {	// f('\r')が見つかった場合.
		if (f == m_tstrText.length() - 1) {	// 最後が'\r'.
			m_NewLine = NEW_LINE_CR;	// NEW_LINE_CRをセット.
		}
		else {	// 最後でない.
			if (m_tstrText[f + 1] == '\n') {	// 次が'\n'の場合.
				m_NewLine = NEW_LINE_CRLF;	// NEW_LINE_CRLFをセット.
			}
			else {	// '\r'だけ.
				m_NewLine = NEW_LINE_CR;	// NEW_LINE_CRをセット.
			}
		}
	}
	else {	// '\r'はないので, '\n'を探す.
		f = m_tstrText.find_first_of(_T('\n'));	// '\n'の位置をfに格納.
		if (f != -1) {	// f('\n')が見つかった場合.
			m_NewLine = NEW_LINE_LF;	// NEW_LINE_LFをセット.
		}
		else {	// '\n'もない.
			m_NewLine = NEW_LINE_NONE;	// NEW_LINE_NONEをセット.
		}
	}

	// 改行コードを返す.
	return m_NewLine;	// m_NewLineを返す.

}

// 指定のテキストファイルを全部一斉読み込み.
BOOL CTextFile::Read(LPCTSTR lpctszFileName) {

	// ファイルを閉じる.
	Close();

	// バッファのクリア.
	Clear();

	// 指定されたファイル名のファイルを読み込む.
	BOOL bRet = CBinaryFile::Read(lpctszFileName);
	if (bRet) {	// 成功.

		// ファイルを閉じる.
		Close();
		// BOMのチェック.
		CheckBom();
		if (m_Bom == BOM_UTF16LE) {	// UTF-16LEのBOMの場合.
			m_Encoding = ENCODING_UTF_16LE;
			DecodeUtf16LEWithBom();	// BOM付きUTF-16LEをテキストにデコード.
		}
		else if (m_Bom == BOM_UTF16BE) {	// UTF-16BEのBOMの場合.
			m_Encoding = ENCODING_UTF_16BE;
			DecodeUtf16BEWithBom();	// BOM付きUTF-16BEをテキストにデコード.
		}
		else if (m_Bom == BOM_UTF8) {	// UTF-8のBOMの場合.
			m_Encoding = ENCODING_UTF_8;
			DecodeUtf8WithBom();	// BOM付きUTF-8をテキストにデコード.
		}
		else {	// それ以外.
			if (m_bDetectEnc) {	// 推測オン.
				DetectEncoding();	// 文字コード推測.
			}
			else {	// オフ
				m_Encoding = ENCODING_NONE;	// 不明.
			}
			if (m_Encoding == ENCODING_NONE) {	// 不明なとき.
				// JISかどうか判定.
				BOOL bJis = IsJis(m_pBytes, m_dwSize);	// IsUtf8でJISかどうか判定.
				if (bJis) {	// TRUE.
					// JISとして変換.
					m_Encoding = ENCODING_JIS;
					DecodeJis();	// JISをテキストにデコード.
				}
				else {
					// UTF-8かどうか判定.
					BOOL bUtf8 = IsUtf8(m_pBytes, m_dwSize);	// IsUtf8でUTF-8かどうか判定.
					if (bUtf8) {	// TRUE.
						// UTF-8として変換.
						m_Encoding = ENCODING_UTF_8;
						DecodeUtf8();	// UTF-8をテキストにデコード.
					}
					else {	// FALSE.
						// Shift_JISかどうか判定.
						BOOL bShiftJis = IsShiftJis(m_pBytes, m_dwSize);	// IsShiftJisでShift_JISかどうか判定.
						if (bShiftJis) {	// TRUE.
							// Shift_JISとして変換.
							m_Encoding = ENCODING_SHIFT_JIS;
							DecodeShiftJis();	// Shift_JISをテキストにデコード.
						}
						else {	// FALSE.
							// EUC-JPかどうか判定.
							BOOL bEucJp = IsEucJp(m_pBytes, m_dwSize);	// IsEucJpでEUC-JPかどうか判定.
							if (bEucJp) {	// TRUE.
								// EUC-JPとして変換.
								m_Encoding = ENCODING_EUC_JP;
								DecodeEucJp();	// EUC-JPをテキストにデコード.
							}
							else {	// FALSE.
								MessageBox(NULL, _T("Unknown"), _T("CTextFile"), MB_OK);	// "Unknown"と表示.
								CBinaryFile::Clear();	// バッファクリア.
								return FALSE;	// ここで終了.
							}
						}
					}
				}
			}
			else if (m_Encoding == ENCODING_SHIFT_JIS) {	// Shift_JISなとき.
				DecodeShiftJis();	// Shift_JISをテキストにデコード.
			}
			else if (m_Encoding == ENCODING_UTF_8) {	// UTF-8なとき.
				DecodeUtf8();	// UTF-8をテキストにデコード.
			}
			else if (m_Encoding == ENCODING_JIS) {	// JISなとき.
				DecodeJis();	// JISをテキストにデコード.
			}
			else if (m_Encoding == ENCODING_EUC_JP) {	// EUC-JPなとき.
				DecodeEucJp();	// EUC-JPをテキストにデコード.
			}
			else {	// それ以外.
				MessageBox(NULL, _T("Unknown"), _T("CTextFile"), MB_OK);	// "Unknown"と表示.
				CBinaryFile::Clear();	// バッファクリア.
				return FALSE;	// ここで終了.
			}
		}
		CheckNewLine();	// 改行コードのチェック.
		if (m_NewLine != NEW_LINE_NONE && m_NewLine != NEW_LINE_CRLF) {	// 改行無しではない and CRLFではない場合.
			ConvertNewLine(CTextFile::NEW_LINE_CRLF, m_NewLine);	// CRLFに変換.
		}
		CBinaryFile::Clear();	// バッファクリア.
		return TRUE;	// TRUEを返す.

	}

	// FALSEを返す.
	CBinaryFile::Clear();	// バッファクリア.
	return FALSE;

}

// バッファのクリア.
void CTextFile::Clear() {

	// メンバの終了処理.
	m_tstrText.clear();	// クリア.

	// 親クラスのClearを呼ぶ.
	CBinaryFile::Clear();	// バッファクリア.

}