// 二重インクルード防止
#ifndef __FILE_H__
#define __FILE_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <string>		// std::string

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ファイルCFile
class CFile {

	// publicメンバ
	public:

		// publicメンバ変数
		HANDLE m_hFile;	// ファイルハンドル
		tstring m_tstrFilePath;	// ファイルパス

		// publicメンバ関数
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// ファイルを開く.

};

#endif