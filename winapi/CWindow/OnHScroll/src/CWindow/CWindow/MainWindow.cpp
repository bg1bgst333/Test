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

	// 破棄したらTRUEを返す.
	if (bRet) {	// TRUEなら.
		return TRUE;	// TRUEを返す.
	}

	// 破棄しなければ, CWindowのDestroyChildrenを返す.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildrenを返す.

}

// ウィンドウの作成が開始された時.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 水平方向スクロールバーの初期化.
	SCROLLINFO scrHorz = {0};	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.nMin = 0;	// 最小値は0.
	scrHorz.nMax = 640 - 1;	// 最大値は639.
	scrHorz.nPage = 100;	// ページサイズは100.
	scrHorz.nPos = 0;	// 現在位置は0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// スクロール情報をセット.

	// 垂直方向スクロールバーの初期化.
	SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.nMin = 0;	// 最小値は0.
	scrVert.nMax = 480 - 1;	// 最大値は479.
	scrVert.nPage = 100;	// ページサイズは100.
	scrVert.nPos = 0;	// 現在位置は0.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy(){

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

}

// ウィンドウの描画を要求された時.
void CMainWindow::OnPaint(){

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 水平方向スクロールバー情報を取得.
	SCROLLINFO scrHorz = {0};	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.fMask = SIF_POS;	// 位置を取得.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfoでscrHorzを取得.

	// 垂直方向スクロールバー情報を取得.
	SCROLLINFO scrVert = {0};	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.fMask = SIF_POS;	// 位置を取得.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

	// 水平方向と垂直方向のスクロールバーの位置の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TCHAR tszPos[128] = {0};	// scrHorz.nPosとscrVert.nPosを文字列にしたものtszPos(長さ128)を{0}で初期化.
	_stprintf(tszPos, _T("scrHorz.nPos = %d, scrVert.nPos = %d"), scrHorz.nPos, scrVert.nPos);	// scrHorz.nPosとscrVert.nPosを文字列tszPosに変換.
	TextOut(hDC, 100, 100, tszPos, (int)_tcslen(tszPos));	// TextOutでtszPosを描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

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