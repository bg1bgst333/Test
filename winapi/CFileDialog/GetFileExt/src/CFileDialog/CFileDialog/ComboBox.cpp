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

// コンボボックスに文字列を追加する関数AddString.
void CComboBox::AddString(LPCTSTR lpctszStr) {

	// 指定の文字列を追加.
	SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)lpctszStr);	// SendMessageでCB_ADDSTRINGを送ることで指定の文字列を追加.

}

// コンボボックスで選択されている要素のインデックスを返すGetCurSel.
int CComboBox::GetCurSel() {

	// 選択されている要素のインデックスを返す.
	return (int)SendMessage(m_hWnd, CB_GETCURSEL, 0, 0);	// SendMessageでCB_GETCURSELを送ることで選択された要素のインデックスを取得.

}

// コンボボックスの指定のインデックス要素を選択SetCurSel.
void CComboBox::SetCurSel(int iIndex) {

	// 指定の要素をセット.
	SendMessage(m_hWnd, CB_SETCURSEL, (WPARAM)iIndex, 0);	// SendMessageでCB_SETCURSELを送ることで指定の要素を選択.

}