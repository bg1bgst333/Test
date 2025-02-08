// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Screen.h"	// CScreen

// �R���X�g���N�^CScreen
CScreen::CScreen() : CUserControl() {

	// �����o�̏�����.
	m_pCanvas = NULL;	// m_pCanvas��NULL�ŏ�����.
	m_pDIBSection = NULL;

}

// �f�X�g���N�^~CScreen
CScreen::~CScreen() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CScreen"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�F�w��o�[�W����.)
BOOL CScreen::RegisterClass(HINSTANCE hInstance, int i) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CScreen"), i);	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CScreen"��o�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CScreen::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CScreen".
	return CUserControl::Create(_T("CScreen"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CScreen"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CScreen::Destroy() {

	// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// �q�E�B���h�E�̔j��.
	DestroyChildren();

	// ���g�̔j��.
	bRet = CUserControl::Destroy();
	return bRet;

}

// �q�E�B���h�E�j���֐�DestroyChildren
BOOL CScreen::DestroyChildren() {

	// �ϐ��̏�����.
	BOOL bRet = FALSE;	// bRet��FALSE�ŏ�����.

	// DIBSection�̔j��.
	if (m_pDIBSection != NULL) {	// NULL�łȂ����.
		delete m_pDIBSection;	// delete��m_pDIBSection�����.
		m_pDIBSection = NULL;	// NULL���Z�b�g.
	}

	// �L�����o�X�̔j��.
	if (m_pCanvas != NULL) {	// NULL�łȂ����.
		bRet = m_pCanvas->Destroy();	// m_pCanvas->Destroy�ŃE�B���h�E��j��.
		delete m_pCanvas;	// delete��m_pCanvas�����.
		m_pCanvas = NULL;	// NULL���Z�b�g.
	}

	// �j��������TRUE��Ԃ�.
	if (bRet) {	// TRUE�Ȃ�.
		return TRUE;	// TRUE��Ԃ�.
	}

	// �j�����Ȃ����, CWindow��DestroyChildren��Ԃ�.
	return CWindow::DestroyChildren();	// CWindow::DestroyChildren��Ԃ�.

}

// �L�����o�X�쐬�֐�CreateCanvas.
const CCanvas* CScreen::CreateCanvas(int x, int y, int iWidth, int iHeight, HMENU hMenu) {

	// �L�����o�X�R���g���[���̃E�B���h�E�쐬.
	m_pCanvas = new CCanvas();	// new��CCanvas�I�u�W�F�N�g���쐬��, �|�C���^m_pCanvas�Ɋi�[.
	m_pCanvas->Create(_T("CCanvas"), 0, x, y, iWidth, iHeight, m_hWnd, (HMENU)(WM_APP + 2), m_hInstance);	// Create�ŃL�����o�X�R���g���[���̃E�B���h�E�쐬.

	// DIB�Z�N�V�����̍쐬.
	m_pDIBSection = new CDIBSection();
	m_pDIBSection->CreateDIBSection(m_pCanvas->m_hWnd, iWidth, iHeight);

	// DIB�Z�N�V�����̃Z�b�g.
	m_pCanvas->SetBitmap(m_pDIBSection);

	// m_pCanvas��Ԃ�.
	return m_pCanvas;

}

// �r�b�g�}�b�v�ۑ��֐�SaveBitmap.
BOOL CScreen::SaveBitmap(LPCTSTR lpctszFileName) {

	// m_pDIBSection->SaveBitmap�ŕۑ�.
	if (m_pCanvas != NULL && m_pDIBSection != NULL) {
		return m_pDIBSection->SaveBitmap(m_pCanvas->m_hWnd, lpctszFileName);	// SaveBitmap�ŕۑ�.
	}
	else {
		return FALSE;
	}

}

// �r�b�g�}�b�v�Ǎ��֐�LoadBitmap.
BOOL CScreen::LoadBitmap(LPCTSTR lpctszFileName) {

	// �r�b�g�}�b�v���̓ǂݍ���.
	m_pDIBSection = new CDIBSection();
	m_pDIBSection->LoadBitmap(lpctszFileName, FALSE);	// �T�C�Y���擾�̂�.

	// �L�����o�X�R���g���[���̃E�B���h�E�쐬.
	m_pCanvas = new CCanvas();	// new��CCanvas�I�u�W�F�N�g���쐬��, �|�C���^m_pCanvas�Ɋi�[.
	m_pCanvas->Create(_T("CCanvas"), 0, 50, 50, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight, m_hWnd, (HMENU)(WM_APP + 2), m_hInstance);	// Create�ŃL�����o�X�R���g���[���̃E�B���h�E�쐬.
	m_pDIBSection->CreateDIBSection(m_pCanvas->m_hWnd, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight);

	// �s�N�Z����ǂݍ���.
	m_pDIBSection->LoadBitmap(lpctszFileName, TRUE);	// �s�N�Z����ǂݍ���.

	// �r�b�g�}�b�v�̃Z�b�g.
	m_pCanvas->SetBitmap(m_pDIBSection);	// m_pDIBSection���Z�b�g.

	// TRUE��Ԃ�.
	return TRUE;

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CScreen::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �e�N���X��OnCreate���Ă�.
	m_hInstance = lpCreateStruct->hInstance;
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}