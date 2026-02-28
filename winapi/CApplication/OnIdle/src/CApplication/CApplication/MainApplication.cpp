// ヘッダのインクルード
// 独自のヘッダ
#include "resource.h"
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow* pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(0, _T("CApplication"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// メッセージループ処理関数Run.
int CMainApplication::Run() {

	// 変数の初期化.
	MSG msg = { 0 };	// MSG型メッセージ構造体msgを{0}で初期化.
	int lCount = 0;	// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.

	// PeekMessageによるメインループ.
	while (TRUE) {	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else {	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else {	// 偽ならウィンドウメッセージが来ていないとき.

			// アイドル処理
			if (OnIdle(lCount)) {	// OnIdleにlCountを渡して, この中でアイドル処理をする.
				lCount++;	// TRUEで返ってくるたびにlCountを増やす.
			}

		}

	}

	// ExitInstanceの値を返す.
	return ExitInstance();	// returnでExitInstanceを返す.

}

// 終了処理関数ExitInstance.
int CMainApplication::ExitInstance() {

	// 親クラスのExitInstanceを呼ぶ.
	return CApplication::ExitInstance();

}

// アイドル処理関数OnIdle.
BOOL CMainApplication::OnIdle(LONG lCount) {

	// 画面の更新.
	if (m_pMainWnd != NULL) {	// m_pMainWndがNULLでない時.
		if (m_pMainWnd->m_hWnd != NULL) {	// m_pMainWnd->m_hWndがNULLでない時.
			HDC hDC = GetDC(m_pMainWnd->m_hWnd);
			TextOut(hDC, 50, 50, _T("ABCDE"), lstrlen(_T("ABCDE")));
			ReleaseDC(m_pMainWnd->m_hWnd, hDC);
		}
	}

	// とりあえずTRUE.
	return TRUE;

}