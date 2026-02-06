// 二重インクルード防止
#ifndef __WINDOW_LIST_VIEW_H__
#define __WINDOW_LIST_VIEW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "MultiView.h"	// CMultiView

// ウィンドウリストビュークラスCWindowListView
class CWindowListView : public CMultiView {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindowListView();	// コンストラクタCWindowListView
		virtual ~CWindowListView();	// デストラクタ~CWindowListView
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground);	// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.

};

#endif