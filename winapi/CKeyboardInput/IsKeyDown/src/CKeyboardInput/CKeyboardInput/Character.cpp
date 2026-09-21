// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCCharacter
CCharacter::CCharacter(){

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
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
