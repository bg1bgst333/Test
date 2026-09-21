// ヘッダのインクルード
// 独自のヘッダ
#include "Paint.h"	// CPaint

// 矩形塗りつぶし関数FillRect.
void CPaint::FillRect(HDC hDC, RECT rc, COLORREF crColor){

	// 指定色のブラシを作成.
	HBRUSH hBrush = CreateSolidBrush(crColor);	// CreateSolidBrushで指定色のブラシを作成.

	// 矩形を塗りつぶす.
	::FillRect(hDC, &rc, hBrush);	// ::FillRectでWinAPI側のFillRectを呼ぶ.(同名のためスコープ解決演算子で区別する.)

	// ブラシの後始末.
	DeleteObject(hBrush);	// DeleteObjectで使い終わったブラシを破棄.

}
