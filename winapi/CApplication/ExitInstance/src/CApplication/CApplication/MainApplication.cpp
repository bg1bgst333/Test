// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CWindow::RegisterClass(hInstance, _T("CWindow"));	// CWindow::RegisterClassでウィンドウクラス"CWindow"を登録.

	// CWindowオブジェクトの作成.
	m_pMainWnd = new CWindow();	// CWindowオブジェクトを作成し, m_pMainWndに格納.

	// ウィンドウの作成.
	if (!m_pMainWnd->Create(_T("CWindow"), _T("CApplication"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Createでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}