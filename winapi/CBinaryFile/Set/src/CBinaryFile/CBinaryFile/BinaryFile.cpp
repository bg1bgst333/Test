// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

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