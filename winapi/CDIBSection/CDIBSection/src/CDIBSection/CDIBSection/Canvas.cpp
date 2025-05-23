// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Canvas.h"	// CCanvas

// コンストラクタCCanvas
CCanvas::CCanvas() : CUserControl() {

	// メンバの初期化.
	m_hDC = NULL;
	m_hMemDC = NULL;
	m_hOldBitmap = NULL;
	m_pDIBSection = NULL;

}

// デストラクタ~CCanvas
CCanvas::~CCanvas() {

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"));	// CUserControl::RegisterClassでウィンドウクラス名"CCanvas"を登録.

}

// ウィンドウクラス登録関数RegisterClass(背景色指定バージョン.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance, int i) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"), i);	// CUserControl::RegisterClassでウィンドウクラス名"CCanvas"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CCanvas::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CCanvas".
	return CUserControl::Create(_T("CCanvas"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CCanvas"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CCanvas::Destroy() {

	// 以前のビットマップハンドルに戻す.
	if (m_hOldBitmap != NULL) {	// NULLでない.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObjectでm_hMemDCでm_hOlbBitmapを選択.
		m_hOldBitmap = NULL;	// NULLをセット.
	}

	// メモリデバイスコンテキストの破棄.
	if (m_hMemDC != NULL) {	// NULLでない.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを破棄.
		m_hMemDC = NULL;	// NULLをセット.
	}

	// デバイスコンテキストの解放.
	if (m_hDC != NULL) {	// NULLでない.
		ReleaseDC(m_hWnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// NULLをセット.
	}

	// m_pDIBSectionは外部のモノなので破棄せずNULLにするだけ.
	if (m_pDIBSection != NULL) {
		m_pDIBSection = NULL;	// NULLをセット.
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ビットマップのセットSetBitmap(CDIBSectionポインタ).
void CCanvas::SetBitmap(CDIBSection* pDIBSection) {

	// ポインタの格納.
	m_pDIBSection = pDIBSection;	// m_pDIBSectionにpDIBSectionを格納.

	// ビットマップオブジェクトの選択.
	HBITMAP hOld = NULL;
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_pDIBSection->m_hDIBSection);	// SelectObjectでm_hMemDCがm_pDIBSection->m_hDIBSectionを選択.
	if (m_hOldBitmap == NULL) {	// m_hOldBitmapがNULLの時.
		m_hOldBitmap = hOld;	// SelectObjectの戻り値を格納,
	}

}

// ウィンドウの作成が開始された時.
int CCanvas::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// デバイスコンテキストの取得.
	m_hDC = GetDC(hwnd);	// GetDCでこのウィンドウのデバイスコンテキストハンドルを取得.
	if (m_hDC == NULL) {	// NULLなら失敗.
		return -1;	// -1を返してウィンドウ作成失敗とする.
	}

	// メモリデバイスコンテキストの生成.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDCでm_hDCに互換性のあるメモリデバイスコンテキストを生成.
	if (m_hMemDC == NULL) {	// NULLなら失敗.
		ReleaseDC(hwnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// NULLをセット.
		return -2;	// -2を返してウィンドウ作成失敗とする.
	}

	// 親クラスのOnCreateを呼ぶ.
	return CUserControl::OnCreate(hwnd, lpCreateStruct);	// CUserControl::OnCreateの値を返す.

}

// ウィンドウの描画を要求された時.
void CCanvas::OnPaint() {

	// DIBSectionの描画.
	if (m_pDIBSection != NULL) {	// NULLでなければ.

		// 描画開始.
		PAINTSTRUCT ps = { 0 };	// PAINTSTRUCT型psを{0}で初期化.
		HDC hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintでhDC取得.

		// 描画.
		BitBlt(hDC, 0, 0, 320, 240, m_hMemDC, 0, 0, SRCCOPY);	// BitBltで転送.

		// 描画終了.
		EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

	}

}
