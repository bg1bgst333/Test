// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication() {

}

// メインループ処理関数MainProc.
void CGameApplication::MainProc(){

	// キー入力で描画位置を動かす.
	static int x;
	static int y;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){
		x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000){
		x += 2;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){
		y -= 2;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000){
		y += 2;
	}

	// "ABCDE"を描画.
	HDC hDC = GetDC(m_pMainWnd->m_hWnd);
	TextOut(hDC, x, y, _T("ABCDE"), lstrlen(_T("ABCDE")));
	ReleaseDC(m_pMainWnd->m_hWnd, hDC);

}