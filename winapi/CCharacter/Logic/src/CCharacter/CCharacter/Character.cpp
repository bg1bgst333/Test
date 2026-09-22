// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "KeyboardInput.h"	// CKeyboardInput

// コンストラクタCCharacter
CCharacter::CCharacter(){

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
	m_vx = 0;	// m_vxを0で初期化.
	m_vy = 0;	// m_vyを0で初期化.
	m_pGraphicalApplication = NULL;	// m_pGraphicalApplicationをNULLで初期化.(使う前にMain側でセットする.)

}

// 描画処理関数Render.
void CCharacter::Render(HDC hDC){

	// 自分の位置(m_x, m_y)に赤い四角形として自分を描画する.
	RECT rc = {m_x, m_y, m_x + CHARACTER_SIZE, m_y + CHARACTER_SIZE};	// キャラクターの矩形rc.
	CPaint::FillRect(hDC, rc, RGB(255, 0, 0));	// CPaint::FillRectで自分の位置に赤い四角形を描画.

}

// 描画処理関数Render.(引数なしオーバーロード.)
void CCharacter::Render(){

	// m_pGraphicalApplicationが持つ現在のバックバッファのDCへ描画する.
	Render(m_pGraphicalApplication->m_hBackBufferDC);	// Render(HDC)へ委譲する.

}

// 右移動関数MoveRight.
void CCharacter::MoveRight(){

	// 右へ進むよう, 速度m_vxを1にする.(座標の更新自体はLogicで行う.)
	m_vx = 1;	// m_vxを1に.

}

// 左移動関数MoveLeft.
void CCharacter::MoveLeft(){

	// 左へ進むよう, 速度m_vxを-1にする.(座標の更新自体はLogicで行う.)
	m_vx = -1;	// m_vxを-1に.

}

// 下移動関数MoveDown.
void CCharacter::MoveDown(){

	// 下へ進むよう, 速度m_vyを1にする.(座標の更新自体はLogicで行う.)
	m_vy = 1;	// m_vyを1に.

}

// 上移動関数MoveUp.
void CCharacter::MoveUp(){

	// 上へ進むよう, 速度m_vyを-1にする.(座標の更新自体はLogicで行う.)
	m_vy = -1;	// m_vyを-1に.

}

// 水平停止関数StopHorizontal.
void CCharacter::StopHorizontal(){

	// X方向の速度m_vxを0にする.
	m_vx = 0;	// m_vxを0に.

}

// 垂直停止関数StopVertical.
void CCharacter::StopVertical(){

	// Y方向の速度m_vyを0にする.
	m_vy = 0;	// m_vyを0に.

}

// 入力処理関数Input.
void CCharacter::Input() {

	// 矢印キーの押下状態を調べて, 自分の速度(m_vx, m_vy)に反映する.(座標の更新自体はLogicで行う.)
	if (CKeyboardInput::IsKeyDown(VK_RIGHT)) {	// 右矢印キーが押されている場合.
		MoveRight();	// MoveRightで右へ移動させる.
	} else if (CKeyboardInput::IsKeyDown(VK_LEFT)) {	// 左矢印キーが押されている場合.
		MoveLeft();	// MoveLeftで左へ移動させる.
	} else {	// どちらも押されていない場合.
		StopHorizontal();	// StopHorizontalで水平方向の速度を止める.
	}
	if (CKeyboardInput::IsKeyDown(VK_DOWN)) {	// 下矢印キーが押されている場合.
		MoveDown();	// MoveDownで下へ移動させる.
	} else if (CKeyboardInput::IsKeyDown(VK_UP)) {	// 上矢印キーが押されている場合.
		MoveUp();	// MoveUpで上へ移動させる.
	} else {	// どちらも押されていない場合.
		StopVertical();	// StopVerticalで垂直方向の速度を止める.
	}

}

// ロジック処理関数Logic.
void CCharacter::Logic() {

	// 速度(m_vx, m_vy)の分だけ座標を進める.
	m_x += m_vx;	// m_xにm_vxを加算.
	m_y += m_vy;	// m_yにm_vyを加算.

	// 画面端で止まるようにクランプする.(跳ね返らず, それ以上は進めない.)
	if (m_x < 0) {	// 左端を超えた場合.
		m_x = 0;	// 左端に合わせる.
	}
	if (m_x > m_pGraphicalApplication->m_iBackBufferWidth - CHARACTER_SIZE) {	// 右端を超えた場合.
		m_x = m_pGraphicalApplication->m_iBackBufferWidth - CHARACTER_SIZE;	// 右端に合わせる.
	}
	if (m_y < 0) {	// 上端を超えた場合.
		m_y = 0;	// 上端に合わせる.
	}
	if (m_y > m_pGraphicalApplication->m_iBackBufferHeight - CHARACTER_SIZE) {	// 下端を超えた場合.
		m_y = m_pGraphicalApplication->m_iBackBufferHeight - CHARACTER_SIZE;	// 下端に合わせる.
	}

}
