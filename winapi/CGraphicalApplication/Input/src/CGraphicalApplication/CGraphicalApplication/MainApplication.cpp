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
	if (!pMainWnd->CreateEx(0, _T("CGraphicalApplication::Input"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 入力処理関数Input.
void CMainApplication::Input(){

	// 矢印キーの押下状態を調べて, タイトルバーに表示する.
	// (CGraphicalApplication::MainProcから毎フレーム呼ばれるInputが, 実際に動いていることを示すデモ.)
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){	// 左矢印キーが押されている場合.
		m_pMainWnd->SetWindowText(_T("Left"));	// タイトルバーに"Left"を表示.
	}else if (GetAsyncKeyState(VK_RIGHT) & 0x8000){	// 右矢印キーが押されている場合.
		m_pMainWnd->SetWindowText(_T("Right"));	// タイトルバーに"Right"を表示.
	}else if (GetAsyncKeyState(VK_UP) & 0x8000){	// 上矢印キーが押されている場合.
		m_pMainWnd->SetWindowText(_T("Up"));	// タイトルバーに"Up"を表示.
	}else if (GetAsyncKeyState(VK_DOWN) & 0x8000){	// 下矢印キーが押されている場合.
		m_pMainWnd->SetWindowText(_T("Down"));	// タイトルバーに"Down"を表示.
	}else{	// どの矢印キーも押されていない場合.
		m_pMainWnd->SetWindowText(_T("CGraphicalApplication::Input"));	// タイトルバーを既定の文字列に戻す.
	}

}
