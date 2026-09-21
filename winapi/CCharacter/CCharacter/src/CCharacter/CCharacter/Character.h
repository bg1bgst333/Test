// 二重インクルード防止
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Paint.h"	// CPaint

// キャラクターのサイズ
#define CHARACTER_SIZE	32	// キャラクターの一辺のサイズCHARACTER_SIZE.

// キャラクタークラスCCharacter
class CCharacter{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// キャラクターのX座標m_x.
		int m_y;	// キャラクターのY座標m_y.

		// publicメンバ関数
		// コンストラクタ
		CCharacter();	// コンストラクタCCharacter
		// メンバ関数
		virtual void Render(HDC hDC);	// 描画処理関数Render.(自分の位置(m_x, m_y)にCPaint::FillRectで赤い四角形として自分を描画する.)

};

#endif
