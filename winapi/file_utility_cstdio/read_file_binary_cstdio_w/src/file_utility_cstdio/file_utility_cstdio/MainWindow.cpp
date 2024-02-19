// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
#include <string>	// std::string
#include <tchar.h>	// TCHAR�^

// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

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
	m_pEdit = NULL;	// m_pEdit��NULL�ŏ�����.

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
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ���j���[�n���h���̒ǉ�.
	AddCommandHandler(ID_FILE_SAVE, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnFileSave);	// AddCommandHandler��ID_FILE_SAVE�ɑ΂���n���h��CMainWindow::OnFileSave��o�^.
	AddCommandHandler(ID_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnFileOpen);	// AddCommandHandler��ID_FILE_OPEN�ɑ΂���n���h��CMainWindow::OnFileOpen��o�^.

	// �G�f�B�b�g�R�A�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pEdit = new CEditCore();	// new��CEditCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pEdit�Ɋi�[.

	// �G�f�B�b�g�R�A�R���g���[���̃E�B���h�E�쐬.
	RECT rc;	// RECT�\����rc.
	rc.left = 50;		// ��50
	rc.right = 150;		// �E150
	rc.top = 50;		// ��50
	rc.bottom = 150;	// ��150
	m_pEdit->Create(_T(""), WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃG�f�B�b�g�R�A�R���g���[���̃E�B���h�E�쐬.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_FILE_SAVE, 0);	// DeleteCommandHandler��ID_FILE_SAVE�̃n���h�����폜.
	DeleteCommandHandler(ID_FILE_OPEN, 0);	// DeleteCommandHandler��ID_FILE_OPEN�̃n���h�����폜.

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	/// �G�f�B�b�g�{�b�N�X�̃T�C�Y�����C���E�B���h�E�̃N���C�A���g�̈�ɍ��킹��.
	if (m_pEdit != NULL) {	// NULL�łȂ��ꍇ.
		m_pEdit->MoveWindow(0, 0, cx, cy);	// m_pEdit->MoveWindow��cx, cy���w��.
	}

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("file_utility_cstdio"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK) {	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}

// Save���I�����ꂽ��.
int CMainWindow::OnFileSave(WPARAM wParam, LPARAM lParam) {

	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���擾.
	std::wstring wstrEditText;	// std::wstring�I�u�W�F�N�gwstrEditText��p��.
	m_pEdit->GetWindowText(wstrEditText);	// m_pEdit->GetWindowText�Ńe�L�X�g�擾.

	// ���C�h�����񂩂�}���`�o�C�g������ɕϊ����K�v.
	int iBufLen = WideCharToMultiByte(CP_ACP, 0, wstrEditText.c_str(), -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
	char* pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
	WideCharToMultiByte(CP_ACP, 0, wstrEditText.c_str(), -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.

	// "test.txt"�Ƀt�@�C���o��.
	write_file_binary_cstdio_w(L"test.txt", pszBuf, iBufLen - 1);	// write_file_binary_cstdio_w��pszBuf��"test.txt"�ɏo��.

	// ���������.
	delete[] pszBuf;	// delete[]��pszBuf�̉��.

	// ���b�Z�[�W�{�b�N�X��\��.
	MessageBox(NULL, _T("Save"), _T("file_utility_cstdio"), MB_OK);	// MessageBox��"Save"�ƕ\��.

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}

// Open���I�����ꂽ��.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam) {

	// "test.txt"�̃T�C�Y���擾.
	size_t file_size = get_file_size("test.txt");	// get_file_size��"test.txt"�̃T�C�Yfile_size���擾.

	// �o�b�t�@�̊m��.
	char* pszBuf = new char[file_size + 1];	// new��(file_size + 1)���̃������m��.

	// �t�@�C���ǂݍ���.
	size_t ret = read_file_binary_cstdio_w(L"test.txt", pszBuf, file_size + 1);	// read_file_binary_cstdio_w�œǂݍ���.
	pszBuf[ret] = '\0';	// NULL�I�[����.

	// �}���`�o�C�g�����񂩂烏�C�h������֕ϊ�.
	int iBufLen = MultiByteToWideChar(CP_ACP, 0, pszBuf, -1, NULL, 0);	// �܂��͒������擾.
	wchar_t* pwszBuf = new wchar_t[iBufLen];	// iBufLen��wchar_t�^�o�b�t�@���m��.
	MultiByteToWideChar(CP_ACP, 0, pszBuf, -1, pwszBuf, iBufLen);	// �ϊ�.

	// �G�f�B�b�g�R���g���[���ɃZ�b�g.
	m_pEdit->SetWindowText(pwszBuf);	// m_pEdit->SetWindowText�Ńe�L�X�g�ݒ�.

	// ���������.
	delete[] pwszBuf;	// delete[]��pwszBuf�̉��.
	delete[] pszBuf;	// delete[]��pszBuf�̉��.	

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}