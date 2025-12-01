// ヘッダのインクルード
// 独自のヘッダ
#include "MultiView.h"	// CMultiView
#include "resource.h"

// staticメンバ変数の宣言.
HBRUSH CMultiView::s_hBrush;	// このウィンドウクラスの背景ブラシs_hBrush.

// コンストラクタCMultiView
CMultiView::CMultiView() : CUserControl() {

	// メンバ変数の初期化.
	m_pMultiViewItemsPanel = NULL;	// m_pMultiViewItemsPanelをNULLで初期化.
	m_iHScrollPos = 0;	// m_iHScrollPosを0で初期化.
	m_iVScrollPos = 0;	// m_iVScrollPosを0で初期化.

}

// デストラクタ~CMultiView
CMultiView::~CMultiView() {

	// メンバの終了処理.
	Destroy();	// Destroyで子ウィンドウの破棄.

}

// ウィンドウクラス登録関数RegisterClass.
BOOL CMultiView::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"));	// CUserControl::RegisterClassで登録.

}

// ウィンドウクラス登録関数RegisterClass(背景ブラシハンドル指定バージョン.)
BOOL CMultiView::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// ウィンドウクラス名にはlpctszClassName, 背景ブラシハンドルにはhbrBackgroundを指定.
	s_hBrush = hbrBackground;	// 背景ブラシハンドルをスタティック変数にセット.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"), hbrBackground);	// CUserControl::RegisterClassで登録.

}

// ウィンドウ作成関数Create.
BOOL CMultiView::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.(WS_CLIPCHILDRENで子ウィンドウ部分を再描画しなくなる.)
	return CUserControl::Create(_T("CMultiView"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createで作成.

}

// ウィンドウ破棄関数Destroy
BOOL CMultiView::Destroy() {

	// 変数の初期化.
	BOOL bRet = FALSE;	// bRetをFALSEで初期化.

	// マルチビューアイテムズパネルの破棄.
	if (m_pMultiViewItemsPanel != NULL) {
		bRet = m_pMultiViewItemsPanel->Destroy();
		delete m_pMultiViewItemsPanel;
		m_pMultiViewItemsPanel = NULL;
	}

	// 親クラスのDestroyを呼ぶ.
	return CUserControl::Destroy();	// CUserControl::Destroyを呼ぶ.

}

// アイテムを末尾から追加する関数Add.
void CMultiView::Add(LPCTSTR lpctszWindowName, int x, int y, int iWidth, int iHeight, HINSTANCE hInstance) {

	// アイテムズパネルに追加.
	if (m_pMultiViewItemsPanel != NULL) {	// m_pMultiViewItemsPanelがNULLでなければ.
		m_pMultiViewItemsPanel->Add(lpctszWindowName, x, y, iWidth, iHeight, hInstance);	// Addで末尾に追加.
	}

}

// アイテムを末尾から削除する関数Remove.
void CMultiView::Remove() {

	// アイテムズパネルから削除.
	if (m_pMultiViewItemsPanel != NULL) {	// m_pMultiViewItemsPanelがNULLでなければ.
		m_pMultiViewItemsPanel->Remove();	// Removeで末尾から削除.
	}

}

// 全てのアイテムを削除する関数RemoveAll.
void CMultiView::RemoveAll() {

	// 全てのアイテムを破棄.
	if (m_pMultiViewItemsPanel != NULL) {	// m_pMultiViewItemsPanelがNULLでなければ.
		m_pMultiViewItemsPanel->RemoveAll();	// RemoveAllで全て削除.
	}

}

// アイテムの数を返す関数GetSize.
size_t CMultiView::GetSize() {

	// アイテムの数を返す.
	if (m_pMultiViewItemsPanel != NULL) {	// m_pMultiViewItemsPanelがNULLでなければ.
		return m_pMultiViewItemsPanel->GetSize();	// m_pMultiViewItemsPanel->GetSizeで要素数を返す.
	}
	else {	// m_pMultiViewItemsPanelがNULL.
		return 0;	// 0を返す.
	}

}

// アイテムを取得する関数Get.
CMultiViewItem* CMultiView::Get(int iIndex) {

	// iIndex番目の要素を返す.
	if (m_pMultiViewItemsPanel != NULL) {	// m_pMultiViewItemsPanelがNULLでなければ.
		return m_pMultiViewItemsPanel->Get(iIndex);	// m_pMultiViewItemsPanel->Get(iIndex)を返す.
	}

	// なければNULL.
	return NULL;	// NULLを返す.

}

// ウィンドウの作成が開始された時.
int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// マルチビューアイテムズパネルの作成.
	m_pMultiViewItemsPanel = new CMultiViewItemsPanel();

	// マルチビューアイテムズパネルのウィンドウ生成.
	RECT rc = { 0 };
	GetClientRect(hwnd, &rc);
	m_pMultiViewItemsPanel->Create(_T(""), 0, 0, 0, rc.right - rc.left, rc.bottom - rc.top, hwnd, (HMENU)IDC_MULTIVIEWITEMSPANEL, lpCreateStruct->hInstance);	// m_pMultiViewItemsPanel->Createでウィンドウ生成.

	// 常にウィンドウ作成に成功するものとする.
	return 0;	// 0を返すと, ウィンドウ作成に成功したということになる.

}

// ウィンドウが破棄された時.
void CMultiView::OnDestroy() {

	// 親クラスのOnDestroyを呼ぶ.
	CUserControl::OnDestroy();	// CUserControl::OnDestroyを呼ぶ.

}

// ウィンドウのサイズが変更された時.
void CMultiView::OnSize(UINT nType, int cx, int cy) {

	// クライアントエリア情報.
	RECT clientRC = { 0 };
	GetClientRect(m_hWnd, &clientRC);

	// アイテムズパネル情報.
	RECT mvitemsPanelRC = { 0 };
	GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &mvitemsPanelRC);

	// スクロールバー設定.
	// 水平方向.
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
	m_ScrollInfo.nPage = clientRC.right - clientRC.left;
	m_ScrollInfo.nMin = 0;
	m_ScrollInfo.nMax = (mvitemsPanelRC.right - mvitemsPanelRC.left) - 1;
	m_ScrollInfo.nPos = m_iHScrollPos;
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// 垂直方向.
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;
	m_ScrollInfo.nPage = clientRC.bottom - clientRC.top;
	m_ScrollInfo.nMin = 0;
	m_ScrollInfo.nMax = (mvitemsPanelRC.bottom - mvitemsPanelRC.top) - 1;
	m_ScrollInfo.nPos = m_iVScrollPos;
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

	// 最新のスクロール位置を再取得.
	m_ScrollInfo.fMask = SIF_POS;
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);
	m_iHScrollPos = m_ScrollInfo.nPos;
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);
	m_iVScrollPos = m_ScrollInfo.nPos;

	// 現在のスクロール位置を考慮して再配置.
	m_pMultiViewItemsPanel->MoveWindow(-m_iHScrollPos, -m_iVScrollPos, mvitemsPanelRC.right - mvitemsPanelRC.left, mvitemsPanelRC.bottom - mvitemsPanelRC.top, TRUE);

}

// 背景消去を要求された時.
int CMultiView::OnEraseBkgnd() {

	// 背景ブラシの再描画.
	HDC hDC = GetDC(m_hWnd);
	RECT rc = { 0 };
	GetClientRect(m_hWnd, &rc);
	HBRUSH hOld = (HBRUSH)SelectObject(hDC, s_hBrush);
	Rectangle(hDC, rc.left, rc.top, rc.right, rc.bottom);
	SelectObject(hDC, hOld);
	ReleaseDC(m_hWnd, hDC);

	// 背景消去済みとして1.
	return 1;

}

// 水平方向スクロールバーイベント時.
void CMultiView::OnHScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番左
		case SB_LEFT:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番右
		case SB_RIGHT:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1列左
		case SB_LINELEFT:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1列右
		case SB_LINERIGHT:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ左
		case SB_PAGELEFT:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ右
		case SB_PAGERIGHT:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// アイテムズパネルの移動.
	RECT rcItemsPanelRC = { 0 };
	::GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &rcItemsPanelRC);
	m_pMultiViewItemsPanel->MoveWindow(0 - m_iHScrollPos, 0 - m_iVScrollPos, rcItemsPanelRC.right - rcItemsPanelRC.left, rcItemsPanelRC.bottom - rcItemsPanelRC.top);	// MoveWindowで移動.
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}

// 垂直方向スクロールバーイベント時.
void CMultiView::OnVScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番上
		case SB_TOP:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番下
		case SB_BOTTOM:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1行上
		case SB_LINEUP:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1行下
		case SB_LINEDOWN:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ上
		case SB_PAGEUP:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ下
		case SB_PAGEDOWN:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);
	// メンバにもセット.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// アイテムズパネルの移動.
	RECT rcItemsPanelRC = { 0 };
	::GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &rcItemsPanelRC);
	m_pMultiViewItemsPanel->MoveWindow(0 - m_iHScrollPos, 0 - m_iVScrollPos, rcItemsPanelRC.right - rcItemsPanelRC.left, rcItemsPanelRC.bottom - rcItemsPanelRC.top);	// MoveWindowで移動.
	// 無効領域を作成して画面の更新.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRectで無効領域作成.

}