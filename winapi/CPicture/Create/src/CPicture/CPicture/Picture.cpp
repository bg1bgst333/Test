// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Picture.h"	// CPicture

// コンストラクタCPicture
CPicture::CPicture() : CUserControl() {

	// メンバの初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.

}

// デストラクタ~CPicture
CPicture::~CPicture() {

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CPicture::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CPicture"));	// CUserControl::RegisterClassでウィンドウクラス名"CPicture"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CPicture::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CPicture".
	return CUserControl::Create(_T("CPicture"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CPicture"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CPicture::Destroy() {

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

	// ビットマップハンドルは外部のモノなので破棄せずNULLにするだけ.
	if (m_hBitmap != NULL) {
		m_hBitmap = NULL;	// NULLをセット.
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ビットマップのセットSetBitmap.
void CPicture::SetBitmap(HBITMAP hBitmap) {

	// ビットマップハンドルの格納.
	m_hBitmap = hBitmap;	// m_hBitmapにhBitmapを格納.

	// ビットマップオブジェクトの選択.
	HBITMAP hOld = NULL;
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hMemDCがm_hBitmapを選択.
	if (m_hOldBitmap == NULL) {	// m_hOldBitmapがNULLの時.
		m_hOldBitmap = hOld;	// SelectObjectの戻り値を格納,
	}

}

// ウィンドウの作成が開始された時.
int CPicture::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

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
void CPicture::OnPaint() {

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 描画の開始.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.

	// ビットマップの描画.
	if (m_hBitmap != NULL) {	// NULLでなければ.
		RECT rc = { 0 };	// クライアント領域rcを{0}で初期化.
		GetClientRect(m_hWnd, &rc);	// GetClientRectでクライアント領域のRECTを取得.
		BitBlt(hDC, 0, 0, rc.right - rc.left + 1, rc.bottom - rc.top + 1, m_hMemDC, 0, 0, SRCCOPY);	// BitBltでm_hMemDCをhDCに転送.
	}

	// 文字列の描画.
	TextOut(hDC, 0, 0, _T("CPicture"), (int)_tcslen(_T("CPicture")));	// Win32APIのTextOutで"CPicture"と描画.
	TCHAR tszBuf1[64] = { 0 };	// TCHARバッファtszBuf1(長さ64)を{0}で初期化.
	_stprintf(tszBuf1, _T("m_hDC = 0x%08x"), m_hDC);	// _stprintfでm_hDCを文字列に変換.
	TextOut(hDC, 0, 25, tszBuf1, (int)_tcslen(tszBuf1));	// Win32APIのTextOutでtszBuf1を描画.
	TCHAR tszBuf2[64] = { 0 };	// TCHARバッファtszBuf2(長さ64)を{0}で初期化.
	_stprintf(tszBuf2, _T("m_hMemDC = 0x%08x"), m_hMemDC);	// _stprintfでm_hMemDCを文字列に変換.
	TextOut(hDC, 0, 50, tszBuf2, (int)_tcslen(tszBuf2));	// Win32APIのTextOutでtszBuf2を描画.

	// 描画の終了.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}