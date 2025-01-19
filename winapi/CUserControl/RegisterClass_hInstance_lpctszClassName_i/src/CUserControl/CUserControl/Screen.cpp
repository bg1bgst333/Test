// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Screen.h"	// CScreen

// コンストラクタCScreen
CScreen::CScreen() : CUserControl(){

}

// デストラクタ~CScreen
CScreen::~CScreen(){

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"));	// CUserControl::RegisterClassでウィンドウクラス名"CScreen"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CScreen::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は"CScreen".
	return CUserControl::Create(_T("CScreen"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CScreen"を指定.
	
}

// ウィンドウ破棄関数Destroy
BOOL CScreen::Destroy(){

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}