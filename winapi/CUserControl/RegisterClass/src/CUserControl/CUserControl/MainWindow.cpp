// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X��"CMainWindow"��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() {

	// �����o�̏�����.
	m_pUserControl = NULL;	// m_pUserControl��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	if (m_hWnd != NULL) {	// m_hWnd��NULL�łȂ���.
		// �q�E�B���h�E�̔j��.
		if (m_pUserControl != NULL) {	// m_pUserControl��NULL�łȂ�.
			DestroyWindow(m_pUserControl->m_hWnd);	// DestroyWindow��m_pUserControl->m_hWnd��j��.
			delete m_pUserControl;	// delete��m_pUserControl�����.
			m_pUserControl = NULL;	// m_pUserControl��NULL���Z�b�g.
		}
		DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
		m_hWnd = NULL;	// m_hWnd��NULL���Z�b�g.
	}

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���b�Z�[�W�{�b�N�X��"CMainWindow::OnCreate"�ƕ\��.
	MessageBox(hwnd, _T("CMainWindow::OnCreate"), _T("CUserControl"), MB_OK);	// MessageBox��"CMainWindow::OnCreate"�ƕ\��.

	// ���[�U�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pUserControl = new CUserControl();	// new��CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.

	// �E�B���h�E�N���X��"UC1"�̃��[�U�R���g���[���̃E�B���h�E�쐬.
	m_pUserControl->Create(_T("UC1"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X��"UC1"��CUserControl�E�B���h�E���쐬.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pUserControl != NULL) {	// m_pUserControl��NULL�łȂ�.
		DestroyWindow(m_pUserControl->m_hWnd);	// DestroyWindow��m_pUserControl->m_hWnd��j��.
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// m_pUserControl��NULL���Z�b�g.
	}

	// ���b�Z�[�W�{�b�N�X��"CMainWindow::OnDestroy"�ƕ\��.
	MessageBox(m_hWnd, _T("CMainWindow::OnDestroy"), _T("CUserControl"), MB_OK);	// MessageBox��"CMainWindow::OnDestroy"�ƕ\��.

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}