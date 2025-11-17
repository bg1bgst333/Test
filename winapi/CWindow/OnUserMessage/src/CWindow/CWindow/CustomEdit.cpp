// ヘッダのインクルード
// 独自のヘッダ
#include "CustomEdit.h"	// CCustomEdit

// ウィンドウ作成関数Create.
BOOL CCustomEdit::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// エディットコントロールのウィンドウ作成.
	return CEditCore::Create(lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CEditCore::Createでウィンドウ作成.

}

// ウィンドウの作成が開始された時.
int CCustomEdit::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ウィンドウサイズの取得.
	RECT rc = {0};
	GetWindowRect(hwnd, &rc);
	int iWidth = rc.right - rc.left;
	int iHeight = rc.bottom - rc.top;

	// WM_USERMESSAGEを投げる.
	WPARAM wParam;
	wParam = MAKEWPARAM(iWidth, iHeight);
	SendMessage(GetParent(hwnd), WM_USERMESSAGE, wParam, (LPARAM)hwnd);

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}