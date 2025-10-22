// ヘッダのインクルード
// 独自のヘッダ
#include "MultiView.h"	// CMultiView
#include "resource.h"

// コンストラクタCMultiView
CMultiView::CMultiView() : CUserControl() {

	// メンバ変数の初期化.
	m_pMultiViewItemsPanel = NULL;	// m_pMultiViewItemsPanelをNULLで初期化.

}

// デストラクタ~CMultiView
CMultiView::~CMultiView() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMultiView::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CMultiView::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiView::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CUserControl::Create(_T("CMultiView"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウ破棄関数Destroy
BOOL CMultiView::Destroy() {

	// マルチビューアイテムズパネルの破棄.
	if (m_pMultiViewItemsPanel != NULL) {
		m_pMultiViewItemsPanel->Destroy();
		delete m_pMultiViewItemsPanel;
		m_pMultiViewItemsPanel = NULL;
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// マルチビューアイテムズパネルの作成.
	m_pMultiViewItemsPanel = new CMultiViewItemsPanel();

	// マルチビューアイテムズパネルのウィンドウ生成.
	m_pMultiViewItemsPanel->Create(_T(""), 0, 10, 10, 320, 240, hwnd, (HMENU)IDC_MULTIVIEWITEMSPANEL, lpCreateStruct->hInstance);	// m_pMultiViewItemsPanel->Createでウィンドウ生成.

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMultiView::OnDestroy() {

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMultiView::OnSize(UINT nType, int cx, int cy) {

}