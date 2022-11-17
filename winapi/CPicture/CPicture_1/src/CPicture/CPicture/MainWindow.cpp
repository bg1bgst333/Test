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
	m_pChild = NULL;	// m_pChild��NULL�ŏ�����.
	m_pPicture = NULL;	// m_pPicture��NULL�ŏ�����.
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
	if (m_pChild != NULL) {	// NULL�łȂ����.
		bRet = m_pChild->Destroy();	// m_pChild->Destroy�ŃE�B���h�E��j��.
		delete m_pChild;	// delete��m_pChild�����.
		m_pChild = NULL;	// NULL���Z�b�g.
	}

	// �s�N�`���[�̔j��.
	if (m_pPicture != NULL) {	// NULL�łȂ����.
		bRet = m_pPicture->Destroy();	// m_pPicture->Destroy�ŃE�B���h�E��j��.
		delete m_pPicture;	// delete��m_pPicture�����.
		m_pPicture = NULL;	// NULL���Z�b�g.
	}

	// �G�f�B�b�g�R�A�̔j��.
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

	// ���������X�N���[���o�[�̏�����.
	SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.nMin = 0;	// �ŏ��l��0.
	scrHorz.nMax = 640 - 1;	// �ő�l��639.
	scrHorz.nPage = 100;	// �y�[�W�T�C�Y��100.
	scrHorz.nPos = 0;	// ���݈ʒu��0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(hwnd, SB_HORZ, &scrHorz, TRUE);	// �X�N���[�������Z�b�g.

	// ���������X�N���[���o�[�̏�����.
	SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.nMin = 0;	// �ŏ��l��0.
	scrVert.nMax = 480 - 1;	// �ő�l��479.
	scrVert.nPage = 100;	// �y�[�W�T�C�Y��100.
	scrVert.nPos = 0;	// ���݈ʒu��0.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(hwnd, SB_VERT, &scrVert, TRUE);	// �X�N���[�������Z�b�g.

	// �q�E�B���h�E�̍쐬.
	m_pChild = new CWindow();	// CWindow�I�u�W�F�N�gm_pChild�쐬.
	RECT rc;	// RECT�\����rc.
	rc.left = 50;		// ��50
	rc.right = 150;		// �E150
	rc.top = 250;		// ��250
	rc.bottom = 350;	// ��350
	m_pChild->Create(_T("Child"), _T(""), WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X"Child"�̃E�B���h�E�쐬.	

	// �q�E�B���h�E�̐��������X�N���[���o�[�̏�����.
	SCROLLINFO scrVertChild = {0};	// ���������X�N���[�����scrVertChild��{0}�ŏ�����.
	scrVertChild.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVertChild.nMin = 0;	// �ŏ��l��0.
	scrVertChild.nMax = 480 - 1;	// �ő�l��479.
	scrVertChild.nPage = 100;	// �y�[�W�T�C�Y��100.
	scrVertChild.nPos = 0;	// ���݈ʒu��0.
	scrVertChild.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_pChild->m_hWnd, SB_VERT, &scrVertChild, TRUE);	// �X�N���[�������Z�b�g.

	// �s�N�`���[�R���g���[���̃E�B���h�E�쐬.
	m_pPicture = new CPicture();	// new��CPicture�I�u�W�F�N�g���쐬��, �|�C���^m_pPicture�Ɋi�[.
	/*
	RECT rc2;	// RECT�\����rc2.
	rc2.left = 150;		// ��150
	rc2.right = 250;		// �E250
	rc2.top = 250;		// ��250
	rc2.bottom = 350;	// ��350
	*/
	//m_pPicture->Create(_T(""), WS_BORDER | WS_VSCROLL | SS_BITMAP, rc2, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Create�Ńs�N�`���[�R���g���[���̃E�B���h�E�쐬.
	m_pPicture->Create(_T("CPicutre"), WS_BORDER | WS_VSCROLL | SS_BITMAP, 150, 250, 100, 100, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// Create�Ńs�N�`���[�R���g���[���̃E�B���h�E�쐬.

	// �s�N�`���[�̐��������X�N���[���o�[�̏�����.
	SCROLLINFO scrVertPicture = {0};	// ���������X�N���[�����scrVertPicture��{0}�ŏ�����.
	scrVertPicture.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVertPicture.nMin = 0;	// �ŏ��l��0.
	scrVertPicture.nMax = 480 - 1;	// �ő�l��479.
	scrVertPicture.nPage = 100;	// �y�[�W�T�C�Y��100.
	scrVertPicture.nPos = 0;	// ���݈ʒu��0.
	scrVertPicture.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_pPicture->m_hWnd, SB_VERT, &scrVertPicture, TRUE);	// �X�N���[�������Z�b�g.

	// �G�f�B�b�g�R�A�R���g���[���̃E�B���h�E�쐬.
	m_pEdit = new CEditCore();	// new��CEditCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pEdit�Ɋi�[.
	RECT rc3;	// RECT�\����rc3.
	rc3.left = 250;		// ��250
	rc3.right = 350;		// �E350
	rc3.top = 250;		// ��250
	rc3.bottom = 350;	// ��350
	m_pEdit->Create(_T("Edit1"), WS_BORDER | WS_VSCROLL, rc3, hwnd, (HMENU)(WM_APP + 3), lpCreateStruct->hInstance);	// Create�ŃG�f�B�b�g�R�A�R���g���[��"Edit1"�̃E�B���h�E�쐬.

	// �G�f�B�b�g�R�A�̐��������X�N���[���o�[�̏�����.
	SCROLLINFO scrVertEdit = {0};	// ���������X�N���[�����scrVertEdit��{0}�ŏ�����.
	scrVertEdit.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVertEdit.nMin = 0;	// �ŏ��l��0.
	scrVertEdit.nMax = 480 - 1;	// �ő�l��479.
	scrVertEdit.nPage = 100;	// �y�[�W�T�C�Y��100.
	scrVertEdit.nPos = 0;	// ���݈ʒu��0.
	scrVertEdit.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_pEdit->m_hWnd, SB_VERT, &scrVertEdit, TRUE);	// �X�N���[�������Z�b�g.
	
	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CMainWindow::OnPaint(){

	// �ϐ��̐錾.
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT�\����ps.

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.fMask = SIF_POS;	// �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfo��scrHorz���擾.

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.fMask = SIF_POS;	// �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfo��scrVert���擾.

	// ���������Ɛ��������̃X�N���[���o�[�̈ʒu�̕`��.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32API��BeginPaint��hDC���擾.
	TCHAR tszPos[128] = {0};	// scrHorz.nPos��scrVert.nPos�𕶎���ɂ�������tszPos(����128)��{0}�ŏ�����.
	_stprintf(tszPos, _T("scrHorz.nPos = %d, scrVert.nPos = %d"), scrHorz.nPos, scrVert.nPos);	// scrHorz.nPos��scrVert.nPos�𕶎���tszPos�ɕϊ�.
	TextOut(hDC, 100, 100, tszPos, (int)_tcslen(tszPos));	// TextOut��tszPos��`��.
	EndPaint(m_hWnd, &ps);	// Win32API��EndPaint�ŕ`��I��.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose(){

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CPicture"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK){	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}