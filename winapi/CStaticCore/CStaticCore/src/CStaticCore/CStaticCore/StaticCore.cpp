// ヘッダのインクルード
// 独自のヘッダ
#include "StaticCore.h"	// CStaticCore

// ウィンドウ作成関数Create.
BOOL CStaticCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Static"を指定.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Static"を指定.

}