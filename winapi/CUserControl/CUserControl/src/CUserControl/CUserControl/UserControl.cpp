// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// コンストラクタCUserControl
CUserControl::CUserControl() : CWindow() {

}

// デストラクタ~CUserControl
CUserControl::~CUserControl() {

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CUserControl::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CWindow::RegisterClass(hInstance, _T("CUserControl"));	// CWindow::RegisterClassでウィンドウクラス名"CUserControl"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CUserControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CUserControl".
	return CWindow::Create(_T("CUserControl"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CUserControl"を指定.

}

// ウィンドウの作成が開始された時.
int CUserControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CUserControl::OnDestroy() {

	// ここでは何も呼ばない.

}