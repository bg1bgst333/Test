// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClassでウィンドウクラス名"CMainWindow"を登録.

}

// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName) {

	// メニュー名はlpctszMenuName.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName);	// CWindow::RegisterClassで, ウィンドウクラス名"CMainWindow", メニュー名lpctszMenuNameを登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() {
	
	// メンバの初期化.
	m_pUserControl = NULL;	// m_pUserControlをNULLで初期化.
	m_pCustomControl1 = NULL;	// m_pCustomControl1をNULLで初期化.
	m_pCustomControl2 = NULL;	// m_pCustomControl2をNULLで初期化.

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

	/// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// DestroyChildrenを分けたので, 自身のウィンドウ破棄は問題ない.
	// まず子ウィンドウの破棄.
	DestroyChildren();

	// 自身のウィンドウ破棄.
	bRet = CWindow::Destroy();	// 戻り値をbRetに格納.

	// bRetを返す.
	return bRet;

}

// 子ウィンドウ破棄関数DestroyChildren
BOOL CMainWindow::DestroyChildren() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// 子ウィンドウの破棄.
	if (m_pUserControl != NULL) {	// NULLでなければ.
		bRet = m_pUserControl->Destroy();	// m_pUserControl->Destroyでウィンドウを破棄.
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// NULLをセット.
	}

	// 子ウィンドウの破棄.
	if (m_pCustomControl1 != NULL) {	// NULLでなければ.
		bRet = m_pCustomControl1->Destroy();	// m_pCustomControl1->Destroyでウィンドウを破棄.
		delete m_pCustomControl1;	// deleteでm_pCustomControl1を解放.
		m_pCustomControl1 = NULL;	// NULLをセット.
	}

	// 子ウィンドウの破棄.
	if (m_pCustomControl2 != NULL) {	// NULLでなければ.
		bRet = m_pCustomControl2->Destroy();	// m_pCustomControl2->Destroyでウィンドウを破棄.
		delete m_pCustomControl2;	// deleteでm_pCustomControl2を解放.
		m_pCustomControl2 = NULL;	// NULLをセット.
	}

	// 破棄したらTRUEを返す.
	if (bRet) {	// TRUEなら.
		return TRUE;	// TRUEを返す.
	}

	// 破棄しなければ, CWindowのDestroyChildrenを返す.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildrenを返す.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// メニューハンドラの追加.
	AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_1);	// AddCommandHandlerでID_ITEM_1_1に対するハンドラCMainWindow::OnItem1_1を登録.

	// ユーザコントロールオブジェクトの作成.
	m_pUserControl = new CUserControl();	// newでCUserControlオブジェクトを作成し, ポインタをm_pUserControlに格納.

	// ウィンドウクラス名"UC1"のユーザコントロールのウィンドウ作成.
	m_pUserControl->Create(_T("UC1"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでウィンドウクラス名"UC1"のCUserControlウィンドウを作成.

	// カスタムコントロールオブジェクト(ボタン)の作成.
	m_pCustomControl1 = new CCustomControl();	// newでCCustomControlオブジェクトを作成し, ポインタをm_pCustomControl1に格納.

	// ウィンドウクラス名"Button"のカスタムコントロール"Button1"のウィンドウ作成.
	m_pCustomControl1->Create(_T("Button"), _T("Button1"), WS_BORDER | BS_PUSHBUTTON, 50, 200, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Createでウィンドウクラス名"Button"のCCustomControlウィンドウ"Button1"作成.

	// カスタムコントロールオブジェクト(エディット)の作成.
	m_pCustomControl2 = new CCustomControl();	// newでCCustomControlオブジェクトを作成し, ポインタをm_pCustomControl2に格納.

	// ウィンドウクラス名"Edit"のカスタムコントロール"Edit1"のウィンドウ作成.
	m_pCustomControl2->Create(_T("Edit"), _T("Edit1"), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 350, 100, 100, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// Createでウィンドウクラス名"Edit"のCCustomControlウィンドウ"Edit1"作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandlerでID_ITEM_1_1のハンドラを削除.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CCustomControl"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// Item1-1が選択された時.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam) {

	// メッセージボックスを表示.
	MessageBox(NULL, _T("Item1-1"), _T("CCustomControl"), MB_OK);	// MessageBoxで"Item1-1"と表示.

	// 0を返す.
	return 0;	// 処理したので0.

}