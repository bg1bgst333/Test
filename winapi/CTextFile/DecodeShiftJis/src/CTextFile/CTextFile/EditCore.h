// ��d�C���N���[�h�h�~
#ifndef __EDIT_CORE_H__
#define __EDIT_CORE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �G�f�B�b�g�R�A�R���g���[���N���XCEditCore
class CEditCore : public CCustomControl {

	// public�����o
	public:

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(RECT�o�[�W����).

};

#endif