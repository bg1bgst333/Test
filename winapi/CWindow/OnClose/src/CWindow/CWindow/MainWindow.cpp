// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClassでウィンドウクラス名"CMainWindow"を登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() {

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	if (m_hWnd != NULL) {	// m_hWndがNULLでない時.
		DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
		m_hWnd = NULL;	// m_hWndにNULLをセット.
	}

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メッセージボックスで"CMainWindow::OnCreate"と表示.
	MessageBox(hwnd, _T("CMainWindow::OnCreate"), _T("CWindow"), MB_OK);	// MessageBoxで"CMainWindow::OnCreate"と表示.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// メッセージボックスで"CMainWindow::OnDestroy"と表示.
	MessageBox(m_hWnd, _T("CMainWindow::OnDestroy"), _T("CWindow"), MB_OK);	// MessageBoxで"CMainWindow::OnDestroy"と表示.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CWindow"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}