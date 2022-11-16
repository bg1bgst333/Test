// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// CCustomControl

// staticメンバ変数の定義
std::map<tstring, WNDPROC>	CCustomControl::m_mapBaseWindowProcMap;	// ベースウィンドウプロシージャマップm_mapBaseWindowProcMap

// コンストラクタCCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// デストラクタ~CCustomControl
CCustomControl::~CCustomControl() {

}

// スタティックウィンドウプロシージャStaticWindowProc.
LRESULT CALLBACK CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ポインタの初期化
	CWindow* pWindow = NULL;	// CWindowオブジェクトポインタpWindowをNULLに初期化.

	// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
	if (m_mapWindowMap.find(hwnd) != m_mapWindowMap.end()) {	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
		pWindow = m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
	}

	// ウィンドウオブジェクトを取得できない場合.
	if (pWindow == NULL) {	// pWindowがNULLの時.

		// 配列の初期化
		TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

		// ウィンドウハンドルからウィンドウクラス名を取得.
		GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

		// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

			// 既定のプロシージャに任せる.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcで, このメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

		}
		else {	// 無い場合.

			// そうでないなら, DefWindowProcに任せる.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcの値を返す.

		}

	}
	else {	// pWindowがあった場合.

		// そのウィンドウのDynamicWindowProcに任せる.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに渡す.

	}

}

// ウィンドウ作成関数Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウクラス名にはlpctszClassNameを指定.
	BOOL bRet = CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createにウィンドウクラス名lpctszClassNameを指定.
	if (bRet) {	// bRetがTRUE.

		// 既定のウィンドウプロシージャを取得し, CCustomControl::StaticWindowProcに差し替える.
		WNDPROC lpfnWndProc;	// 既定のプロシージャlpfnWndProc
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLongでプロシージャlpfnWndProcを取得.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLongでプロシージャCCustomControl::StaticWindowProcを設定.

		// OnCreateは以降は呼ばれないので, ここで呼んでおく.
		CREATESTRUCT cs;	// CREATESTRUCTを一応用意.
		cs.hInstance = hInstance;	// hInstanceは要るかもしれないので, これは渡せるようにしておく.
		if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreateにm_hWndとcsを渡す.

			// 戻り値が0でない場合, 破棄.
			Destroy();	// Destroyで破棄.
			return FALSE;	// FALSEを返す.

		}

		// マップのキーにウィンドウクラス名がなければ登録.
		if (m_mapBaseWindowProcMap.find(lpctszClassName) == m_mapBaseWindowProcMap.end()) {	// マップに無い時.
			m_mapBaseWindowProcMap.insert(std::pair<LPCTSTR, WNDPROC>(lpctszClassName, lpfnWndProc));	// プロシージャを登録.
		}

		// WM_CREATEを通らないので, ウィンドウマップの登録も行う.
		if (m_mapWindowMap.find(m_hWnd) == m_mapWindowMap.end()) {	// ウィンドウマップになければ.
			m_mapWindowMap.insert(std::pair<HWND, CWindow*>(m_hWnd, this));	// 登録する.
		}

	}
	return bRet;	// bRetを返す.

}

// ウィンドウ作成関数Create(RECTバージョン).
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// RECTで指定されたサイズをx, y, iWidth, iHeightに変換.
	return CCustomControl::Create(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left + 1, rect.bottom - rect.top + 1, hWndParent, hMenu, hInstance);	// CCustomControl::Createでカスタムコントロールのウィンドウ作成.

}

// ウィンドウ破棄関数Destroy
BOOL CCustomControl::Destroy() {

	// 親クラスのDestroyを呼ぶ.
	return CWindow::Destroy();	// CWindow::Destroyを呼ぶ.

}

// ダイナミックウィンドウプロシージャDynamicWindowProc.
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージの処理
	switch (uMsg) {	// uMsgの値ごとに処理を振り分ける.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理へ向かう.

		// ウィンドウの描画を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// OnPaintに任せる.
				OnPaint();	// OnPaintを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理(DefWindowProc)へ向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

			}

			// 既定の処理へ向かう.
			break;	// breakで抜けて, 既定の処理へ向かう.

	}

	// 配列の初期化
	TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

	// ウィンドウハンドルからウィンドウクラス名を取得.
	GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

	// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
	if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

		// 既定のプロシージャに任せる.
		return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcで, このメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

	}
	else {	// 無い場合.

		// そうでないなら, DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcの値を返す.

	}

}

// ウィンドウの作成が開始された時.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CCustomControl::OnDestroy() {

	// 自分のウィンドウハンドルが残っていたらマップから削除.
	if (m_mapWindowMap.find(m_hWnd) != m_mapWindowMap.end()) {	// findでみつかったら.
		m_mapWindowMap.erase(m_hWnd);	// m_mapWindowMap.eraseで削除.
	}

}

// ウィンドウの描画を要求された時.
void CCustomControl::OnPaint() {

	// 変数の宣言.
	HDC hDC;	// デバイスコンテキストハンドルhDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT構造体ps.

	// 文字列の描画.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32APIのBeginPaintでhDCを取得.
	TextOut(hDC, 0, 0, _T("CCustomControl"), (int)_tcslen(_T("CCustomControl")));	// Win32APIのTextOutで"CCustomControl"と描画.
	EndPaint(m_hWnd, &ps);	// Win32APIのEndPaintで描画終了.

}

// 垂直方向スクロールバーイベント時.
void CCustomControl::OnVScroll(UINT nSBCode, UINT nPos) {

	// 垂直方向スクロールバー情報を取得.
	SCROLLINFO scrVert = { 0 };	// 垂直方向スクロール情報scrVertを{0}で初期化.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeofで構造体サイズ指定.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// ページ, レンジ, 位置を取得.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfoでscrVertを取得.

	// つまみの最大位置を計算.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// セットした最大値 + 1が大きさで, そこからページ数を引くと, つまみの最大の位置.

	// 通知コード処理
	switch (nSBCode) {	// 通知コードが格納されているので, それで判定する.

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
				scrVert.nPos--;	// 1戻る.
			}
			break;	// 抜ける.

		// 1列下
		case SB_LINEDOWN:

			// 1列下に進める.
			if (scrVert.nPos < iMaxPos) {	// scrVert.nPosがiMaxPosより小さい場合.
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
					scrVert.nPos -= scrVert.nPage;	// 1ページ分マイナス.
				}
				else {	// 下限を超えたら.
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
					scrVert.nPos += scrVert.nPage;	// 1ページ分プラス.
				}
				else {	// 上限を超えたら.
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
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域を作成.(NULLなので全体が無効領域.)
	UpdateWindow(m_hWnd);	// UpdateWindowでウィンドウの更新.

	// WM_VSCROLLが発生した時に来たことを示す.
	HDC hDC = GetDC(m_hWnd);	// hDC取得.
	static int j = 0;	// スタティック変数jを0で初期化.
	TCHAR tszJ[16] = { 0 };	// 文字列バッファtszJ(長さ16)を{0}で初期化.
	_stprintf(tszJ, _T("j = %d"), j);	// jを文字列tszJに変換.
	BOOL b = TextOut(hDC, 0, 0, tszJ, _tcslen(tszJ));	// tszJを描画.
	j++;	// jをインクリメント.
	ReleaseDC(m_hWnd, hDC);	// hDC解放.

}