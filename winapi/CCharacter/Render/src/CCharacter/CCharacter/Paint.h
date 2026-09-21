// 二重インクルード防止
#ifndef __PAINT_H__
#define __PAINT_H__

// ヘッダのインクルード
// 標準のヘッダ
#include <windows.h>	// 標準WindowsAPI

// 描画クラスCPaint
class CPaint{

	// publicメンバ
	public:

		// publicメンバ関数
		// static関数
		static void FillRect(HDC hDC, RECT rc, COLORREF crColor);	// 矩形塗りつぶし関数FillRect.(状態を持たない静的関数. 指定色でその場限りのブラシを作って塗り, 後始末まで行う.)

};

#endif
