// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);
	m_hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("test1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// "test1.bmp"のロード.
	m_hBrush1 = CreatePatternBrush(m_hBitmap1);	// "test1"パターンブラシの生成.
	CMultiView::RegisterClass(hInstance, m_hBrush1);	// CMultiViewの登録.
	m_hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("test2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// "test2.bmp"のロード.
	m_hBrush2 = CreatePatternBrush(m_hBitmap2);	// "test2"パターンブラシの生成.
	CMultiViewItemsPanel::RegisterClass(hInstance, m_hBrush2);	// CMultiViewItemsPanelの登録.
	m_hBitmap3 = (HBITMAP)LoadImage(hInstance, _T("test1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// "test3.bmpのロード.
	m_hBrush3 = CreatePatternBrush(m_hBitmap3);	// "test3"パターンブラシの生成.
	CMultiViewItem::RegisterClass(hInstance, m_hBrush3);	// CMultiViewItemの登録.

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(WS_EX_COMPOSITED, _T("CComboBox"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

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

	// ブラシの解放.
	DeleteObject(m_hBitmap3);
	DeleteObject(m_hBrush3);
	DeleteObject(m_hBitmap2);
	DeleteObject(m_hBrush2);
	DeleteObject(m_hBitmap1);
	DeleteObject(m_hBrush1);

	// 親クラスのExitInstanceを呼ぶ.
	return CApplication::ExitInstance();

}