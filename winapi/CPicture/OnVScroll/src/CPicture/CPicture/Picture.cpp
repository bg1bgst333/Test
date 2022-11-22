// ヘッダのインクルード
// 既定のヘッダ
#include <stdio.h>	// C標準入出力
// 独自のヘッダ
#include "Picture.h"	// CPicture

// コンストラクタCPicture
CPicture::CPicture() : CUserControl() {

	// メンバの初期化.
	m_hDC = NULL;	// m_hDCをNULLで初期化.
	m_hMemDC = NULL;	// m_hMemDCをNULLで初期化.
	m_hBitmap = NULL;	// m_hBitmapをNULLで初期化.
	m_hOldBitmap = NULL;	// m_hOldBitmapをNULLで初期化.

}

// デストラクタ~CPicture
CPicture::~CPicture() {

}

// ウィンドウクラス登録関数RegisterClass.(ウィンドウクラス名省略バージョン.)
BOOL CPicture::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CPicture"));	// CUserControl::RegisterClassでウィンドウクラス名"CPicture"を登録.

}

// ウィンドウ作成関数Create.(ウィンドウクラス名省略バージョン.)
BOOL CPicture::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名は"CPicture".
	return CUserControl::Create(_T("CPicture"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createにウィンドウクラス名"CPicture"を指定.

}

// ウィンドウ破棄関数Destroy
BOOL CPicture::Destroy() {

	// 以前のビットマップハンドルに戻す.
	if (m_hOldBitmap != NULL) {	// NULLでない.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObjectでm_hMemDCでm_hOlbBitmapを選択.
		m_hOldBitmap = NULL;	// NULLをセット.
	}

	// メモリデバイスコンテキストの破棄.
	if (m_hMemDC != NULL) {	// NULLでない.
		DeleteDC(m_hMemDC);	// DeleteDCでm_hMemDCを破棄.
		m_hMemDC = NULL;	// NULLをセット.
	}

	// デバイスコンテキストの解放.
	if (m_hDC != NULL) {	// NULLでない.
		ReleaseDC(m_hWnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// NULLをセット.
	}

	// ビットマップハンドルは外部のモノなので破棄せずNULLにするだけ.
	if (m_hBitmap != NULL) {
		m_hBitmap = NULL;	// NULLをセット.
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// ビットマップのセットSetBitmap.
void CPicture::SetBitmap(HBITMAP hBitmap) {

	// ビットマップハンドルの格納.
	m_hBitmap = hBitmap;	// m_hBitmapにhBitmapを格納.

	// ビットマップオブジェクトの選択.
	HBITMAP hOld = NULL;
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObjectでm_hMemDCがm_hBitmapを選択.
	if (m_hOldBitmap == NULL) {	// m_hOldBitmapがNULLの時.
		m_hOldBitmap = hOld;	// SelectObjectの戻り値を格納,
	}

	// クライアント領域のRECTを取得.
	RECT rc = { 0 };	// RECT型rcを{0}で初期化.
	GetClientRect(m_hWnd, &rc);	// ピクチャーのクライアント領域のRECTを取得.

	// ビットマップ情報の取得.
	BITMAP bitmap = { 0 };	// BITMAP構造体変数bitmapを{0}で初期化.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObjectでbitmapを取得.

	// 水平方向スクロールバーの初期化.
	SCROLLINFO scrHorz = { 0 };	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.nMin = 0;	// 最小値は0.
	scrHorz.nMax = bitmap.bmWidth - 1;	// 最大値はbitmap.bmWidth - 1.
	scrHorz.nPage = rc.right - rc.left;	// ページサイズはrc.right - rc.left.
	scrHorz.nPos = 0;	// 現在位置は0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// スクロール情報をセット.

	// 垂直方向スクロールバーの初期化.
	SCROLLINFO scrVert = { 0 };	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.nMin = 0;	// 最小値は0.
	scrVert.nMax = bitmap.bmHeight - 1;	// 最大値はbitmap.bmHeight - 1.
	scrVert.nPage = rc.bottom - rc.top;	// ページサイズはrc.bottom - rc.top.
	scrVert.nPos = 0;	// 現在位置は0.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置をセット.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// スクロール情報をセット.

}

// ウィンドウの作成が開始された時.
int CPicture::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// デバイスコンテキストの取得.
	m_hDC = GetDC(hwnd);	// GetDCでこのウィンドウのデバイスコンテキストハンドルを取得.
	if (m_hDC == NULL) {	// NULLなら失敗.
		return -1;	// -1を返してウィンドウ作成失敗とする.
	}

	// メモリデバイスコンテキストの生成.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDCでm_hDCに互換性のあるメモリデバイスコンテキストを生成.
	if (m_hMemDC == NULL) {	// NULLなら失敗.
		ReleaseDC(hwnd, m_hDC);	// ReleaseDCでm_hDCを解放.
		m_hDC = NULL;	// NULLをセット.
		return -2;	// -2を返してウィンドウ作成失敗とする.
	}

	// 親クラスのOnCreateを呼ぶ.
	return CUserControl::OnCreate(hwnd, lpCreateStruct);	// CUserControl::OnCreateの値を返す.

}

// ウィンドウの描画を要求された時.
void CPicture::OnPaint() {

	// ビットマップの描画.
	if (m_hBitmap != NULL) {	// NULLでなければ.

		// 更新領域の取得.
		RECT rcClient = { 0 };	// クライアント領域rcClientを{0}で初期化.
		GetClientRect(m_hWnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
		RECT rcUpdate = { 0 };	// 更新領域rcUpdateを{0}で初期化.
		GetUpdateRect(m_hWnd, &rcUpdate, FALSE);	// GetUpdateRectで更新領域rcUpdateを取得.

		// スクロール情報の取得.
		SCROLLINFO siHorz = { 0 };	// 水平方向スクロール情報siHorz.
		siHorz.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
		siHorz.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// 位置, ページ, レンジ.
		GetScrollInfo(m_hWnd, SB_HORZ, &siHorz);	// GetScrollInfoでsiHorz取得.
		SCROLLINFO siVert = { 0 };	// 垂直方向スクロール情報siVert.
		siVert.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
		siVert.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// 位置, ページ, レンジ.
		GetScrollInfo(m_hWnd, SB_VERT, &siVert);	// GetScrollInfoでsiVert取得.

		// 描画開始.
		PAINTSTRUCT ps = { 0 };	// PAINTSTRUCT型psを{0}で初期化.
		HDC hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintでhDC取得.

		// 描画.
		int x1 = 0;	// 転送先x1を0で初期化.
		int y1 = 0;	// 転送先y1を0で初期化.
		if (m_dx > 0) {	// m_dxがプラス.
			x1 = siHorz.nPage + siHorz.nPos - (rcUpdate.right - rcUpdate.left);	// x1はページ数 + 位置 - 1 - (再描画する範囲).
		}
		else {	// dxが0以下.
			x1 = siHorz.nPos;	// x1は位置.
		}
		if (m_dy > 0) {	// m_dyがプラス.
			y1 = siVert.nPage + siVert.nPos - (rcUpdate.bottom - rcUpdate.top);	// y1はページ数 + 位置 - 1 - (再描画する範囲).
		}
		else {	// m_dyが0以下.
			y1 = siVert.nPos;	// y1は位置.
		}
		BitBlt(hDC, rcUpdate.left, rcUpdate.top, rcUpdate.right - rcUpdate.left, rcUpdate.bottom - rcUpdate.top, m_hMemDC, x1, y1, SRCCOPY);	// BitBltで転送.

		// 描画終了.
		EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

	}

}

// 水平方向スクロールバーイベント時.
void CPicture::OnHScroll(UINT nSBCode, UINT nPos) {

	// 水平方向スクロールバー情報を取得.
	SCROLLINFO scrHorz = { 0 };	// 水平方向スクロール情報scrHorzを{0}で初期化.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfoでscrHorzを取得.

	// つまみの最大位置を計算.
	int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

	// 変化量を0にリセット.
	m_dx = 0;	// m_dxを0にリセット.

	// 通知コード処理
	switch (nSBCode) {	// nSBCodeに行われた操作の通知コードが格納されているので, それで判定する.

		// 1番左
		case SB_LEFT:

			// 1番左にセット.
			scrHorz.nPos = scrHorz.nMin;	// 現在位置を1番左にセット.
			break;	// 抜ける.

		// 1番右
		case SB_RIGHT:

			// 1番右にセット.
			scrHorz.nPos = scrHorz.nMax;	// 現在位置を1番右にセット.
			break;	// 抜ける.

		// 1列左
		case SB_LINELEFT:

			// 1列左に戻す.
			if (scrHorz.nPos > scrHorz.nMin) {	// scrHorz.nPosがscrHorz.nMinより大きい場合.
				m_dx = -1;	// 変化量-1.
				scrHorz.nPos--;	// 1戻る.
			}
			break;	// 抜ける.

		// 1列右
		case SB_LINERIGHT:

			// 1列右に進める.
			if (scrHorz.nPos < iMaxPos) {	// scrHorz.nPosがiMaxPosより小さい場合.
				m_dx = 1;	// 変化量1.
				scrHorz.nPos++;	// 1進む.
			}
			break;	// 抜ける.

		// 1ページ左
		case SB_PAGELEFT:

			// SB_PAGELEFTブロック.
			{

				// 1ページ戻る.
				int after = scrHorz.nPos - scrHorz.nPage;	// 現在位置から1ページ分引く.
				if (after >= scrHorz.nMin) {	// 下限を超えてなければ.
					m_dx = -1 * scrHorz.nPage;	// 1ページ分マイナス.
					scrHorz.nPos -= scrHorz.nPage;	// 1ページ分マイナス.
				}
				else {	// 下限を超えたら.
					m_dx = -1 * (scrHorz.nPos - scrHorz.nMin);	// 現在位置から最小値までの差に-1をかけて変化量とする.
					scrHorz.nPos = scrHorz.nMin;	// 最小値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 1ページ右
		case SB_PAGERIGHT:

			// SB_PAGERIGHTブロック.
			{

				// 1ページ進む.
				int after = scrHorz.nPos + scrHorz.nPage;	// 現在位置から1ページ分足す.
				if (after <= iMaxPos) {	// 上限を超えてなければ.
					m_dx = scrHorz.nPage;	// 1ページ分プラス.
					scrHorz.nPos += scrHorz.nPage;	// 1ページ分プラス.
				}
				else {	// 上限を超えたら.
					m_dx = iMaxPos - scrHorz.nPos;	// iMaxPosから現在位置までの差を変化量とする.
					scrHorz.nPos = scrHorz.nMax;	// 最大値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スクロールつまみが離された時.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITIONブロック.
			{

				// 離された位置をセット.
				int before = scrHorz.nPos;	// 以前.
				int after = nPos;	// 以後.
				m_dx = after - before;	// 変化量はafterが大きいと+, beforeが大きいと-.
				scrHorz.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrHorz.nPosにセット.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// scrHorz.nPosをm_hWndのSB_HORZにセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfoで現在のscrHorz.nPosをm_hWndにセット.
	// クライアント領域のスクロール.
	ScrollWindow(m_hWnd, -m_dx, 0, NULL, NULL);	// ScrollWindowで-m_dx分スクロール.
	// 無効領域の計算.
	RECT rcClient = { 0 };	// クライアント領域rcClientを{0}で初期化.
	GetClientRect(m_hWnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
	RECT rcInvalidate = { 0 };	// 無効領域rcInvalidateを{0}で初期化.
	if (m_dx < 0) {	// m_dxがマイナスの時.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right = -m_dx;	// 左から-m_dx(プラス)
		rcInvalidate.bottom = rcClient.bottom;	// 縦.
	}
	else {	// m_dxが0かプラスの時.
		rcInvalidate.left = rcClient.right - m_dx;	// 右から-m_dx(マイナス)
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right = rcClient.right;	// 横.
		rcInvalidate.bottom = rcClient.bottom;	// 縦.
	}
	// 無効領域の作成.
	InvalidateRect(m_hWnd, &rcInvalidate, FALSE);	// InvalidateRectで無効領域rcInvalidate作成.
	// ウィンドウの更新.
	UpdateWindow(m_hWnd);	// UpdateWinowでhwndの更新.

}

// 垂直方向スクロールバーイベント時.
void CPicture::OnVScroll(UINT nSBCode, UINT nPos) {

	// 垂直方向スクロールバー情報を取得.
	SCROLLINFO scrVert = { 0 };	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

	// つまみの最大位置を計算.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

	// 変化量を0にリセット.
	m_dy = 0;	// m_dyを0にリセット.

	// 通知コード処理
	switch (nSBCode) {	// nSBCodeに行われた操作の通知コードが格納されているので, それで判定する.

		// 1番上
		case SB_TOP:

			// 1番上にセット.
			scrVert.nPos = scrVert.nMin;	// 現在位置を1番上にセット.
			break;	// 抜ける.

		// 1番下
		case SB_BOTTOM:

			// 1番下にセット.
			scrVert.nPos = scrVert.nMax;	// 現在位置を1番下にセット.
			break;	// 抜ける.

		// 1列上
		case SB_LINEUP:

			// 1列上に戻す.
			if (scrVert.nPos > scrVert.nMin) {	// scrVert.nPosがscrVert.nMinより大きい場合.
				m_dy = -1;	// 変化量-1.
				scrVert.nPos--;	// 1戻る.
			}
			break;	// 抜ける.

		// 1列下
		case SB_LINEDOWN:

			// 1列下に進める.
			if (scrVert.nPos < iMaxPos) {	// scrVert.nPosがiMaxPosより小さい場合.
				m_dy = 1;	// 変化量1.
				scrVert.nPos++;	// 1進む.
			}
			break;	// 抜ける.

		// 1ページ上
		case SB_PAGEUP:

			// SB_PAGEUPブロック.
			{

				// 1ページ戻る.
				int after = scrVert.nPos - scrVert.nPage;	// 現在位置から1ページ分引く.
				if (after >= scrVert.nMin) {	// 下限を超えてなければ.
					m_dy = -1 * scrVert.nPage;	// 1ページ分マイナス.
					scrVert.nPos -= scrVert.nPage;	// 1ページ分マイナス.
				}
				else {	// 下限を超えたら.
					m_dy = -1 * (scrVert.nPos - scrVert.nMin);	// 現在位置から最小値までの差に-1をかけて変化量とする.
					scrVert.nPos = scrVert.nMin;	// 最小値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// 1ページ下
		case SB_PAGEDOWN:

			// SB_PAGEDOWNブロック.
			{

				// 1ページ進む.
				int after = scrVert.nPos + scrVert.nPage;	// 現在位置から1ページ分足す.
				if (after <= iMaxPos) {	// 上限を超えてなければ.
					m_dy = scrVert.nPage;	// 1ページ分プラス.
					scrVert.nPos += scrVert.nPage;	// 1ページ分プラス.
				}
				else {	// 上限を超えたら.
					m_dy = iMaxPos - scrVert.nPos;	// iMaxPosから現在位置までの差を変化量とする.
					scrVert.nPos = scrVert.nMax;	// 最大値に.
				}

			}

			// 抜ける.
			break;	// breakで抜ける.

		// スクロールつまみが離された時.
		case SB_THUMBPOSITION:

			// SB_THUMBPOSITIONブロック.
			{

				// 離された位置をセット.
				int before = scrVert.nPos;	// 以前.
				int after = nPos;	// 以後.
				m_dy = after - before;	// 変化量はafterが大きいと+, beforeが大きいと-.
				scrVert.nPos = after;	// HIWORD(wParam)に離された位置が格納されているのでscrVert.nPosにセット.

			}

			// 抜ける.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// 抜ける.
			break;	// breakで抜ける.

	}

	// scrVert.nPosをhwndのSB_VERTにセット.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfoで現在のscrVert.nPosをm_hWndにセット.
	// クライアント領域のスクロール.
	ScrollWindow(m_hWnd, 0, -m_dy, NULL, NULL);	// ScrollWindowで-m_dy分スクロール.
	// 無効領域の計算.
	RECT rcClient = { 0 };	// クライアント領域rcClientを{0}で初期化.
	GetClientRect(m_hWnd, &rcClient);	// GetClientRectで現在のクライアント領域のRECTであるrcClientを取得.
	RECT rcInvalidate = { 0 };	// 無効領域rcInvalidateを{0}で初期化.
	if (m_dy < 0) {	// m_dyがマイナスの時.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right = rcClient.right;	// 横.
		rcInvalidate.bottom = -m_dy;	// 上から-m_dy(プラス)
	}
	else {	// dyが0かプラスの時.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.bottom - m_dy;	// 下から-m_dy(マイナス)
		rcInvalidate.right = rcClient.right;	// 横.
		rcInvalidate.bottom = rcClient.bottom;	// 縦.
	}
	// 無効領域の作成.
	InvalidateRect(m_hWnd, &rcInvalidate, FALSE);	// InvalidateRectで無効領域rcInvalidate作成.
	// ウィンドウの更新.
	UpdateWindow(m_hWnd);	// UpdateWinowでm_hWndの更新.

}