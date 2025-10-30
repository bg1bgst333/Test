// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "resource.h"
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"			// CMainWindow

// �C���X�^���X�������֐�InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �E�B���h�E�N���X�̓o�^.
	CMainWindow::RegisterClass(hInstance);
	m_hBitmap1 = (HBITMAP)LoadImage(hInstance, _T("test1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// "test1.bmp"�̃��[�h.
	m_hBrush1 = CreatePatternBrush(m_hBitmap1);	// "test1"�p�^�[���u���V�̐���.
	CMultiView::RegisterClass(hInstance, m_hBrush1);	// CMultiView�̓o�^.
	m_hBitmap2 = (HBITMAP)LoadImage(hInstance, _T("test2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// "test2.bmp"�̃��[�h.
	m_hBrush2 = CreatePatternBrush(m_hBitmap2);	// "test2"�p�^�[���u���V�̐���.
	CMultiViewItemsPanel::RegisterClass(hInstance, m_hBrush2);	// CMultiView�̓o�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWnd = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, m_pMainWnd�Ɋi�[.

	// �E�B���h�E�̍쐬.
	if (!m_pMainWnd->Create(_T("CWindow"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWnd->Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

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

	// �u���V�̉��.
	DeleteObject(m_hBitmap2);
	DeleteObject(m_hBrush2);
	DeleteObject(m_hBitmap1);
	DeleteObject(m_hBrush1);

	// �e�N���X��ExitInstance���Ă�.
	return CApplication::ExitInstance();

}