// ヘッダのインクルード
// 独自のヘッダ
#include "DIBSection.h"	// CDIBSection
#include "BinaryFile.h"	// CBinaryFile

// コンストラクタCDIBSection()
CDIBSection::CDIBSection(){

	// メンバの初期化.
	m_hDIBSection = NULL;	// m_hDIBSectionをNULLで初期化.
	m_lpBitsPixel = NULL;	// m_lpBitsPixelをNULLで初期化.

}

// デストラクタ~CDIBSection()
CDIBSection::~CDIBSection(){

	// メンバの終了処理.
	if (m_hDIBSection != NULL){	// NULLでない.
		::DeleteObject(m_hDIBSection);	// DeleteObjectで破棄.
		m_hDIBSection = NULL;	// NULLをセット.
	}
	m_lpBitsPixel = NULL;	// 自動解放なのでNULLをセット.

}

// DIBセクション作成関数CreateDIBSection.
BOOL CDIBSection::CreateDIBSection(HWND hWnd, int iWidth, int iHeight){

	// 変数の宣言・初期化
	HDC hDC = NULL;	// ウィンドウのデバイスコンテキストハンドルhDCをNULLに初期化.
	BITMAPINFO bi = {0};	// ビットマップ情報BiTMAPINFO構造体biを{0}で初期化.
	m_iWidth = iWidth;	// 幅をセット.
	m_iHeight = iHeight;	// 高さをセット.

	// ウィンドウのデバイスコンテキストハンドルを取得.
	hDC = GetDC(hWnd);	// GetDCでウィンドウのデバイスコンテキストハンドルを取得し, hDCに格納.
	if (hDC){

		// ビットマップ情報のセット.
		bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bi.bmiHeader.biWidth = m_iWidth;
		bi.bmiHeader.biHeight = m_iHeight;
		bi.bmiHeader.biPlanes = 1;
		bi.bmiHeader.biBitCount = 24;
		bi.bmiHeader.biCompression = BI_RGB;

		// DIBセクションの作成.
		m_hDIBSection = ::CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&m_lpBitsPixel, NULL, 0);	// CreateDIBSectionでDIBセクションを作成.

		// デバイスコンテキストの解放.
		ReleaseDC(hWnd, hDC);	// ReleaseDCでデバイスコンテキストを解放.

		// NULLじゃなければ成功.
		if (m_hDIBSection != NULL){
			return TRUE;
		}

	}

	return FALSE;

}

// ビットマップ保存関数SaveBitmap.
BOOL CDIBSection::SaveBitmap(HWND hWnd, LPCTSTR lpctszFileName){

	// 変数の初期化.
	BITMAPINFO bi = {0};	// BITMAPINFO構造体変数biを{0}で初期化.
	BITMAPFILEHEADER bfh = {0};	// BITMAPFILEHEADER構造体bfhを{0}で初期化.
	HDC hDC = NULL;	// hDCをNULLで初期化.

	// ビットマップ情報のセット.
	bi.bmiHeader.biBitCount = 24;	// ひとまず24bitビットマップのみ対応.
	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);	// BITMAPINFOHEADERのサイズを指定しておく.
	bi.bmiHeader.biWidth = m_iWidth;	// 幅をセット.
	bi.bmiHeader.biHeight = m_iHeight;	// 高さをセット.
	bi.bmiHeader.biPlanes = 1;	// 1をセット.
	bi.bmiHeader.biCompression = BI_RGB;	// RGB.

	// DDBからDIBの情報を取得.(ピクセル列は不要.)
	hDC = GetDC(hWnd);	// GetDCでhWndのデバイスコンテキストhDCを取得.
	GetDIBits(hDC, m_hDIBSection, 0, m_iHeight, NULL, &bi, DIB_RGB_COLORS);	// GetDIBitsでピクセル列のサイズ(bi.bmiHeader.biSizeImage)を取得.
	ReleaseDC(hWnd, hDC);	// hDCをリリース.

	// ビットマップファイル情報のセット.(24bitビットマップの場合.)
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);	// ピクセル列以外のサイズ.(つまりヘッダのサイズ.)
	bfh.bfSize = bfh.bfOffBits + bi.bmiHeader.biSizeImage;	// 全体のサイズはヘッダ + ピクセル列.
	bfh.bfType = 0x4d42;	// 0x4d42("BM")はビットマップであるという意味.
	bfh.bfReserved1 = 0;	// ここは0をセット.
	bfh.bfReserved2 = 0;	// ここは0をセット.

	// ビットマップバイナリのファイル書き込み.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFileオブジェクトを作成し, ポインタをpBinaryFileに格納.
	pBinaryFile->Set((BYTE *)&bfh, sizeof(BITMAPFILEHEADER));	// pBinaryFile->SetでBITMAPFILEHEADERのbfhをセット.
	pBinaryFile->Write(lpctszFileName);	// pBinaryFile->Write(ファイル名引数ありバージョン)でファイルを開いて書き込み.
	pBinaryFile->Set((BYTE *)&bi, sizeof(BITMAPINFOHEADER));	// pBinaryFile->SetでBITMAPINFOHEADERのbi(正確にはbi.bmiHeader)をセット.
	pBinaryFile->Write();	// pBinaryFile->Write(ファイル名引数なしバージョン)で書き込み.
	pBinaryFile->Set(m_lpBitsPixel, sizeof(BYTE) * bi.bmiHeader.biSizeImage);	// pBinaryFile->SetでlpBitsPixelをセット.
	pBinaryFile->Write();	// pBinaryFile->Write(ファイル名引数なしバージョン)で書き込み.
	delete pBinaryFile;	// pBinaryFileを解放.

	return TRUE;

}
