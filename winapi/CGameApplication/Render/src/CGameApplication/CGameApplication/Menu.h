// 二重インクルード防止
#ifndef __MENU_H__
#define __MENU_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <map>			// std::map

// メニュークラスCMenuの定義
class CMenu {

	// publicメンバ
	public:

		// publicメンバ変数
		HMENU m_hMenu;	// メニューハンドルm_hMenu

		// staticメンバ変数
		static std::map<HMENU, CMenu*>m_mapMenuHandleMap;	// メニューハンドルをキー, CMenuオブジェクトポインタを値とするマップm_mapMenuHandleMap.

		// publicメンバ関数
		// コンストラクタ
		CMenu();	// コンストラクタCMenu

		// staticメンバ関数
		static CMenu* FromHandle(HMENU hMenu);	// 渡されたメニューハンドルを持つCMenuオブジェクトポインタを返す.
		static void DeleteMenuHandleMap();	// メニューハンドルマップの削除.

		// メンバ関数
		HMENU GetSubMenuHandle(int nPos);	// 指定位置のサブメニューハンドル取得.
		CMenu* GetSubMenu(int nPos);	// 指定位置のサブメニューオブジェクトポインタ取得.
		BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);	// アイテムの追加.
		BOOL LoadMenu(HINSTANCE hInstance, UINT nIDResource);	// メニューリソースのロード.
		BOOL CreateMenu();	// メニューの作成.
		BOOL CreatePopupMenu();	// ポップアップメニューの作成.
		BOOL DeleteMenu(UINT nPosition, UINT nFlags);	// アイテムの削除.
		UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);	// メニュー項目の有効化, 無効化.
		UINT GetMenuState(UINT nID, UINT nFlags);	// メニュー項目の状態取得.
		UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);	// メニュー項目のチェック.
		BOOL CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags);	// メニューラジオ項目のチェック.

};

#endif