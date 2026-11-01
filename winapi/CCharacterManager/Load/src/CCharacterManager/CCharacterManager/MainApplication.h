// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "CharacterManager.h"	// CCharacterManager

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGraphicalApplication{

	// public メンバ
	public:

		// public メンバ変数
		CCharacterManager m_CharacterManager;	// キャラクター管理オブジェクトm_CharacterManager.(複数のCCharacterをまとめて持ち, Input/Logic/Renderをまとめて呼び出す.)

		// public メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual void Input();	// 入力処理関数Input.(CGraphicalApplication::Inputをオーバーライド. キー状態の記録のみ行う.)
		virtual void Logic();	// ロジック処理関数Logic.(CGraphicalApplication::Logicをオーバーライド. m_CharacterManagerの座標更新と画面端でのクランプを行う.)
		virtual void Render();	// 描画処理関数Render.(CGraphicalApplication::Renderをオーバーライド. m_CharacterManager.Renderでバックバッファに描画して画面へ転送する.)

};

#endif
