// 二重インクルード防止
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "GraphicalApplication.h"	// CGraphicalApplication
#include "CharacterManager.h"	// CCharacterManager

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CGraphicalApplication{

	// public メンバ
	public:

		// public メンバ変数
		CCharacterManager m_CharacterManagerA;	// 比較用のキャラクター管理オブジェクトm_CharacterManagerA.(Loadはするが, Renderを一度も呼ばない.)
		CCharacterManager m_CharacterManagerB;	// 本来の使い方をするキャラクター管理オブジェクトm_CharacterManagerB.(Loadした後, 毎フレームRenderを呼ぶ.)

		// public メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance.
		virtual void Render();	// 描画処理関数Render.(CGraphicalApplication::Renderをオーバーライド. m_CharacterManagerBだけRenderを呼ぶ.)

};

#endif
