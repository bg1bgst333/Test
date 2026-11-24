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

// マスク画像読込関数LoadMask.
BOOL CSprite::LoadMask(HINSTANCE hInstance, LPCTSTR lpctszFileName){

	// CBitmap::LoadImageでマスク画像をロード.
	if (!m_Mask.LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE)){	// LR_LOADFROMFILEでlpctszFileNameのパスからロード.

		// ロード失敗
		return FALSE;	// FALSEを返して呼び出し元に失敗を伝える.

	}

	// マスクの幅・高さを取得し, 本体のスプライトと一致するか確認.
	BITMAP bm = {0};	// ビットマップ情報を格納するBITMAP構造体bm.
	GetObject((HBITMAP)m_Mask, sizeof(BITMAP), &bm);	// GetObjectでbmに幅・高さを格納.
	if (bm.bmWidth != m_iWidth || bm.bmHeight != m_iHeight){	// 幅または高さが本体と違う場合.

		// サイズ不一致
		return FALSE;	// FALSEを返して呼び出し元に失敗を伝える.

	}

	// ロードとサイズ確認が成功
	return TRUE;	// TRUEを返して呼び出し元に成功を伝える.

}
// マスク付き描画関数DrawMasked.
void CSprite::DrawMasked(HDC hDC){

	// スプライトとマスクのメモリDCを作成し, ビットマップを選択.
	HDC hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDCでhDCと互換のメモリDCを作成.
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, (HBITMAP)m_Bitmap);	// SelectObjectでスプライトを選択.
	HDC hMaskDC = CreateCompatibleDC(hDC);	// マスク用のメモリDCを作成.
	HBITMAP hOldMask = (HBITMAP)SelectObject(hMaskDC, (HBITMAP)m_Mask);	// SelectObjectでマスクを選択.

	// 透過部分を黒にした一時的なスプライトを作る.(スプライトとマスクをANDする. マスクの白(表示)は残り, 黒(透過)は黒になる.)
	HDC hTempDC = CreateCompatibleDC(hDC);	// 一時用のメモリDCを作成.
	HBITMAP hTemp = CreateCompatibleBitmap(hDC, m_iWidth, m_iHeight);	// 一時用のビットマップを作成.
	HBITMAP hOldTemp = (HBITMAP)SelectObject(hTempDC, hTemp);	// SelectObjectで一時用ビットマップを選択.
	BitBlt(hTempDC, 0, 0, m_iWidth, m_iHeight, hMemDC, 0, 0, SRCCOPY);	// スプライトを一時用にコピー.
	BitBlt(hTempDC, 0, 0, m_iWidth, m_iHeight, hMaskDC, 0, 0, SRCAND);	// マスクとANDして透過部分を黒にする.

	// 描画先のうち, マスクの白(表示)の部分を黒にする.(描画先 AND NOT マスク.)
	BitBlt(hDC, m_x, m_y, m_iWidth, m_iHeight, hMaskDC, 0, 0, 0x00220326);	// 0x00220326は描画先AND NOT元のラスタオペレーション.

	// 一時用のスプライトを描画先にORで重ねる.(表示部分はスプライトの色, 透過部分は背景のまま.)
	BitBlt(hDC, m_x, m_y, m_iWidth, m_iHeight, hTempDC, 0, 0, SRCPAINT);	// SRCPAINTで描画先とORする.

	// 後始末.
	SelectObject(hTempDC, hOldTemp);	// SelectObjectで元のビットマップに戻す.
	DeleteObject(hTemp);	// DeleteObjectで一時用ビットマップを破棄.
	DeleteDC(hTempDC);	// DeleteDCで一時用DCを破棄.
	SelectObject(hMaskDC, hOldMask);	// SelectObjectで元のビットマップに戻す.
	DeleteDC(hMaskDC);	// DeleteDCでマスク用DCを破棄.
	SelectObject(hMemDC, hOldBitmap);	// SelectObjectで元のビットマップに戻す.
	DeleteDC(hMemDC);	// DeleteDCでメモリDCを破棄.

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
