// 二重インクルード防止
#ifndef __ENCODING_COMBO_BOX_H__
#define __ENCODING_COMBO_BOX_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "ComboBox.h"	// CComboBox

// エンコーディングコンボボックスコントロールクラス
class CEncodingComboBox : public CComboBox {

	// publicメンバ
	public:

		// publicメンバ巻数
		// メンバ関数
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時.

};

#endif