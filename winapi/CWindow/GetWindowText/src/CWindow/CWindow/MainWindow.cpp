// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X��"CMainWindow"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[���w��o�[�W����)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName){

	// ���j���[����lpctszMenuName.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName);	// CWindow::RegisterClass��, �E�B���h�E�N���X��"CMainWindow", ���j���[��lpctszMenuName��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow(){

	// �����o�̏�����.
	m_pButton = NULL;	// m_pButton��NULL�ŏ�����.
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow(){

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CMainWindow::Destroy(){

	// �ϐ��̏�����.
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
BOOL CMainWindow::DestroyChildren(){

	// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// �q�E�B���h�E�̔j��.
	if (m_pButton != NULL) {	// NULL�łȂ����.
		bRet = m_pButton->Destroy();	// m_pButton->Destroy�ŃE�B���h�E��j��.
		delete m_pButton;	// delete��m_pButton�����.
		m_pButton = NULL;	// NULL���Z�b�g.
	}

	// �q�E�B���h�E�̔j��.
	if (m_pEdit != NULL) {	// NULL�łȂ����.
		bRet = m_pEdit->Destroy();	// m_pEdit->Destroy�ŃE�B���h�E��j��.
		delete m_pEdit;	// delete��m_pEdit�����.
		m_pEdit = NULL;	// NULL���Z�b�g.
	}

	// �j��������TRUE��Ԃ�.
	if (bRet) {	// TRUE�Ȃ�.
		return TRUE;	// TRUE��Ԃ�.
	}

	// �j�����Ȃ����, CWindow��DestroyChildren��Ԃ�.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildren��Ԃ�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���j���[�n���h���̒ǉ�.
	AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnItem1_1);	// AddCommandHandler��ID_ITEM_1_1�ɑ΂���n���h��CMainWindow::OnItem1_1��o�^.
	
	// �{�^���R�A�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pButton = new CButtonCore();	// new��CButtonCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pButton�Ɋi�[.

	// �{�^���R�A�R���g���[��"Button1"�̃E�B���h�E�쐬.
	m_pButton->Create(_T("Button1"), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�Ń{�^���R�A�R���g���[��"Button1"�̃E�B���h�E�쐬.

	// �{�^���n���h���̒ǉ�.
	AddCommandHandler(WM_APP + 1, BN_CLICKED, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBnClicked1);	// AddCommandHandler��WM_APP + 1��BN_CLICKED�ɑ΂���n���h��CMainWindow::OnBnClicked1��o�^.

	// �G�f�B�b�g�R�A�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pEdit = new CEditCore();	// new��CEditCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pEdit�Ɋi�[.

	// �G�f�B�b�g�R�A�R���g���[��"Edit1"�̃E�B���h�E�쐬.
	m_pEdit->Create(_T("Edit1"), WS_BORDER, 50, 200, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Create�ŃG�f�B�b�g�R�A�R���g���[��"Edit1"�̃E�B���h�E�쐬.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandler��ID_ITEM_1_1�̃n���h�����폜.

	// �{�^���n���h���̍폜.
	DeleteCommandHandler(WM_APP + 1, BN_CLICKED);	// DeleteCommandHandler��WM_APP + 1��BN_CLICKED�ɑ΂���n���h�����폜.

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose(){

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CWindow"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK){	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}

// Item1-1���I�����ꂽ��.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam){

	// m_pEdit�̃e�L�X�g���擾.
	int iEditLen = m_pEdit->GetWindowTextLength();	// CWindow::GetWindowTextLength��m_pEdit�̃e�L�X�g�̒������擾.
	TCHAR *ptszBuf = new TCHAR[iEditLen + 1];	// TCHAR�o�b�t�@ptszBuf(����iEditLen + 1)���m��.
	ZeroMemory(ptszBuf, sizeof(TCHAR) * (iEditLen + 1));	// ptszBuf�̏�����.
	m_pEdit->GetWindowText(ptszBuf, iEditLen + 1);	// CWindow::GetWindowText��m_pEdit�̃e�L�X�g���擾.
	MessageBox(NULL, ptszBuf, _T("CWindow"), MB_OK);	// MessageBox��ptszBuf��\��.
	delete [] ptszBuf;	// delete[]��ptszBuf�����.

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}

// Button1���N���b�N���ꂽ��.
int CMainWindow::OnBnClicked1(WPARAM wParam, LPARAM lParam){

	// �{�^���̃e�L�X�g��"Clicked!"�ɕύX.
	m_pButton->SetWindowText(_T("Clicked!"));	// CWindow::SetWindowText��"Clicked!"���Z�b�g.

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}