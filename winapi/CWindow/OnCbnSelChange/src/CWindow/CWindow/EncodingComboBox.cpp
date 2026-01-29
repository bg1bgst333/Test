// ヘッダのインクルード
// 独自のヘッダ
#include "EncodingComboBox.h"

// ウィンドウのサイズが変更された時.
void CEncodingComboBox::OnSize(UINT nType, int cx, int cy){

	// 親ウィンドウの既定処理.
	CCustomControl::OnSize(nType, cx, cy);	// CCustomControl::OnSizeを呼ぶ.

	// ウィンドウサイズの取得.
	RECT rc = {0};
	GetWindowRect(m_hWnd, &rc);
	int iWidth = rc.right - rc.left;
	int iHeight = rc.bottom - rc.top;

	// UM_SIZECHILDを投げる.
	WPARAM wParam;
	wParam = MAKEWPARAM(iWidth, iHeight);
	SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

}