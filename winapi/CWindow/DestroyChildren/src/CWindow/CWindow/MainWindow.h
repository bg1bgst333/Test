// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// メインウィンドウクラスCMainWindow
class CMainWindow : public CWindow {

	// publicメンバ
	public:

		// メンバ変数
		CUserControl* m_pUserControl;	// CUserControlオブジェクトポインタm_pUserControl.

		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL DestroyChildren();	// 子ウィンドウ破棄関数DestroyChildren
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual int OnClose();	// ウィンドウが閉じられる時.

};

#endif