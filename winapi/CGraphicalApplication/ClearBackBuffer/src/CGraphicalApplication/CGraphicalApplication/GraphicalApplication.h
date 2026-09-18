// 二重インクルード防止
#ifndef __GRAPHICAL_APPLICATION_H__
#define __GRAPHICAL_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// グラフィカルアプリケーションクラスCGraphicalApplication
class CGraphicalApplication : public CApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hBackBufferDC;	// メモリデバイスコンテキストハンドルm_hBackBufferDC.
		HBITMAP m_hBackBufferBitmap;	// バックバッファビットマップハンドルm_hBackBufferBitmap.
		HBITMAP m_hOldBitmap;	// 以前のビットマップハンドルm_hOldBitmap.
		int m_iBackBufferWidth;	// バックバッファの幅m_iBackBufferWidth.
		int m_iBackBufferHeight;	// バックバッファの高さm_iBackBufferHeight.
		// publicメンバ関数
		// コンストラクタ
		CGraphicalApplication();	// コンストラクタCGraphicalApplication
		virtual int Run();	// メッセージループ処理関数Run.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.
		virtual BOOL OnIdle(LONG lCount);	// アイドル処理関数OnIdle.
		virtual void MainProc();	// メインループ処理関数MainProc.
		virtual void CreateBackBuffer();	// バックバッファ作成関数CreateBackBuffer.
		virtual void DestroyBackBuffer();	// バックバッファ破棄関数DestroyBackBuffer.
		virtual void ClearBackBuffer();	// バックバッファクリア関数ClearBackBuffer.(バックバッファを背景色で塗りつぶす. どのデモでも共通の処理なのでここに持たせる.)
		virtual void PresentBackBuffer();	// バックバッファ転送関数PresentBackBuffer.(バックバッファの内容を画面へ一括転送する. どのデモでも共通の処理なのでここに持たせる.)
		virtual void Input();	// 入力処理関数Input.(既定では何もしない. 派生クラスでオーバーライドして使う.)
		virtual void Logic();	// ロジック処理関数Logic.(既定では何もしない. 派生クラスでオーバーライドして使う.)
		virtual void Render();	// 描画処理関数Render.(既定では何もしない. 派生クラスでオーバーライドして使う.)

};

#endif
