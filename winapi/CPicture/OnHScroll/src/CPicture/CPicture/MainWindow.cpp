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
	m_pPicture = NULL;	// m_pPictureをNULLで初期化.
	m_pBitmap = NULL;	// m_pBitmapをNULLで初期化.

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

	// ピクチャーの破棄.
	if (m_pPicture != NULL) {	// NULLでなければ.
		bRet = m_pPicture->Destroy();	// m_pPicture->Destroyでウィンドウを破棄.
		delete m_pPicture;	// deleteでm_pPictureを解放.
		m_pPicture = NULL;	// NULLをセット.
	}

	// ビットマップオブジェクトの破棄.
	if (m_pBitmap != NULL) {	// NULLでない.
		delete m_pBitmap;	// deleteでm_pBitmapを破棄.
		m_pBitmap = NULL;	// m_pBitmapにNULLをセット.
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

	// ピクチャーコントロールのウィンドウ作成.
	m_pPicture = new CPicture();	// newでCPictureオブジェクトを作成し, ポインタm_pPictureに格納.
	m_pPicture->Create(_T("CPicture"), WS_BORDER | WS_HSCROLL, 50, 50, 400, 300, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Createでピクチャーコントロールのウィンドウ作成.

	// ビットマップオブジェクトの作成とロード.
	m_pBitmap = new CBitmap();	// newでCBitmapオブジェクトを作成し, ポインタをm_pBitmapに格納.
	m_pBitmap->LoadImage(lpCreateStruct->hInstance, _T("bitmap1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// CBitmap::LoadImageで"bitmap1.bmp"をロード.

	// ビットマップオブジェクトのビットマップをセット.
	m_pPicture->SetBitmap(*m_pBitmap);	// m_pPicture->SetBitmapで*m_pBitmapをセット.

	// クライアント領域のRECTを取得.
	RECT rc = { 0 };	// RECT型rcを{0}で初期化.
	GetClientRect(m_pPicture->m_hWnd, &rc);	// ピクチャーのクライアント領域のRECTを取得.

	// 水平方向スクロールバーの初期化.
	SCROLLINFO scrHorz = { 0 };	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.nMin = 0;	// 最小値は0.
	scrHorz.nMax = 640 - 1;	// 最大値は639.
	scrHorz.nPage = rc.right - rc.left;	// ページサイズはrc.right - rc.left.
	scrHorz.nPos = 0;	// 現在位置は0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_pPicture->m_hWnd, SB_HORZ, &scrHorz, TRUE);	// スクロール情報をセット.

	// 親クラスのOnCreateを呼ぶ.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}

// ウィンドウが破棄された時.
void CMainWindow::OnDestroy() {

	// CWindowのOnDestroyを呼ぶ.
	CWindow::OnDestroy();	// CWindow::OnDestroyを呼ぶ.

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