// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Canvas.h"	// CCanvas

// コンストラクタCCanvas
CCanvas::CCanvas() : CUserControl() {

}

// デストラクタ~CCanvas
CCanvas::~CCanvas() {

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"));	// CUserControl::RegisterClassでウィンドウクラス名"CCanvas"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CCanvas::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CCanvas".
	return CUserControl::Create(_T("CCanvas"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CCanvas"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CCanvas::Destroy() {

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}