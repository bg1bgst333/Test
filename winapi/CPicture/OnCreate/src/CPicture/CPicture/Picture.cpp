// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Picture.h"	// CPicture

// コンストラクタCPicture
CPicture::CPicture() : CStaticCore() {

	// メンバの初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.

}

// デストラクタ~CPicture
CPicture::~CPicture() {

}

// ウィンドウ破棄関数Destroy
BOOL CPicture::Destroy() {

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

	// 親クラスのDestroyを呼ぶ.
	return CStaticCore::Destroy();	// CStaticCore::Destroyを呼ぶ.

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
	return CStaticCore::OnCreate(hwnd, lpCreateStruct);	// CStaticCore::OnCreateの値を返す.

}

// ウィンドウの描画を要求された時.
void CPicture::OnPaint() {

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 文字列の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TextOut(hDC, 0, 0, _T("CPicture"), (int)_tcslen(_T("CPicture")));	// Win32APIのTextOutで"CPicture"と描画.
	TCHAR tszBuf1[64] = { 0 };	// TCHARバッファtszBuf1(長さ64)を{0}で初期化.
	_stprintf(tszBuf1, _T("m_hDC = 0x%08x"), m_hDC);	// _stprintfでm_hDCを文字列に変換.
	TextOut(hDC, 0, 50, tszBuf1, (int)_tcslen(tszBuf1));	// Win32APIのTextOutでtszBuf1を描画.
	TCHAR tszBuf2[64] = { 0 };	// TCHARバッファtszBuf2(長さ64)を{0}で初期化.
	_stprintf(tszBuf2, _T("m_hMemDC = 0x%08x"), m_hMemDC);	// _stprintfでm_hMemDCを文字列に変換.
	TextOut(hDC, 0, 100, tszBuf2, (int)_tcslen(tszBuf2));	// Win32APIのTextOutでtszBuf2を描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}