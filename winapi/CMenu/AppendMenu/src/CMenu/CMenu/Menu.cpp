// ヘッダのインクルード
// 独自のヘッダ
#include "Menu.h"	// CMenu

// staticメンバ変数の定義.
std::map<HMENU, CMenu*> CMenu::m_mapMenuHandleMap;	// メニューハンドルマップm_mapMenuHandleMap.

// コンストラクタCMenu
CMenu::CMenu() {

	// メンバの初期化
	m_hMenu = NULL;	// m_hMenuをNULLで初期化.

}

// 渡されたメニューハンドルを持つCMenuオブジェクトポインタを返す.
CMenu* CMenu::FromHandle(HMENU hMenu) {

	// hMenuでポインタ引けたら返す, 無かったらオブジェクト生成し, ハンドルをセットして, マップに登録.
	if (CMenu::m_mapMenuHandleMap.find(hMenu) != CMenu::m_mapMenuHandleMap.end()) {
		return CMenu::m_mapMenuHandleMap[hMenu];
	}
	else {
		CMenu* pMenu = new CMenu();
		pMenu->m_hMenu = hMenu;
		CMenu::m_mapMenuHandleMap[hMenu] = pMenu;
		return pMenu;
	}

}

// メニューハンドルマップの削除.
void CMenu::DeleteMenuHandleMap() {

	// メニューハンドルマップの全削除.
	std::map<HMENU, CMenu*>::iterator itor = m_mapMenuHandleMap.begin();
	while (itor != m_mapMenuHandleMap.end()) {
		HMENU hMenu = itor->first;
		CMenu* pMenu = itor->second;
		DestroyMenu(hMenu);
		delete pMenu;
		itor++;
	}
	m_mapMenuHandleMap.clear();

}

// 指定位置のサブメニューハンドル取得.
HMENU CMenu::GetSubMenuHandle(int nPos) {

	// m_hMenuの位置nPosのサブメニューハンドルを返す.
	return ::GetSubMenu(m_hMenu, nPos);	// GetSubMenuの戻り値を返す.

}

// 指定位置のサブメニューオブジェクトポインタ取得.
CMenu* CMenu::GetSubMenu(int nPos) {

	// ハンドル取得して, そこからポインタ取得.
	HMENU hMenu = GetSubMenuHandle(nPos);
	return FromHandle(hMenu);

}

// アイテムの追加.
BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem) {

	// 指定位置にアイテム追加.
	return ::AppendMenu(m_hMenu, nFlags, nIDNewItem, lpszNewItem);

}