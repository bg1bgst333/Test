// 二重インクルード防止
#ifndef __CUSTOM_CONTROL_H__
#define __CUSTOM_CONTROL_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <string>	// std::string
// 独自のヘッダ
#include "Window.h"	// CWindow

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// カスタムコントロールクラスCCustomControl
class CCustomControl : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		// staticメンバ変数
		static std::map<tstring, WNDPROC> m_mapBaseWindowProcMap;	// 既定のウィンドウクラス名をキー, 既定のウィンドウプロシージャを値とするマップm_mapBaseWindowProcMap.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CCustomControl();	// コンストラクタCCustomControl
		virtual ~CCustomControl();	// デストラクタ~CCustomControl
		// staticメンバ関数
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// スタティックウィンドウプロシージャStaticWindowProc.
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ダイナミックウィンドウプロシージャDynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.

};

#endif