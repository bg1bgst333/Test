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
		BOOL bRet = DestroyMenu(hMenu);
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

// メニューリソースのロード.
BOOL CMenu::LoadMenu(HINSTANCE hInstance, UINT nIDResource) {

	// ロードしてからメニューハンドルマップに登録.
	HMENU hNew = ::LoadMenu(hInstance, MAKEINTRESOURCE(nIDResource));
	if (hNew != NULL) {	// ロード成功.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// 古いのが登録済み.
			if (this == itor->second) {	// 同じはず.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// 登録されてない.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// メニューの作成.
BOOL CMenu::CreateMenu() {

	// 作成してからメニューハンドルマップに登録.
	HMENU hNew = ::CreateMenu();
	if (hNew != NULL) {	// 作成成功.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// 古いのが登録済み.
			if (this == itor->second) {	// 同じはず.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// 登録されてない.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// ポップアップメニューの作成.
BOOL CMenu::CreatePopupMenu() {

	// 作成してからメニューハンドルマップに登録.
	HMENU hNew = ::CreatePopupMenu();
	if (hNew != NULL) {	// 作成成功.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// 古いのが登録済み.
			if (this == itor->second) {	// 同じはず.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// 登録されてない.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// アイテムの削除.
BOOL CMenu::DeleteMenu(UINT nPosition, UINT nFlags) {

	// 指定のアイテム削除.
	return ::DeleteMenu(m_hMenu, nPosition, nFlags);

}

// メニュー項目の有効化, 無効化.
UINT CMenu::EnableMenuItem(UINT nIDEnableItem, UINT nEnable) {

	// 指定の状態にする.
	return ::EnableMenuItem(m_hMenu, nIDEnableItem, nEnable);

}

// メニュー項目の状態取得.
UINT CMenu::GetMenuState(UINT nID, UINT nFlags) {

	// 状態取得.
	return ::GetMenuState(m_hMenu, nID, nFlags);

}

// メニュー項目のチェック.
UINT CMenu::CheckMenuItem(UINT nIDCheckItem, UINT nCheck) {

	// チェック.
	return ::CheckMenuItem(m_hMenu, nIDCheckItem, nCheck);

}

// メニューラジオ項目のチェック.
BOOL CMenu::CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags) {

	// ラジオチェック.
	return ::CheckMenuRadioItem(m_hMenu, nIDFirst, nIDLast, nIDItem, nFlags);

}