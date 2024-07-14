// ヘッダのインクルード
// 既定のヘッダ
#include <shlwapi.h>	// シェルAPI
// 独自ヘッダ
#include "File.h"	// CFile

// ファイルを開く.
BOOL CFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition) {

	// 与えられた引数のパスが相対パスかどうかチェック.
	BOOL bRet = PathIsRelative(lpctszFileName);	// PathIsRelativeで相対パスかチェック.
	if (bRet) {
		// 絶対パスの取得.
		TCHAR tszFullPath[1024] = { 0 };
		TCHAR* ptszFilePart = NULL;
		DWORD dwRet = GetFullPathName(lpctszFileName, 1024, tszFullPath, &ptszFilePart);	// GetFullPathNameでフルパスを取得.
		if (dwRet) {
			m_tstrFilePath = tszFullPath;
			// ファイルハンドルの取得.
			m_hFile = CreateFile(m_tstrFilePath.c_str(), dwDesiredAccess, FILE_SHARE_READ, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで開く.
			if (m_hFile == INVALID_HANDLE_VALUE) {	// 失敗.
				m_hFile = NULL;
				m_tstrFilePath.clear();
				return FALSE;
			}
			else {	// 成功.
				return TRUE;
			}
		}
		else {
			return FALSE;
		}
	}
	else {
		m_tstrFilePath = lpctszFileName;
		// ファイルハンドルの取得.
		m_hFile = CreateFile(m_tstrFilePath.c_str(), dwDesiredAccess, FILE_SHARE_READ, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileで開く.
		if (m_hFile == INVALID_HANDLE_VALUE) {	// 失敗.
			m_hFile = NULL;
			m_tstrFilePath.clear();
			return FALSE;
		}
		else {	// 成功.
			return TRUE;
		}
	}

}