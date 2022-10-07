// ヘッダのインクルード
// 独自のヘッダ
#include "StaticCore.h"	// CStaticCore

// ウィンドウ作成関数Create.
BOOL CStaticCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Static"を指定.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Static"を指定.

}

// ウィンドウ作成関数Create(RECTバージョン).
BOOL CStaticCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"Static"を指定.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, rect, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"Static"を指定.

}

// ビットマップのセットSetBitmap.
void CStaticCore::SetBitmap(HBITMAP hBitmap) {

	// スタティックコントロールにビットマップをセット.
	SendMessage(m_hWnd, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);	// SendMessageのSTM_SETIMAGEでm_hWndにhBitmapをセット.

}