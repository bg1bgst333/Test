// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
#include "FileDialog.h"	// CFileDialog
#include "resource.h"

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
	m_pMainMenu = NULL;
	m_pTextFile = NULL;

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

	// 暫定
	if (m_pTextFile != NULL) {	// m_pTextFileがNULLでなければ.
		delete m_pTextFile;	// deleteでm_pTextFileを解放.
		m_pTextFile = NULL;	// m_pTextFileにNULLをセット.
	}

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
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 親クラスのOnCreateを呼ぶ.
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値をiRetに格納.
	m_pMainMenu = GetMenu();	// CWindow::GetMenuでm_pMainMenu取得.
	if (m_pMainMenu == NULL) {	// メニューハンドルが無い場合は, m_pMainMenuがNULLになる.
		m_pMainMenu = new CMenu();
		BOOL bRet = m_pMainMenu->CreateMenu();
		if (bRet) {
			// サブメニュー1の作成.
			CMenu* pSubMenu1 = new CMenu();
			pSubMenu1->CreatePopupMenu();
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_1, _T("Item1-1(&A)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_2, _T("Item1-2(&B)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_3, _T("Item1-3(&C)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_4, _T("Item1-4(&D)"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu1->m_hMenu, _T("Item1"));
			// サブメニュー2の作成.
			CMenu* pSubMenu2 = new CMenu();
			pSubMenu2->CreatePopupMenu();
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_1, _T("Item2-1(&E)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_2, _T("Item2-2(&F)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_3, _T("Item2-3(&G)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_4, _T("Item2-4(&H)"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu2->m_hMenu, _T("Item2"));
			// サブメニュー3の作成.
			CMenu* pSubMenu3 = new CMenu();
			pSubMenu3->CreatePopupMenu();
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&I)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&J)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&K)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_4, _T("Item3-4(&L)"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu3->m_hMenu, _T("Item3"));
			SetMenu(m_pMainMenu);	// CWindow::SetMenuでm_pMainMenuをセット.
			DrawMenuBar();
			// メニューハンドラの追加.
			AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_1);	// AddCommandHandlerでID_ITEM_1_1に対するハンドラCMainWindow::OnItem1_1を登録.
			AddCommandHandler(ID_ITEM_1_2, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_2);	// AddCommandHandlerでID_ITEM_1_2に対するハンドラCMainWindow::OnItem1_2を登録.
			AddCommandHandler(ID_ITEM_1_3, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_3);	// AddCommandHandlerでID_ITEM_1_3に対するハンドラCMainWindow::OnItem1_3を登録.
			AddCommandHandler(ID_ITEM_1_4, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_4);	// AddCommandHandlerでID_ITEM_1_4に対するハンドラCMainWindow::OnItem1_4を登録.
			AddCommandHandler(ID_ITEM_2_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem2_1);	// AddCommandHandlerでID_ITEM_2_1に対するハンドラCMainWindow::OnItem2_1を登録.
			AddCommandHandler(ID_ITEM_2_2, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem2_2);	// AddCommandHandlerでID_ITEM_2_2に対するハンドラCMainWindow::OnItem2_2を登録.
			// エディットコアコントロールオブジェクトの作成.
			m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.
			// エディットコアコントロール"Edit1"のウィンドウ作成.
			RECT rc;	// RECT構造体rc.
			rc.left = 10;			// 左10
			rc.right = 10 + 320;	// 右10 + 320
			rc.top = 10;			// 上10
			rc.bottom = 10 + 240;	// 下10 + 240
			m_pEdit->Create(_T(""), WS_BORDER | WS_HSCROLL | WS_VSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでエディットコアコントロールのウィンドウ作成.
			// テキストファイルオブジェクトの作成.
			m_pTextFile = new CTextFile();
			m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOMはNONEとする.
			// Item1-1にラジオチェックを付ける.
			CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_1, MF_BYCOMMAND);
		}
	}
	return iRet;	// iRetを返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandlerでID_ITEM_1_1のハンドラを削除.
	DeleteCommandHandler(ID_ITEM_1_2, 0);	// DeleteCommandHandlerでID_ITEM_1_2のハンドラを削除.
	DeleteCommandHandler(ID_ITEM_1_3, 0);	// DeleteCommandHandlerでID_ITEM_1_3のハンドラを削除.
	DeleteCommandHandler(ID_ITEM_1_4, 0);	// DeleteCommandHandlerでID_ITEM_1_4のハンドラを削除.
	DeleteCommandHandler(ID_ITEM_2_1, 0);	// DeleteCommandHandlerでID_ITEM_2_1のハンドラを削除.
	DeleteCommandHandler(ID_ITEM_2_2, 0);	// DeleteCommandHandlerでID_ITEM_2_2のハンドラを削除.

	// メニューの終了処理.
	CMenu::DeleteMenuHandleMap();
	m_pMainMenu = NULL;

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	// エディットボックスのサイズをウィンドウ一杯に変更.
	if (m_pEdit != NULL) {
		m_pEdit->MoveWindow(0, 0, cx, cy);
	}

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CTextFile"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// タイミングによっては破棄が行われない可能性があるので, ここにも一応置いておく.
	if (m_pTextFile != NULL) {	// m_pTextFileがNULLでなければ.
		delete m_pTextFile;	// deleteでm_pTextFileを解放.
		m_pTextFile = NULL;	// m_pTextFileにNULLをセット.
	}

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// Item1-1が選択された時.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam) {

	// Item1-1にラジオチェックを付ける.
	CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_1, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOMはNONEとする.
	return 0;	// 処理したので0.

}

// Item1-2が選択された時.
int CMainWindow::OnItem1_2(WPARAM wParam, LPARAM lParam) {

	// Item1-2にラジオチェックを付ける.
	CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_2, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16LE;	// BOM_UTF16LEとする.
	return 0;	// 処理したので0.


}

// Item1-3が選択された時.
int CMainWindow::OnItem1_3(WPARAM wParam, LPARAM lParam) {

	return 0;	// 処理したので0.

}

// Item1-4が選択された時.
int CMainWindow::OnItem1_4(WPARAM wParam, LPARAM lParam) {

	return 0;	// 処理したので0.

}

// Item2-1が選択された時.
int CMainWindow::OnItem2_1(WPARAM wParam, LPARAM lParam) {

	// "開く"ダイアログ
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK) {
		MessageBox(m_hWnd, _T("IDOK"), _T("CTextFile"), MB_OK);
		MessageBox(m_hWnd, dlg.GetOFN().lpstrFile, _T("CTextFile"), MB_OK);
	}
	else {
		MessageBox(m_hWnd, _T("IDCANCEL"), _T("CTextFile"), MB_OK);
	}

	// 0を返す.
	return 0;	// 処理したので0.

}

// Item2-2が選択された時.
int CMainWindow::OnItem2_2(WPARAM wParam, LPARAM lParam) {

	// "名前を付けて保存"ダイアログ
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK) {
		tstring tstrText;
		m_pEdit->GetWindowText(tstrText);	// m_pEditから取得.
		m_pTextFile->SetText(tstrText);	// tstrTextをm_pTextFileにセット.
		m_pTextFile->Write(dlg.GetOFN().lpstrFile);	// UTF-16LEバイト列に変換し, バッファにセットし, dlg.GetOFN().lpstrFileに書き込み.
	}

	// 0を返す.
	return 0;	// 処理したので0.


}