// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "KeyboardInput.h"	// CKeyboardInput
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	// m_Characterの位置(m_x, m_y)と速度(m_vx, m_vy)はCCharacterのコンストラクタで既に0に初期化されている.
	m_Character.m_pGraphicalApplication = this;	// m_Character.m_pGraphicalApplicationに自分自身(CMainApplication)をセット.(引数なしのRenderで使う.)

	// 背景色の指定.(既定の白ではなく, SetBackgroundColorの効果を見せるため薄い水色にする.)
	SetBackgroundColor(RGB(200, 220, 255));	// SetBackgroundColorで背景色を薄い水色に変更.

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(0, _T("CCharacter"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

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

	// m_Character自身に入力処理をさせる.
	m_Character.Input();	// m_Character.Inputで矢印キーの押下状態を自分の速度に反映させる.

}

// ロジック処理関数Logic.
void CMainApplication::Logic(){

	// ウィンドウのリサイズに合わせてバックバッファを作り直す.(GetClientRect/DestroyBackBuffer/CreateBackBufferという, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ResizeBackBuffer();

	// m_Character自身にロジック処理をさせる.
	m_Character.Logic();	// m_Character.Logicで座標更新と画面端クランプをさせる.

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
