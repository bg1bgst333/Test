// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Screen.h"	// CScreen

// コンストラクタCScreen
CScreen::CScreen() : CUserControl() {

	// メンバの初期化.
	m_pCanvas = NULL;	// m_pCanvasをNULLで初期化.
	m_pDIBSection = NULL;

}

// デストラクタ~CScreen
CScreen::~CScreen() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"));	// CUserControl::RegisterClassでウィンドウクラス名"CScreen"を登録.

}

// ウィンドウクラス登録関数RegisterClass(背景色指定バージョン.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance, int i) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"), i);	// CUserControl::RegisterClassでウィンドウクラス名"CScreen"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CScreen::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CScreen".
	return CUserControl::Create(_T("CScreen"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CScreen"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CScreen::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// 子ウィンドウの破棄.
	DestroyChildren();

	// 自身の破棄.
	bRet = CUserControl::Destroy();
	return bRet;

}

// 子ウィンドウ破棄関数DestroyChildren
BOOL CScreen::DestroyChildren() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// DIBSectionの破棄.
	if (m_pDIBSection != NULL) {	// NULLでなければ.
		delete m_pDIBSection;	// deleteでm_pDIBSectionを解放.
		m_pDIBSection = NULL;	// NULLをセット.
	}

	// キャンバスの破棄.
	if (m_pCanvas != NULL) {	// NULLでなければ.
		bRet = m_pCanvas->Destroy();	// m_pCanvas->Destroyでウィンドウを破棄.
		delete m_pCanvas;	// deleteでm_pCanvasを解放.
		m_pCanvas = NULL;	// NULLをセット.
	}

	// 破棄したらTRUEを返す.
	if (bRet) {	// TRUEなら.
		return TRUE;	// TRUEを返す.
	}

	// 破棄しなければ, CWindowのDestroyChildrenを返す.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildrenを返す.

}

// キャンバス作成関数CreateCanvas.
const CCanvas* CScreen::CreateCanvas(int x, int y, int iWidth, int iHeight, HMENU hMenu) {

	// キャンバスコントロールのウィンドウ作成.
	m_pCanvas = new CCanvas();	// newでCCanvasオブジェクトを作成し, ポインタm_pCanvasに格納.
	m_pCanvas->Create(_T("CCanvas"), 0, x, y, iWidth, iHeight, m_hWnd, (HMENU)(WM_APP + 2), m_hInstance);	// Createでキャンバスコントロールのウィンドウ作成.

	// DIBセクションの作成.
	m_pDIBSection = new CDIBSection();
	m_pDIBSection->CreateDIBSection(m_pCanvas->m_hWnd, iWidth, iHeight);

	// DIBセクションのセット.
	m_pCanvas->SetBitmap(m_pDIBSection);

	// m_pCanvasを返す.
	return m_pCanvas;

}

// ビットマップ保存関数SaveBitmap.
BOOL CScreen::SaveBitmap(LPCTSTR lpctszFileName) {

	// m_pDIBSection->SaveBitmapで保存.
	if (m_pCanvas != NULL && m_pDIBSection != NULL) {
		return m_pDIBSection->SaveBitmap(m_pCanvas->m_hWnd, lpctszFileName);	// SaveBitmapで保存.
	}
	else {
		return FALSE;
	}

}

// ビットマップ読込関数LoadBitmap.
BOOL CScreen::LoadBitmap(LPCTSTR lpctszFileName) {

	// ビットマップ情報の読み込み.
	m_pDIBSection = new CDIBSection();
	m_pDIBSection->LoadBitmap(lpctszFileName, FALSE);	// サイズ情報取得のみ.

	// キャンバスコントロールのウィンドウ作成.
	m_pCanvas = new CCanvas();	// newでCCanvasオブジェクトを作成し, ポインタm_pCanvasに格納.
	m_pCanvas->Create(_T("CCanvas"), 0, 50, 50, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight, m_hWnd, (HMENU)(WM_APP + 2), m_hInstance);	// Createでキャンバスコントロールのウィンドウ作成.
	m_pDIBSection->CreateDIBSection(m_pCanvas->m_hWnd, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight);

	// ピクセル列読み込み.
	m_pDIBSection->LoadBitmap(lpctszFileName, TRUE);	// ピクセル列読み込み.

	// ビットマップのセット.
	m_pCanvas->SetBitmap(m_pDIBSection);	// m_pDIBSectionをセット.

	// TRUEを返す.
	return TRUE;

}

// ウィンドウの作成が開始された時.
int CScreen::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 親クラスのOnCreateを呼ぶ.
	m_hInstance = lpCreateStruct->hInstance;
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreateを呼び, 戻り値を返す.

}