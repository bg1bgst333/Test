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
class CMainWindow : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CMenu* m_pMainMenu;	// CMenu�I�u�W�F�N�g�|�C���^m_pMainMenu.
		CEditCore* m_pEdit;	// CEditCore�I�u�W�F�N�g�|�C���^m_pEdit.
		CTextFile* m_pTextFile;	// CTextFile�I�u�W�F�N�g�|�C���^m_pTextFile.

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
		int OnBomNone(WPARAM wParam, LPARAM lParam);	// BOM�Ȃ����I�����ꂽ��.
		int OnBomUtf16LE(WPARAM wParam, LPARAM lParam);	// UTF-16LE BOM���I�����ꂽ��.
		int OnBomUtf16BE(WPARAM wParam, LPARAM lParam);	// UTF-16BE BOM���I�����ꂽ��.
		int OnEncodeShiftJis(WPARAM wParam, LPARAM lParam);	// Shift_JIS���I�����ꂽ��.
		int OnEncodeUtf16LE(WPARAM wParam, LPARAM lParam);	// UTF-16LE�I�����ꂽ��.
		int OnEncodeUtf16BE(WPARAM wParam, LPARAM lParam);	// UTF-16LE���I�����ꂽ��.
		int OnEncodeUtf8(WPARAM wParam, LPARAM lParam);	// UTF-8���I�����ꂽ��.
		int OnNewLineCRLF(WPARAM wParam, LPARAM lParam);	// CRLF���I�����ꂽ��.
		int OnNewLineLF(WPARAM wParam, LPARAM lParam);	// LF���I�����ꂽ��.
		int OnNewLineCR(WPARAM wParam, LPARAM lParam);	// CR���I�����ꂽ��.
		int OnFileOpen(WPARAM wParam, LPARAM lParam);	// �J�����I�����ꂽ��.
		int OnFileSaveAs(WPARAM wParam, LPARAM lParam);	// ���O��t���ĕۑ����I�����ꂽ��.

};

#endif