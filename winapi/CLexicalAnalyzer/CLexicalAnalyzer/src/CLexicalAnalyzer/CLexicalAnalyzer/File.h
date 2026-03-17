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
		// コンストラクタ・デストラクタ
		CFile();	// コンストラクタ
		virtual ~CFile();	// デストラクタ
		// メンバ巻数
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// ファイルを開く.
		virtual void Close();	// ファイルを閉じる.
		virtual DWORD Read(LPVOID lpBuf, DWORD dwBytes);	// ファイル内容の読み込み.
		virtual DWORD Write(LPVOID lpBuf, DWORD dwBytes);	// ファイル内容の書き込み.
		virtual DWORD GetFileSize();	// ファイルサイズ(32bit)を取得.
		virtual DWORD SetFilePointer(LONG lDistanceToMove, DWORD dwMoveMethod);	// ファイルポインタ(32bit)の設定と取得.

};

#endif