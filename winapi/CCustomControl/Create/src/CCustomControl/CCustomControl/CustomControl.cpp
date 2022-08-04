// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// staticメンバ変数の定義
std::map<LPCTSTR, WNDPROC>	CCustomControl::m_mapBaseWindowProcMap;	// ベースウィンドウプロシージャマップm_mapBaseWindowProcMap

// コンストラクタCCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// デストラクタ~CCustomControl
CCustomControl::~CCustomControl() {

}

// スタティックウィンドウプロシージャStaticWindowProc.
LRESULT CALLBACK CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// DefWindowProcに任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcの値を返す.

}

// ウィンドウ作成関数Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名にはlpctszClassNameを指定.
	BOOL bRet = CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名lpctszClassNameを指定.
	if (bRet) {	// bRetがTRUE.

		// 既定のウィンドウプロシージャを取得し, CCustomControl::StaticWindowProcに差し替える.
		WNDPROC lpfnWndProc;	// 既定のプロシージャlpfnWndProc
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLongでプロシージャlpfnWndProcを取得.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLongでプロシージャCCustomControl::StaticWindowProcを設定.

		// マップのキーにウィンドウクラス名がなければ登録.
		if (m_mapBaseWindowProcMap.find(lpctszClassName) == m_mapBaseWindowProcMap.end()) {	// マップに無い時.
			m_mapBaseWindowProcMap.insert(std::pair<LPCTSTR, WNDPROC>(lpctszClassName, lpfnWndProc));	// プロシージャを登録.
		}

		// WM_CREATEを通らないので, ウィンドウマップの登録も行う.
		if (m_mapWindowMap.find(m_hWnd) == m_mapWindowMap.end()) {	// ウィンドウマップになければ.
			m_mapWindowMap.insert(std::pair<HWND, CWindow*>(m_hWnd, this));	// 登録する.
		}

	}
	return bRet;	// bRetを返す.

}

// ウィンドウ破棄関数Destroy
BOOL CCustomControl::Destroy() {

	// 親クラスのDestroyを呼ぶ.
	return CWindow::Destroy();	// CWindow::Destroyを呼ぶ.

}

// ウィンドウの作成が開始された時.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CCustomControl::OnDestroy() {

	// ここでは何も呼ばない.

}