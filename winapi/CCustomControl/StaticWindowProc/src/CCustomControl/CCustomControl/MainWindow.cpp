// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X��"CMainWindow"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName) {

	// ���j���[����lpctszMenuName.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName);	// CWindow::RegisterClass��, �E�B���h�E�N���X��"CMainWindow", ���j���[��lpctszMenuName��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() {
	
	// �����o�̏�����.
	m_pUserControl = NULL;	// m_pUserControl��NULL�ŏ�����.
	m_pCustomControl1 = NULL;	// m_pCustomControl1��NULL�ŏ�����.
	m_pCustomControl2 = NULL;	// m_pCustomControl2��NULL�ŏ�����.

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

	/// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// DestroyChildren�𕪂����̂�, ���g�̃E�B���h�E�j���͖��Ȃ�.
	// �܂��q�E�B���h�E�̔j��.
	DestroyChildren();

	// ���g�̃E�B���h�E�j��.
	bRet = CWindow::Destroy();	// �߂�l��bRet�Ɋi�[.

	// bRet��Ԃ�.
	return bRet;

}

// �q�E�B���h�E�j���֐�DestroyChildren
BOOL CMainWindow::DestroyChildren() {

	// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// �q�E�B���h�E�̔j��.
	if (m_pUserControl != NULL) {	// NULL�łȂ����.
		bRet = m_pUserControl->Destroy();	// m_pUserControl->Destroy�ŃE�B���h�E��j��.
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// NULL���Z�b�g.
	}

	// �q�E�B���h�E�̔j��.
	if (m_pCustomControl1 != NULL) {	// NULL�łȂ����.
		bRet = m_pCustomControl1->Destroy();	// m_pCustomControl1->Destroy�ŃE�B���h�E��j��.
		delete m_pCustomControl1;	// delete��m_pCustomControl1�����.
		m_pCustomControl1 = NULL;	// NULL���Z�b�g.
	}

	// �q�E�B���h�E�̔j��.
	if (m_pCustomControl2 != NULL) {	// NULL�łȂ����.
		bRet = m_pCustomControl2->Destroy();	// m_pCustomControl2->Destroy�ŃE�B���h�E��j��.
		delete m_pCustomControl2;	// delete��m_pCustomControl2�����.
		m_pCustomControl2 = NULL;	// NULL���Z�b�g.
	}

	// �j��������TRUE��Ԃ�.
	if (bRet) {	// TRUE�Ȃ�.
		return TRUE;	// TRUE��Ԃ�.
	}

	// �j�����Ȃ����, CWindow��DestroyChildren��Ԃ�.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildren��Ԃ�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���j���[�n���h���̒ǉ�.
	AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_1);	// AddCommandHandler��ID_ITEM_1_1�ɑ΂���n���h��CMainWindow::OnItem1_1��o�^.

	// ���[�U�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pUserControl = new CUserControl();	// new��CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.

	// �E�B���h�E�N���X��"UC1"�̃��[�U�R���g���[���̃E�B���h�E�쐬.
	m_pUserControl->Create(_T("UC1"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X��"UC1"��CUserControl�E�B���h�E���쐬.

	// �J�X�^���R���g���[���I�u�W�F�N�g(�{�^��)�̍쐬.
	m_pCustomControl1 = new CCustomControl();	// new��CCustomControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pCustomControl1�Ɋi�[.

	// �E�B���h�E�N���X��"Button"�̃J�X�^���R���g���[��"Button1"�̃E�B���h�E�쐬.
	m_pCustomControl1->Create(_T("Button"), _T("Button1"), WS_BORDER | BS_PUSHBUTTON, 50, 200, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X��"Button"��CCustomControl�E�B���h�E"Button1"�쐬.

	// �J�X�^���R���g���[���I�u�W�F�N�g(�G�f�B�b�g)�̍쐬.
	m_pCustomControl2 = new CCustomControl();	// new��CCustomControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pCustomControl2�Ɋi�[.

	// �E�B���h�E�N���X��"Edit"�̃J�X�^���R���g���[��"Edit1"�̃E�B���h�E�쐬.
	m_pCustomControl2->Create(_T("Edit"), _T("Edit1"), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 350, 100, 100, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X��"Edit"��CCustomControl�E�B���h�E"Edit1"�쐬.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandler��ID_ITEM_1_1�̃n���h�����폜.

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CCustomControl"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK) {	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}

// Item1-1���I�����ꂽ��.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam) {

	// ���b�Z�[�W�{�b�N�X��\��.
	MessageBox(NULL, _T("Item1-1"), _T("CCustomControl"), MB_OK);	// MessageBox��"Item1-1"�ƕ\��.

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}