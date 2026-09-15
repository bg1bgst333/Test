// 二重インクルード防止
#ifndef __SPRITE_H__
#define __SPRITE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Bitmap.h"	// CBitmap

// スプライトクラスCSprite
class CSprite {

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// 描画位置X座標m_x.
		int m_y;	// 描画位置Y座標m_y.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CSprite();	// コンストラクタCSprite()
		virtual ~CSprite();	// デストラクタ~CSprite()
		// メンバ関数
		virtual BOOL Load(HINSTANCE hInstance, LPCTSTR lpctszFileName);	// 画像読込関数Load.
		virtual void Draw(HDC hDC);	// 描画関数Draw.

	// privateメンバ
	private:

		// privateメンバ変数
		// メンバ変数
		CBitmap m_Bitmap;	// CBitmapオブジェクトm_Bitmap.

};

#endif
