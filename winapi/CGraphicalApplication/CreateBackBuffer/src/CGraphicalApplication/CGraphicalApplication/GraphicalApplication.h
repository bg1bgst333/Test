// 二重インクルード防止
#ifndef __GRAPHICAL_APPLICATION_H__
#define __GRAPHICAL_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// グラフィカルアプリケーションクラスCGraphicalApplication
class CGraphicalApplication : public CApplication {

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hBackBufferDC;	// メモリデバイスコンテキストハンドルm_hBackBufferDC.
		HBITMAP m_hBackBufferBitmap;	// バックバッファビットマップハンドルm_hBackBufferBitmap.
		HBITMAP m_hOldBitmap;	// 以前のビットマップハンドルm_hOldBitmap.
		// publicメンバ関数
		// コンストラクタ
		CGraphicalApplication();	// コンストラクタCGraphicalApplication
		virtual int Run();	// メッセージループ処理関数Run.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.
		virtual BOOL OnIdle(LONG lCount);	// アイドル処理関数OnIdle.
		virtual void MainProc();	// メインループ処理関数MainProc.
		virtual void CreateBackBuffer();	// バックバッファ作成関数CreateBackBuffer.

};

#endif