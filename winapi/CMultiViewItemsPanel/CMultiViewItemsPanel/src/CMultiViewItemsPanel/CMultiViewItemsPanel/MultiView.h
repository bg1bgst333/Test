// ��d�C���N���[�h�h�~
#ifndef __MULTI_VIEW_H__
#define __MULTI_VIEW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl
#include "MultiViewItemsPanel.h"	// CMultiViewItemsPanel

// �}���`�r���[�R���g���[���N���XCMultiView
class CMultiView : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		CMultiViewItemsPanel* m_pMultiViewItemsPanel;	// CMultiViewItemsPanel�I�u�W�F�N�g�|�C���^m_pMultiViewItemsPanel.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMultiView();	// �R���X�g���N�^CMultiView
		virtual ~CMultiView();	// �f�X�g���N�^~CMultiView
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�n���h���w��o�[�W����.)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.

};

#endif
