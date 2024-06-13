// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Menu.h"	// CMenu

// static�����o�ϐ��̒�`.
std::map<HMENU, CMenu*> CMenu::m_mapMenuHandleMap;	// ���j���[�n���h���}�b�vm_mapMenuHandleMap.

// �R���X�g���N�^CMenu
CMenu::CMenu() {

	// �����o�̏�����
	m_hMenu = NULL;	// m_hMenu��NULL�ŏ�����.

}

// �n���ꂽ���j���[�n���h��������CMenu�I�u�W�F�N�g�|�C���^��Ԃ�.
CMenu* CMenu::FromHandle(HMENU hMenu) {

	// hMenu�Ń|�C���^��������Ԃ�, ����������I�u�W�F�N�g������, �n���h�����Z�b�g����, �}�b�v�ɓo�^.
	if (CMenu::m_mapMenuHandleMap.find(hMenu) != CMenu::m_mapMenuHandleMap.end()) {
		return CMenu::m_mapMenuHandleMap[hMenu];
	}
	else {
		CMenu* pMenu = new CMenu();
		pMenu->m_hMenu = hMenu;
		CMenu::m_mapMenuHandleMap[hMenu] = pMenu;
		return pMenu;
	}

}

// �w��ʒu�̃T�u���j���[�n���h���擾.
HMENU CMenu::GetSubMenuHandle(int nPos) {

	// m_hMenu�̈ʒunPos�̃T�u���j���[�n���h����Ԃ�.
	return GetSubMenu(m_hMenu, nPos);	// GetSubMenu�̖߂�l��Ԃ�.

}