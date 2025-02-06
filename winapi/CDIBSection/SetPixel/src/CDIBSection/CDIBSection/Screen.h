// ��d�C���N���[�h�h�~
#ifndef __SCREEN_H__
#define __SCREEN_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl
#include "Canvas.h"	// CCanvas
#include "DIBSection.h"	// CDIBSection

// �X�N���[���N���XCScreen
class CScreen : public CUserControl {

	// public�����o
	public:

		// �����o�ϐ�
		CCanvas* m_pCanvas;	// CCanvas�I�u�W�F�N�g�|�C���^m_pCanvas.
		CDIBSection* m_pDIBSection;	// CDIBSection�I�u�W�F�N�g�|�C���^m_pDIBSection.
		HINSTANCE m_hInstance;	// �C���X�^���X�n���h��m_hInstance.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CScreen();	// �R���X�g���N�^CScreen
		virtual ~CScreen();	// �f�X�g���N�^~CScreen
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, int i);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�F�w��o�[�W����.)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL DestroyChildren();	// �q�E�B���h�E�j���֐�DestroyChildren
		const CCanvas* CreateCanvas(int x, int y, int iWidth, int iHeight, HMENU hMenu);	// �L�����o�X�쐬�֐�CreateCanvas.
		virtual BOOL SaveBitmap(LPCTSTR lpctszFileName);	// �r�b�g�}�b�v�ۑ��֐�SaveBitmap.
		virtual BOOL LoadBitmap(LPCTSTR lpctszFileName);	// �r�b�g�}�b�v�Ǎ��֐�LoadBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.

};

#endif