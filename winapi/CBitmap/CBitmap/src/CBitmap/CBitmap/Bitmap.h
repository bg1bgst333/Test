// 二重インクルード防止
#ifndef __BITMAP_H__
#define __BITMAP_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI

// ビットマップクラスCBitmap
class CBitmap {

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		HBITMAP m_hBitmap;	// HBITMAP型ビットマップハンドルm_hBitmap.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBitmap();	// コンストラクタCBitmap()
		virtual ~CBitmap();	// デストラクタ~CBitmap()

};

#endif