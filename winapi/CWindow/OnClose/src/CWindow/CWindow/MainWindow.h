// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CWindow{

	// public�����o
	public:

		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();	// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual int OnClose();	// �E�B���h�E�������鎞.

};

#endif