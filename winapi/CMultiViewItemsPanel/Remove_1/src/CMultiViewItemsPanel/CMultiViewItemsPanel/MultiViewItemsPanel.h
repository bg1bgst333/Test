// 二重インクルード防止
#ifndef __MULTI_VIEW_ITEMS_PANEL_H__
#define __MULTI_VIEW_ITEMS_PANEL_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <vector>	// std::vector
#include <map>		// std::map
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "MultiViewItem.h"

// マルチビューアイテムズパネルクラスCMultiViewItemsPanel
class CMultiViewItemsPanel : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		std::vector<CMultiViewItem*> m_vecMultiViewItemList;	// マルチビューアイテムリストm_vecMultiViewItemList.
		std::map<tstring, CMultiViewItem*>m_mapMultiViewItemMap;	// マルチビューアイテムマップm_mapMultiViewItemMap.
		int m_nNextId;	// マルチビューアイテムの次期払い出しリソースID m_nNextId.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMultiViewItemsPanel();	// コンストラクタCMultiViewItemsPanel
		virtual ~CMultiViewItemsPanel();	// デストラクタ~CMultiViewItemsPanel
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground);	// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual void Add(LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance);	// アイテムを末尾から追加する関数Add.
		virtual BOOL Add(const tstring& tstrKey, LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance);	// アイテムを末尾から追加する関数Add.
		virtual BOOL Insert(int iIndex, const tstring& tstrKey, LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance);	// アイテムを挿入する関数Insert.
		virtual BOOL Remove();	// アイテムを末尾から削除する関数Remove.
		virtual BOOL Delete(int iIndex);	// アイテムを削除する関数Delete.
		virtual void RemoveAll();	// 全てのアイテムを削除する関数RemoveAll.
		virtual size_t GetSize();	// アイテムの数を返す関数GetSize.
		virtual CMultiViewItem* Get(int iIndex);	// アイテムを取得する関数Get.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnDestroy();	// ウィンドウが破棄された時.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// 子から親へウィンドウサイズ変更の要求が発生した時.

};

#endif