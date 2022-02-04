// 二重インクルード防止
#ifndef __USER_CONTROL_H__
#define __USER_CONTROL_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// ユーザコントロールクラスCUserControl
class CUserControl : public CWindow{

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CUserControl();	// コンストラクタCUserControl
		virtual ~CUserControl();	// デストラクタ~CUserControl
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.

};

#endif