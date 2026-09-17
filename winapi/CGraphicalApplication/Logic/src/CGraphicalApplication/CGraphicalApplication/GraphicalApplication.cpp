// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCGraphicalApplication
CGraphicalApplication::CGraphicalApplication() : CApplication(){

	// メンバの初期化.
	m_hBackBufferDC = NULL;
	m_hBackBufferBitmap = NULL;
	m_hOldBitmap = NULL;
	m_iBackBufferWidth = 0;
	m_iBackBufferHeight = 0;

}

// メッセージループ処理関数Run.
int CGraphicalApplication::Run(){

	// 変数の初期化.
	MSG msg = {0};	// MSG型メッセージ構造体msgを{0}で初期化.
	int lCount = 0;	// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// メッセージループが来ていれば処理する.
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// WM_QUITならExitInstanceを呼んで終了.
			if (msg.message == WM_QUIT){
				return ExitInstance();
			}

			// ウィンドウメッセージの送出
			TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
			DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

		}

		// アイドル処理
		OnIdle(lCount++);
		Sleep(1);

	}

}

// 終了処理関数ExitInstance.
int CGraphicalApplication::ExitInstance(){

	// バックバッファの後始末.
	DestroyBackBuffer();	// DestroyBackBufferでバックバッファを破棄.

	// 親クラスのExitInstanceを呼ぶ.
	return CApplication::ExitInstance();

}

// アイドル処理関数OnIdle.
BOOL CGraphicalApplication::OnIdle(LONG lCount){

	// 画面の更新.
	if (m_pMainWnd != NULL){	// m_pMainWndがNULLでない時.
		if (m_pMainWnd->m_hWnd != NULL){	// m_pMainWnd->m_hWndがNULLでない時.
			// メインループ処理.
			MainProc();
		}
	}

	// とりあえずTRUE.
	return TRUE;

}

// メインループ処理関数MainProc.
void CGraphicalApplication::MainProc(){

	// 入力処理
	Input();

	// ロジック処理
	Logic();

}

// バックバッファ作成関数CreateBackBuffer.
void CGraphicalApplication::CreateBackBuffer(){

	// ウィンドウのDCを取得.
	HDC hDC = GetDC(m_pMainWnd->m_hWnd);	// GetDCでウィンドウのDCを取得.

	// クライアント領域のサイズを取得.
	RECT rc = {0};
	GetClientRect(m_pMainWnd->m_hWnd, &rc);

	// メモリDCとバックバッファビットマップの作成.
	m_hBackBufferDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでウィンドウDCと互換のメモリDCを作成.
	m_hBackBufferBitmap = CreateCompatibleBitmap(hDC, rc.right - rc.left, rc.bottom - rc.top);	// CreateCompatibleBitmapでクライアント領域と同じサイズのビットマップを作成.

	// バックバッファのサイズを記録しておく.(次回Renderでリサイズ検知に使う.)
	m_iBackBufferWidth = rc.right - rc.left;
	m_iBackBufferHeight = rc.bottom - rc.top;

	// メモリDCにバックバッファビットマップを選択し, 元のビットマップをm_hOldBitmapに保持.
	m_hOldBitmap = (HBITMAP)SelectObject(m_hBackBufferDC, m_hBackBufferBitmap);	// SelectObjectでm_hBackBufferDCにm_hBackBufferBitmapを選択.

	// ウィンドウのDCを解放.
	ReleaseDC(m_pMainWnd->m_hWnd, hDC);	// ReleaseDCでウィンドウのDCを解放.

}

// バックバッファ破棄関数DestroyBackBuffer.
void CGraphicalApplication::DestroyBackBuffer(){

	// バックバッファが作成されていれば後始末する.
	if (m_hBackBufferDC != NULL){
		SelectObject(m_hBackBufferDC, m_hOldBitmap);	// SelectObjectで元のビットマップに戻す.
		DeleteObject(m_hBackBufferBitmap);	// DeleteObjectでバックバッファビットマップを破棄.
		DeleteDC(m_hBackBufferDC);	// DeleteDCでメモリDCを破棄.
		// 破棄後はハンドルをNULLに戻しておく.(繰り返しCreate/Destroyされるため, 二重解放を防ぐ.)
		m_hBackBufferDC = NULL;
		m_hBackBufferBitmap = NULL;
		m_hOldBitmap = NULL;
		m_iBackBufferWidth = 0;
		m_iBackBufferHeight = 0;
	}

}

// 入力処理関数Input.
void CGraphicalApplication::Input(){

	// 既定では何もしない.(派生クラスでオーバーライドして使う.)

}

// ロジック処理関数Logic.
void CGraphicalApplication::Logic(){

	// 既定では何もしない.(派生クラスでオーバーライドして使う.)

}
