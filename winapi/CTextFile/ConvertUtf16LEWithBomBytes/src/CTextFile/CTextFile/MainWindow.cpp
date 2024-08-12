// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow
#include "FileDialog.h"	// CFileDialog
#include "resource.h"

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
	m_pMainMenu = NULL;
	m_pTextFile = NULL;

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

	// �b��
	if (m_pTextFile != NULL) {	// m_pTextFile��NULL�łȂ����.
		delete m_pTextFile;	// delete��m_pTextFile�����.
		m_pTextFile = NULL;	// m_pTextFile��NULL���Z�b�g.
	}

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

	// �e�N���X��OnCreate���Ă�.
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��iRet�Ɋi�[.
	m_pMainMenu = GetMenu();	// CWindow::GetMenu��m_pMainMenu�擾.
	if (m_pMainMenu == NULL) {	// ���j���[�n���h���������ꍇ��, m_pMainMenu��NULL�ɂȂ�.
		m_pMainMenu = new CMenu();
		BOOL bRet = m_pMainMenu->CreateMenu();
		if (bRet) {
			// �T�u���j���[1�̍쐬.
			CMenu* pSubMenu1 = new CMenu();
			pSubMenu1->CreatePopupMenu();
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_1, _T("Item1-1(&A)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_2, _T("Item1-2(&B)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_3, _T("Item1-3(&C)"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_1_4, _T("Item1-4(&D)"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu1->m_hMenu, _T("Item1"));
			// �T�u���j���[2�̍쐬.
			CMenu* pSubMenu2 = new CMenu();
			pSubMenu2->CreatePopupMenu();
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_1, _T("Item2-1(&E)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_2, _T("Item2-2(&F)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_3, _T("Item2-3(&G)"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_2_4, _T("Item2-4(&H)"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu2->m_hMenu, _T("Item2"));
			// �T�u���j���[3�̍쐬.
			CMenu* pSubMenu3 = new CMenu();
			pSubMenu3->CreatePopupMenu();
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&I)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&J)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&K)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_4, _T("Item3-4(&L)"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu3->m_hMenu, _T("Item3"));
			SetMenu(m_pMainMenu);	// CWindow::SetMenu��m_pMainMenu���Z�b�g.
			DrawMenuBar();
			// ���j���[�n���h���̒ǉ�.
			AddCommandHandler(ID_ITEM_1_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_1);	// AddCommandHandler��ID_ITEM_1_1�ɑ΂���n���h��CMainWindow::OnItem1_1��o�^.
			AddCommandHandler(ID_ITEM_1_2, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_2);	// AddCommandHandler��ID_ITEM_1_2�ɑ΂���n���h��CMainWindow::OnItem1_2��o�^.
			AddCommandHandler(ID_ITEM_1_3, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_3);	// AddCommandHandler��ID_ITEM_1_3�ɑ΂���n���h��CMainWindow::OnItem1_3��o�^.
			AddCommandHandler(ID_ITEM_1_4, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem1_4);	// AddCommandHandler��ID_ITEM_1_4�ɑ΂���n���h��CMainWindow::OnItem1_4��o�^.
			AddCommandHandler(ID_ITEM_2_1, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem2_1);	// AddCommandHandler��ID_ITEM_2_1�ɑ΂���n���h��CMainWindow::OnItem2_1��o�^.
			AddCommandHandler(ID_ITEM_2_2, 0, (int(CWindow::*)(WPARAM, LPARAM)) & CMainWindow::OnItem2_2);	// AddCommandHandler��ID_ITEM_2_2�ɑ΂���n���h��CMainWindow::OnItem2_2��o�^.
			// �G�f�B�b�g�R�A�R���g���[���I�u�W�F�N�g�̍쐬.
			m_pEdit = new CEditCore();	// new��CEditCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pEdit�Ɋi�[.
			// �G�f�B�b�g�R�A�R���g���[��"Edit1"�̃E�B���h�E�쐬.
			RECT rc;	// RECT�\����rc.
			rc.left = 10;			// ��10
			rc.right = 10 + 320;	// �E10 + 320
			rc.top = 10;			// ��10
			rc.bottom = 10 + 240;	// ��10 + 240
			m_pEdit->Create(_T(""), WS_BORDER | WS_HSCROLL | WS_VSCROLL, rc, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃG�f�B�b�g�R�A�R���g���[���̃E�B���h�E�쐬.
			// �e�L�X�g�t�@�C���I�u�W�F�N�g�̍쐬.
			m_pTextFile = new CTextFile();
			m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOM��NONE�Ƃ���.
			// Item1-1�Ƀ��W�I�`�F�b�N��t����.
			CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_1, MF_BYCOMMAND);
		}
	}
	return iRet;	// iRet��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy() {

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_1_1, 0);	// DeleteCommandHandler��ID_ITEM_1_1�̃n���h�����폜.
	DeleteCommandHandler(ID_ITEM_1_2, 0);	// DeleteCommandHandler��ID_ITEM_1_2�̃n���h�����폜.
	DeleteCommandHandler(ID_ITEM_1_3, 0);	// DeleteCommandHandler��ID_ITEM_1_3�̃n���h�����폜.
	DeleteCommandHandler(ID_ITEM_1_4, 0);	// DeleteCommandHandler��ID_ITEM_1_4�̃n���h�����폜.
	DeleteCommandHandler(ID_ITEM_2_1, 0);	// DeleteCommandHandler��ID_ITEM_2_1�̃n���h�����폜.
	DeleteCommandHandler(ID_ITEM_2_2, 0);	// DeleteCommandHandler��ID_ITEM_2_2�̃n���h�����폜.

	// ���j���[�̏I������.
	CMenu::DeleteMenuHandleMap();
	m_pMainMenu = NULL;

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	// �G�f�B�b�g�{�b�N�X�̃T�C�Y���E�B���h�E��t�ɕύX.
	if (m_pEdit != NULL) {
		m_pEdit->MoveWindow(0, 0, cx, cy);
	}

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose() {

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CTextFile"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK) {	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// �^�C�~���O�ɂ���Ă͔j�����s���Ȃ��\��������̂�, �����ɂ��ꉞ�u���Ă���.
	if (m_pTextFile != NULL) {	// m_pTextFile��NULL�łȂ����.
		delete m_pTextFile;	// delete��m_pTextFile�����.
		m_pTextFile = NULL;	// m_pTextFile��NULL���Z�b�g.
	}

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}

// Item1-1���I�����ꂽ��.
int CMainWindow::OnItem1_1(WPARAM wParam, LPARAM lParam) {

	// Item1-1�Ƀ��W�I�`�F�b�N��t����.
	CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_1, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOM��NONE�Ƃ���.
	return 0;	// ���������̂�0.

}

// Item1-2���I�����ꂽ��.
int CMainWindow::OnItem1_2(WPARAM wParam, LPARAM lParam) {

	// Item1-2�Ƀ��W�I�`�F�b�N��t����.
	CMenu* pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_1_1, ID_ITEM_1_2, ID_ITEM_1_2, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16LE;	// BOM_UTF16LE�Ƃ���.
	return 0;	// ���������̂�0.


}

// Item1-3���I�����ꂽ��.
int CMainWindow::OnItem1_3(WPARAM wParam, LPARAM lParam) {

	return 0;	// ���������̂�0.

}

// Item1-4���I�����ꂽ��.
int CMainWindow::OnItem1_4(WPARAM wParam, LPARAM lParam) {

	return 0;	// ���������̂�0.

}

// Item2-1���I�����ꂽ��.
int CMainWindow::OnItem2_1(WPARAM wParam, LPARAM lParam) {

	// "�J��"�_�C�A���O
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK) {
		MessageBox(m_hWnd, _T("IDOK"), _T("CTextFile"), MB_OK);
		MessageBox(m_hWnd, dlg.GetOFN().lpstrFile, _T("CTextFile"), MB_OK);
	}
	else {
		MessageBox(m_hWnd, _T("IDCANCEL"), _T("CTextFile"), MB_OK);
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}

// Item2-2���I�����ꂽ��.
int CMainWindow::OnItem2_2(WPARAM wParam, LPARAM lParam) {

	// "���O��t���ĕۑ�"�_�C�A���O
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK) {
		tstring tstrText;
		m_pEdit->GetWindowText(tstrText);	// m_pEdit����擾.
		m_pTextFile->SetText(tstrText);	// tstrText��m_pTextFile�ɃZ�b�g.
		m_pTextFile->Write(dlg.GetOFN().lpstrFile);	// UTF-16LE�o�C�g��ɕϊ���, �o�b�t�@�ɃZ�b�g��, dlg.GetOFN().lpstrFile�ɏ�������.
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.


}