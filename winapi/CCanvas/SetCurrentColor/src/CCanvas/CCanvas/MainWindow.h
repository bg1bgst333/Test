// 二重インクルード防止
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow
#include "Screen.h"	// CScreen

// メインウィンドウクラスCMainWindow
class CMainWindow : public CWindow {

	// publicメンバ
	public:

		// 列挙型の定義
		// 現在の色
		typedef enum TAG_CURRENT_COLOR {
			CURRENT_COLOR_BLACK,
			CURRENT_COLOR_WHITE,
			CURRENT_COLOR_RED,
			CURRENT_COLOR_GREEN,
			CURRENT_COLOR_BLUE
		} CURRENT_COLOR;

		// メンバ変数
		CScreen* m_pScreen;	// CScreenオブジェクトポインタm_pScreen.
		HINSTANCE m_hInstance;	// インスタンスハンドルm_hInstance
		CURRENT_COLOR m_CurrentColor;	// 現在の色.

		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName);	// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName, int i);	// ウィンドウクラス登録関数RegisterClass.(メニュー名, 色指定バージョン)
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
		int OnFileOpen(WPARAM wParam, LPARAM lParam);	// 開くが選択された時.
		int OnFileSaveAs(WPARAM wParam, LPARAM lParam);	// 名前を付けて保存が選択された時.
		int OnCurrentColorBlack(WPARAM wParam, LPARAM lParam);	// 黒が選択された時.
		int OnCurrentColorWhite(WPARAM wParam, LPARAM lParam);	// 白が選択された時.
		int OnCurrentColorRed(WPARAM wParam, LPARAM lParam);	// 赤が選択された時.
		int OnCurrentColorGreen(WPARAM wParam, LPARAM lParam);	// 緑が選択された時.
		int OnCurrentColorBlue(WPARAM wParam, LPARAM lParam);	// 青が選択された時.

};

#endif