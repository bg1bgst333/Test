// ヘッダのインクルード
// 独自のヘッダ
#include "Menu.h"	// CMenu

// コンストラクタCMenu
CMenu::CMenu(){

	// メンバの初期化
	m_hMenu = NULL;	// m_hMenuをNULLで初期化.

}

// 指定位置のサブメニューハンドル取得.
HMENU CMenu::GetSubMenuHandle(int nPos){

	// m_hMenuの位置nPosのサブメニューハンドルを返す.
	return GetSubMenu(m_hMenu, nPos);	// GetSubMenuの戻り値を返す.

}