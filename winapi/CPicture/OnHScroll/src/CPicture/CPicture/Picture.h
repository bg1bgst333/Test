// 二重インクルード防止
#ifndef __PICTURE_H__
#define __PICTURE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// CUserControl

// ピクチャークラスCPicture
class CPicture : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CPicture();	// コンストラクタCPicture
		virtual ~CPicture();	// デストラクタ~CPicture
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
		virtual BOOL Destroy();	// ウィンドウ破棄関数Destroy
		virtual void SetBitmap(HBITMAP hBitmap);	// ビットマップのセットSetBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウの作成が開始された時.
		virtual void OnPaint();	// ウィンドウの描画を要求された時.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// 水平方向スクロールバーイベント時.

	// privateメンバ
	private:

		// privateメンバ変数
		// メンバ変数
		HDC m_hDC;	// HDC型デバイスコンテキストハンドルm_hDC.
		HDC m_hMemDC;	// HDC型メモリデバイスコンテキストハンドルm_hMemDC.
		HBITMAP m_hBitmap;	// HBITMAP型ビットマップハンドルm_hBitmap.
		HBITMAP m_hOldBitmap;	// HBITMAP型の以前のビットマップハンドルm_hOldBitmap.
		int m_dx;	// 水平方向の変化量m_dx.

};

#endif