// 二重インクルード防止
#ifndef __STATIC_CORE_H__
#define __STATIC_CORE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// スタティックコアコントロールクラスCStaticCore
class CStaticCore : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(RECTバージョン).

};

#endif