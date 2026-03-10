// ヘッダのインクルード
// 独自のヘッダ
#include "GameApplication.h"	// CGameApplication

// コンストラクタCGameApplication
CGameApplication::CGameApplication() : CGraphicalApplication() {

}

// メインループ処理関数MainProc.
void CGameApplication::MainProc() {

	// "ABCDE"を描画.
	HDC hDC = GetDC(m_pMainWnd->m_hWnd);
	TextOut(hDC, 50, 50, _T("ABCDE"), lstrlen(_T("ABCDE")));
	ReleaseDC(m_pMainWnd->m_hWnd, hDC);

}