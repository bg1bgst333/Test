// 二重インクルード防止
#ifndef __CUSTOM_CONTROL_H__
#define __CUSTOM_CONTROL_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// カスタムコントロールクラスCCustomControl
class CCustomControl : public CWindow {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CCustomControl();	// コンストラクタCCustomControl
		virtual ~CCustomControl();	// デストラクタ~CCustomControl

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.

};

#endif