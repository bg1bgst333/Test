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