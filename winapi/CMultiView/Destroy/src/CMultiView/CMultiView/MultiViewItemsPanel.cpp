// ヘッダのインクルード
// 独自のヘッダ
#include "MultiViewItemsPanel.h"	// CMultiViewItemsPanel

// コンストラクタCMultiViewItemsPanel
CMultiViewItemsPanel::CMultiViewItemsPanel() : CUserControl() {

}

// デストラクタ~CMultiViewItemsPanel
CMultiViewItemsPanel::~CMultiViewItemsPanel() {

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMultiViewItemsPanel::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItemsPanel"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiViewItemsPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CUserControl::Create(_T("CMultiViewItemsPanel"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウの作成が開始された時.
int CMultiViewItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMultiViewItemsPanel::OnDestroy() {

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMultiViewItemsPanel::OnSize(UINT nType, int cx, int cy) {

}