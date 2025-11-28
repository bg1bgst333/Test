// 二重インクルード防止
#ifndef __CUSTOM_EDIT_H__
#define __CUSTOM_EDIT_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "EditCore.h"	// CEditCore

// カスタムエディットコントロールクラスCCustomEdit
class CCustomEdit : public CEditCore{

	// publicメンバ
	public:

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.

};

#endif