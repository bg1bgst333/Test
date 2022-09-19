// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

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
	m_pEdit = NULL;	// m_pEditをNULLで初期化.

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

	// 子ウィンドウの破棄.
	if (m_pEdit != NULL) {	// NULLでなければ.
		bRet = m_pEdit->Destroy();	// m_pEdit->Destroyでウィンドウを破棄.
		delete m_pEdit;	// deleteでm_pEditを解放.
		m_pEdit = NULL;	// NULLをセット.
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

	// メニューハンドラの追加.
	AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnItem1_1);	// AddCommandHandlerでID_ITEM_1_1に対するハンドラCMainWindow::OnItem1_1を登録.
	
	// エディットコアコントロールオブジェクトの作成.
	m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.

	// エディットコアコントロール"Edit1"のウィンドウ作成.
	RECT rc;	// RECT構造体rc.
	rc.left = 50;		// 左50
	rc.right = 150;		// 右150
	rc.top = 50;		// 上50
	rc.bottom = 150;	// 下150
	m_pEdit->Create(_T("Edit1"), WS_BORDER, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでエディットコアコントロール"Edit1"のウィンドウ作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandlerでID_ITEM_1_1のハンドラを削除.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose(){

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CEditCore"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK){	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// Item1-1が選択された時.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam){

	// エディットコントロールのウィンドウテキストを変更する.
	m_pEdit->SetWindowText(_T("Renamed!"));	// CWindow::SetWindowTextで"Renamed!"に変更.

	// 0を返す.
	return 0;	// 処理したので0.

}