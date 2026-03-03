// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCGraphicalApplication
CGraphicalApplication::CGraphicalApplication() : CApplication() {

}

// メッセージループ処理関数Run.
int CGraphicalApplication::Run() {

	// 変数の初期化.
	MSG msg = { 0 };	// MSG型メッセージ構造体msgを{0}で初期化.
	int lCount = 0;	// ウィンドウメッセージが来なかった時の回数を保持するint型変数lCountの初期値を0とする.

	// PeekMessageによるメインループ.
	while (TRUE) {	// 常に真(TRUE)なので無限ループ.

		// ウィンドウメッセージが来ているかを確認する.
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {	// PeekMessageでウィンドウメッセージが来ているかを確認し, 真なら来ている.(PM_NOREMOVEなのでメッセージキューからこのメッセージを削除しない.次のGetMessageがそのメッセージを処理する.)

			// 0にリセット.
			lCount = 0;	// lCountを0にリセット.

			// 来ていたらそのメッセージを取得.
			if (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでPeekMessageで確認したメッセージを取得.

				// ウィンドウメッセージの送出
				TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージへ変換.
				DispatchMessage(&msg);	// DispatchMessageで受け取ったメッセージをウィンドウプロシージャ(この場合は独自に定義したWindowProc)に送出.

			}
			else {	// 正常終了(0), またはエラーによる異常終了(-1).

				// メインループを抜ける.
				break;	// breakでメインループを抜ける.

			}

		}
		else {	// 偽ならウィンドウメッセージが来ていないとき.

			// アイドル処理
			if (OnIdle(lCount)) {	// OnIdleにlCountを渡して, この中でアイドル処理をする.
				lCount++;	// TRUEで返ってくるたびにlCountを増やす.
			}

		}

	}

	// ExitInstanceの値を返す.
	return ExitInstance();	// returnでExitInstanceを返す.

}