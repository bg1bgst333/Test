// 二重インクルード防止
#ifndef __MENU_H__
#define __MENU_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI

// メニュークラスCMenuの定義
class CMenu {

	// publicメンバ
	public:

		// publicメンバ変数
		HMENU m_hMenu;	// メニューハンドルm_hMenu

		// publicメンバ関数
		// コンストラクタ
		CMenu();	// コンストラクタCMenu
		// メンバ関数
		HMENU GetSubMenuHandle(int nPos);	// 指定位置のサブメニューハンドル取得.

};

#endif