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
	m_pPicture = NULL;	// m_pPicture��NULL�ŏ�����.
	m_pBitmap = NULL;	// m_pBitmap��NULL�ŏ�����.

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

	// �s�N�`���[�̔j��.
	if (m_pPicture != NULL) {	// NULL�łȂ����.
		bRet = m_pPicture->Destroy();	// m_pPicture->Destroy�ŃE�B���h�E��j��.
		delete m_pPicture;	// delete��m_pPicture�����.
		m_pPicture = NULL;	// NULL���Z�b�g.
	}

	// �r�b�g�}�b�v�I�u�W�F�N�g�̔j��.
	if (m_pBitmap != NULL) {	// NULL�łȂ�.
		delete m_pBitmap;	// delete��m_pBitmap��j��.
		m_pBitmap = NULL;	// m_pBitmap��NULL���Z�b�g.
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

	// �s�N�`���[�R���g���[���̃E�B���h�E�쐬.
	m_pPicture = new CPicture();	// new��CPicture�I�u�W�F�N�g���쐬��, �|�C���^m_pPicture�Ɋi�[.
	m_pPicture->Create(_T("CPicture"), WS_BORDER | WS_HSCROLL, 50, 50, 400, 300, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�Ńs�N�`���[�R���g���[���̃E�B���h�E�쐬.

	// �r�b�g�}�b�v�I�u�W�F�N�g�̍쐬�ƃ��[�h.
	m_pBitmap = new CBitmap();	// new��CBitmap�I�u�W�F�N�g���쐬��, �|�C���^��m_pBitmap�Ɋi�[.
	m_pBitmap->LoadImage(lpCreateStruct->hInstance, _T("bitmap1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);	// CBitmap::LoadImage��"bitmap1.bmp"�����[�h.

	// �r�b�g�}�b�v�I�u�W�F�N�g�̃r�b�g�}�b�v���Z�b�g.
	m_pPicture->SetBitmap(*m_pBitmap);	// m_pPicture->SetBitmap��*m_pBitmap���Z�b�g.

	// �N���C�A���g�̈��RECT���擾.
	RECT rc = { 0 };	// RECT�^rc��{0}�ŏ�����.
	GetClientRect(m_pPicture->m_hWnd, &rc);	// �s�N�`���[�̃N���C�A���g�̈��RECT���擾.

	// ���������X�N���[���o�[�̏�����.
	SCROLLINFO scrHorz = { 0 };	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.nMin = 0;	// �ŏ��l��0.
	scrHorz.nMax = 640 - 1;	// �ő�l��639.
	scrHorz.nPage = rc.right - rc.left;	// �y�[�W�T�C�Y��rc.right - rc.left.
	scrHorz.nPos = 0;	// ���݈ʒu��0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_pPicture->m_hWnd, SB_HORZ, &scrHorz, TRUE);	// �X�N���[�������Z�b�g.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CPicture"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK) {	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}