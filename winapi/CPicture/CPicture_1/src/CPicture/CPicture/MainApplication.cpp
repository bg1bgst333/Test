// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow
#include "UserControl.h"		// CUserControl

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance, MAKEINTRESOURCE(IDR_MAINMENU));	// CMainWindow::RegisterClass�Ń��j���[IDR_MAINMENU���w�肵�ă��C���̃E�B���h�E�N���X��o�^.
	CWindow::RegisterClass(hInstance, _T("Child"));	// �E�B���h�E�N���X"Child"�̓o�^.
	CUserControl::RegisterClass(hInstance);	// �E�B���h�E�N���X"CUserControl"�̓o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// ���������X�N���[���o�[�t���E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("CPicture"), WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindow�ŕ\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}