// 二重インクルード防止
#ifndef __COMBO_BOX_H__
#define __COMBO_BOX_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// コンボボックスコントロールクラス
class CComboBox : public CCustomControl {

	// publicメンバ
	public:

		// publicメンバ巻数
		// コンストラクタ・デストラクタ
		CComboBox();	// コンストラクタCComboBox
		virtual ~CComboBox();	// デストラクタ~CComboBox
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.
		void AddString(LPCTSTR lpctszStr);	// コンボボックスに文字列を追加する関数AddString.
		int GetCurSel();	// コンボボックスで選択されている要素のインデックスを返すGetCurSel.
		void SetCurSel(int iIndex);	// コンボボックスの指定のインデックス要素を選択SetCurSel.

};

#endif