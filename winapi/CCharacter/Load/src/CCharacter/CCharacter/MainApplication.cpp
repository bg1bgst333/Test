// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "KeyboardInput.h"	// CKeyboardInput
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	m_CharacterManager.m_pGraphicalApplication = this;	// m_CharacterManager.m_pGraphicalApplicationに自分自身(CMainApplication)をセット.(Loadで各キャラクターに引き渡すために使う.)

	// 背景色の指定.(既定の白ではなく, SetBackgroundColorの効果が分かるよう水色にする.)
	SetBackgroundColor(RGB(200, 220, 255));	// SetBackgroundColorで背景色を水色に変更.

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

	// 全キャラクターのスプライト画像のロード.
	if (!m_CharacterManager.Load(hInstance)){	// CCharacterManager::Loadで画像をロードし, 失敗した場合.

		// エラー処理
		MessageBox(m_pMainWnd->m_hWnd, _T("CCharacterManager::Load failed!"), _T("CCharacter"), MB_OK | MB_ICONHAND);	// MessageBoxで"CCharacterManager::Load failed!"とエラーメッセージを表示.
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 入力処理関数Input.
void CMainApplication::Input(){

	// m_CharacterManagerに入力処理を委譲する.
	m_CharacterManager.Input();	// m_CharacterManager.Inputで先頭キャラクターの速度に矢印キーの押下状態を反映させる.

}

// ロジック処理関数Logic.
void CMainApplication::Logic(){

	// ウィンドウのリサイズに合わせてバックバッファを作り直す.(GetClientRect/DestroyBackBuffer/CreateBackBufferといった, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ResizeBackBuffer();

	// m_CharacterManagerにロジック処理を委譲する.
	m_CharacterManager.Logic();	// m_CharacterManager.Logicで全キャラクターの座標更新と画面端クランプを行わせる.

}

// 描画処理関数Render.
void CMainApplication::Render(){

	// バックバッファのクリア.(前フレームの描画を消す. GetClientRect/FillRectといった, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ClearBackBuffer();

	// m_CharacterManagerに自分自身をバックバッファに描画させる.
	m_CharacterManager.Render();	// m_CharacterManager.Renderで全キャラクターを描画.

	// バックバッファの内容を画面へ転送.
	PresentBackBuffer();	// PresentBackBufferでバックバッファの内容を画面へ一括転送.(GetDC/BitBlt/ReleaseDCといった, どのデモでも共通の処理はCGraphicalApplication側に任せる.)

}
