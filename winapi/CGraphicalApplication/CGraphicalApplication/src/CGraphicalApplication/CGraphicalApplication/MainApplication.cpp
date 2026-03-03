// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(0, _T("CGraphicalApplication"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 終了処理関数ExitInstance.
int CMainApplication::ExitInstance(){

	// 親クラスのExitInstanceを呼ぶ.
	return CApplication::ExitInstance();

}

// アイドル処理関数OnIdle.
BOOL CMainApplication::OnIdle(LONG lCount){

	// 画面の更新.
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.
		if (m_pMainWnd->m_hWnd != NULL){	// m_pMainWnd->m_hWndがNULLでない時.
			HDC hDC = GetDC(m_pMainWnd->m_hWnd);
			TextOut(hDC, 50, 50, _T("ABCDE"), lstrlen(_T("ABCDE")));
			ReleaseDC(m_pMainWnd->m_hWnd, hDC);
		}
	}

	// とりあえずTRUE.
	return TRUE;

}