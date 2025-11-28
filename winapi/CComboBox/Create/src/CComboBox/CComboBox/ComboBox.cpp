// ヘッダのインクルード
// 独自のヘッダ
#include "ComboBox.h"	// CComboBox

// コンストラクタCComboBox
CComboBox::CComboBox() : CCustomControl() {

}

// デストラクタ~CComboBox
CComboBox::~CComboBox() {

	// メンバの終了処理
	Destroy();	// Destroyでこのウィンドウの終了処理をする.

}

// ウィンドウ作成関数Create.
BOOL CComboBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名には"ComboBox"を指定.
	return CCustomControl::Create(_T("ComboBox"), lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createにウィンドウクラス名"ComboBox"を指定.

}
