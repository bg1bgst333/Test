// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListView.h"	// CWindowListView
#include "resource.h"

// コンストラクタCWindowListView
CWindowListView::CWindowListView() : CMultiView() {

	// メンバ変数の初期化.
	m_pMultiViewItemsPanel = NULL;	// m_pMultiViewItemsPanelをNULLで初期化.
	m_iHScrollPos = 0;	// m_iHScrollPosを0で初期化.
	m_iVScrollPos = 0;	// m_iVScrollPosを0で初期化.

}

// デストラクタ~CWindowListView
CWindowListView::~CWindowListView() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWindowListView::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CWindowListView"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CWindowListView::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	s_hBrush = hbrBackground;	// 背景ブラシハンドルをスタティック変数にセット.
	return CUserControl::RegisterClass(hInstance, _T("CWindowListView"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CWindowListView::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.(WS_CLIPCHILDRENで子ウィンドウ部分を再描画しなくなる.)
	return CUserControl::Create(_T("CWindowListView"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウ破棄関数Destroy
BOOL CWindowListView::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// マルチビューアイテムズパネルの破棄.
	if (m_pMultiViewItemsPanel != NULL) {
		bRet = m_pMultiViewItemsPanel->Destroy();
		delete m_pMultiViewItemsPanel;
		m_pMultiViewItemsPanel = NULL;
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// マルチビューアイテムズパネルの作成.
	m_pMultiViewItemsPanel = new CMultiViewItemsPanel();

	// マルチビューアイテムズパネルのウィンドウ生成.
	RECT rc = { 0 };
	GetClientRect(hwnd, &rc);
	m_pMultiViewItemsPanel->Create(_T(""), 0, 0, 0, rc.right - rc.left, rc.bottom - rc.top, hwnd, (HMENU)IDC_MULTIVIEWITEMSPANEL, lpCreateStruct->hInstance);	// m_pMultiViewItemsPanel->Createでウィンドウ生成.

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWindowListView::OnDestroy() {

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}
