// ��d�C���N���[�h�h�~
#ifndef __MENU_H__
#define __MENU_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI

// ���j���[�N���XCMenu�̒�`
class CMenu {

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu

		// public�����o�֐�
		// �R���X�g���N�^
		CMenu();	// �R���X�g���N�^CMenu
		// �����o�֐�
		HMENU GetSubMenuHandle(int nPos);	// �w��ʒu�̃T�u���j���[�n���h���擾.

};

#endif