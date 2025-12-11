// ヘッダのインクルード
// 独自のヘッダ
#include "MultiViewItem.h"	// CMultiViewItem

// コンストラクタCMultiViewItem
CMultiViewItem::CMultiViewItem() : CUserControl() {

	// メンバの初期化.
	m_mapChildMap.clear();	// m_mapChildMapをクリア.

}

// デストラクタ~CMultiViewItem
CMultiViewItem::~CMultiViewItem() {

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMultiViewItem::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItem"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CMultiViewItem::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItem"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiViewItem::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CUserControl::Create(_T("CMultiViewItem"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウの破棄と終了処理関数Destroy.
BOOL CMultiViewItem::Destroy() {

	// アイテムの一斉削除.
	std::map<tstring, CWindow*>::iterator itor = m_mapChildMap.begin();	// イテレータitorをbegin()で初期化.
	while (itor != m_mapChildMap.end()) {	// end()まで.
		if (itor->second != NULL) {	// 値がNULLでなければ.
			itor->second->Destroy();	// Destroyで破棄処理.
			delete itor->second;	// 解放.
			itor->second = NULL;	// NULLをセット.
		}
		itor++;	// 進む.
	}
	m_mapChildMap.clear();	// クリア.

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CMultiViewItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMultiViewItem::OnDestroy() {

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMultiViewItem::OnSize(UINT nType, int cx, int cy) {

	// 親ウィンドウの既定処理.
	CUserControl::OnSize(nType, cx, cy);	// CUserControl::OnSizeを呼ぶ.

	// ウィンドウサイズの取得.
	RECT rc = { 0 };
	GetWindowRect(m_hWnd, &rc);
	int iWidth = rc.right - rc.left;
	int iHeight = rc.bottom - rc.top;

	// UM_SIZECHILDを投げる.
	WPARAM wParam;
	wParam = MAKEWPARAM(iWidth, iHeight);
	SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

}

// 子から親へウィンドウサイズ変更の要求が発生した時.
void CMultiViewItem::OnSizeChild(WPARAM wParam, LPARAM lParam) {

	// 自身のRECT取得.
	RECT rc = { 0 };
	GetWindowRect(m_hWnd, &rc);

	// 取り出し.
	HWND hWndChild = (HWND)lParam;

	// 子ウィンドウ(CCustomEdit)のRECTを取得.
	RECT rcChild = { 0 };
	GetWindowRect(hWndChild, &rcChild);

	// 子(CCustomEdit)の右下を自身(CMultiViewItem)のクライアント座標に変換.
	POINT ptChildRB = { 0 };
	ptChildRB.x = rcChild.right;
	ptChildRB.y = rcChild.bottom;
	ScreenToClient(GetParent(hWndChild), &ptChildRB);

	// 親(CMultiViewItemsPanel)のクライアント座標に変換.
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