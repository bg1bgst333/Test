// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow
#include "UserControl.h"		// CUserControl

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));	// CMainWindow::RegisterClassでメニューIDR_MAINMENUを指定してメインのウィンドウクラスを登録.
	CWindow::RegisterClass(hInstance, _T("Child"));	// ウィンドウクラス"Child"の登録.
	CUserControl::RegisterClass(hInstance);	// ウィンドウクラス"CUserControl"の登録.

	// CMainWindowオブジェクトの作成.
	m_pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, m_pMainWndに格納.

	// 垂直方向スクロールバー付きウィンドウの作成.
	if (!m_pMainWnd->Create(_T("CPicture"), WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Createでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}