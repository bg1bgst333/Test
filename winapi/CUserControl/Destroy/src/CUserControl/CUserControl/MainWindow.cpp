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
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CMainWindow::Destroy() {

	// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// �q�E�B���h�E�̔j��.
	if (m_pUserControl != NULL) {	// NULL�łȂ����.
		bRet = m_pUserControl->Destroy();	// m_pUserControl->Destroy�ŃE�B���h�E��j��.
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// NULL���Z�b�g.
	}

	// ���g�̃E�B���h�E���j��.(OnClose�̑O��OnDestroy���Ă΂��̂͂��������̂ŃR�����g�A�E�g.)
	//return CWindow::Destroy();	// CWindow::Destroy���Ă�.
	MessageBox(m_hWnd, _T("CMainWindow::Destroy"), _T("CUserControl"), MB_OK);	// MessageBox��"CMainWindow::Destroy"�ƕ\��.
	return bRet;	// bRet��Ԃ�.

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

	// ���b�Z�[�W�{�b�N�X��"CMainWindow::OnDestroy"�ƕ\��.
	MessageBox(m_hWnd, _T("CMainWindow::OnDestroy"), _T("CUserControl"), MB_OK);	// MessageBox��"CMainWindow::OnDestroy"�ƕ\��.


	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CUserControl"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK) {	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.
	Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}