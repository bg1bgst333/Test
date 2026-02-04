// ヘッダのインクルード
// 独自のヘッダ
#include "MultiViewItemsPanel.h"	// CMultiViewItemsPanel
#include "resource.h"

// コンストラクタCMultiViewItemsPanel
CMultiViewItemsPanel::CMultiViewItemsPanel() : CUserControl() {

	// メンバの初期化.
	m_vecMultiViewItemList.clear();	// m_vecMultiViewItemList.clearでクリア.
	m_nNextId = 0;	// m_nNextIdを0で初期化.

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

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CMultiViewItemsPanel::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItemsPanel"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiViewItemsPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CUserControl::Create(_T("CMultiViewItemsPanel"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウ破棄関数Destroy
BOOL CMultiViewItemsPanel::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// すべてのマルチビューアイテムを破棄.
	RemoveAll();

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// アイテムを末尾から追加する関数Add.
void CMultiViewItemsPanel::Add(LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance) {

	// マルチビューアイテムの追加.
	CMultiViewItem* pMultiViewItem = new CMultiViewItem();	// CMultiViewItemオブジェクトを生成し, ポインタをpMultiViewItemに格納.
	pMultiViewItem->Create(lpctszWindowName, WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, m_hWnd, (HMENU)(ID_MULTIVIEWITEM_START + m_nNextId), hInstance);	// pMultiViewItem->Createでアイテム作成.
	m_vecMultiViewItemList.push_back(pMultiViewItem);	// m_vecMultiViewItemList.push_backで末尾に追加.
	m_nNextId++;	// m_nNextIdをインクリメント.

}

// アイテムを末尾から削除する関数Remove.
void CMultiViewItemsPanel::Remove() {

	// マルチビューアイテムの削除.
	if (m_nNextId > 0) {	// 0より大きい時.
		CMultiViewItem* pMultiViewItem = m_vecMultiViewItemList[m_nNextId - 1];
		pMultiViewItem->Destroy();
		delete pMultiViewItem;
		m_vecMultiViewItemList.pop_back();
		m_nNextId--;
	}

}

// 全てのアイテムを削除する関数RemoveAll.
void CMultiViewItemsPanel::RemoveAll() {

	// すべてのマルチビューアイテムを破棄.
	size_t n = GetSize();
	for (size_t ui = 0; ui < n; ui++) {
		Remove();
	}

}

// アイテムの数を返す関数GetSize.
size_t CMultiViewItemsPanel::GetSize() {

	// アイテムの要素数を返す.
	return m_vecMultiViewItemList.size();	// m_vecMultiViewItemList.sizeで要素数を返す.

}

// アイテムを取得する関数Get.
CMultiViewItem* CMultiViewItemsPanel::Get(int iIndex) {

	// iIndex番目の要素を返す.
	if (GetSize() > 0) {
		return m_vecMultiViewItemList[iIndex];	// m_vecMultiViewItemList[iIndex]を返す.
	}
	else {
		return NULL;
	}

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

// 子から親へウィンドウサイズ変更の要求が発生した時.
void CMultiViewItemsPanel::OnSizeChild(WPARAM wParam, LPARAM lParam) {

	// 自身のRECT取得.
	RECT rc = { 0 };
	GetWindowRect(m_hWnd, &rc);

	// 取り出し.
	HWND hWndChild = (HWND)lParam;

	// 子ウィンドウ(CMultiViewItem)のRECTを取得.
	RECT rcChild = { 0 };
	GetWindowRect(hWndChild, &rcChild);

	// 子(CMultiViewItem)の右下を自身(CMultiViewItemsPanel)のクライアント座標に変換.
	POINT ptChildRB = { 0 };
	ptChildRB.x = rcChild.right;
	ptChildRB.y = rcChild.bottom;
	ScreenToClient(GetParent(hWndChild), &ptChildRB);

	// 親(CMultiView)のクライアント座標に変換.
	POINT pt = { 0 };
	pt.x = rc.left;
	pt.y = rc.top;
	ScreenToClient(GetParent(m_hWnd), &pt);

	// 自身のウィンドウサイズを変更.
	int w = rc.right - rc.left;
	int h = rc.bottom - rc.top;
	if (w < ptChildRB.x) {
		w = ptChildRB.x;
	}
	if (h < ptChildRB.y) {
		h = ptChildRB.y;
	}
	MoveWindow(pt.x, pt.y, w, h, TRUE);

}
