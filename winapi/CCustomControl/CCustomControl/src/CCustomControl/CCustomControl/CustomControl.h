// ��d�C���N���[�h�h�~
#ifndef __CUSTOM_CONTROL_H__
#define __CUSTOM_CONTROL_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �J�X�^���R���g���[���N���XCCustomControl
class CCustomControl : public CWindow{

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CCustomControl();	// �R���X�g���N�^CCustomControl
		virtual ~CCustomControl();	// �f�X�g���N�^~CCustomControl

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		
};

#endif