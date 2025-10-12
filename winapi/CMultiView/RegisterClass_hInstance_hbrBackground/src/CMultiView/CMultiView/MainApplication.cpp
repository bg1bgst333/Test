// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance);
	m_hBrush = CreateSolidBrush(RGB(0xff, 0, 0));	// �ԃu���V�̐���.
	CMultiView::RegisterClass(hInstance, m_hBrush);	// �Ԃ�CMultiView�̓o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("CMultiView"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWnd->Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindow�ŕ\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}

// �I�������֐�ExitInstance.
int CMainApplication::ExitInstance() {

	// �ԃu���V�̉��.
	DeleteObject(m_hBrush);

	// �e�N���X��ExitInstance���Ă�.
	return CApplication::ExitInstance();

}