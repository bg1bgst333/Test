// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// CWindow

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// ウィンドウマップm_mapWindowMap.

// コンストラクタCWindow()
CWindow::CWindow(){

	// メンバの初期化.
	m_hWnd = NULL;	// m_hWndをNULLで初期化.

}

// デストラクタ~CWindow()
CWindow::~CWindow(){

	// メンバの終了処理.
	Destroy();	// Destroyを呼ぶ.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// メニュー名はNULL.
	return RegisterClass(hInstance, lpctszClassName, NULL);	// RegisterClass(メニュー名指定バージョン)のメニュー名にNULLを指定.

}

// ウィンドウクラス登録関数RegisterClass(メニュー名指定バージョン)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, LPCTSTR lpctszMenuName){

	// 変数・構造体の宣言
	WNDCLASS wc;	// WNDCLASS型ウィンドウクラス構造体wc.

	// ウィンドウクラス構造体wcにパラメータをセット.
	wc.lpszClassName = lpctszClassName;	// ウィンドウクラス名にlpctszClassNameをセットする.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// スタイルはとりあえずCS_HREDRAW | CS_VREDRAWとする.
	wc.lpfnWndProc = StaticWindowProc;	// ウィンドウプロシージャには下で定義するStaticWindowProcを指定する.
	wc.hInstance = hInstance;	// アプリケーションインスタンスハンドルは引数のhInstanceを使う.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIconでアプリケーション既定のアイコンをロード.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursorでアプリケーション既定のカーソルをロード.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObjectで白ブラシを背景とする.
	wc.lpszMenuName = lpctszMenuName;	// メニューにはlpctszMenuNameをセット.
	wc.cbClsExtra = 0;	// とりあえず0を指定.
	wc.cbWndExtra = 0;	// とりあえず0を指定.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)){	// WindowsAPIのRegisterClassでウィンドウクラスを登録する.

		// 戻り値が0なら登録失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// 登録成功なのでTRUE.
	return TRUE;	// returnでTRUEを返す.

}

// スタティックウィンドウプロシージャStaticWindowProc関数の定義
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ポインタの初期化.
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindowをNULLで初期化.

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCTへのポインタlpCreateStructをNULL.

				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL){	// lpCreateStructがNULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindowオブジェクトポインタにキャストし, pWindowに格納.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL){	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに引数をそのまま渡して, DefWindowProcの戻り値をそのまま返す.

	}
	else{	// pWindowがNULLでない時.

		// そのCWindowオブジェクトのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに引数をそのまま渡して, DynamicWindowProcの戻り値をそのまま返す.

	}

}

// ウィンドウ作成関数Create.
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowでウィンドウを作成し, ハンドルをm_hWndに格納.(最後の引数にオブジェクト自身のポインタthisを渡す.)
	if (m_hWnd == NULL){	// m_hWndがNULLなら失敗.

		// m_hWndがNULLならウィンドウ作成失敗なのでエラー処理.
		return FALSE;	// FALSEを返す.

	}

	// ウィンドウ作成成功なのでTRUE.
	return TRUE;	// returnでTRUEを返す.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)

	// ウィンドウクラス名は"CWindow".
	return CWindow::Create(_T("CWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CWindow"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CWindow::Destroy(){

	// 変数の初期化.
	BOOL bDestroy = FALSE;	// 破棄に成功かどうかを示すbDestroyをFALSEに初期化.

	// 破棄処理.
	if (m_hWnd != NULL){	// m_hWndがNULLでない時.
		bDestroy = DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
		if (bDestroy){	// TRUEなら.
			m_hWnd = NULL;	// m_hWndにNULLをセット.
			return bDestroy;	// bDestroyを返す.
		}
	}

	// 上を通らない(破棄処理をしなかった)のでFALSE.
	return FALSE;	// returnでFALSEを返す.

}

// 子ウィンドウ破棄関数DestroyChildren
BOOL CWindow::DestroyChildren(){

	// ここでは何もせず, 常にFALSEを返す.
	return FALSE;

}

// ウィンドウ表示関数ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow){

	// ウィンドウの表示.
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// ダイナミックウィンドウプロシージャDynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウメッセージの処理.
	switch (uMsg){	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡し, あとは任せる.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// ウィンドウが閉じられる時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// OnCloseに任せる.
				if (OnClose() != 0){	// 0以外なら.
					return 0;	// 0を返す.(閉じなくなる.)
				}

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// 上記以外の時.
		default:

			// defaultブロック
			{

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

	}

	// あとは既定の処理に任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// 戻り値も含めてDefWindowProcに既定の処理を任せる.

}

// ウィンドウの作成が開始された時.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CWindow::OnDestroy(){

	// ウィンドウハンドルはNULL.
	m_hWnd = NULL;	// NULLをセット.

	// 終了メッセージの送信.
	PostQuitMessage(0);	// PostQuitMessageで終了コードを0としてWM_QUITメッセージを送信.

}

// ウィンドウが閉じられる時.
int CWindow::OnClose(){

	// 子ウィンドウの破棄.
	DestroyChildren();	// DestroyChildrenで子ウィンドウの破棄.

	// 常に閉じるものとする.
	return 0;	// 0を返してウィンドウを閉じる.

}