// ヘッダのインクルード
// 独自のヘッダ
#include "EditCore.h"	// CEditCore

// ウィンドウ作成関数Create.
BOOL CEditCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Edit"を指定.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Edit"を指定.

}

// ウィンドウ作成関数Create(RECTバージョン).
BOOL CEditCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Edit"を指定.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rect, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Edit"を指定.

}