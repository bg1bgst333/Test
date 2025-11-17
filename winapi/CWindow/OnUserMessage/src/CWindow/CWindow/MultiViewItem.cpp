// ヘッダのインクルード
// 独自のヘッダ
#include "MultiViewItem.h"	// CMultiViewItem

// コンストラクタCMultiViewItem
CMultiViewItem::CMultiViewItem() : CUserControl(){

}

// デストラクタ~CMultiViewItem
CMultiViewItem::~CMultiViewItem(){

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMultiViewItem::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItem"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CMultiViewItem::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground){

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	return CUserControl::RegisterClass(hInstance, _T("CMultiViewItem"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiViewItem::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	return CUserControl::Create(_T("CMultiViewItem"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウの作成が開始された時.
int CMultiViewItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMultiViewItem::OnDestroy(){

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMultiViewItem::OnSize(UINT nType, int cx, int cy){

}

// ユーザ定義メッセージが発生した時.
void CMultiViewItem::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam){

	// 自身のRECT取得.
	RECT rc = {0};
	GetWindowRect(m_hWnd, &rc);

	// サイズ取り出し.
	int iWidth = LOWORD(wParam);
	int iHeight = HIWORD(wParam);

	// 親のクライアント座標に変換.
	POINT pt = {0};
	pt.x = rc.left;
	pt.y = rc.top;
	ScreenToClient(GetParent(m_hWnd), &pt);

	// 自身のウィンドウサイズを変更.
	MoveWindow(pt.x, pt.y, iWidth, iHeight, TRUE);

}