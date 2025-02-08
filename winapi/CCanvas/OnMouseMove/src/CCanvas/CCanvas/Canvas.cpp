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
	ZeroMemory(&m_rgbqCurrentColor, sizeof(RGBQUAD));
	m_hPen = NULL;
	m_hOldPen = NULL;

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

	// ペンオブジェクトの破棄.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

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

	// ペンオブジェクトの破棄.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

	// ペンオブジェクトの作成.
	m_hPen = CreatePen(PS_SOLID, 1, RGB(m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue));

	// ペンオブジェクトの選択.
	m_hOldPen = (HPEN)SelectObject(m_hMemDC, m_hPen);

}

// 現在の色をセットする関数SetCurrentColor.
void CCanvas::SetCurrentColor(BYTE r, BYTE g, BYTE b) {

	// 指定の色をセット.
	m_rgbqCurrentColor.rgbRed = r;
	m_rgbqCurrentColor.rgbGreen = g;
	m_rgbqCurrentColor.rgbBlue = b;

	// ペンオブジェクトの破棄.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

	// ペンオブジェクトの作成.
	m_hPen = CreatePen(PS_SOLID, 1, RGB(m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue));

	// ペンオブジェクトの選択.
	m_hOldPen = (HPEN)SelectObject(m_hMemDC, m_hPen);

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
		if (m_pDIBSection != NULL) {
			BitBlt(hDC, 0, 0, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBltで転送.
		}

		// 描画終了.
		EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

	}

}

// マウスが移動している時.
void CCanvas::OnMouseMove(UINT nFlags, POINT pt) {

	// マウスダウンフラグが立っている時.
	if (nFlags == MK_LBUTTON) {	// 左ボタンが押されている時.

		// 移動中は現在の色の線を引く.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			LineTo(m_hMemDC, pt.x, pt.y);
			MoveToEx(m_hMemDC, pt.x, pt.y, NULL);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}
	else {	// 左ボタンが押されていない時.

		// 始点を移動.
		MoveToEx(m_hMemDC, pt.x, pt.y, NULL);

	}

}

// マウスの左ボタンが押された時.
void CCanvas::OnLButtonDown(UINT nFlags, POINT pt) {

	// マウスダウンフラグが立っている時.
	if (nFlags == MK_LBUTTON) {	// 左ボタンが押されている時.

		// 押した部分に現在の色をセット.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}

}

// マウスの左ボタンが離された時.
void CCanvas::OnLButtonUp(UINT nFlags, POINT pt) {

	// マウスダウンフラグが立っている時.
	if (nFlags == MK_LBUTTON) {	// 左ボタンが押されている時.

		// 離した部分に現在の色をセット.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}

}