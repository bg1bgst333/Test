// 二重インクルード防止
#ifndef __PICTURE_H__
#define __PICTURE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "StaticCore.h"	// CStaticCore

// ピクチャークラスCPicture
class CPicture : public CStaticCore {

	// publicメンバ
	public:

		// publicメンバ関数
		// メンバ関数
		virtual void OnPaint();	// ウィンドウの描画を要求された時.

};

#endif