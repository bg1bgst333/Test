// 二重インクルード防止
#ifndef __MULTI_VIEW_H__
#define __MULTI_VIEW_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "MultiViewItemsPanel.h"	// CMultiViewItemsPanel

// マルチビューコントロールクラスCMultiView
class CMultiView : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		CMultiViewItemsPanel* m_pMultiViewItemsPanel;	// CMultiViewItemsPanelオブジェクトポインタm_pMultiViewItemsPanel.
		SCROLLINFO m_ScrollInfo;	// スクロール情報m_ScrollInfo.
		int m_iHScrollPos;	// スクロールバーの水平方向の位置m_iHScrollPos
		int m_iVScrollPos;	// スクロールバーの垂直方向の位置m_iVScrollPos
		// staticメンバ変数
		static HBRUSH s_hBrush;	// このウィンドウクラスの背景ブラシs_hBrush.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMultiView();	// コンストラクタCMultiView
		virtual ~CMultiView();	// デストラクタ~CMultiView
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground);	// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual void Add(LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance);	// アイテムを末尾から追加する関数Add.
		virtual void Remove();	// アイテムを末尾から削除する関数Remove.
		virtual size_t GetSize();	// アイテムの数を返す関数GetSize.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.
		virtual int OnEraseBkgnd();	// 背景消去を要求された時.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// 水平方向スクロールバーイベント時.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// 垂直方向スクロールバーイベント時.

};

#endif
