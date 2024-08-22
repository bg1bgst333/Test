// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "Menu.h"	// CMenu
#include "EditCore.h"	// CEditCore
#include "TextFile.h"	// CTextFile

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CWindow{

	// public�����o
	public:

		// public�����o�ϐ�
		CMenu *m_pMainMenu;	// CMenu�I�u�W�F�N�g�|�C���^m_pMainMenu.
		CEditCore *m_pEdit;	// CEditCore�I�u�W�F�N�g�|�C���^m_pEdit.
		CTextFile *m_pTextFile;	// CTextFile�I�u�W�F�N�g�|�C���^m_pTextFile.

		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����)
		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();	// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL DestroyChildren();	// �q�E�B���h�E�j���֐�DestroyChildren
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		virtual int OnClose();	// �E�B���h�E�������鎞.
		int OnItem1_1(WPARAM wParam, LPARAM lParam);	// Item1-1���I�����ꂽ��.
		int OnItem1_2(WPARAM wParam, LPARAM lParam);	// Item1-2���I�����ꂽ��.
		int OnItem1_3(WPARAM wParam, LPARAM lParam);	// Item1-3���I�����ꂽ��.
		int OnItem1_4(WPARAM wParam, LPARAM lParam);	// Item1-4���I�����ꂽ��.
		int OnItem1_5(WPARAM wParam, LPARAM lParam);	// Item1-5���I�����ꂽ��.
		int OnItem1_6(WPARAM wParam, LPARAM lParam);	// Item1-6���I�����ꂽ��.
		int OnItem1_7(WPARAM wParam, LPARAM lParam);	// Item1-7���I�����ꂽ��.
		int OnItem2_1(WPARAM wParam, LPARAM lParam);	// Item2-1���I�����ꂽ��.
		int OnItem2_2(WPARAM wParam, LPARAM lParam);	// Item2-2���I�����ꂽ��.

};

#endif