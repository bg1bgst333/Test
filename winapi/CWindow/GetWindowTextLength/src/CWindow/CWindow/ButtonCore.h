// ��d�C���N���[�h�h�~
#ifndef __BUTTON_CORE_H__
#define __BUTTON_CORE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �{�^���R�A�R���g���[���N���XCButtonCore
class CButtonCore : public CCustomControl {

	// public�����o
	public:

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.

};

#endif