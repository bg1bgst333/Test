// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "Character.h"	// CCharacter

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		CCharacter m_Character;	// キャラクターオブジェクトm_Character.(位置(m_x, m_y)と速度(m_vx, m_vy)と自分の描画を持つ.)

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual void Input();	// 入力処理関数Input.(CGraphicalApplication::Inputをオーバーライド. キー状態の記録のみ行う.)
		virtual void Logic();	// ロジック処理関数Logic.(CGraphicalApplication::Logicをオーバーライド. m_Characterの座標更新と画面端でのクランプを行う.)
		virtual void Render();	// 描画処理関数Render.(CGraphicalApplication::Renderをオーバーライド. m_Character.Renderでバックバッファに描画して画面へ転送する.)

};

#endif
