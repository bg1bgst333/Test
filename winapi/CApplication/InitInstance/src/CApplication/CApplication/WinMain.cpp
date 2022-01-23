// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// オブジェクトの宣言.
	CMainApplication app;	// CMainApplicationオブジェクトapp.
	int iRet;	// app.Runの戻り値iRet.

	// インスタンスの初期化.
	if (!app.InitInstance(hInstance, lpCmdLine, nShowCmd)){	// app.InitInstanceがFALSEの場合.

		// 異常終了.
		app.ExitInstance();	// app.ExitInstanceで終了処理を実行.
		delete app.m_pMainWnd;	// メインウィンドウポインタを解放.
		return -1;	// returnで-1を返して異常終了.

	}

	// メッセージループ処理.
	//return app.Run();	// app.Runの戻り値をそのまま返す.
	iRet = app.Run();	// 戻り値をiRetに格納.
	delete app.m_pMainWnd;	// メインウィンドウポインタを解放.
	return iRet;	// iRetを返す.

}