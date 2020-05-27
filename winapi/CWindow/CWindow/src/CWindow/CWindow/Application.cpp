// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �C���X�^���X�������֐�InitInstance.
BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �E�B���h�E�N���X�̓o�^.
	CWindow::RegisterClass(hInstance, _T("CWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"CWindow"��o�^.

	// �E�B���h�E�̍쐬.
	if (!m_mainWnd.Create(_T("CWindow"), _T("CWindow"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_mainWnd.Create�ŃE�B���h�E�쐬��, ���s�����ꍇ.

		// �G���[����
		return FALSE;	// return��FALSE��Ԃ��Ĉُ�I��.

	}

	// �E�B���h�E�̕\��.
	m_mainWnd.ShowWindow(SW_SHOW);	// m_mainWnd.ShowWindow�ŕ\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}

// ���b�Z�[�W���[�v�����֐�Run.
int CApplication::Run(){

	// �\���̂̐錾
	MSG msg;	// MSG�^�\����msg.

	// ���b�Z�[�W���[�v�̏���
	while (GetMessage(&msg, NULL, 0, 0) > 0){	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ炱���𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�֕ϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W��WindowProc�ɑ��o.

	}

	// ExitInstance�̒l��Ԃ�.
	return ExitInstance();	// return��ExitInstance�̒l��Ԃ�.

}

// �I�������֐�ExitInstance.
int CApplication::ExitInstance(){

	// ����͏��0��Ԃ�.
	return 0;	// return��0��Ԃ�.

}