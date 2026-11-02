// ヘッダのインクルード
// 独自のヘッダ
#include "KeyboardInput.h"	// CKeyboardInput

// 指定した仮想キーコードが現在押されているかを調べる関数IsKeyDown.
BOOL CKeyboardInput::IsKeyDown(int nVirtKey){

	// GetAsyncKeyStateの最上位ビットで押下状態を調べる.
	return (GetAsyncKeyState(nVirtKey) & 0x8000) ? TRUE : FALSE;	// GetAsyncKeyStateでnVirtKeyの押下状態を調べ, 押されていればTRUEを返す.

}
