// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

// 指定のバイナリファイルに全部一斉書き込み.
BOOL CBinaryFile::Write(LPCTSTR lpctszFileName) {

	// ファイルのオープン
	BOOL bRet = Open(lpctszFileName, GENERIC_WRITE, CREATE_ALWAYS);	// CFile::Openで指定のファイルを開く.
	if (bRet) {	// 成功.

		// ファイルの書き込み.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Writeでデータを書き込む.

	}

	// bRetで成功かどうかわかる.
	return bRet;	// bRetを返す.

}

// 全部一斉に書き込むバッファのセット.
void CBinaryFile::Set(BYTE* pBytes, DWORD dwSize) {

	// メンバにセット.
	m_dwSize = dwSize;	// m_deSizeにdwSizeをセット.

	// バッファの作成.
	m_pBytes = new BYTE[m_dwSize + 1];	// newでm_dwSize + 1のバイト列を作成し, ポインタをm_pBytesに格納.
	ZeroMemory(m_pBytes, m_dwSize + 1);	// ZeroMemoryでm_pBytesを(m_dwSize + 1)分, 0で埋める.

	// データをコピー.
	CopyMemory(m_pBytes, pBytes, m_dwSize);	// CopyMemoryでコピー.

}