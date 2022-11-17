// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// CWindow
#include "Picture.h"	// CPicture
#include "EditCore.h"	// CEditCore
#include "resource.h"	// ���\�[�X

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CWindow{

	// public�����o
	public:

		// �����o�ϐ�
		CWindow *m_pChild;	// CWindow�I�u�W�F�N�g�|�C���^m_pChild.
		CPicture *m_pPicture;	// CPicture�I�u�W�F�N�g�|�C���^m_pPicture.
		CEditCore *m_pEdit;	// CEditCore�I�u�W�F�N�g�|�C���^m_pEdit.

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
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.
		virtual int OnClose();	// �E�B���h�E�������鎞.

};

#endif