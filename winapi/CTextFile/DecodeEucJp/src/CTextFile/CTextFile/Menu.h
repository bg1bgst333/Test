// ��d�C���N���[�h�h�~
#ifndef __MENU_H__
#define __MENU_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <map>			// std::map

// ���j���[�N���XCMenu�̒�`
class CMenu {

	// public�����o
	public:

		// public�����o�ϐ�
		HMENU m_hMenu;	// ���j���[�n���h��m_hMenu

		// static�����o�ϐ�
		static std::map<HMENU, CMenu*>m_mapMenuHandleMap;	// ���j���[�n���h�����L�[, CMenu�I�u�W�F�N�g�|�C���^��l�Ƃ���}�b�vm_mapMenuHandleMap.

		// public�����o�֐�
		// �R���X�g���N�^
		CMenu();	// �R���X�g���N�^CMenu

		// static�����o�֐�
		static CMenu* FromHandle(HMENU hMenu);	// �n���ꂽ���j���[�n���h��������CMenu�I�u�W�F�N�g�|�C���^��Ԃ�.
		static void DeleteMenuHandleMap();	// ���j���[�n���h���}�b�v�̍폜.

		// �����o�֐�
		HMENU GetSubMenuHandle(int nPos);	// �w��ʒu�̃T�u���j���[�n���h���擾.
		CMenu* GetSubMenu(int nPos);	// �w��ʒu�̃T�u���j���[�I�u�W�F�N�g�|�C���^�擾.
		BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);	// �A�C�e���̒ǉ�.
		BOOL LoadMenu(HINSTANCE hInstance, UINT nIDResource);	// ���j���[���\�[�X�̃��[�h.
		BOOL CreateMenu();	// ���j���[�̍쐬.
		BOOL CreatePopupMenu();	// �|�b�v�A�b�v���j���[�̍쐬.
		BOOL DeleteMenu(UINT nPosition, UINT nFlags);	// �A�C�e���̍폜.
		UINT EnableMenuItem(UINT nIDEnableItem, UINT nEnable);	// ���j���[���ڂ̗L����, ������.
		UINT GetMenuState(UINT nID, UINT nFlags);	// ���j���[���ڂ̏�Ԏ擾.
		UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);	// ���j���[���ڂ̃`�F�b�N.
		BOOL CheckMenuRadioItem(UINT nIDFirst, UINT nIDLast, UINT nIDItem, UINT nFlags);	// ���j���[���W�I���ڂ̃`�F�b�N.

};

#endif