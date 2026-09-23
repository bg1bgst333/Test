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
	m_iCurrentFrame = 0;	// m_iCurrentFrameを0で初期化.
	m_dwLastFrameTime = 0;	// m_dwLastFrameTimeを0で初期化.(最初のLogicで即座に判定される.)

}

// 画像読込関数Load.
BOOL CCharacter::Load(HINSTANCE hInstance){

	// m_Sprites[0]からm_Sprites[WALK_FRAME_COUNT-1]まで、walk1.bmpからwalk8.bmpまでを順にロードさせる.
	for (int i = 0; i < WALK_FRAME_COUNT; i++){	// iを0からWALK_FRAME_COUNT-1まで回す.

		TCHAR tszFileName[16];	// ファイル名を組み立てるバッファtszFileName.
		wsprintf(tszFileName, _T("walk%d.bmp"), i + 1);	// wsprintfで"walk1.bmp"から"walk8.bmp"までを組み立てる.
		if (!m_Sprites[i].Load(hInstance, tszFileName)){	// m_Sprites[i].Loadでロードし, 失敗した場合.

			return FALSE;	// returnでFALSEを返して異常終了.

		}

	}

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 描画処理関数Render.
void CCharacter::Render(HDC hDC){

	// m_Sprites[m_iCurrentFrame]の描画位置を自分の座標に合わせる.
	m_Sprites[m_iCurrentFrame].m_x = m_x;	// m_Sprites[m_iCurrentFrame].m_xにm_xを反映.
	m_Sprites[m_iCurrentFrame].m_y = m_y;	// m_Sprites[m_iCurrentFrame].m_yにm_yを反映.

	// m_Sprites[m_iCurrentFrame].Drawで自分を描画する.
	m_Sprites[m_iCurrentFrame].Draw(hDC);	// m_Sprites[m_iCurrentFrame].Drawで現在のコマを描画.

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
void CCharacter::Input(){

	// 矢印キーの押下状態を調べて, 自分の速度(m_vx, m_vy)に反映する.(座標の更新自体はLogicで行う.)
	if (CKeyboardInput::IsKeyDown(VK_RIGHT)){	// 右矢印キーが押されている場合.
		MoveRight();	// MoveRightで右へ移動させる.
	}else if (CKeyboardInput::IsKeyDown(VK_LEFT)){	// 左矢印キーが押されている場合.
		MoveLeft();	// MoveLeftで左へ移動させる.
	}else{	// どちらも押されていない場合.
		StopHorizontal();	// StopHorizontalで水平方向の速度を止める.
	}
	if (CKeyboardInput::IsKeyDown(VK_DOWN)){	// 下矢印キーが押されている場合.
		MoveDown();	// MoveDownで下へ移動させる.
	}else if (CKeyboardInput::IsKeyDown(VK_UP)){	// 上矢印キーが押されている場合.
		MoveUp();	// MoveUpで上へ移動させる.
	}else{	// どちらも押されていない場合.
		StopVertical();	// StopVerticalで垂直方向の速度を止める.
	}

}

// ロジック処理関数Logic.
void CCharacter::Logic(){

	// 速度(m_vx, m_vy)の分だけ座標を進める.
	m_x += m_vx;	// m_xにm_vxを加算.
	m_y += m_vy;	// m_yにm_vyを加算.

	// 画面端で止まるようにクランプする.(跳ね返らず, それ以上は進めない. サイズはm_Sprites[0]の実寸を使う.)
	if (m_x < 0){	// 左端を超えた場合.
		m_x = 0;	// 左端に合わせる.
	}
	if (m_x > m_pGraphicalApplication->m_iBackBufferWidth - m_Sprites[0].m_iWidth){	// 右端を超えた場合.
		m_x = m_pGraphicalApplication->m_iBackBufferWidth - m_Sprites[0].m_iWidth;	// 右端に合わせる.
	}
	if (m_y < 0){	// 上端を超えた場合.
		m_y = 0;	// 上端に合わせる.
	}
	if (m_y > m_pGraphicalApplication->m_iBackBufferHeight - m_Sprites[0].m_iHeight){	// 下端を超えた場合.
		m_y = m_pGraphicalApplication->m_iBackBufferHeight - m_Sprites[0].m_iHeight;	// 下端に合わせる.
	}

	// アニメーションのコマを進める.
	Animate();

}

// アニメーション処理関数Animate.
void CCharacter::Animate(){

	// 移動中(m_vxかm_vyのどちらかが0でない)でなければ, 何もしない.
	if (m_vx == 0 && m_vy == 0){	// 止まっている場合.

		return;	// returnで何もせず抜ける.

	}

	// 時間経過に応じてm_iCurrentFrameを進める.
	DWORD dwNow = GetTickCount();	// GetTickCountで現在時刻(起動からのミリ秒)を取得.
	if (dwNow - m_dwLastFrameTime >= WALK_FRAME_INTERVAL){	// 前回コマを進めてからWALK_FRAME_INTERVAL以上経過している場合.

		m_iCurrentFrame = (m_iCurrentFrame + 1) % WALK_FRAME_COUNT;	// m_iCurrentFrameを1つ進め, WALK_FRAME_COUNTで折り返す.
		m_dwLastFrameTime = dwNow;	// m_dwLastFrameTimeを現在時刻に更新.

	}

}
