// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
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
	m_pButton = NULL;	// m_pButtonをNULLで初期化.
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
	if (m_pButton != NULL) {	// NULLでなければ.
		bRet = m_pButton->Destroy();	// m_pButton->Destroyでウィンドウを破棄.
		delete m_pButton;	// deleteでm_pButtonを解放.
		m_pButton = NULL;	// NULLをセット.
	}

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
	
	// ボタンコアコントロールオブジェクトの作成.
	m_pButton = new CButtonCore();	// newでCButtonCoreオブジェクトを作成し, ポインタをm_pButtonに格納.

	// ボタンコアコントロール"Button1"のウィンドウ作成.
	m_pButton->Create(_T("Button1"), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでボタンコアコントロール"Button1"のウィンドウ作成.

	// ボタンハンドラの追加.
	AddCommandHandler(WM_APP + 1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBnClicked1);	// AddCommandHandlerでWM_APP + 1のBN_CLICKEDに対するハンドラCMainWindow::OnBnClicked1を登録.

	// エディットコアコントロールオブジェクトの作成.
	m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.

	// エディットコアコントロール"Edit1"のウィンドウ作成.
	m_pEdit->Create(_T("Edit1"), WS_BORDER, 50, 200, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Createでエディットコアコントロール"Edit1"のウィンドウ作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandlerでID_ITEM_1_1のハンドラを削除.

	// ボタンハンドラの削除.
	DeleteCommandHandler(WM_APP + 1, BN_CLICKED);	// DeleteCommandHandlerでWM_APP + 1のBN_CLICKEDに対するハンドラを削除.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose(){

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CWindow"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
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

	// m_pEditのテキストを取得.
	int iEditLen = m_pEdit->GetWindowTextLength();	// CWindow::GetWindowTextLengthでm_pEditのテキストの長さを取得.
	TCHAR *ptszBuf = new TCHAR[iEditLen + 1];	// TCHARバッファptszBuf(長さiEditLen + 1)を確保.
	ZeroMemory(ptszBuf, sizeof(TCHAR) * (iEditLen + 1));	// ptszBufの初期化.
	m_pEdit->GetWindowText(ptszBuf, iEditLen + 1);	// CWindow::GetWindowTextでm_pEditのテキストを取得.
	MessageBox(NULL, ptszBuf, _T("CWindow"), MB_OK);	// MessageBoxでptszBufを表示.
	delete [] ptszBuf;	// delete[]でptszBufを解放.

	// 0を返す.
	return 0;	// 処理したので0.

}

// Button1がクリックされた時.
int CMainWindow::OnBnClicked1(WPARAM wParam, LPARAM lParam){

	// ボタンのテキストを"Clicked!"に変更.
	m_pButton->SetWindowText(_T("Clicked!"));	// CWindow::SetWindowTextで"Clicked!"をセット.

	// 0を返す.
	return 0;	// 処理したので0.

}