// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// CApplication

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		HBRUSH m_hBrush1;
		HBRUSH m_hBrush2;
		HBITMAP m_hBitmap1;
		HBITMAP m_hBitmap2;

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.

};

#endif