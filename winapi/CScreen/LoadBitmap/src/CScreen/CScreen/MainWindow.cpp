// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "FileDialog.h"	// CFileDialog
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

// ウィンドウクラス登録関数RegisterClass.(メニュー名, 色指定バージョン)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName, int i){

	// メニュー名はlpctszMenuName, 色はi.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName, i);	// CWindow::RegisterClassで, ウィンドウクラス名"CMainWindow", メニュー名lpctszMenuName, 色はiを登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow(){

	// メンバの初期化.
	m_pScreen = NULL;	// m_pScreenをNULLで初期化.

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

	// スクリーンの破棄.
	if (m_pScreen != NULL) {	// NULLでなければ.
		bRet = m_pScreen->Destroy();	// m_pScreen->Destroyでウィンドウを破棄.
		delete m_pScreen;	// deleteでm_pScreenを解放.
		m_pScreen = NULL;	// NULLをセット.
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

	// スクリーンコントロールのウィンドウ作成.
	m_pScreen = new CScreen();	// newでCScreenオブジェクトを作成し, ポインタm_pScreenに格納.
	m_pScreen->Create(_T("CScreen"), WS_BORDER, 0, 0, 400, 300, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでスクリーンコントロールのウィンドウ作成.

#if 0
	// キャンバス作成.
	m_pScreen->CreateCanvas(50, 50, 320, 240, (HMENU)(WM_APP + 2));
#endif

	// ハンドラ追加.
	AddCommandHandler(ID_ITEM_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileOpen);
	AddCommandHandler(ID_ITEM_FILE_SAVEAS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileSaveAs);

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_FILE_OPEN, 0);
	DeleteCommandHandler(ID_ITEM_FILE_SAVEAS, 0);

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// スクリーンのサイズをウィンドウ一杯に変更.
	if (m_pScreen != NULL){
		m_pScreen->MoveWindow(0, 0, cx, cy);
	}

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose(){

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CScreen"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
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
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Bitmap Files(*.bmp)|*.bmp|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK){
		if (m_pScreen != NULL){
			m_pScreen->LoadBitmap(dlg.GetOFN().lpstrFile);	// LoadBitmapでロード.
		}
	}

	// 0を返す.
	return 0;	// 処理したので0.

}

// 名前を付けて保存が選択された時.
int CMainWindow::OnFileSaveAs(WPARAM wParam, LPARAM lParam){

	// "名前を付けて保存"ダイアログ
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Bitmap Files(*.bmp)|*.bmp||"));
	INT_PTR ret = dlg.DoModal();	
	if (ret == IDOK){
		if (m_pScreen != NULL){
			m_pScreen->SaveBitmap(dlg.GetOFN().lpstrFile);	// SaveBitmapで保存.
		}
	}

	// 0を返す.
	return 0;	// 処理したので0.
	
}