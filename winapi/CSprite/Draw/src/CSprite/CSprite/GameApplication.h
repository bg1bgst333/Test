// 二重インクルード防止
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "Sprite.h"	// CSprite

// ゲームアプリケーションクラスCGameApplication
class CGameApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// テキストの位置X座標m_x
		int m_y;	// テキストの位置Y座標m_y
		int m_vx;	// X方向の速度m_vx;
		int m_vy;	// Y方向の速度m_vy;
		CSprite m_Sprite;	// CSpriteオブジェクトm_Sprite.
		HBRUSH m_hbrBackground;	// バックバッファ塗りつぶし用のブラシハンドルm_hbrBackground.(CreateSolidBrushで作成するため, ExitInstanceでDeleteObjectする必要がある.)

		// publicメンバ関数
		// コンストラクタ
		CGameApplication();	// コンストラクタCGameApplication
		virtual int ExitInstance();	// 終了処理関数ExitInstance.
		virtual void MainProc();	// メインループ処理関数MainProc.
		virtual void Input();	// 入力処理関数Input.
		virtual void Logic();	// ロジック処理関数Logic.
		virtual void Render();	// 描画処理関数Render.

};

#endif
