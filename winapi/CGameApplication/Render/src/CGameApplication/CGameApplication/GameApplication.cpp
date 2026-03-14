// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// 初期化.
	m_x = 0;
	m_y = 0;

}

// メインループ処理関数MainProc.
void CGameApplication::MainProc(){

	// 入力処理
	Input();

	// 描画処理
	Render();

}

// 入力処理関数Input.
void CGameApplication::Input(){
	
	// キー入力で描画位置を動かす.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){
		m_x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
		m_x += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){
		m_y -= 2;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000){
		m_y += 2;
	}

}

// 描画処理関数Render.
void CGameApplication::Render(){

	// "ABCDE"を描画.
	HDC hDC = GetDC(m_pMainWnd->m_hWnd);
	TextOut(hDC, m_x, m_y, _T("ABCDE"), lstrlen(_T("ABCDE")));
	ReleaseDC(m_pMainWnd->m_hWnd, hDC);

}