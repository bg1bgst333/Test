// ヘッダのインクルード
// 独自のヘッダ
#include "Sprite.h"	// CSprite

// コンストラクタCSprite()
CSprite::CSprite(){

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.

}

// デストラクタ~CSprite()
CSprite::~CSprite(){

}

// 画像読込関数Load.
BOOL CSprite::Load(HINSTANCE hInstance, LPCTSTR lpctszFileName){

	// CBitmap::LoadImageでファイルから画像をロード.
	if (!m_Bitmap.LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE)){	// LR_LOADFROMFILEでlpctszFileNameのパスからロード.

		// ロード失敗
		return FALSE;	// FALSEを返して呼び出し元に失敗を伝える.

	}

	// ビットマップの幅・高さを取得し, キャッシュしておく.(Drawで毎回GetObjectしなくて済むようにするため.)
	{

		// このブロックのローカル変数の宣言
		BITMAP bm = {0};	// ビットマップ情報を格納するBITMAP構造体bm.

		// GetObjectでビットマップの幅・高さを取得.
		GetObject((HBITMAP)m_Bitmap, sizeof(BITMAP), &bm);	// GetObjectでbmに幅・高さを格納.
		m_iWidth = bm.bmWidth;	// m_iWidthにbm.bmWidthを格納.
		m_iHeight = bm.bmHeight;	// m_iHeightにbm.bmHeightを格納.

	}

	// 透過色のサンプリング.(左上(0, 0)のピクセルの色を透過色として使う. 見た目は白でも, 実際の値は完全な白(255, 255, 255)とは限らないため.)
	{

		// このブロックのローカル変数の宣言
		HDC hDCTemp;			// サンプリング用のデバイスコンテキストハンドルhDCTemp.
		HDC hMemDCTemp;			// サンプリング用のメモリデバイスコンテキストハンドルhMemDCTemp.
		HBITMAP hOldBitmapTemp;	// サンプリング用のSelectObject前のビットマップハンドルhOldBitmapTemp.

		// デバイスコンテキストの取得とメモリデバイスコンテキストの生成.
		hDCTemp = GetDC(NULL);	// GetDCで画面全体のデバイスコンテキストを取得.
		hMemDCTemp = CreateCompatibleDC(hDCTemp);	// CreateCompatibleDCで互換のメモリデバイスコンテキストを生成.
		hOldBitmapTemp = (HBITMAP)SelectObject(hMemDCTemp, (HBITMAP)m_Bitmap);	// SelectObjectでロードしたビットマップを選択.

		// 左上(0, 0)のピクセルの色を取得し, 透過色として保持しておく.
		m_crTransparent = GetPixel(hMemDCTemp, 0, 0);	// GetPixelで(0, 0)の色を取得し, m_crTransparentに格納.

		// 後始末.
		SelectObject(hMemDCTemp, hOldBitmapTemp);	// SelectObjectで元のビットマップに戻す.
		DeleteDC(hMemDCTemp);	// DeleteDCでhMemDCTempを破棄.
		ReleaseDC(NULL, hDCTemp);	// ReleaseDCでhDCTempを解放.

	}

	// ロード成功
	return TRUE;	// TRUEを返して呼び出し元に成功を伝える.

}

// 描画関数Draw.
void CSprite::Draw(HDC hDC){

	// 描画元のメモリDCを作成し, ビットマップを選択.
	HDC hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhDCと互換のメモリDCを作成.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, (HBITMAP)m_Bitmap);	// SelectObjectでメモリDCにビットマップを選択.

	// TransparentBltでm_crTransparentを透過色に指定して描画.(白い背景を透過させて, スプライトの絵柄だけを表示する.)
	TransparentBlt(hDC, m_x, m_y, m_iWidth, m_iHeight, hMemDC, 0, 0, m_iWidth, m_iHeight, m_crTransparent);	// TransparentBltでhDCのm_x, m_y位置に描画.(幅・高さはLoadでキャッシュしたm_iWidth/m_iHeightを使う.)

	// 後始末.
	SelectObject(hMemDC, hOldBitmap);	// SelectObjectで元のビットマップに戻す.
	DeleteDC(hMemDC);	// DeleteDCでメモリDCを破棄.

}
