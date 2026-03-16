// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication(){

	// 初期化.
	m_x = 0;
	m_y = 0;
	m_vx = 1;
	m_vy = 1;

}

// メインループ処理関数MainProc.
void CGameApplication::MainProc(){

	// 入力処理
	Input();

	// ロジック処理
	Logic();

	// 描画処理
	Render();

}

// 入力処理関数Input.
void CGameApplication::Input(){
	
	// キー入力で描画位置を動かす.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){
		m_x -= 1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
		m_x += 1;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){
		m_y -= 1;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000){
		m_y += 1;
	}

}

// ロジック処理関数Logic.
void CGameApplication::Logic(){

	// クライアント領域のサイズ取得.
	RECT rc = {0};
	GetClientRect(m_pMainWnd->m_hWnd, &rc);

	// 速度の分進める.
	m_x += m_vx;
	m_y += m_vy;

	// 画面端で跳ねる.
	if (m_x < 0 || m_x > rc.right - rc.left - 50){
		m_vx = -m_vx;
	}
	if (m_y < 0 || m_y > rc.bottom - rc.top - 25){
		m_vy = -m_vy;
	}

}

// 描画処理関数Render.
void CGameApplication::Render(){

	// "ABCDE"を描画.
	HDC hDC = GetDC(m_pMainWnd->m_hWnd);
	TextOut(hDC, m_x, m_y, _T("ABCDE"), lstrlen(_T("ABCDE")));
	ReleaseDC(m_pMainWnd->m_hWnd, hDC);

}