// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCGraphicalApplication
CGraphicalApplication::CGraphicalApplication() : CApplication(){

}

// メッセージループ処理関数Run.
int CGraphicalApplication::Run(){

	// 変数の初期化.
	MSG msg = {0};	// MSG型メッセージ構造体msgを{0}で初期化.
	int lCount = 0;	// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.

	// PeekMessageによるメインループ.
	while (TRUE){	// 常に真(TRUE)なので無限ループ.

		// メッセージループが来ていれば処理する.
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// WM_QUITならExitInstanceを呼んで終了.
			if (msg.message == WM_QUIT){
				return ExitInstance();
			}

			// ウィンドウメッセージの送出
			TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
			DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

		}

		// アイドル処理
		OnIdle(lCount++);
		Sleep(1);

	}

}