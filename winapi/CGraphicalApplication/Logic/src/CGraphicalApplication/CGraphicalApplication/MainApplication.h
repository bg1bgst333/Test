// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// 座標X座標m_x.(Logicで更新する.)
		int m_y;	// 座標Y座標m_y.(Logicで更新する.)
		int m_vx;	// X方向の速度m_vx.(Inputで設定する.)
		int m_vy;	// Y方向の速度m_vy.(Inputで設定する.)

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual void Input();	// 入力処理関数Input.(CGraphicalApplication::Inputをオーバーライド. キー状態の記録のみ行う.)
		virtual void Logic();	// ロジック処理関数Logic.(CGraphicalApplication::Logicをオーバーライド. 座標の更新を行う.)

};

#endif
