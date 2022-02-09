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

	// メンバの初期化.
	m_pUserControl = NULL;	// m_pUserControlをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	if (m_hWnd != NULL) {	// m_hWndがNULLでない時.
		// 子ウィンドウの破棄.
		if (m_pUserControl != NULL) {	// m_pUserControlがNULLでない.
			DestroyWindow(m_pUserControl->m_hWnd);	// DestroyWindowでm_pUserControl->m_hWndを破棄.
			delete m_pUserControl;	// deleteでm_pUserControlを解放.
			m_pUserControl = NULL;	// m_pUserControlにNULLをセット.
		}
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
	MessageBox(hwnd, _T("CMainWindow::OnCreate"), _T("CUserControl"), MB_OK);	// MessageBoxで"CMainWindow::OnCreate"と表示.

	// ユーザコントロールオブジェクトの作成.
	m_pUserControl = new CUserControl();	// newでCUserControlオブジェクトを作成し, ポインタをm_pUserControlに格納.

	// ウィンドウクラス名"UC1"のユーザコントロールのウィンドウ作成.
	m_pUserControl->Create(_T("UC1"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでウィンドウクラス名"UC1"のCUserControlウィンドウを作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// 子ウィンドウの破棄.
	if (m_pUserControl != NULL) {	// m_pUserControlがNULLでない.
		DestroyWindow(m_pUserControl->m_hWnd);	// DestroyWindowでm_pUserControl->m_hWndを破棄.
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// m_pUserControlにNULLをセット.
	}

	// メッセージボックスで"CMainWindow::OnDestroy"と表示.
	MessageBox(m_hWnd, _T("CMainWindow::OnDestroy"), _T("CUserControl"), MB_OK);	// MessageBoxで"CMainWindow::OnDestroy"と表示.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}