// ��d�C���N���[�h�h�~
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow
#include "Screen.h"	// CScreen

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CWindow {

	// public�����o
	public:

		// �񋓌^�̒�`
		// ���݂̐F
		typedef enum TAG_CURRENT_COLOR {
			CURRENT_COLOR_BLACK,
			CURRENT_COLOR_WHITE,
			CURRENT_COLOR_RED,
			CURRENT_COLOR_GREEN,
			CURRENT_COLOR_BLUE
		} CURRENT_COLOR;

		// �����o�ϐ�
		CScreen* m_pScreen;	// CScreen�I�u�W�F�N�g�|�C���^m_pScreen.
		HINSTANCE m_hInstance;	// �C���X�^���X�n���h��m_hInstance
		CURRENT_COLOR m_CurrentColor;	// ���݂̐F.

		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName, int i);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[��, �F�w��o�[�W����)
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
		int OnFileOpen(WPARAM wParam, LPARAM lParam);	// �J�����I�����ꂽ��.
		int OnFileSaveAs(WPARAM wParam, LPARAM lParam);	// ���O��t���ĕۑ����I�����ꂽ��.
		int OnCurrentColorBlack(WPARAM wParam, LPARAM lParam);	// �����I�����ꂽ��.
		int OnCurrentColorWhite(WPARAM wParam, LPARAM lParam);	// �����I�����ꂽ��.
		int OnCurrentColorRed(WPARAM wParam, LPARAM lParam);	// �Ԃ��I�����ꂽ��.
		int OnCurrentColorGreen(WPARAM wParam, LPARAM lParam);	// �΂��I�����ꂽ��.
		int OnCurrentColorBlue(WPARAM wParam, LPARAM lParam);	// ���I�����ꂽ��.

};

#endif