// ヘッダのインクルード
// 独自のヘッダ
#include "Sprite.h"	// CSprite

// コンストラクタCSprite()
CSprite::CSprite() {

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.

}

// デストラクタ~CSprite()
CSprite::~CSprite() {

}

// 画像読込関数Load.
BOOL CSprite::Load(HINSTANCE hInstance, LPCTSTR lpctszFileName) {

	// CBitmap::LoadImageでファイルから画像をロード.
	return m_Bitmap.LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// LR_LOADFROMFILEでlpctszFileNameのパスからロード.

}

// 描画関数Draw.
void CSprite::Draw(HDC hDC) {

	// ビットマップのサイズを取得.
	BITMAP bm = { 0 };
	GetObject((HBITMAP)m_Bitmap, sizeof(BITMAP), &bm);	// GetObjectでビットマップの幅・高さ等を取得.

	// 描画元のメモリDCを作成し, ビットマップを選択.
	HDC hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhDCと互換のメモリDCを作成.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, (HBITMAP)m_Bitmap);	// SelectObjectでメモリDCにビットマップを選択.

	// BitBltで描画.
	BitBlt(hDC, m_x, m_y, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);	// BitBltでhDCのm_x, m_y位置に描画.

	// 後始末.
	SelectObject(hMemDC, hOldBitmap);	// SelectObjectで元のビットマップに戻す.
	DeleteDC(hMemDC);	// DeleteDCでメモリDCを破棄.

}
