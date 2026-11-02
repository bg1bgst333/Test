// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "KeyboardInput.h"	// CKeyboardInput
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	m_CharacterManagerA.m_pGraphicalApplication = this;	// m_CharacterManagerA.m_pGraphicalApplicationに自分自身(CMainApplication)をセット.
	m_CharacterManagerB.m_pGraphicalApplication = this;	// m_CharacterManagerB.m_pGraphicalApplicationにも同様にセット.

	// 背景色の指定.(既定の白ではなく, SetBackgroundColorの効果が分かるよう水色にする.)
	SetBackgroundColor(RGB(200, 220, 255));	// SetBackgroundColorで背景色を水色に変更.

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.(左右2組を並べて見せるため, 既定サイズではなく幅1000・高さ400を明示的に指定する.)
	if (!pMainWnd->CreateEx(0, _T("CCharacterManager"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 400, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// バックバッファの作成.
	CreateBackBuffer();	// CreateBackBufferでバックバッファを作成.

	// 両方のキャラクター管理オブジェクトのスプライト画像をロードする.(どちらもLoad自体は行う. 違いはこのあとRenderを呼ぶかどうかだけ.)
	if (!m_CharacterManagerA.Load(hInstance)){	// m_CharacterManagerA.Loadで画像をロードし, 失敗した場合.

		// エラー処理
		MessageBox(m_pMainWnd->m_hWnd, _T("CCharacterManager::Load failed! (A)"), _T("CCharacterManager"), MB_OK | MB_ICONHAND);	// MessageBoxでエラーメッセージを表示.
		return FALSE;	// returnでFALSEを返して異常終了.

	}
	if (!m_CharacterManagerB.Load(hInstance)){	// m_CharacterManagerB.Loadで画像をロードし, 失敗した場合.

		// エラー処理
		MessageBox(m_pMainWnd->m_hWnd, _T("CCharacterManager::Load failed! (B)"), _T("CCharacterManager"), MB_OK | MB_ICONHAND);	// MessageBoxでエラーメッセージを表示.
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// m_CharacterManagerBだけ, 右側に表示されるようX座標をまとめてずらす.(m_CharacterManagerAと重ならないようにするため. CCharacterManager::Load自体にオフセット機能は無いので, ロード後にここで直接ずらす.)
	for (int i = 0; i < CHARACTER_COUNT; i++) {	// iを0からCHARACTER_COUNT-1まで回す.

		m_CharacterManagerB.m_Characters[i].m_x += 500;	// m_xに500を足して右側へずらす.
		m_CharacterManagerB.m_Characters[i].m_fPosX = (FLOAT)m_CharacterManagerB.m_Characters[i].m_x;	// アキュムレータm_fPosXもm_xに合わせておく.

	}

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 描画処理関数Render.
void CMainApplication::Render(){

	// バックバッファのクリア.(前フレームの描画を消す. GetClientRect/FillRectといった, どのデモでも共通の処理はCGraphicalApplication側に任せる.)
	ClearBackBuffer();

	// m_CharacterManagerAのRenderはあえて呼ばない.(Loadはしてあるが描画はされない, という対比を見せるため.)

	// m_CharacterManagerBだけ, CCharacterManager::Renderでまとめて描画させる.
	m_CharacterManagerB.Render();	// m_CharacterManagerB.Renderで全キャラクターをバックバッファへ描画.

	// バックバッファの内容を画面へ転送.
	PresentBackBuffer();	// PresentBackBufferでバックバッファの内容を画面へ一括転送.(GetDC/BitBlt/ReleaseDCといった, どのデモでも共通の処理はCGraphicalApplication側に任せる.)

}
