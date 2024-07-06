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

// ���j���[�n���h���}�b�v�̍폜.
void CMenu::DeleteMenuHandleMap() {

	// ���j���[�n���h���}�b�v�̑S�폜.
	std::map<HMENU, CMenu*>::iterator itor = m_mapMenuHandleMap.begin();
	while (itor != m_mapMenuHandleMap.end()) {
		HMENU hMenu = itor->first;
		CMenu* pMenu = itor->second;
		BOOL bRet = DestroyMenu(hMenu);
		delete pMenu;
		itor++;
	}
	m_mapMenuHandleMap.clear();

}

// �w��ʒu�̃T�u���j���[�n���h���擾.
HMENU CMenu::GetSubMenuHandle(int nPos) {

	// m_hMenu�̈ʒunPos�̃T�u���j���[�n���h����Ԃ�.
	return ::GetSubMenu(m_hMenu, nPos);	// GetSubMenu�̖߂�l��Ԃ�.

}

// �w��ʒu�̃T�u���j���[�I�u�W�F�N�g�|�C���^�擾.
CMenu* CMenu::GetSubMenu(int nPos) {

	// �n���h���擾����, ��������|�C���^�擾.
	HMENU hMenu = GetSubMenuHandle(nPos);
	return FromHandle(hMenu);

}

// �A�C�e���̒ǉ�.
BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem) {

	// �w��ʒu�ɃA�C�e���ǉ�.
	return ::AppendMenu(m_hMenu, nFlags, nIDNewItem, lpszNewItem);

}

// ���j���[���\�[�X�̃��[�h.
BOOL CMenu::LoadMenu(HINSTANCE hInstance, UINT nIDResource) {

	// ���[�h���Ă��烁�j���[�n���h���}�b�v�ɓo�^.
	HMENU hNew = ::LoadMenu(hInstance, MAKEINTRESOURCE(nIDResource));
	if (hNew != NULL) {	// ���[�h����.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// �Â��̂��o�^�ς�.
			if (this == itor->second) {	// �����͂�.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// �o�^����ĂȂ�.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// ���j���[�̍쐬.
BOOL CMenu::CreateMenu() {

	// �쐬���Ă��烁�j���[�n���h���}�b�v�ɓo�^.
	HMENU hNew = ::CreateMenu();
	if (hNew != NULL) {	// �쐬����.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// �Â��̂��o�^�ς�.
			if (this == itor->second) {	// �����͂�.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// �o�^����ĂȂ�.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// �|�b�v�A�b�v���j���[�̍쐬.
BOOL CMenu::CreatePopupMenu() {

	// �쐬���Ă��烁�j���[�n���h���}�b�v�ɓo�^.
	HMENU hNew = ::CreatePopupMenu();
	if (hNew != NULL) {	// �쐬����.
		std::map<HMENU, CMenu*>::iterator itor;
		itor = CMenu::m_mapMenuHandleMap.find(m_hMenu);
		if (itor != CMenu::m_mapMenuHandleMap.end()) {	// �Â��̂��o�^�ς�.
			if (this == itor->second) {	// �����͂�.
				CMenu::m_mapMenuHandleMap.erase(itor);
				DestroyMenu(m_hMenu);
				m_hMenu = hNew;
				CMenu::m_mapMenuHandleMap[m_hMenu] = this;
				return TRUE;
			}
		}
		else {	// �o�^����ĂȂ�.
			m_hMenu = hNew;
			CMenu::m_mapMenuHandleMap[m_hMenu] = this;
			return TRUE;
		}
	}
	return FALSE;

}

// �A�C�e���̍폜.
BOOL CMenu::DeleteMenu(UINT nPosition, UINT nFlags) {

	// �w��̃A�C�e���폜.
	return ::DeleteMenu(m_hMenu, nPosition, nFlags);

}

// ���j���[���ڂ̗L����, ������.
UINT CMenu::EnableMenuItem(UINT nIDEnableItem, UINT nEnable) {

	// �w��̏�Ԃɂ���.
	return ::EnableMenuItem(m_hMenu, nIDEnableItem, nEnable);

}

// ���j���[���ڂ̏�Ԏ擾.
UINT CMenu::GetMenuState(UINT nID, UINT nFlags) {

	// ��Ԏ擾.
	return ::GetMenuState(m_hMenu, nID, nFlags);

}

// ���j���[���ڂ̃`�F�b�N.
UINT CMenu::CheckMenuItem(UINT nIDCheckItem, UINT nCheck) {

	// �`�F�b�N.
	return ::CheckMenuItem(m_hMenu, nIDCheckItem, nCheck);

}

// ���j���[���W�I���ڂ̃`�F�b�N.
BOOL CMenu::CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags) {

	// ���W�I�`�F�b�N.
	return ::CheckMenuRadioItem(m_hMenu, nIDFirst, nIDLast, nIDItem, nFlags);

}