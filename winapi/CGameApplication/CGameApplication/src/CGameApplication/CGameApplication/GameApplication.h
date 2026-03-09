// 二重インクルード防止
#ifndef __GAME_APPLICATION_H__
#define __GAME_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// ゲームアプリケーションクラスCGameApplication
class CGameApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ
		CGameApplication();	// コンストラクタCGameApplication
		virtual void MainProc();	// メインループ処理関数MainProc.

};

#endif