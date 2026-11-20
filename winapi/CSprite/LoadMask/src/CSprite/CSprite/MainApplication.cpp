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
	if (!pMainWnd->CreateEx(0, _T("CSprite"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// バックバッファの作成.
	CreateBackBuffer();	// CreateBackBufferでバックバッファを作成.

	// スプライト画像のロード.
	if (!m_Sprite.Load(hInstance, _T("walk1.bmp"))){	// CSprite::Loadで画像をロードし, 失敗した場合.

		// エラー処理
		MessageBox(m_pMainWnd->m_hWnd, _T("CSprite::Load failed!"), _T("CSprite"), MB_OK | MB_ICONHAND);	// MessageBoxで"CSprite::Load failed!"とエラーメッセージを表示.
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// マスク読込のテスト.(同じサイズのマスクはTRUE, サイズの違うマスクはFALSEになることを確認する.)
	BOOL bMatch = m_Sprite.LoadMask(hInstance, _T("walk1_mask.bmp"));	// 同じサイズのマスクを読み込む.
	BOOL bMismatch = m_Sprite.LoadMask(hInstance, _T("small_mask.bmp"));	// サイズの違うマスクを読み込む.
	TCHAR szText[256];	// 結果の文字列バッファ.
	wsprintf(szText, _T("walk1_mask.bmp = %d\n small_mask.bmp = %d (0なら失敗)"), bMatch, bMismatch);	// 結果を文字列にする.
	MessageBox(m_pMainWnd->m_hWnd, szText, _T("LoadMask"), MB_OK);	// 結果をMessageBoxで表示.
	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}
