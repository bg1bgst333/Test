// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ウィンドウクラスの登録.
	CWindow::RegisterClass(hInstance, _T("Window1"));	// CWindow::RegisterClassでウィンドウクラス"Window1"を登録.

	// CMainWindowオブジェクトの作成.
	m_pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, m_pMainWndに格納.

	// ウィンドウの作成.
	RECT rc;	// RECT構造体rc.
	rc.left = 100;	// 左100
	rc.right = 740;	// 右740
	rc.top = 100;	// 上100
	rc.bottom = 580;	// 下580
	if (!m_pMainWnd->Create(_T("Window1"), _T("CWindow"), WS_OVERLAPPEDWINDOW, rc, NULL, NULL, hInstance)) {	// m_pMainWnd->Createでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}