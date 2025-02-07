// 二重インクルード防止
#ifndef __SCREEN_H__
#define __SCREEN_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "Canvas.h"	// CCanvas
#include "DIBSection.h"	// CDIBSection

// スクリーンクラスCScreen
class CScreen : public CUserControl {

	// publicメンバ
	public:

		// メンバ変数
		CCanvas* m_pCanvas;	// CCanvasオブジェクトポインタm_pCanvas.
		CDIBSection* m_pDIBSection;	// CDIBSectionオブジェクトポインタm_pDIBSection.
		HINSTANCE m_hInstance;	// インスタンスハンドルm_hInstance.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CScreen();	// コンストラクタCScreen
		virtual ~CScreen();	// デストラクタ~CScreen
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		static BOOL RegisterClass(HINSTANCE hInstance, int i);	// ウィンドウクラス登録関数RegisterClass(背景色指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL DestroyChildren();	// 子ウィンドウ破棄関数DestroyChildren
		const CCanvas* CreateCanvas(int x, int y, int iWidth, int iHeight, HMENU hMenu);	// キャンバス作成関数CreateCanvas.
		virtual BOOL SaveBitmap(LPCTSTR lpctszFileName);	// ビットマップ保存関数SaveBitmap.
		virtual BOOL LoadBitmap(LPCTSTR lpctszFileName);	// ビットマップ読込関数LoadBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.

};

#endif