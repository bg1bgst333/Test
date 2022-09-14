// ��d�C���N���[�h�h�~
#ifndef __CUSTOM_CONTROL_H__
#define __CUSTOM_CONTROL_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �J�X�^���R���g���[���N���XCCustomControl
class CCustomControl : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		// static�����o�ϐ�
		static std::map<tstring, WNDPROC> m_mapBaseWindowProcMap;	// ����̃E�B���h�E�N���X�����L�[, ����̃E�B���h�E�v���V�[�W����l�Ƃ���}�b�vm_mapBaseWindowProcMap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CCustomControl();	// �R���X�g���N�^CCustomControl
		virtual ~CCustomControl();	// �f�X�g���N�^~CCustomControl
		// static�����o�֐�
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnDestroy();	// �E�B���h�E���j�����ꂽ��.

};

#endif