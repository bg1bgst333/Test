// 二重インクルード防止
#ifndef __CHARACTER_MANAGER_H__
#define __CHARACTER_MANAGER_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "Character.h"	// CCharacter

// 前方宣言
class CGraphicalApplication;	// CGraphicalApplication.(実体の定義はCharacterManager.cpp内でインクルードする. ここではポインタとして持つだけなので前方宣言で十分.)

// 管理するキャラクターの人数
#define CHARACTER_COUNT	3	// CCharacterManagerが管理するキャラクターの人数CHARACTER_COUNT.

// 接地ライン(足元を揃えるY座標)
#define FOOT_BASELINE_Y	286	// 全キャラクター共通の接地ラインFOOT_BASELINE_Y.(Loadで, 各キャラクターの実測スプライト高さをこの値から引いてm_yを決める. キャラごとにキャンバスサイズ(身長差)が違っても足元が揃う.)

// キャラクター管理クラスCCharacterManager
class CCharacterManager {

	// public メンバ
	public:

		// public メンバ変数
		CCharacter m_Characters[CHARACTER_COUNT];	// 管理対象のCCharacter配列m_Characters.(Loadでまとめてロードし, Input/Logic/Renderをまとめて呼び出す.)
		CGraphicalApplication *m_pGraphicalApplication;	// 所属先のCGraphicalApplicationへのポインタm_pGraphicalApplication.(各m_Characters[i].m_pGraphicalApplicationにそのまま渡すために持つ.)

		// public メンバ関数
		// コンストラクタ
		CCharacterManager();	// コンストラクタCCharacterManager
		// メンバ関数
		virtual BOOL Load(HINSTANCE hInstance);	// 画像読込関数Load.(全キャラクターのスプライトをロードし, FOOT_BASELINE_Yを基準にそれぞれ足元が揃う初期位置に配置する.)
		virtual void Input();	// 入力処理関数Input.(先頭のm_Characters[0]だけがプレイヤー操作対象. 他のキャラクターはその場に留まる.)
		virtual void Logic();	// ロジック処理関数Logic.(全キャラクターのLogicを順に呼び出す.)
		virtual void Render();	// 描画処理関数Render.(全キャラクターのRenderを順に呼び出す.)

};

#endif
