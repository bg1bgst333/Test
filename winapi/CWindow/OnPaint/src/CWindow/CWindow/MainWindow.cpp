// ヘッダのインクルード
// 独自のヘッダ
#include "MainWindow.h"	// CMainWindow

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウクラス名は"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名"CMainWindow"を指定.

}

// ウィンドウの描画を要求された時.
void CMainWindow::OnPaint(){

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 文字列の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TextOut(hDC, 0, 0, _T("CWindow"), (int)_tcslen(_T("CWindow")));	// Win32APIのTextOutで"CWindow"と描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}