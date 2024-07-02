// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "Menu.h"	// CMenu

// メインウィンドウクラスCMainWindow
class CMainWindow : public CWindow{

	// publicメンバ
	public:

		// publicメンバ変数
		CMenu *m_pMainMenu;	// CMenuオブジェクトポインタm_pMainMenu.

		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName);	// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン)
		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainWindow();	// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL DestroyChildren();	// 子ウィンドウ破棄関数DestroyChildren
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.
		virtual int OnClose();	// ウィンドウが閉じられる時.
		int OnItem1_1(WPARAM wParam, LPARAM lParam);	// Item1-1が選択された時.
		int OnItem1_2(WPARAM wParam, LPARAM lParam);	// Item1-2が選択された時.
		int OnItem1_3(WPARAM wParam, LPARAM lParam);	// Item1-3が選択された時.
		int OnItem1_4(WPARAM wParam, LPARAM lParam);	// Item1-4が選択された時.
		int OnItem2_1(WPARAM wParam, LPARAM lParam);	// Item2-1が選択された時.

};

#endif