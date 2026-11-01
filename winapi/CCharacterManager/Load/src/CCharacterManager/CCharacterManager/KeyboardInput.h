// 二重インクルード防止
#ifndef __KEYBOARD_INPUT_H__
#define __KEYBOARD_INPUT_H__

// ヘッダのインクルード
// 標準のヘッダ
#include <windows.h>	// 標準WindowsAPI

// キーボード入力クラスCKeyboardInput
class CKeyboardInput{

	// publicメンバ
	public:

		// publicメンバ関数
		// static関数
		static BOOL IsKeyDown(int nVirtKey);	// 指定した仮想キーコードが現在押されているかを調べる関数IsKeyDown.(状態を持たない静的関数. GetAsyncKeyStateをラップする.)

};

#endif
