// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow
#include "UserControl.h"		// CUserControl

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));	// CMainWindow::RegisterClass�Ń��j���[IDR_MAINMENU���w�肵�ăE�B���h�E�N���X��o�^.
	CUserControl::RegisterClass(hInstance, _T("UC1"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"UC1"��o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("CCustomControl"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWnd->Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindow�ŕ\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}