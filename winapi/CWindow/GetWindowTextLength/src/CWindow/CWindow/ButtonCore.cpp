// ヘッダのインクルード
// 独自のヘッダ
#include "ButtonCore.h"	// CButtonCore

// ウィンドウ作成関数Create.
BOOL CButtonCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Button"を指定.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle | BS_PUSHBUTTON, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Button"を指定.

}