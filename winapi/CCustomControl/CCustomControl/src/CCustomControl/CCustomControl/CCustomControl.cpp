// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// コンストラクタCCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// デストラクタ~CCustomControl
CCustomControl::~CCustomControl() {

}

// ウィンドウ作成関数Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名にはlpctszClassNameを指定.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名lpctszClassNameを指定.

}

// ウィンドウ破棄関数Destroy
BOOL CCustomControl::Destroy() {

	// 親クラスのDestroyを呼ぶ.
	return CWindow::Destroy();	// CWindow::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CCustomControl::OnDestroy() {

	// ここでは何も呼ばない.

}