// 二重インクルード防止
#ifndef __FILE_DIALOG_H__
#define __FILE_DIALOG_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// ファイル選択ダイアログCFileDialog
class CFileDialog {

	// privateメンバ
	private:

		// privateメンバ変数
		BOOL m_bOpenFileDalog;
		TCHAR m_tszDefExt[16];
		TCHAR m_tszFileName[1024];
		TCHAR m_tszFilter[1024];

	// protectedメンバ
	protected:

		// protectedメンバ変数
		OPENFILENAME m_ofn;	// OPENFILENAME構造体m_ofn.

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CFileDialog(BOOL bOpenFileDalog, LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, LPCTSTR lpszFilter = NULL, CWindow* pParentWnd = NULL, DWORD dwSize = 0);	// コンストラクタCFileDialog
		// メンバ関数
		INT_PTR DoModal();	// モーダル表示.
		OPENFILENAME& GetOFN();	// OPENFILENAMEの取得.

};

#endif