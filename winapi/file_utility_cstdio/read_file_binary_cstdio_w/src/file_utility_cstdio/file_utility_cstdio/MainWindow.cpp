// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
#include <string>	// std::string
#include <tchar.h>	// TCHAR型

// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow
extern "C" {	// C言語として解釈する.
	#include "file_utility_cstdio.h"	// ファイルユーティリティ(C標準入出力)
}

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
	m_pEdit = NULL;	// m_pEditをNULLで初期化.

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

	// メニューハンドラの追加.
	AddCommandHandler(ID_FILE_SAVE, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnFileSave);	// AddCommandHandlerでID_FILE_SAVEに対するハンドラCMainWindow::OnFileSaveを登録.
	AddCommandHandler(ID_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnFileOpen);	// AddCommandHandlerでID_FILE_OPENに対するハンドラCMainWindow::OnFileOpenを登録.

	// エディットコアコントロールオブジェクトの作成.
	m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.

	// エディットコアコントロールのウィンドウ作成.
	RECT rc;	// RECT構造体rc.
	rc.left = 50;		// 左50
	rc.right = 150;		// 右150
	rc.top = 50;		// 上50
	rc.bottom = 150;	// 下150
	m_pEdit->Create(_T(""), WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでエディットコアコントロールのウィンドウ作成.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// メニューハンドラの削除.
	DeleteCommandHandler(ID_FILE_SAVE, 0);	// DeleteCommandHandlerでID_FILE_SAVEのハンドラを削除.
	DeleteCommandHandler(ID_FILE_OPEN, 0);	// DeleteCommandHandlerでID_FILE_OPENのハンドラを削除.

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	/// エディットボックスのサイズをメインウィンドウのクライアント領域に合わせる.
	if (m_pEdit != NULL) {	// NULLでない場合.
		m_pEdit->MoveWindow(0, 0, cx, cy);	// m_pEdit->MoveWindowにcx, cyを指定.
	}

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("file_utility_cstdio"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}

// Saveが選択された時.
int CMainWindow::OnFileSave(WPARAM wParam, LPARAM lParam) {

	// エディットボックスのテキストを取得.
	std::wstring wstrEditText;	// std::wstringオブジェクトwstrEditTextを用意.
	m_pEdit->GetWindowText(wstrEditText);	// m_pEdit->GetWindowTextでテキスト取得.

	// ワイド文字列からマルチバイト文字列に変換が必要.
	int iBufLen = WideCharToMultiByte(CP_ACP, 0, wstrEditText.c_str(), -1, NULL, 0, NULL, NULL);	// まずは長さを取得.
	char* pszBuf = new char[iBufLen];	// iBufLenのchar型バッファを確保.
	WideCharToMultiByte(CP_ACP, 0, wstrEditText.c_str(), -1, pszBuf, iBufLen, NULL, NULL);	// 変換.

	// "test.txt"にファイル出力.
	write_file_binary_cstdio_w(L"test.txt", pszBuf, iBufLen - 1);	// write_file_binary_cstdio_wでpszBufを"test.txt"に出力.

	// メモリ解放.
	delete[] pszBuf;	// delete[]でpszBufの解放.

	// メッセージボックスを表示.
	MessageBox(NULL, _T("Save"), _T("file_utility_cstdio"), MB_OK);	// MessageBoxで"Save"と表示.

	// 0を返す.
	return 0;	// 処理したので0.

}

// Openが選択された時.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam) {

	// "test.txt"のサイズを取得.
	size_t file_size = get_file_size("test.txt");	// get_file_sizeで"test.txt"のサイズfile_sizeを取得.

	// バッファの確保.
	char* pszBuf = new char[file_size + 1];	// newで(file_size + 1)分のメモリ確保.

	// ファイル読み込み.
	size_t ret = read_file_binary_cstdio_w(L"test.txt", pszBuf, file_size + 1);	// read_file_binary_cstdio_wで読み込み.
	pszBuf[ret] = '\0';	// NULL終端する.

	// マルチバイト文字列からワイド文字列へ変換.
	int iBufLen = MultiByteToWideChar(CP_ACP, 0, pszBuf, -1, NULL, 0);	// まずは長さを取得.
	wchar_t* pwszBuf = new wchar_t[iBufLen];	// iBufLenのwchar_t型バッファを確保.
	MultiByteToWideChar(CP_ACP, 0, pszBuf, -1, pwszBuf, iBufLen);	// 変換.

	// エディットコントロールにセット.
	m_pEdit->SetWindowText(pwszBuf);	// m_pEdit->SetWindowTextでテキスト設定.

	// メモリ解放.
	delete[] pwszBuf;	// delete[]でpwszBufの解放.
	delete[] pszBuf;	// delete[]でpszBufの解放.	

	// 0を返す.
	return 0;	// 処理したので0.

}