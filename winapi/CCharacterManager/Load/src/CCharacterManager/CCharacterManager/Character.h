// 二重インクルード防止
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

// ヘッダのインクルード
// 標準のヘッダ
#include <tchar.h>	// TCHAR型, _Tマクロ
// 独自のヘッダ
#include "Sprite.h"	// CSprite

// 前方宣言
class CGraphicalApplication;	// CGraphicalApplication.(実体の定義はCharacter.cpp内でインクルードする. ここではポインタとして持つだけなので前方宣言で十分.)

// 歩行アニメーションのコマ数・切り替え間隔
#define WALK_FRAME_COUNT	8	// 歩行アニメーションのコマ数WALK_FRAME_COUNT.
#define WALK_FRAME_INTERVAL	100	// 歩行アニメーションのコマ切り替え間隔(ミリ秒)WALK_FRAME_INTERVAL.
#define MOVE_SPEED	150.0f	// 1秒あたりの移動速度(ピクセル)MOVE_SPEED.(Logicで時間ベースの移動量を計算するのに使う.)

// キャラクタークラスCCharacter
class CCharacter{

	// public メンバ
	public:

		// public メンバ変数
		int m_x;	// キャラクターのX座標m_x.
		int m_y;	// キャラクターのY座標m_y.
		int m_vx;	// キャラクターのX方向の速度m_vx.(MoveRightなどで設定する. 座標の更新自体はLogicで行う.)
		int m_vy;	// キャラクターのY方向の速度m_vy.(今のところInputから直接設定する.)
		CGraphicalApplication *m_pGraphicalApplication;	// 所属先であるCGraphicalApplicationへのポインタm_pGraphicalApplication.(引数なしのRenderで, 現在のバックバッファのDCをこれ経由で取得するために使う.)
		CSprite m_Sprites[WALK_FRAME_COUNT];	// 歩行アニメーション用のCSprite配列m_Sprites.(8コマ分, Loadでまとめてロードする.)
		int m_iCurrentFrame;	// 現在描画中のコマ番号m_iCurrentFrame.(0からWALK_FRAME_COUNT-1まで.)
		DWORD m_dwLastFrameTime;	// 直前にコマを進めた時刻m_dwLastFrameTime.(GetTickCountと比較する.)
		FLOAT m_fPosX;	// サブピクセル精度のX座標アキュムレータm_fPosX.(Logicでの時間ベース移動に使う. m_xはこれをintにキャストした値.)
		FLOAT m_fPosY;	// サブピクセル精度のY座標アキュムレータm_fPosY.(Logicでの時間ベース移動に使う. m_yはこれをintにキャストした値.)
		DWORD m_dwLastLogicTime;	// 直前にLogicを呼んだ時刻m_dwLastLogicTime.(GetTickCountと比較し, 経過時間を秒単位の移動量に変換する.)

		// public メンバ関数
		// コンストラクタ
		CCharacter();	// コンストラクタCCharacter
		// メンバ関数
		virtual BOOL Load(HINSTANCE hInstance, LPCTSTR pszPrefix = _T("character1"));	// 画像読込関数Load.(m_Sprites[0]からm_Sprites[WALK_FRAME_COUNT-1]まで, "pszPrefix_1.bmp"から"pszPrefix_8.bmp"までを順にロードしていく. pszPrefixを省略した場合は既定の"character1"になる.)
		virtual void Render(HDC hDC);	// 描画処理関数Render.(指定されたHDCに, 自分の位置(m_x, m_y)へm_Sprites[m_iCurrentFrame]を描画する.)
		virtual void Render();	// 描画処理関数Render.(引数なしオーバーロード. m_pGraphicalApplication->m_hBackBufferDCへ描画する.)
		virtual void MoveRight();	// 右移動関数MoveRight.(右へ進むよう, 自分の速度m_vxを設定する.)
		virtual void MoveLeft();	// 左移動関数MoveLeft.(左へ進むよう, 自分の速度m_vxを設定する.)
		virtual void MoveDown();	// 下移動関数MoveDown.(下へ進むよう, 自分の速度m_vyを設定する.)
		virtual void MoveUp();	// 上移動関数MoveUp.(上へ進むよう, 自分の速度m_vyを設定する.)
		virtual void StopHorizontal();	// 水平停止関数StopHorizontal.(X方向の速度m_vxを0にする.)
		virtual void StopVertical();	// 垂直停止関数StopVertical.(Y方向の速度m_vyを0にする.)
		virtual void Input();	// 入力処理関数Input.(矢印キーの押下状態を調べ, 自分の速度(m_vx, m_vy)に反映する.)
		virtual void Logic();	// ロジック処理関数Logic.(速度(m_vx, m_vy)と経過時間から, 時間ベースで座標を進め, 画面端でクランプする.)
		virtual void Animate();	// アニメーション処理関数Animate.(移動中なら, 時間経過に応じてm_iCurrentFrameを進める. 止まっていれば何もしない.)

};

#endif
