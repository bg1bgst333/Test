// 二重インクルード防止
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Paint.h"	// CPaint

// 前方宣言
class CGraphicalApplication;	// CGraphicalApplication.(実体の定義はCharacter.cpp側でインクルードする. ここではポインタとして持つだけなので前方宣言で十分.)

// キャラクターのサイズ
#define CHARACTER_SIZE	32	// キャラクターの一辺のサイズCHARACTER_SIZE.

// キャラクタークラスCCharacter
class CCharacter{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// キャラクターのX座標m_x.
		int m_y;	// キャラクターのY座標m_y.
		int m_vx;	// キャラクターのX方向の速度m_vx.(MoveRightなどで設定する. 座標の更新自体はLogicで行う.)
		int m_vy;	// キャラクターのY方向の速度m_vy.(今のところInputから直接設定する.)
		CGraphicalApplication *m_pGraphicalApplication;	// 自分が属するCGraphicalApplicationへのポインタm_pGraphicalApplication.(引数なしのRenderで, 現在のバックバッファのDCをここ経由で取得するために使う.)

		// publicメンバ関数
		// コンストラクタ
		CCharacter();	// コンストラクタCCharacter
		// メンバ関数
		virtual void Render(HDC hDC);	// 描画処理関数Render.(指定されたHDCに, 自分の位置(m_x, m_y)にCPaint::FillRectで赤い四角形として自分を描画する.)
		virtual void Render();	// 描画処理関数Render.(引数なしオーバーロード. m_pGraphicalApplication->m_hBackBufferDCへ描画する.)
		virtual void MoveRight();	// 右移動関数MoveRight.(右へ進むよう, 自分の速度m_vxを設定する.)

};

#endif
