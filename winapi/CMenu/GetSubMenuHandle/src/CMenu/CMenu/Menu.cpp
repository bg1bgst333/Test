// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Menu.h"	// CMenu

// �R���X�g���N�^CMenu
CMenu::CMenu(){

	// �����o�̏�����
	m_hMenu = NULL;	// m_hMenu��NULL�ŏ�����.

}

// �w��ʒu�̃T�u���j���[�n���h���擾.
HMENU CMenu::GetSubMenuHandle(int nPos){

	// m_hMenu�̈ʒunPos�̃T�u���j���[�n���h����Ԃ�.
	return GetSubMenu(m_hMenu, nPos);	// GetSubMenu�̖߂�l��Ԃ�.

}