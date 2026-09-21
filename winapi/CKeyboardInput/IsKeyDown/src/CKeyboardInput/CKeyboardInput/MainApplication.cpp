// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "KeyboardInput.h"	// CKeyboardInput
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	m_vx = 0;	// m_vxを0で初期化.
	m_vy = 0;	// m_vyを0で初期化.
	// m_Characterの位置(m_x, m_y)はCCharacterのコンストラクタで既に0に初期化されている.
	m_Character.m_pGraphicalApplication = this;	// m_Character.m_pGraphicalApplicationに自分自身(CMainApplication)をセット.(引数なしのRenderで使う.)

	// 背景色の指定.(既定の白ではなく, SetBackgroundColorの効果を見せるため薄い水色にする.)
	SetBackgroundColor(RGB(200, 220, 255));	// SetBackgroundColorで背景色を薄い水色に変更.

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(0, _T("CKeyboardInput"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

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

// 入力処理関数Input.
void CMainApplication::Input(){

	// 矢印キーの押下状態を調べて, 速度(m_vx, m_vy)に反映する.(座標の更新自体はLogicで行う.)
	m_vx = 0;	// m_vxをいったん0にリセット.
	m_vy = 0;	// m_vyをいったん0にリセット.
	if (CKeyboardInput::IsKeyDown(VK_LEFT)){	// 左矢印キーが押されている場合.
		m_vx = -1;	// m_vxを-1に.
	}else if (CKeyboardInput::IsKeyDown(VK_RIGHT)){	// 右矢印キーが押されている場合.
		m_vx = 1;	// m_vxを1に.
	}
	if (CKeyboardInput::IsKeyDown(VK_UP)){	// 上矢印キーが押されている場合.
		m_vy = -1;	// m_vyを-1に.
	}else if (CKeyboardInput::IsKeyDown(VK_DOWN)){	// 下矢印キーが押されている場合.
		m_vy = 1;	// m_vyを1に.
	}

}

// ロジック処理関数Logic.
void CMainApplication::Logic(){

	// ウィンドウのリサイズに合わせてバックバッファを作り直す.(GetClientRect/DestroyBackBuffer/CreateBackBufferという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ResizeBackBuffer();

	// 速度(m_vx, m_vy)の分だけm_Characterの座標を進める.
	m_Character.m_x += m_vx;	// m_Character.m_xにm_vxを加算.
	m_Character.m_y += m_vy;	// m_Character.m_yにm_vyを加算.

	// 画面端で止まるようにクランプする.(跳ね返らず, それ以上は進めない.)
	if (m_Character.m_x < 0){	// 左端を超えた場合.
		m_Character.m_x = 0;	// 左端に合わせる.
	}
	if (m_Character.m_x > m_iBackBufferWidth - CHARACTER_SIZE){	// 右端を超えた場合.
		m_Character.m_x = m_iBackBufferWidth - CHARACTER_SIZE;	// 右端に合わせる.
	}
	if (m_Character.m_y < 0){	// 上端を超えた場合.
		m_Character.m_y = 0;	// 上端に合わせる.
	}
	if (m_Character.m_y > m_iBackBufferHeight - CHARACTER_SIZE){	// 下端を超えた場合.
		m_Character.m_y = m_iBackBufferHeight - CHARACTER_SIZE;	// 下端に合わせる.
	}

}

// 描画処理関数Render.
void CMainApplication::Render(){

	// バックバッファのクリア.(前フレームの描画を消す. GetClientRect/FillRectという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ClearBackBuffer();

	// m_Characterを自分自身でバックバッファに描画させる.(引数なしのRenderで, m_Character.m_pGraphicalApplication経由で現在のバックバッファのDCを取得させる.)
	m_Character.Render();	// m_Character.Renderで自分自身を描画.

	// バックバッファの内容を画面へ転送.
	PresentBackBuffer();	// PresentBackBufferでバックバッファの内容を画面へ一括転送.(GetDC/BitBlt/ReleaseDCという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)

}
