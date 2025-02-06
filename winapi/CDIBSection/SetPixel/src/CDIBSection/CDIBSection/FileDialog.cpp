// ヘッダのインクルード
// 既定のヘッダ
#include <string.h>	// C文字列処理
// 独自のヘッダ
extern "C" {	// C言語として解釈する.
	#include "string_utility_cstring.h"	// 文字列ユーティリティ(C文字列処理)
}
#include "FileDialog.h"	// CFileDialog

// コンストラクタCFileDialog()
CFileDialog::CFileDialog(BOOL bOpenFileDalog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName, DWORD dwFlags, LPCTSTR lpszFilter, CWindow* pParentWnd, DWORD dwSize) {

	// メンバの初期化.
	m_bOpenFileDalog = bOpenFileDalog;
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	if (lpszDefExt != NULL) {
		_tcscpy(m_tszDefExt, lpszDefExt);
		m_ofn.lpstrDefExt = m_tszDefExt;
	}
	if (lpszFileName != NULL) {
		_tcscpy(m_tszFileName, lpszFileName);
	}
	else {
		memset(m_tszFileName, 0, sizeof(TCHAR) * 1024);
	}
	m_ofn.nMaxFile = 1024;
	m_ofn.lpstrFile = m_tszFileName;
	m_ofn.Flags = dwFlags;
	if (lpszFilter != NULL) {
		_tcscpy(m_tszFilter, lpszFilter);
		int len = _tcslen(m_tszFilter);
		replace_wbyte_all(m_tszFilter, len, _T('|'), _T('\0'));
		m_ofn.lpstrFilter = m_tszFilter;
	}
	if (pParentWnd != NULL) {
		m_ofn.hwndOwner = pParentWnd->m_hWnd;
	}
	if (dwSize == 0) {
		m_ofn.lStructSize = sizeof(OPENFILENAME);
	}
	else {
		m_ofn.lStructSize = dwSize;
	}

}

// モーダル表示.
INT_PTR CFileDialog::DoModal() {

	// どちらのファイル選択ダイアログを開くか判定.
	if (m_bOpenFileDalog) {	// "開く"
		BOOL bRet = GetOpenFileName(&m_ofn);
		if (bRet) {
			return IDOK;
		}
		else {
			return IDCANCEL;
		}
	}
	else {	// "名前を付けて保存"
		BOOL bRet = GetSaveFileName(&m_ofn);
		if (bRet) {
			return IDOK;
		}
		else {
			return IDCANCEL;
		}
	}

}

// OPENFILENAMEの取得.
OPENFILENAME& CFileDialog::GetOFN() {

	// OPENFILENAMEを返す.
	return m_ofn;

}