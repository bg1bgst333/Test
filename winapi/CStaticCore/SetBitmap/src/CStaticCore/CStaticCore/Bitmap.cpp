// ヘッダのインクルード
// 独自のヘッダ
#include "Bitmap.h"	// CBitmap

// コンストラクタCBitmap()
CBitmap::CBitmap() {

	// メンバの初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.

}

// デストラクタ~CBitmap()
CBitmap::~CBitmap() {

	// メンバの終了処理.
	if (m_hBitmap != NULL) {	// NULLでない.
		::DeleteObject(m_hBitmap);	// DeleteObjectで破棄.
		m_hBitmap = NULL;	// NULLをセット.
	}

}

// ビットマップリソースロード関数LoadBitmap.
BOOL CBitmap::LoadBitmap(HINSTANCE hInstance, LPCTSTR lpctszResourceName) {

	// ビットマップリソースをロード.
	m_hBitmap = ::LoadBitmap(hInstance, lpctszResourceName);	// LoadBitmapで指定のビットマップリソースをロード.
	if (m_hBitmap != NULL) {	// NULLでない.
		return TRUE;	// TRUEを返す.
	}
	else {	// NULL.
		return FALSE;	// FALSEを返す.
	}

}

// HBITMAP演算子
CBitmap::operator HBITMAP() const {

	// ビットマップハンドルを返す.
	return m_hBitmap;	// m_hBitmapを返す.

}