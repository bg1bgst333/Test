// 二重インクルード防止
#ifndef __SCREEN_H__
#define __SCREEN_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "Canvas.h"	// CCanvas

// スクリーンクラスCScreen
class CScreen : public CUserControl {

	// publicメンバ
	public:

		// メンバ変数
		CCanvas *m_pCanvas;	// CCanvasオブジェクトポインタm_pCanvas.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScreen();	// コンストラクタCScreen
		virtual ~CScreen();	// デストラクタ~CScreen
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		static BOOL RegisterClass(HINSTANCE hInstance, int i);	// ウィンドウクラス登録関数RegisterClass(背景色指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL DestroyChildren();	// 子ウィンドウ破棄関数DestroyChildren
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.

};

#endif