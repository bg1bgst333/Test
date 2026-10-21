// ヘッダのインクルード
// 独自のヘッダ
#include "CharacterManager.h"	// CCharacterManager
#include "GraphicalApplication.h"	// CGraphicalApplication

// コンストラクタCCharacterManager
CCharacterManager::CCharacterManager(){

	// メンバの初期化.
	m_pGraphicalApplication = NULL;	// m_pGraphicalApplicationをNULLで初期化.(使う前にMain側でセットされる.)

}

// 画像読込関数Load.
BOOL CCharacterManager::Load(HINSTANCE hInstance){

	// キャラクターごとに使うスプライトのファイル名接頭辞.(CCharacter::LoadにpszPrefixを渡すだけで, キャラクターごとに違う見た目にできる.)
	static LPCTSTR pszPrefixes[CHARACTER_COUNT] = { _T("character1"), _T("character2"), _T("character3") };	// 0番目は制服(character1), 1番目は水色(character2), 2番目はピンク(character3).

	// 全キャラクターをロードし, それぞれ別の位置に並べて配置する.
	for (int i = 0; i < CHARACTER_COUNT; i++){	// iを0からCHARACTER_COUNT-1まで回す.

		m_Characters[i].m_pGraphicalApplication = m_pGraphicalApplication;	// m_Characters[i].m_pGraphicalApplicationに自分自身が持つポインタをそのまま渡す.

		if (!m_Characters[i].Load(hInstance, pszPrefixes[i])){	// m_Characters[i].LoadにpszPrefixes[i]を渡して画像をロードし, 失敗した場合.

			return FALSE;	// returnでFALSEを返して異常終了.

		}

		// 初期位置を, キャラクターごとに横に並べて配置する.(重ならないよう150ピクセルずつずらす.)
		m_Characters[i].m_x = 100 + i * 150;	// m_Characters[i].m_xを100 + i * 150に設定.
		m_Characters[i].m_y = 200;	// m_Characters[i].m_yを200に設定.
		m_Characters[i].m_fPosX = (FLOAT)m_Characters[i].m_x;	// アキュムレータm_fPosXもm_xに合わせておく.(Logicでの時間ベース移動のずれを防ぐ.)
		m_Characters[i].m_fPosY = (FLOAT)m_Characters[i].m_y;	// アキュムレータm_fPosYもm_yに合わせておく.

	}

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 入力処理関数Input.
void CCharacterManager::Input(){

	// 先頭のm_Characters[0]だけにキー入力を反映する.(他のキャラクターはm_vx/m_vyが常に0のままなので, その場に留まる.)
	m_Characters[0].Input();	// m_Characters[0].Inputで矢印キーの押下状態を調べ, 先頭キャラクターの速度に反映させる.

}

// ロジック処理関数Logic.
void CCharacterManager::Logic(){

	// 全キャラクターのLogicを順に呼び出す.
	for (int i = 0; i < CHARACTER_COUNT; i++){	// iを0からCHARACTER_COUNT-1まで回す.

		m_Characters[i].Logic();	// m_Characters[i].Logicで座標更新と画面端クランプを行わせる.

	}

}

// 描画処理関数Render.
void CCharacterManager::Render(){

	// 全キャラクターのRenderを順に呼び出す.
	for (int i = 0; i < CHARACTER_COUNT; i++){	// iを0からCHARACTER_COUNT-1まで回す.

		m_Characters[i].Render();	// m_Characters[i].Renderで自分自身をバックバッファへ描画させる.

	}

}
