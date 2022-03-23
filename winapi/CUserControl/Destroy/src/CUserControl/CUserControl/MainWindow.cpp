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
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CMainWindow::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// 子ウィンドウの破棄.
	if (m_pUserControl != NULL) {	// NULLでなければ.
		bRet = m_pUserControl->Destroy();	// m_pUserControl->Destroyでウィンドウを破棄.
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// NULLをセット.
	}

	// 自身のウィンドウも破棄.(OnCloseの前にOnDestroyが呼ばれるのはおかしいのでコメントアウト.)
	//return CWindow::Destroy();	// CWindow::Destroyを呼ぶ.
	MessageBox(m_hWnd, _T("CMainWindow::Destroy"), _T("CUserControl"), MB_OK);	// MessageBoxで"CMainWindow::Destroy"と表示.
	return bRet;	// bRetを返す.

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

	// メッセージボックスで"CMainWindow::OnDestroy"と表示.
	MessageBox(m_hWnd, _T("CMainWindow::OnDestroy"), _T("CUserControl"), MB_OK);	// MessageBoxで"CMainWindow::OnDestroy"と表示.


	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CUserControl"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.
	Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}