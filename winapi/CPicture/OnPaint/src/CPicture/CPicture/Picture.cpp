// ヘッダのインクルード
// 独自のヘッダ
#include "Picture.h"	// CPicture

// ウィンドウの描画を要求された時.
void CPicture::OnPaint() {

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 文字列の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TextOut(hDC, 0, 0, _T("CPicture"), (int)_tcslen(_T("CPicture")));	// Win32APIのTextOutで"CPicture"と描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}