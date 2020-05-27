// 二重インクルード防止
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// アプリケーションクラスCApplicationの定義
class CApplication{

	// publicメンバ
	public:

		// publicメンバ変数
		CWindow m_mainWnd;	// メインウィンドウm_mainWnd.

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual int Run();	// メッセージループ処理関数Run.
		virtual int ExitInstance();	// 終了処理関数ExitInstance.

};

#endif