// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
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
	m_pStatic = NULL;	// m_pStatic��NULL�ŏ�����.

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
	if (m_pStatic != NULL) {	// NULL�łȂ����.
		bRet = m_pStatic->Destroy();	// m_pStatic->Destroy�ŃE�B���h�E��j��.
		delete m_pStatic;	// delete��m_pStatic�����.
		m_pStatic = NULL;	// NULL���Z�b�g.
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

	// �X�^�e�B�b�N�R�A�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pStatic = new CStaticCore();	// new��CStaticCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pStatic�Ɋi�[.

	// �X�^�e�B�b�N�R�A�R���g���[��"Static1"�̃E�B���h�E�쐬.
	RECT rc;	// RECT�\����rc.
	rc.left = 50;		// ��50
	rc.right = 150;		// �E150
	rc.top = 50;		// ��50
	rc.bottom = 150;	// ��150
	m_pStatic->Create(_T("Static1"), WS_BORDER | SS_SIMPLE, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃX�^�e�B�b�N�R�A�R���g���[��"Static1"�̃E�B���h�E�쐬.

	// �r�b�g�}�b�v�I�u�W�F�N�g�̍쐬�ƃ��[�h.
	m_pBitmap = new CBitmap();	// new��CBitmap�I�u�W�F�N�g���쐬��, �|�C���^��m_pBitmap�Ɋi�[.
	BOOL bRet = m_pBitmap->LoadBitmap(lpCreateStruct->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));	// CBitmap::LoadBitmap��IDB_BITMAP1�����[�h.
	TCHAR tszBuf[64] = { 0 };	// TCHAR�o�b�t�@tszBuf(����64)��{0}�ŏ�����.
	_stprintf(tszBuf, _T("m_pBitmap->m_hBitmap = 0x%08x"), (unsigned int)m_pBitmap->m_hBitmap);	// _stprintf�Ńn���h���𕶎���ɕϊ�.
	MessageBox(m_hWnd, tszBuf, _T("CBitmap"), MB_OK);	// MessageBox��tszBuf��\��.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// �r�b�g�}�b�v�I�u�W�F�N�g�̔j��.
	if (m_pBitmap != NULL) {	// NULL�łȂ�.
		delete m_pBitmap;	// delete��m_pBitmap��j��.
		m_pBitmap = NULL;	// m_pBitmap��NULL���Z�b�g.
	}

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandler��ID_ITEM_1_1�̃n���h�����폜.

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CBitmap"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
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

	// �X�^�e�B�b�N�R���g���[���̃E�B���h�E�e�L�X�g��ύX����.
	m_pStatic->SetWindowText(_T("Renamed!"));	// CWindow::SetWindowText��"Renamed!"�ɕύX.

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}