// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "FileDialog.h"	// CFileDialog
#include "resource.h"

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

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(���j���[��, �F�w��o�[�W����)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszMenuName, int i){

	// ���j���[����lpctszMenuName, �F��i.
	return CWindow::RegisterClass(hInstance, _T("CMainWindow"), lpctszMenuName, i);	// CWindow::RegisterClass��, �E�B���h�E�N���X��"CMainWindow", ���j���[��lpctszMenuName, �F��i��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow(){

	// �����o�̏�����.
	m_pScreen = NULL;	// m_pScreen��NULL�ŏ�����.

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

	// �X�N���[���̔j��.
	if (m_pScreen != NULL) {	// NULL�łȂ����.
		bRet = m_pScreen->Destroy();	// m_pScreen->Destroy�ŃE�B���h�E��j��.
		delete m_pScreen;	// delete��m_pScreen�����.
		m_pScreen = NULL;	// NULL���Z�b�g.
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

	// �X�N���[���R���g���[���̃E�B���h�E�쐬.
	m_pScreen = new CScreen();	// new��CScreen�I�u�W�F�N�g���쐬��, �|�C���^m_pScreen�Ɋi�[.
	m_pScreen->Create(_T("CWindow"), WS_BORDER, 0, 0, 400, 300, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃX�N���[���R���g���[���̃E�B���h�E�쐬.

#if 1
	// �L�����o�X�쐬.
	m_pScreen->CreateCanvas(50, 50, 320, 240, (HMENU)(WM_APP + 2));
#endif

	// �n���h���ǉ�.
	AddCommandHandler(ID_ITEM_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileOpen);
	AddCommandHandler(ID_ITEM_FILE_SAVEAS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileSaveAs);
	AddCommandHandler(ID_ITEM_CURRENT_COLOR_BLACK, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnCurrentColorBlack);
	AddCommandHandler(ID_ITEM_CURRENT_COLOR_WHITE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnCurrentColorWhite);
	AddCommandHandler(ID_ITEM_CURRENT_COLOR_RED, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnCurrentColorRed);
	AddCommandHandler(ID_ITEM_CURRENT_COLOR_GREEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnCurrentColorGreen);
	AddCommandHandler(ID_ITEM_CURRENT_COLOR_BLUE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnCurrentColorBlue);

	// �e�N���X��OnCreate���Ă�.
	m_hInstance = lpCreateStruct->hInstance;
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

	// ���݂̐F�͍�.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0x00, 0x00, 0x00);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_BLACK;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_BLACK, MF_BYCOMMAND);
	return iRet;

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_FILE_OPEN, 0);
	DeleteCommandHandler(ID_ITEM_FILE_SAVEAS, 0);
	DeleteCommandHandler(ID_ITEM_CURRENT_COLOR_BLACK, 0);
	DeleteCommandHandler(ID_ITEM_CURRENT_COLOR_WHITE, 0);
	DeleteCommandHandler(ID_ITEM_CURRENT_COLOR_RED, 0);
	DeleteCommandHandler(ID_ITEM_CURRENT_COLOR_GREEN, 0);
	DeleteCommandHandler(ID_ITEM_CURRENT_COLOR_BLUE, 0);

	// ���j���[�̏I������.
	CMenu::DeleteMenuHandleMap();

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// �X�N���[���̃T�C�Y���E�B���h�E��t�ɕύX.
	if (m_pScreen != NULL){
		m_pScreen->MoveWindow(0, 0, cx, cy);
	}

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

// �J�����I�����ꂽ��.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam){

	// "�J��"�_�C�A���O
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Bitmap Files(*.bmp)|*.bmp|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK){
		if (m_pScreen != NULL){
			delete m_pScreen;
			m_pScreen = NULL;
		}
		m_pScreen = new CScreen();	// new��CScreen�I�u�W�F�N�g���쐬��, �|�C���^m_pScreen�Ɋi�[.
		m_pScreen->Create(_T("CWindow"), WS_BORDER, 0, 0, 400, 300, m_hWnd, (HMENU)(WM_APP + 1), m_hInstance);	// Create�ŃX�N���[���R���g���[���̃E�B���h�E�쐬.
		m_pScreen->LoadBitmap(dlg.GetOFN().lpstrFile);	// LoadBitmap�Ń��[�h.
		RECT rc = {0};
		GetClientRect(m_hWnd, &rc);
		m_pScreen->MoveWindow(0, 0, rc.right - rc.left, rc.bottom - rc.top, TRUE);
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}

// ���O��t���ĕۑ����I�����ꂽ��.
int CMainWindow::OnFileSaveAs(WPARAM wParam, LPARAM lParam){

	// "���O��t���ĕۑ�"�_�C�A���O
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Bitmap Files(*.bmp)|*.bmp||"));
	INT_PTR ret = dlg.DoModal();	
	if (ret == IDOK){
		if (m_pScreen != NULL){
			m_pScreen->SaveBitmap(dlg.GetOFN().lpstrFile);	// SaveBitmap�ŕۑ�.
		}
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.
	
}

// �����I�����ꂽ��.
int CMainWindow::OnCurrentColorBlack(WPARAM wParam, LPARAM lParam){

	// ���݂̐F�����ɕύX.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0x00, 0x00, 0x00);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_BLACK;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_BLACK, MF_BYCOMMAND);
	return 0;	// ���������̂�0.

}

// �����I�����ꂽ��.
int CMainWindow::OnCurrentColorWhite(WPARAM wParam, LPARAM lParam){

	// ���݂̐F�𔒂ɕύX.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0xff, 0xff, 0xff);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_WHITE;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_WHITE, MF_BYCOMMAND);
	return 0;	// ���������̂�0.

}

// �Ԃ��I�����ꂽ��.
int CMainWindow::OnCurrentColorRed(WPARAM wParam, LPARAM lParam){

	// ���݂̐F��ԂɕύX.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0xff, 0x00, 0x00);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_RED;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_RED, MF_BYCOMMAND);
	return 0;	// ���������̂�0.

}

// �΂��I�����ꂽ��.
int CMainWindow::OnCurrentColorGreen(WPARAM wParam, LPARAM lParam){

	// ���݂̐F��΂ɕύX.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0x00, 0xff, 0x00);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_GREEN;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_GREEN, MF_BYCOMMAND);
	return 0;	// ���������̂�0.

}

// ���I�����ꂽ��.
int CMainWindow::OnCurrentColorBlue(WPARAM wParam, LPARAM lParam){

	// ���݂̐F��ɕύX.
	CMenu *pMainMenu = GetMenu();
	m_pScreen->m_pCanvas->SetCurrentColor(0x00, 0x00, 0xff);
	m_CurrentColor = CURRENT_COLOR::CURRENT_COLOR_BLUE;
	CMenu *pSubMenu1 = pMainMenu->GetSubMenu(1);
	pSubMenu1->CheckMenuRadioItem(ID_ITEM_CURRENT_COLOR_BLACK, ID_ITEM_CURRENT_COLOR_BLUE, ID_ITEM_CURRENT_COLOR_BLUE, MF_BYCOMMAND);
	return 0;	// ���������̂�0.

}