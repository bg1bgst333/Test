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

// コンストラクタCMainWindow()
CMainWindow::CMainWindow(){

	// メンバの初期化.
	m_pMainMenu = NULL;
	m_pTextFile = NULL;

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow(){

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

	// 暫定
	if (m_pTextFile != NULL){	// m_pTextFileがNULLでなければ.
		delete m_pTextFile;	// deleteでm_pTextFileを解放.
		m_pTextFile = NULL;	// m_pTextFileにNULLをセット.
	}

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

	// 親クラスのOnCreateを呼ぶ.
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値をiRetに格納.
	m_pMainMenu = GetMenu();	// CWindow::GetMenuでm_pMainMenu取得.
	if (m_pMainMenu == NULL){	// メニューハンドルが無い場合は, m_pMainMenuがNULLになる.
		m_pMainMenu = new CMenu();
		BOOL bRet = m_pMainMenu->CreateMenu();
		if (bRet){
			// サブメニュー1の作成.
			CMenu *pSubMenu1 = new CMenu();
			pSubMenu1->CreatePopupMenu();
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_NONE, _T("BOMなし"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF16LE, _T("UTF-16LE BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF16BE, _T("UTF-16BE BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF8, _T("UTF-8 BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_SHIFTJIS, _T("Shift_JIS"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF16LE, _T("UTF-16LE"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF16BE, _T("UTF-16BE"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF8, _T("UTF-8"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_EUCJP, _T("EUC-JP"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_JIS, _T("JIS"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_CRLF, _T("CRLF"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_LF, _T("LF"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_CR, _T("CR"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu1->m_hMenu, _T("Item1"));
			// サブメニュー2の作成.
			CMenu *pSubMenu2 = new CMenu();
			pSubMenu2->CreatePopupMenu();
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_FILE_OPEN, _T("開く"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_FILE_SAVEAS, _T("名前を付けて保存"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu2->m_hMenu, _T("Item2"));
			// サブメニュー3の作成.
			CMenu *pSubMenu3 = new CMenu();
			pSubMenu3->CreatePopupMenu();
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&L)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&M)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&N)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_4, _T("Item3-4(&O)"));
			// メインメニューに追加.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu3->m_hMenu, _T("Item3"));
			SetMenu(m_pMainMenu);	// CWindow::SetMenuでm_pMainMenuをセット.
			DrawMenuBar();
			// メニューハンドラの追加.
			AddCommandHandler(ID_ITEM_BOM_NONE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomNone);
			AddCommandHandler(ID_ITEM_BOM_UTF16LE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf16LE);
			AddCommandHandler(ID_ITEM_BOM_UTF16BE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf16BE);
			AddCommandHandler(ID_ITEM_BOM_UTF8, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf8);
			AddCommandHandler(ID_ITEM_ENCODE_SHIFTJIS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeShiftJis);
			AddCommandHandler(ID_ITEM_ENCODE_UTF16LE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf16LE);
			AddCommandHandler(ID_ITEM_ENCODE_UTF16BE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf16BE);
			AddCommandHandler(ID_ITEM_ENCODE_UTF8, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf8);
			AddCommandHandler(ID_ITEM_ENCODE_EUCJP, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeEucJp);
			AddCommandHandler(ID_ITEM_ENCODE_JIS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeJis);
			AddCommandHandler(ID_ITEM_NEW_LINE_CRLF, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineCRLF);
			AddCommandHandler(ID_ITEM_NEW_LINE_LF, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineLF);
			AddCommandHandler(ID_ITEM_NEW_LINE_CR, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineCR);
			AddCommandHandler(ID_ITEM_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileOpen);
			AddCommandHandler(ID_ITEM_FILE_SAVEAS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileSaveAs);
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
			CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
			m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOMはNONEとする.
			// Item1-3にラジオチェックを付ける.
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
			m_pTextFile->m_Encoding = CTextFile::ENCODING_SHIFT_JIS;	// Shift_JISとする.
			// Item1-5にラジオチェックを付ける.
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
			m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CRLF;	// CRLFとする.
		}
	}
	return iRet;	// iRetを返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_ITEM_BOM_NONE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF16LE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF16BE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF8, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_SHIFTJIS, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF16LE, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF16BE, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF8, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_EUCJP, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_JIS, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_CRLF, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_LF, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_CR, 0);
	DeleteCommandHandler(ID_ITEM_FILE_OPEN, 0);
	DeleteCommandHandler(ID_ITEM_FILE_SAVEAS, 0);

	// メニューの終了処理.
	CMenu::DeleteMenuHandleMap();
	m_pMainMenu = NULL;

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// エディットボックスのサイズをウィンドウ一杯に変更.
	if (m_pEdit != NULL){
		m_pEdit->MoveWindow(0, 0, cx, cy);
	}

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose(){

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CTextFile"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK){	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// タイミングによっては破棄が行われない可能性があるので, ここにも一応置いておく.
	if (m_pTextFile != NULL){	// m_pTextFileがNULLでなければ.
		delete m_pTextFile;	// deleteでm_pTextFileを解放.
		m_pTextFile = NULL;	// m_pTextFileにNULLをセット.
	}

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// BOMなしが選択された時.
int CMainWindow::OnBomNone(WPARAM wParam, LPARAM lParam){

	// BOMなしにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOMはNONEとする.
	return 0;	// 処理したので0.

}

// UTF-16LE BOMが選択された時.
int CMainWindow::OnBomUtf16LE(WPARAM wParam, LPARAM lParam){

	// UTF-16LE BOMにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16LE;	// BOM_UTF16LEとする.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16LE;	// UTF-16LEとする.
	return 0;	// 処理したので0.

}

// UTF-16BE BOMが選択された時.
int CMainWindow::OnBomUtf16BE(WPARAM wParam, LPARAM lParam){

	// UTF-16BE BOMにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16BE;	// BOM_UTF16BEとする.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16BE;	// UTF-16BEとする.
	return 0;	// 処理したので0.

}

// UTF-8 BOMが選択された時.
int CMainWindow::OnBomUtf8(WPARAM wParam, LPARAM lParam){

	// UTF-8 BOMにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF8;	// BOM_UTF8とする.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_8;	// UTF-8とする.
	return 0;	// 処理したので0.

}

// Shift_JISが選択された時.
int CMainWindow::OnEncodeShiftJis(WPARAM wParam, LPARAM lParam){

	// Shift_JISにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_SHIFT_JIS;	// Shift_JISとする.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOMはNONEとする.
	return 0;	// 処理したので0.

}

// UTF-16LE選択された時.
int CMainWindow::OnEncodeUtf16LE(WPARAM wParam, LPARAM lParam){

	// UTF-16LEにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16LE;	// UTF-16LEとする.
	return 0;	// 処理したので0.

}

// UTF-16BEが選択された時.
int CMainWindow::OnEncodeUtf16BE(WPARAM wParam, LPARAM lParam){

	// UTF-16BEにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16BE;	// UTF-16BEとする.
	return 0;	// 処理したので0.


}

// UTF-8が選択された時.
int CMainWindow::OnEncodeUtf8(WPARAM wParam, LPARAM lParam){

	// UTF-8にラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_8;	// UTF-8とする.
	return 0;	// 処理したので0.

}

// EUC-JPが選択された時.
int CMainWindow::OnEncodeEucJp(WPARAM wParam, LPARAM lParam){

	// EUC-JPにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_EUCJP, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_EUC_JP;	// EUC-JPとする.
	return 0;	// 処理したので0.

}

// JISが選択された時.
int CMainWindow::OnEncodeJis(WPARAM wParam, LPARAM lParam){

	// JISにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_JIS, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_JIS;	// JISとする.
	return 0;	// 処理したので0.

}

// CRLFが選択された時.
int CMainWindow::OnNewLineCRLF(WPARAM wParam, LPARAM lParam){

	// CRLFにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CRLF;	// CRLFとする.
	return 0;	// 処理したので0.

}

// LFが選択された時.
int CMainWindow::OnNewLineLF(WPARAM wParam, LPARAM lParam){

	// LFにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_LF, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_LF;	// LFとする.
	return 0;	// 処理したので0.

}

// CRが選択された時.
int CMainWindow::OnNewLineCR(WPARAM wParam, LPARAM lParam){

	// CRにラジオチェックを付ける.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CR, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CR;	// CRとする.
	return 0;	// 処理したので0.

}

// 開くが選択された時.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam){

	// "開く"ダイアログ
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK){
		BOOL bRet = m_pTextFile->Read(dlg.GetOFN().lpstrFile);	// 指定されたファイルを読み込み, 読み込んだバイト列を文字コード変換し, テキストとして持つ.
		if (bRet){	// 成功.
			// メニューラジオチェックの変更.
			CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			// BOM.
			if (m_pTextFile->m_Bom == CTextFile::BOM_UTF16LE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16LE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Bom == CTextFile::BOM_UTF16BE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16BE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Bom == CTextFile::BOM_UTF8){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF8, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
			}
			// 文字コード.
			if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_16LE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_16BE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_8){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_SHIFT_JIS){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_EUCJP, MF_BYCOMMAND);
			}
			// 改行コード.
			if (m_pTextFile->m_NewLine == CTextFile::NEW_LINE_CR){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CR, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_NewLine == CTextFile::NEW_LINE_LF){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_LF, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
			}
			m_pEdit->SetWindowText(m_pTextFile->m_tstrText.c_str());	// m_tstrTextをm_pEditにセット.
		}
	}

	// 0を返す.
	return 0;	// 処理したので0.

}

// 名前を付けて保存が選択された時.
int CMainWindow::OnFileSaveAs(WPARAM wParam, LPARAM lParam){

	// "名前を付けて保存"ダイアログ
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();	
	if (ret == IDOK){
		tstring tstrText;
		m_pEdit->GetWindowText(tstrText);	// m_pEditから取得.
		m_pTextFile->SetText(tstrText);	// tstrTextをm_pTextFileにセット.
		m_pTextFile->Write(dlg.GetOFN().lpstrFile);	// UTF-16LEバイト列に変換し, バッファにセットし, dlg.GetOFN().lpstrFileに書き込み.
	}

	// 0を返す.
	return 0;	// 処理したので0.
	
}