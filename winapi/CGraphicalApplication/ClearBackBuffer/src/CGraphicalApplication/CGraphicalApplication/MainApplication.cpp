// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
	m_vx = 0;	// m_vxを0で初期化.
	m_vy = 0;	// m_vyを0で初期化.
	m_hbrSquare = NULL;	// m_hbrSquareをNULLで初期化.(Renderで初回に作成する.)

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

	// バックバッファの作成.
	CreateBackBuffer();	// CreateBackBufferでバックバッファを作成.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 終了処理関数ExitInstance.
int CMainApplication::ExitInstance(){

	// ブラシの後始末.
	if (m_hbrSquare != NULL){	// m_hbrSquareがNULLでない場合.(作成済みの場合.)

		// ブラシの破棄
		DeleteObject(m_hbrSquare);	// DeleteObjectでm_hbrSquareを破棄.
		// 破棄後はハンドルをNULLに戻しておく.
		m_hbrSquare = NULL;

	}

	// 親クラスのExitInstanceを呼ぶ.
	return CGraphicalApplication::ExitInstance();

}

// 入力処理関数Input.
void CMainApplication::Input(){

	// 矢印キーの押下状態を調べて, 速度(m_vx, m_vy)に反映する.(座標の更新自体はLogicで行う.)
	m_vx = 0;	// m_vxをいったん0にリセット.
	m_vy = 0;	// m_vyをいったん0にリセット.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){	// 左矢印キーが押されている場合.
		m_vx = -1;	// m_vxを-1に.
	}else if (GetAsyncKeyState(VK_RIGHT) & 0x8000){	// 右矢印キーが押されている場合.
		m_vx = 1;	// m_vxを1に.
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){	// 上矢印キーが押されている場合.
		m_vy = -1;	// m_vyを-1に.
	}else if (GetAsyncKeyState(VK_DOWN) & 0x8000){	// 下矢印キーが押されている場合.
		m_vy = 1;	// m_vyを1に.
	}

}

// ロジック処理関数Logic.
void CMainApplication::Logic(){

	// ウィンドウがリサイズされてバックバッファのサイズと合わなくなっていたら, 作り直す.
	RECT rc = {0};
	GetClientRect(m_pMainWnd->m_hWnd, &rc);
	if (rc.right - rc.left != m_iBackBufferWidth || rc.bottom - rc.top != m_iBackBufferHeight){
		DestroyBackBuffer();	// DestroyBackBufferで古いバックバッファを破棄.
		CreateBackBuffer();	// CreateBackBufferで新しいサイズのバックバッファを作成.
	}

	// 速度(m_vx, m_vy)の分だけ座標(m_x, m_y)を進める.
	m_x += m_vx;	// m_xにm_vxを加算.
	m_y += m_vy;	// m_yにm_vyを加算.

	// 画面端で止まるようにクランプする.(跳ね返らず, それ以上は進めない.)
	if (m_x < 0){	// 左端を超えた場合.
		m_x = 0;	// 左端に合わせる.
	}
	if (m_x > m_iBackBufferWidth - SQUARE_SIZE){	// 右端を超えた場合.
		m_x = m_iBackBufferWidth - SQUARE_SIZE;	// 右端に合わせる.
	}
	if (m_y < 0){	// 上端を超えた場合.
		m_y = 0;	// 上端に合わせる.
	}
	if (m_y > m_iBackBufferHeight - SQUARE_SIZE){	// 下端を超えた場合.
		m_y = m_iBackBufferHeight - SQUARE_SIZE;	// 下端に合わせる.
	}

}

// 描画処理関数Render.
void CMainApplication::Render(){

	// バックバッファのクリア.(前フレームの描画を消す. GetClientRect/FillRectという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ClearBackBuffer();

	// 四角形をバックバッファに描画.
	if (m_hbrSquare == NULL){	// まだ作成していない場合.
		m_hbrSquare = CreateSolidBrush(RGB(255, 0, 0));	// CreateSolidBrushで赤いブラシを作成.(ExitInstanceでDeleteObjectする.)
	}
	RECT rcSquare = {m_x, m_y, m_x + SQUARE_SIZE, m_y + SQUARE_SIZE};	// 四角形の矩形rcSquare.
	FillRect(m_hBackBufferDC, &rcSquare, m_hbrSquare);	// FillRectで(m_x, m_y)位置に四角形を描画.

	// バックバッファの内容を画面へ転送.
	PresentBackBuffer();	// PresentBackBufferでバックバッファの内容を画面へ一括転送.(GetDC/BitBlt/ReleaseDCという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)

}
