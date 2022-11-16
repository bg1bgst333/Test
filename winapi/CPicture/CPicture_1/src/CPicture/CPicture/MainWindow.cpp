// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
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
	m_pChild = NULL;	// m_pChildをNULLで初期化.
	m_pPicture = NULL;	// m_pPictureをNULLで初期化.
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
	if (m_pChild != NULL) {	// NULLでなければ.
		bRet = m_pChild->Destroy();	// m_pChild->Destroyでウィンドウを破棄.
		delete m_pChild;	// deleteでm_pChildを解放.
		m_pChild = NULL;	// NULLをセット.
	}

	// ピクチャーの破棄.
	if (m_pPicture != NULL) {	// NULLでなければ.
		bRet = m_pPicture->Destroy();	// m_pPicture->Destroyでウィンドウを破棄.
		delete m_pPicture;	// deleteでm_pPictureを解放.
		m_pPicture = NULL;	// NULLをセット.
	}

	// エディットコアの破棄.
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

	// 水平方向スクロールバーの初期化.
	SCROLLINFO scrHorz = { 0 };	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.nMin = 0;	// 最小値は0.
	scrHorz.nMax = 640 - 1;	// 最大値は639.
	scrHorz.nPage = 100;	// ページサイズは100.
	scrHorz.nPos = 0;	// 現在位置は0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// スクロール情報をセット.

	// 垂直方向スクロールバーの初期化.
	SCROLLINFO scrVert = { 0 };	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.nMin = 0;	// 最小値は0.
	scrVert.nMax = 480 - 1;	// 最大値は479.
	scrVert.nPage = 100;	// ページサイズは100.
	scrVert.nPos = 0;	// 現在位置は0.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット

	// 子ウィンドウの作成.
	m_pChild = new CWindow();	// CWindowオブジェクトm_pChild作成.
	RECT rc;	// RECT構造体rc.
	rc.left = 50;		// 左50
	rc.right = 150;		// 右150
	rc.top = 250;		// 上250
	rc.bottom = 350;	// 下350
	m_pChild->Create(_T("Child"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでウィンドウクラス"Child"のウィンドウ作成.	

	// 子ウィンドウの垂直方向スクロールバーの初期化.
	SCROLLINFO scrVertChild = { 0 };	// 垂直方向スクロール情報scrVertChildを{0}で初期化.
	scrVertChild.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVertChild.nMin = 0;	// 最小値は0.
	scrVertChild.nMax = 480 - 1;	// 最大値は479.
	scrVertChild.nPage = 100;	// ページサイズは100.
	scrVertChild.nPos = 0;	// 現在位置は0.
	scrVertChild.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_pChild->m_hWnd, SB_VERT, &scrVertChild, TRUE);	// スクロール情報をセット.

	// ピクチャーコントロールのウィンドウ作成.
	m_pPicture = new CPicture();	// newでCPictureオブジェクトを作成し, ポインタm_pPictureに格納.
	/*
	RECT rc2;	// RECT構造体rc2.
	rc2.left = 150;		// 左150
	rc2.right = 250;		// 右250
	rc2.top = 250;		// 上250
	rc2.bottom = 350;	// 下350
	*/
	//m_pPicture->Create(_T(""), WS_BORDER | WS_VSCROLL | SS_BITMAP, rc2, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Createでピクチャーコントロールのウィンドウ作成.
	m_pPicture->Create(_T("CPicutre"), WS_BORDER | WS_VSCROLL | SS_BITMAP, 150, 250, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Createでピクチャーコントロールのウィンドウ作成.

	// ピクチャーの垂直方向スクロールバーの初期化.
	SCROLLINFO scrVertPicture = { 0 };	// 垂直方向スクロール情報scrVertPictureを{0}で初期化.
	scrVertPicture.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVertPicture.nMin = 0;	// 最小値は0.
	scrVertPicture.nMax = 480 - 1;	// 最大値は479.
	scrVertPicture.nPage = 100;	// ページサイズは100.
	scrVertPicture.nPos = 0;	// 現在位置は0.
	scrVertPicture.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_pPicture->m_hWnd, SB_VERT, &scrVertPicture, TRUE);	// スクロール情報をセット.

	// エディットコアコントロールのウィンドウ作成.
	m_pEdit = new CEditCore();	// newでCEditCoreオブジェクトを作成し, ポインタをm_pEditに格納.
	RECT rc3;	// RECT構造体rc3.
	rc3.left = 250;		// 左250
	rc3.right = 350;		// 右350
	rc3.top = 250;		// 上250
	rc3.bottom = 350;	// 下350
	m_pEdit->Create(_T("Edit1"), WS_BORDER | WS_VSCROLL, rc3, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// Createでエディットコアコントロール"Edit1"のウィンドウ作成.

	// エディットコアの垂直方向スクロールバーの初期化.
	SCROLLINFO scrVertEdit = { 0 };	// 垂直方向スクロール情報scrVertEditを{0}で初期化.
	scrVertEdit.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVertEdit.nMin = 0;	// 最小値は0.
	scrVertEdit.nMax = 480 - 1;	// 最大値は479.
	scrVertEdit.nPage = 100;	// ページサイズは100.
	scrVertEdit.nPos = 0;	// 現在位置は0.
	scrVertEdit.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_pEdit->m_hWnd, SB_VERT, &scrVertEdit, TRUE);	// スクロール情報をセット.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウの描画を要求された時.
void CMainWindow::OnPaint() {

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 水平方向スクロールバー情報を取得.
	SCROLLINFO scrHorz = { 0 };	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.fMask = SIF_POS;	// 位置を取得.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfoでscrHorzを取得.

	// 垂直方向スクロールバー情報を取得.
	SCROLLINFO scrVert = { 0 };	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.fMask = SIF_POS;	// 位置を取得.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

	// 水平方向と垂直方向のスクロールバーの位置の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TCHAR tszPos[128] = { 0 };	// scrHorz.nPosとscrVert.nPosを文字列にしたものtszPos(長さ128)を{0}で初期化.
	_stprintf(tszPos, _T("scrHorz.nPos = %d, scrVert.nPos = %d"), scrHorz.nPos, scrVert.nPos);	// scrHorz.nPosとscrVert.nPosを文字列tszPosに変換.
	TextOut(hDC, 100, 100, tszPos, (int)_tcslen(tszPos));	// TextOutでtszPosを描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}

// ウィンドウが閉じられる時.
int CMainWindow::OnClose() {

	// メッセージボックスで"Close CMainWindow OK?"と表示.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CPicture"), MB_OKCANCEL);	// MessageBoxで"Close CMainWindow OK?"と表示し, 戻り値をiRetに格納.
	if (iRet != IDOK) {	// OK以外.(Cancelなど.)
		return -1;	// -1を返す.
	}

	// このウィンドウの破棄.(OnCloseの後, ウィンドウの破棄処理が勝手に行われるので, Destroyは不要なのでコメントアウト.)
	//Destroy();	// Destroyでこのウィンドウの破棄処理.

	// OKなので閉じる.
	return CWindow::OnClose();	// 親クラスのOnCloseを呼ぶ.(親クラスのOnCloseは常に閉じる処理になっている.)

}