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
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CWindow"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK){	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}