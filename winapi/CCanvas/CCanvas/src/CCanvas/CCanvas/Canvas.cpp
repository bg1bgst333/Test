// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Canvas.h"	// CCanvas

// �R���X�g���N�^CCanvas
CCanvas::CCanvas() : CUserControl() {

}

// �f�X�g���N�^~CCanvas
CCanvas::~CCanvas() {

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CCanvas"��o�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CCanvas::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CCanvas".
	return CUserControl::Create(_T("CCanvas"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CCanvas"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CCanvas::Destroy() {

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}