// ヘッダのインクルード
// 独自のヘッダ
#include "DIBSection.h"	// CDIBSection

// コンストラクタCDIBSection()
CDIBSection::CDIBSection(){

	// メンバの初期化.
	m_hDIBSection = NULL;	// m_hDIBSectionをNULLで初期化.
	m_lpBitsPixel = NULL;	// m_lpBitsPixelをNULLで初期化.

}

// デストラクタ~CDIBSection()
CDIBSection::~CDIBSection(){

	// メンバの終了処理.
	if (m_hDIBSection != NULL){	// NULLでない.
		::DeleteObject(m_hDIBSection);	// DeleteObjectで破棄.
		m_hDIBSection = NULL;	// NULLをセット.
	}
	m_lpBitsPixel = NULL;	// 自動解放なのでNULLをセット.

}

// DIBセクション作成関数CreateDIBSection.
BOOL CDIBSection::CreateDIBSection(HWND hWnd, int iWidth, int iHeight){

	// 変数の宣言・初期化
	HDC hDC = NULL;	// ウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	BITMAPINFO bi = {0};	// ビットマップ情報BiTMAPINFO構造体biを{0}で初期化.

	// ウィンドウのデバイスコンテキストハンドルを取得.
	hDC = GetDC(hWnd);	// GetDCでウィンドウのデバイスコンテキストハンドルを取得し, hDCに格納.
	if (hDC){

		// ビットマップ情報のセット.
		bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bi.bmiHeader.biWidth = iWidth;
		bi.bmiHeader.biHeight = iHeight;
		bi.bmiHeader.biPlanes = 1;
		bi.bmiHeader.biBitCount = 24;
		bi.bmiHeader.biCompression = BI_RGB;

		// DIBセクションの作成.
		m_hDIBSection = ::CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&m_lpBitsPixel, NULL, 0);	// CreateDIBSectionでDIBセクションを作成.

		// デバイスコンテキストの解放.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでデバイスコンテキストを解放.

		// NULLじゃなければ成功.
		if (m_hDIBSection != NULL){
			return TRUE;
		}

	}

	return FALSE;

}