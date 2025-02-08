// 二重インクルード防止
#ifndef __DIBSECTION_H__
#define __DIBSECTION_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI

// DIBセクションクラスCDIBSection
class CDIBSection {

	// publicメンバ
	public:

		// publicメンバ変数
		HBITMAP m_hDIBSection;	// HBITMAP型DIBセクションハンドルm_hDIBSection.
		LPBYTE m_lpBitsPixel;	// LPBYTE型DIBセクションピクセル列m_lpBitsPixel.
		int m_iWidth;	// int型幅m_iWidth
		int m_iHeight;	// int型高さm_iHeight

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CDIBSection();	// コンストラクタCDIBSection()
		virtual ~CDIBSection();	// デストラクタ~CDIBSection()
		// メンバ関数
		virtual BOOL CreateDIBSection(HWND hWnd, int iWidth, int iHeight);	// DIBセクション作成関数CreateDIBSection.
		virtual BOOL SaveBitmap(HWND hWnd, LPCTSTR lpctszFileName);	// ビットマップ保存関数SaveBitmap.
		virtual BOOL LoadBitmap(LPCTSTR lpctszFileName, BOOL bLoad);	// ビットマップ読込関数LoadBitmap.
		virtual void SetPixel(int x, int y, BYTE r, BYTE g, BYTE b);	// 指定ピクセルに色をセットする関数SetPixel.

};

#endif