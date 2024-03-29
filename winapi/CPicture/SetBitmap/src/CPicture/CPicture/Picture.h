// 二重インクルード防止
#ifndef __PICTURE_H__
#define __PICTURE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "StaticCore.h"	// CStaticCore

// ピクチャークラスCPicture
class CPicture : public CStaticCore {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CPicture();	// コンストラクタCPicture
		virtual ~CPicture();	// デストラクタ~CPicture
		// メンバ関数
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual void SetBitmap(HBITMAP hBitmap);	// ビットマップのセットSetBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnPaint();	// ウィンドウの描画を要求された時.

	// privateメンバ
	private:

		// privateメンバ変数
		// メンバ変数
		HDC m_hDC;	// HDC型デバイスコンテキストハンドルm_hDC.
		HDC m_hMemDC;	// HDC型メモリデバイスコンテキストハンドルm_hMemDC.
		HBITMAP m_hBitmap;	// HBITMAP型ビットマップハンドルm_hBitmap.
		HBITMAP m_hOldBitmap;	// HBITMAP型の以前のビットマップハンドルm_hOldBitmap.

};

#endif