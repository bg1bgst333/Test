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

};

#endif