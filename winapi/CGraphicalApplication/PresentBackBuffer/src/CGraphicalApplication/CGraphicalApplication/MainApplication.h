// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// 四角形のサイズ
#define SQUARE_SIZE	32	// 四角形の一辺のサイズSQUARE_SIZE.

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGraphicalApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		int m_x;	// 四角形のX座標m_x.(Logicで更新する.)
		int m_y;	// 四角形のY座標m_y.(Logicで更新する.)
		int m_vx;	// X方向の速度m_vx.(Inputで設定する.)
		int m_vy;	// Y方向の速度m_vy.(Inputで設定する.)
		HBRUSH m_hbrSquare;	// 四角形描画用のブラシハンドルm_hbrSquare.(CreateSolidBrushで作成するため, ExitInstanceでDeleteObjectする必要がある.)

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.
		virtual void Input();	// 入力処理関数Input.(CGraphicalApplication::Inputをオーバーライド. キー状態の記録のみ行う.)
		virtual void Logic();	// ロジック処理関数Logic.(CGraphicalApplication::Logicをオーバーライド. 座標の更新と画面端でのクランプを行う.)
		virtual void Render();	// 描画処理関数Render.(CGraphicalApplication::Renderをオーバーライド. 四角形をバックバッファに描画して画面へ転送する.)

};

#endif
