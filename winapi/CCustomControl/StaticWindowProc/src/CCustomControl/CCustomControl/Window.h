// 二重インクルード防止
#ifndef __WINDOW_H__
#define __WINDOW_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <map>			// std::map
// 独自のヘッダ
#include "HandlerConditions.h"	// 構造体HandlerConditions

// ウィンドウクラスCWindowの定義
class CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		HWND m_hWnd;	// HWND型ウィンドウハンドルm_hWnd.
		// staticメンバ変数
		static std::map<HWND, CWindow *> m_mapWindowMap;	// ウィンドウハンドルをキー, CWindowオブジェクトポインタを値とするマップm_mapWindowMap.
		static std::map<DWORD, HandlerConditions*>m_mapHandlerMap;	// DWORD値をキー, HandlerConditions構造体ポインタを値とするマップm_mapHandlerMap.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindow();	// コンストラクタCWindow()
		virtual ~CWindow();	// デストラクタ~CWindow()
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpctszMenuName);	// ウィンドウクラス登録関数RegisterClass(メニュー名指定バージョン)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// スタティックウィンドウプロシージャStaticWindowProc.
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL DestroyChildren();	// 子ウィンドウ破棄関数DestroyChildren
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow.
		virtual void AddCommandHandler(UINT nID, UINT nCode, int(CWindow::* handler)(WPARAM wParam, LPARAM lParam));	// コマンドハンドラの追加.
		virtual void DeleteCommandHandler(UINT nID, UINT nCode);	// コマンドハンドラの削除.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイナミックウィンドウプロシージャDynamicWindowProc
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual int OnClose();	// ウィンドウが閉じられる時.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンドが発生した時.

};

#endif