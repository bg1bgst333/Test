// 二重インクルード防止
#ifndef __BITMAP_H__
#define __BITMAP_H__

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI

// ビットマップクラスCBitmap
class CBitmap {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBitmap();	// コンストラクタCBitmap()
		virtual ~CBitmap();	// デストラクタ~CBitmap()
		// メンバ関数
		virtual BOOL LoadBitmap(HINSTANCE hInstance, LPCTSTR lpctszResourceName);	// ビットマップリソースロード関数LoadBitmap.
		virtual BOOL LoadImage(HINSTANCE hInstance, LPCTSTR lpctszFileName, UINT uType, int cxDesired, int cyDesired, UINT fuLoad);	// ビットマップイメージファイルロード関数LoadImage.

		// publicメンバ演算子
		// メンバ演算子
		operator HBITMAP() const;	// HBITMAP演算子

	// privateメンバ
	private:

		// privateメンバ変数
		// メンバ変数
		HBITMAP m_hBitmap;	// HBITMAP型ビットマップハンドルm_hBitmap.

};

#endif