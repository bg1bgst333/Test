// ヘッダのインクルード
// 独自のヘッダ
#include "TextFile.h"	// CTextFile
#include "string_utility_cppstring.h"	// 文字列ユーティリティ(C++文字列処理)

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

// テキストをShift_JISバイト列に変換に変換してバッファにセット.
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
	else {	// それ以外.
		// 最終的にShift_JISにする.
		BOOL bRet = EncodeShiftJis();	// EncodeShiftJisでm_tstrTextをShift_JISバイト列に変換してバッファにセット.
		if (!bRet) {	// 失敗
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

// BOMのチェック.
CTextFile::BOM CTextFile::CheckBom() {

	// BOMの判定.
	if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LEの場合.
		m_Bom = BOM_UTF16LE;	// BOM_UTF16LEをセット.
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

}

// 改行のチェック.
CTextFile::NEW_LINE CTextFile::CheckNewLine() {

	// まずCR('\r')を探す.
	size_t f = m_tstrText.find_first_of(_T('\r'));	// '\r'の位置をfに格納.
	if (f != -1 && f < m_tstrText.length() - 1) {	// f('\r')が見つかった場合.
		if (m_tstrText[f + 1] == '\n') {	// 次が'\n'の場合.
			m_NewLine = NEW_LINE_CRLF;	// NEW_LINE_CRLFをセット.
		}
		else {	// '\r'だけ.
			m_NewLine = NEW_LINE_CR;	// NEW_LINE_CRをセット.
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

		// BOMのチェック.
		CheckBom();
		if (m_Bom == BOM_UTF16LE) {	// UTF-16LEのBOMの場合.
			m_Encoding = ENCODING_UTF_16LE;
			DecodeUtf16LEWithBom();	// BOM付きUTF-16LEをテキストにデコード.
		}
		else {	// それ以外.
			m_Encoding = ENCODING_SHIFT_JIS;
			DecodeShiftJis();	// Shift_JISをテキストにデコード.
		}
		CheckNewLine();	// 改行コードのチェック.
		if (m_NewLine != NEW_LINE_NONE || m_NewLine != NEW_LINE_CRLF) {	// 改行無しではない or CRLFではない場合.
			ConvertNewLine(CTextFile::NEW_LINE_CRLF, m_NewLine);	// CRLFに変換.
		}
		return TRUE;	// TRUEを返す.

	}

	// FALSEを返す.
	return FALSE;

}

// バッファのクリア.
void CTextFile::Clear() {

	// メンバの終了処理.
	m_tstrText.clear();	// クリア.
	m_Encoding = ENCODING_NONE;	// エンコード無し.
	m_Bom = BOM_NONE;	// BOM無し.

	// 親クラスのClearを呼ぶ.
	CBinaryFile::Clear();	// バッファクリア.

}