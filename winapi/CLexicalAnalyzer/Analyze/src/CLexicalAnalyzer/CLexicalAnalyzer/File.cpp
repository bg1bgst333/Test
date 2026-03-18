// ヘッダのインクルード
// 既定のヘッダ
#include <shlwapi.h>	// シェルAPI
// 独自ヘッダ
#include "File.h"	// CFile

// コンストラクタ
CFile::CFile() {

	// メンバの初期化.
	m_hFile = NULL;	// m_hFileにNULLをセット.
	m_tstrFilePath.clear();	// m_tstrFilePath.clearでクリア.

}

// デストラクタ
CFile::~CFile() {

	// メンバの終了処理.
	Close();	// Closeで閉じる.

}

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

// ファイルを閉じる.
void CFile::Close() {

	// ファイルハンドルを閉じる.
	if (m_hFile != NULL) {	// ハンドルが残っていたら.
		CloseHandle(m_hFile);	// CloseHandleでm_hFileを閉じる.
		m_hFile = NULL;	// m_hFileにNULLをセット.
	}

	// ファイル名などの情報もクリア.
	m_tstrFilePath.clear();

}

// ファイル内容の読み込み.
DWORD CFile::Read(LPVOID lpBuf, DWORD dwBytes) {

	// 変数の初期化.
	DWORD dwReadBytes = 0;	// 読み込んだバイト数dwReadBytesを0に初期化.

	// ファイルを読み込む.
	ReadFile(m_hFile, lpBuf, dwBytes, &dwReadBytes, NULL);	// ReadFileで読み込み.

	// 読み込んだバイト数を返す.
	return dwReadBytes;	// dwReadBytesを返す.

}

// ファイル内容の書き込み.
DWORD CFile::Write(LPVOID lpBuf, DWORD dwBytes) {

	// 変数の初期化.
	DWORD dwWrittenBytes = 0;	// 書き込んだバイト数dwWrittenBytesを0に初期化.

	// ファイルに書き込む.
	WriteFile(m_hFile, lpBuf, dwBytes, &dwWrittenBytes, NULL);	// WriteFileで書き込み.

	// 書き込んだバイト数を返す.
	return dwWrittenBytes;	// dwWrittenBytesを返す.

}

// ファイルサイズ(32bit)を取得.
DWORD CFile::GetFileSize() {

	// ファイルサイズ(32bit)を返す.
	return ::GetFileSize(m_hFile, NULL);	// Win32APIのGetFileSizeで32bit分返す.

}

// ファイルポインタ(32bit)の設定と取得.
DWORD CFile::SetFilePointer(LONG lDistanceToMove, DWORD dwMoveMethod) {

	// 移動するバイト数と移動の開始点を渡す.
	return ::SetFilePointer(m_hFile, lDistanceToMove, NULL, dwMoveMethod);	// Win32APIのSetFilePointerで位置の設定や取得をする.

}