// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// 関数のプロトタイプ宣言
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);				// インスタンスの初期化.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// ウィンドウプロシージャWindowProc.

// _tWinMain関数の定義
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 構造体の宣言
	MSG msg;	// MSG型構造体msg.

	// インスタンスの初期化.
	if (!InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// InitInstanceがFALSEの場合.

		// 異常終了.
		return -1;	// returnで-1を返して異常終了.

	}

	// メッセージループの処理
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでウィンドウメッセージを取得し, msgに格納.(0以下ならここを抜ける.)

		// メッセージの変換と送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字メッセージに変換.
		DispatchMessage(&msg);	// DispatchMessageでメッセージをウィンドウプロシージャWindowProcに送出.

	}

	// プログラムの終了
	return (int)msg.wParam;	// 終了コード(msg.wParam)を戻り値として返す.

}

// InitInstance関数の定義
BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数・構造体の宣言
	HWND hWnd;	// HWND型ウィンドウハンドルhWnd.
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc.

	// ウィンドウクラス構造体wcにパラメータをセット.
	wc.lpszClassName = _T("InitInstance");	// ウィンドウクラス名はとりあえず"InitInstance"とする.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルはとりあえずCS_HREDRAW | CS_VREDRAWとする.
	wc.lpfnWndProc = WindowProc;	// ウィンドウプロシージャには下で定義するWindowProcを指定する.
	wc.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectで白ブラシを背景とする.
	wc.lpszMenuName = NULL;	// メニューはなし, なのでNULL.
	wc.cbClsExtra = 0;	// とりあえず0を指定.
	wc.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録.
	if (!RegisterClass(&wc)) {	// RegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// ウィンドウの作成.
	hWnd = CreateWindow(wc.lpszClassName, _T("InitInstance"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindowでウィンドウクラス名が"InitInstance"なウィンドウ"InitInstance"を作成.
	if (hWnd == NULL) {	// hWndがNULLならウィンドウ作成失敗.

		// hWndがNULLならウィンドウ作成失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// ウィンドウの表示
	ShowWindow(hWnd, SW_SHOW);	// ShowWindowでウィンドウを表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// ウィンドウプロシージャWindowProc関数の定義
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージの処理.
	switch (uMsg) {	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ウィンドウ作成を成功とさせるには0を返す.
				return 0;	// 0を返す.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// アプリケーションを終了させたいので, 終了メッセージの送信.
				PostQuitMessage(0);	// PostQuitMessageで終了コードを0として, WM_QUITメッセージを送信.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}