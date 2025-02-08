// 二重インクルード防止
#ifndef __CANVAS_H__
#define __CANVAS_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl
#include "DIBSection.h"	// CDIBSection

// キャンバスクラスCCanvas
class CCanvas : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		HDC m_hDC;	// HDC型デバイスコンテキストハンドルm_hDC.
		HDC m_hMemDC;	// HDC型メモリデバイスコンテキストハンドルm_hMemDC.
		HBITMAP m_hOldBitmap;	// HBITMAP型の以前のビットマップハンドルm_hOldBitmap.
		CDIBSection* m_pDIBSection;	// CDIBSectionオブジェクトポインタm_pDIBSection.
		RGBQUAD m_rgbqCurrentColor;	// RGBQUAD構造体変数m_rgbqCurrentColor.
		HPEN m_hPen;	// HPEN型ペンハンドルm_hPen.
		HPEN m_hOldPen;	// HPEN型の以前のペンハンドルm_hOldPen.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CCanvas();	// コンストラクタCCanvas
		virtual ~CCanvas();	// デストラクタ~CCanvas
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		static BOOL RegisterClass(HINSTANCE hInstance, int i);	// ウィンドウクラス登録関数RegisterClass(背景色指定バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual void SetBitmap(CDIBSection* pDIBSection);	// ビットマップのセットSetBitmap(CDIBSectionポインタ).
		virtual void SetCurrentColor(BYTE r, BYTE g, BYTE b);	// 現在の色をセットする関数SetCurrentColor.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnPaint();	// ウィンドウの描画を要求された時.
		virtual void OnMouseMove(UINT nFlags, POINT pt);	// マウスが移動している時.
		virtual void OnLButtonDown(UINT nFlags, POINT pt);	// マウスの左ボタンが押された時.
		virtual void OnLButtonUp(UINT nFlags, POINT pt);	// マウスの左ボタンが離された時.

};

#endif