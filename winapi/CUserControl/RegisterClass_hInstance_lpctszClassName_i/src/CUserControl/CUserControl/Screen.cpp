// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Screen.h"	// CScreen

// �R���X�g���N�^CScreen
CScreen::CScreen() : CUserControl(){

}

// �f�X�g���N�^~CScreen
CScreen::~CScreen(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CScreen"��o�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CScreen::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CScreen".
	return CUserControl::Create(_T("CScreen"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CScreen"���w��.
	
}

// �E�B���h�E�j���֐�Destroy
BOOL CScreen::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}