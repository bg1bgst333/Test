// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <stdio.h>	// C標準入出力
#include <commctrl.h>	// コモンコントロール
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "FileDialog.h"	// CFileDialog
#include "CustomEdit.h"	// CCustomEdit
#include "resource.h"

// ウィンドウクラス登録関数RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClassでウィンドウクラス名"CMainWindow"を登録.

}

// ウィンドウクラス登録関数RegisterClass.(メニュー名指定バージョン)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName){

	// メニュー名はlpctszMenuName.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName);	// CWindow::RegisterClassで, ウィンドウクラス名"CMainWindow", メニュー名lpctszMenuNameを登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow(){

	// メンバの初期化.
	m_hInstance = NULL;
	m_pMainMenu = NULL;
	m_pMultiView = NULL;
	m_pWindow2 = NULL;

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow(){

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウ作成関数CreateEx.
BOOL CMainWindow::CreateEx(DWORD dwExStyle, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::CreateEx(dwExStyle, _T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::CreateExにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CMainWindow::Destroy(){

	// 変数の初期化.
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
BOOL CMainWindow::DestroyChildren(){

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// マルチビューアイテム内のウィンドウの破棄.
	if (m_pWindow2 != NULL){
		m_pWindow2->Destroy();
		delete m_pWindow2;
		m_pWindow2 = NULL;
	}

	// メンバの終了処理.
	if (m_pMultiView != NULL){
		bRet = m_pMultiView->Destroy();
		delete m_pMultiView;
		m_pMultiView = NULL;
	}

	// 破棄したらTRUEを返す.
	if (bRet) {	// TRUEなら.
		return TRUE;	// TRUEを返す.
	}

	// 破棄しなければ, CWindowのDestroyChildrenを返す.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildrenを返す.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 親クラスのOnCreateを呼ぶ.
	m_hInstance = lpCreateStruct->hInstance;
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値をiRetに格納.
	m_pMainMenu = GetMenu();	// CWindow::GetMenuでm_pMainMenu取得.
	if (m_pMainMenu == NULL){	// メニューハンドルが無い場合は, m_pMainMenuがNULLになる.
		m_pMainMenu = new CMenu();
		BOOL bRet = m_pMainMenu->LoadMenu(lpCreateStruct->hInstance, IDM_MAINMENU);
		if (bRet){
			SetMenu(m_pMainMenu);
			AddCommandHandler(ID_ITEM_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileOpen);
			// CMultiViewの生成.
			m_pMultiView = new CMultiView();
			m_pMultiView->Create(_T(""), 0, 0, 0, 640, 480, hwnd, (HMENU)IDC_MULTIVIEW, m_hInstance);
			// アイテムの追加.
			m_pMultiView->Add(_T("Item1"), 20, 20, 160, 120, m_hInstance);
			m_pMultiView->Add(_T("Item2"), 200, 20, 160, 120, m_hInstance);
			m_pMultiView->Add(_T("Item3"), 470, 350, 160, 120, m_hInstance);
			// マルチビューアイテムの取得.
			CMultiViewItem *pItem2 = m_pMultiView->Get(2);
			// マルチビューアイテム内にウィンドウを配置.
			CCustomEdit *pCustomEdit = new CCustomEdit();
			m_pWindow2 = pCustomEdit;
			pCustomEdit->Create(_T("Item2-CustomEdit"), WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10, 10, 140, 140, pItem2->m_hWnd, (HMENU)WM_APP + 200, m_hInstance);
		}
	}
	return iRet;	// iRetを返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_FILE_OPEN, 0);

	// メニューの終了処理.
	CMenu::DeleteMenuHandleMap();
	m_pMainMenu = NULL;

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// マルチビューをメインウィンドウのクライアント領域サイズにリサイズ.
	if (m_pMultiView != NULL){
		m_pMultiView->MoveWindow(0, 0, cx, cy);
	}

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose(){

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CMultiViewItemsPanel"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK){	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// 開くが選択された時.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam){

	// "開く"ダイアログ
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK){
		MessageBox(m_hWnd, dlg.GetOFN().lpstrFile, _T("CMultiViewItemsPanel"), MB_OK);
	}

	// 0を返す.
	return 0;	// 処理したので0.

}