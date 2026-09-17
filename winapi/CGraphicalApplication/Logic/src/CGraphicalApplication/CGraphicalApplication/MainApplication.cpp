// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// メンバの初期化.
	m_x = 0;	// m_xを0で初期化.
	m_y = 0;	// m_yを0で初期化.
	m_vx = 0;	// m_vxを0で初期化.
	m_vy = 0;	// m_vyを0で初期化.

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);

	// CMainWindowオブジェクトの作成.
	CMainWindow *pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, pMainWndに格納.
	m_pMainWnd = pMainWnd;	// pMainWndをm_pMainWndにもセット.
	// ウィンドウの作成.
	if (!pMainWnd->CreateEx(0, _T("CGraphicalApplication::Logic"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->CreateExでウィンドウ作成し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// TRUEを返す.
	return TRUE;	// returnでTRUEを返す.

}

// 入力処理関数Input.
void CMainApplication::Input(){

	// 矢印キーの押下状態を調べて, 速度(m_vx, m_vy)に反映する.(座標の更新自体はLogicで行う.)
	m_vx = 0;	// m_vxをいったん0にリセット.
	m_vy = 0;	// m_vyをいったん0にリセット.
	if (GetAsyncKeyState(VK_LEFT) & 0x8000){	// 左矢印キーが押されている場合.
		m_vx = -1;	// m_vxを-1に.
	}else if (GetAsyncKeyState(VK_RIGHT) & 0x8000){	// 右矢印キーが押されている場合.
		m_vx = 1;	// m_vxを1に.
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000){	// 上矢印キーが押されている場合.
		m_vy = -1;	// m_vyを-1に.
	}else if (GetAsyncKeyState(VK_DOWN) & 0x8000){	// 下矢印キーが押されている場合.
		m_vy = 1;	// m_vyを1に.
	}

}

// ロジック処理関数Logic.
void CMainApplication::Logic(){

	// 速度(m_vx, m_vy)の分だけ座標(m_x, m_y)を進める.
	m_x += m_vx;	// m_xにm_vxを加算.
	m_y += m_vy;	// m_yにm_vyを加算.

	// 座標をタイトルバーに表示する.
	// (CGraphicalApplication::MainProcからInputの後にLogicが毎フレーム呼ばれ, 実際に座標が更新されていることを示すデモ.)
	TCHAR tszText[64] = {0};	// タイトルバー用のバッファtszText.
	wsprintf(tszText, _T("x=%d, y=%d"), m_x, m_y);	// wsprintfで"x=..., y=..."という文字列を組み立てる.
	m_pMainWnd->SetWindowText(tszText);	// SetWindowTextでタイトルバーに表示.

}
