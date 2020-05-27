// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// インスタンス初期化関数InitInstance.
BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CWindow::RegisterClass(hInstance, _T("CWindow"));	// CWindow::RegisterClassでウィンドウクラス"CWindow"を登録.

	// ウィンドウの作成.
	if (!m_mainWnd.Create(_T("CWindow"), _T("CWindow"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_mainWnd.Createでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_mainWnd.ShowWindow(SW_SHOW);	// m_mainWnd.ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// メッセージループ処理関数Run.
int CApplication::Run(){

	// 構造体の宣言
	MSG msg;	// MSG型構造体msg.

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessageでウィンドウメッセージを取得し, msgに格納.(0以下ならここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャWindowProcに送出.

	}

	// ExitInstanceの値を返す.
	return ExitInstance();	// returnでExitInstanceの値を返す.

}

// 終了処理関数ExitInstance.
int CApplication::ExitInstance(){

	// 今回は常に0を返す.
	return 0;	// returnで0を返す.

}