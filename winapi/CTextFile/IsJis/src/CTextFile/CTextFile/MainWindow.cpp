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

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow(){

	// �����o�̏�����.
	m_pMainMenu = NULL;
	m_pTextFile = NULL;

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow(){

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

	// �b��
	if (m_pTextFile != NULL){	// m_pTextFile��NULL�łȂ����.
		delete m_pTextFile;	// delete��m_pTextFile�����.
		m_pTextFile = NULL;	// m_pTextFile��NULL���Z�b�g.
	}

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

	// �e�N���X��OnCreate���Ă�.
	int iRet = CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��iRet�Ɋi�[.
	m_pMainMenu = GetMenu();	// CWindow::GetMenu��m_pMainMenu�擾.
	if (m_pMainMenu == NULL){	// ���j���[�n���h���������ꍇ��, m_pMainMenu��NULL�ɂȂ�.
		m_pMainMenu = new CMenu();
		BOOL bRet = m_pMainMenu->CreateMenu();
		if (bRet){
			// �T�u���j���[1�̍쐬.
			CMenu *pSubMenu1 = new CMenu();
			pSubMenu1->CreatePopupMenu();
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_NONE, _T("BOM�Ȃ�"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF16LE, _T("UTF-16LE BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF16BE, _T("UTF-16BE BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_BOM_UTF8, _T("UTF-8 BOM"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_SHIFTJIS, _T("Shift_JIS"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF16LE, _T("UTF-16LE"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF16BE, _T("UTF-16BE"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_UTF8, _T("UTF-8"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_EUCJP, _T("EUC-JP"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_ENCODE_JIS, _T("JIS"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_CRLF, _T("CRLF"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_LF, _T("LF"));
			pSubMenu1->AppendMenu(MF_STRING, ID_ITEM_NEW_LINE_CR, _T("CR"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu1->m_hMenu, _T("Item1"));
			// �T�u���j���[2�̍쐬.
			CMenu *pSubMenu2 = new CMenu();
			pSubMenu2->CreatePopupMenu();
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_FILE_OPEN, _T("�J��"));
			pSubMenu2->AppendMenu(MF_STRING, ID_ITEM_FILE_SAVEAS, _T("���O��t���ĕۑ�"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu2->m_hMenu, _T("Item2"));
			// �T�u���j���[3�̍쐬.
			CMenu *pSubMenu3 = new CMenu();
			pSubMenu3->CreatePopupMenu();
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_1, _T("Item3-1(&L)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_2, _T("Item3-2(&M)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_3, _T("Item3-3(&N)"));
			pSubMenu3->AppendMenu(MF_STRING, ID_ITEM_3_4, _T("Item3-4(&O)"));
			// ���C�����j���[�ɒǉ�.
			m_pMainMenu->AppendMenu(MF_POPUP, (UINT_PTR)pSubMenu3->m_hMenu, _T("Item3"));
			SetMenu(m_pMainMenu);	// CWindow::SetMenu��m_pMainMenu���Z�b�g.
			DrawMenuBar();
			// ���j���[�n���h���̒ǉ�.
			AddCommandHandler(ID_ITEM_BOM_NONE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomNone);
			AddCommandHandler(ID_ITEM_BOM_UTF16LE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf16LE);
			AddCommandHandler(ID_ITEM_BOM_UTF16BE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf16BE);
			AddCommandHandler(ID_ITEM_BOM_UTF8, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnBomUtf8);
			AddCommandHandler(ID_ITEM_ENCODE_SHIFTJIS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeShiftJis);
			AddCommandHandler(ID_ITEM_ENCODE_UTF16LE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf16LE);
			AddCommandHandler(ID_ITEM_ENCODE_UTF16BE, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf16BE);
			AddCommandHandler(ID_ITEM_ENCODE_UTF8, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeUtf8);
			AddCommandHandler(ID_ITEM_ENCODE_EUCJP, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeEucJp);
			AddCommandHandler(ID_ITEM_ENCODE_JIS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnEncodeJis);
			AddCommandHandler(ID_ITEM_NEW_LINE_CRLF, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineCRLF);
			AddCommandHandler(ID_ITEM_NEW_LINE_LF, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineLF);
			AddCommandHandler(ID_ITEM_NEW_LINE_CR, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnNewLineCR);
			AddCommandHandler(ID_ITEM_FILE_OPEN, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileOpen);
			AddCommandHandler(ID_ITEM_FILE_SAVEAS, 0, (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnFileSaveAs);
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
			CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
			m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOM��NONE�Ƃ���.
			// Item1-3�Ƀ��W�I�`�F�b�N��t����.
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
			m_pTextFile->m_Encoding = CTextFile::ENCODING_SHIFT_JIS;	// Shift_JIS�Ƃ���.
			// Item1-5�Ƀ��W�I�`�F�b�N��t����.
			pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
			m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CRLF;	// CRLF�Ƃ���.
		}
	}
	return iRet;	// iRet��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// ���j���[�n���h���̍폜.
	DeleteCommandHandler(ID_ITEM_BOM_NONE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF16LE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF16BE, 0);
	DeleteCommandHandler(ID_ITEM_BOM_UTF8, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_SHIFTJIS, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF16LE, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF16BE, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_UTF8, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_EUCJP, 0);
	DeleteCommandHandler(ID_ITEM_ENCODE_JIS, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_CRLF, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_LF, 0);
	DeleteCommandHandler(ID_ITEM_NEW_LINE_CR, 0);
	DeleteCommandHandler(ID_ITEM_FILE_OPEN, 0);
	DeleteCommandHandler(ID_ITEM_FILE_SAVEAS, 0);

	// ���j���[�̏I������.
	CMenu::DeleteMenuHandleMap();
	m_pMainMenu = NULL;

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMainWindow::OnSize(UINT nType, int cx, int cy){

	// �G�f�B�b�g�{�b�N�X�̃T�C�Y���E�B���h�E��t�ɕύX.
	if (m_pEdit != NULL){
		m_pEdit->MoveWindow(0, 0, cx, cy);
	}

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose(){

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("CTextFile"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
	if (iRet != IDOK){	// OK�ȊO.(Cancel�Ȃ�.)
		return -1;	// -1��Ԃ�.
	}

	// ���̃E�B���h�E�̔j��.(OnClose�̌�, �E�B���h�E�̔j������������ɍs����̂�, Destroy�͕s�v�Ȃ̂ŃR�����g�A�E�g.)
	//Destroy();	// Destroy�ł��̃E�B���h�E�̔j������.

	// �^�C�~���O�ɂ���Ă͔j�����s���Ȃ��\��������̂�, �����ɂ��ꉞ�u���Ă���.
	if (m_pTextFile != NULL){	// m_pTextFile��NULL�łȂ����.
		delete m_pTextFile;	// delete��m_pTextFile�����.
		m_pTextFile = NULL;	// m_pTextFile��NULL���Z�b�g.
	}

	// OK�Ȃ̂ŕ���.
	return CWindow::OnClose();	// �e�N���X��OnClose���Ă�.(�e�N���X��OnClose�͏�ɕ��鏈���ɂȂ��Ă���.)

}

// BOM�Ȃ����I�����ꂽ��.
int CMainWindow::OnBomNone(WPARAM wParam, LPARAM lParam){

	// BOM�Ȃ��Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOM��NONE�Ƃ���.
	return 0;	// ���������̂�0.

}

// UTF-16LE BOM���I�����ꂽ��.
int CMainWindow::OnBomUtf16LE(WPARAM wParam, LPARAM lParam){

	// UTF-16LE BOM�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16LE;	// BOM_UTF16LE�Ƃ���.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16LE;	// UTF-16LE�Ƃ���.
	return 0;	// ���������̂�0.

}

// UTF-16BE BOM���I�����ꂽ��.
int CMainWindow::OnBomUtf16BE(WPARAM wParam, LPARAM lParam){

	// UTF-16BE BOM�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF16BE;	// BOM_UTF16BE�Ƃ���.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16BE;	// UTF-16BE�Ƃ���.
	return 0;	// ���������̂�0.

}

// UTF-8 BOM���I�����ꂽ��.
int CMainWindow::OnBomUtf8(WPARAM wParam, LPARAM lParam){

	// UTF-8 BOM�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_UTF8;	// BOM_UTF8�Ƃ���.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_8;	// UTF-8�Ƃ���.
	return 0;	// ���������̂�0.

}

// Shift_JIS���I�����ꂽ��.
int CMainWindow::OnEncodeShiftJis(WPARAM wParam, LPARAM lParam){

	// Shift_JIS�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_SHIFT_JIS;	// Shift_JIS�Ƃ���.
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
	m_pTextFile->m_Bom = CTextFile::BOM_NONE;	// BOM��NONE�Ƃ���.
	return 0;	// ���������̂�0.

}

// UTF-16LE�I�����ꂽ��.
int CMainWindow::OnEncodeUtf16LE(WPARAM wParam, LPARAM lParam){

	// UTF-16LE�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16LE;	// UTF-16LE�Ƃ���.
	return 0;	// ���������̂�0.

}

// UTF-16BE���I�����ꂽ��.
int CMainWindow::OnEncodeUtf16BE(WPARAM wParam, LPARAM lParam){

	// UTF-16BE�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_16BE;	// UTF-16BE�Ƃ���.
	return 0;	// ���������̂�0.


}

// UTF-8���I�����ꂽ��.
int CMainWindow::OnEncodeUtf8(WPARAM wParam, LPARAM lParam){

	// UTF-8�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_UTF_8;	// UTF-8�Ƃ���.
	return 0;	// ���������̂�0.

}

// EUC-JP���I�����ꂽ��.
int CMainWindow::OnEncodeEucJp(WPARAM wParam, LPARAM lParam){

	// EUC-JP�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_EUCJP, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_EUC_JP;	// EUC-JP�Ƃ���.
	return 0;	// ���������̂�0.

}

// JIS���I�����ꂽ��.
int CMainWindow::OnEncodeJis(WPARAM wParam, LPARAM lParam){

	// JIS�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_JIS, ID_ITEM_ENCODE_JIS, MF_BYCOMMAND);
	m_pTextFile->m_Encoding = CTextFile::ENCODING_JIS;	// JIS�Ƃ���.
	return 0;	// ���������̂�0.

}

// CRLF���I�����ꂽ��.
int CMainWindow::OnNewLineCRLF(WPARAM wParam, LPARAM lParam){

	// CRLF�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CRLF;	// CRLF�Ƃ���.
	return 0;	// ���������̂�0.

}

// LF���I�����ꂽ��.
int CMainWindow::OnNewLineLF(WPARAM wParam, LPARAM lParam){

	// LF�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_LF, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_LF;	// LF�Ƃ���.
	return 0;	// ���������̂�0.

}

// CR���I�����ꂽ��.
int CMainWindow::OnNewLineCR(WPARAM wParam, LPARAM lParam){

	// CR�Ƀ��W�I�`�F�b�N��t����.
	CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
	pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CR, MF_BYCOMMAND);
	m_pTextFile->m_NewLine = CTextFile::NEW_LINE_CR;	// CR�Ƃ���.
	return 0;	// ���������̂�0.

}

// �J�����I�����ꂽ��.
int CMainWindow::OnFileOpen(WPARAM wParam, LPARAM lParam){

	// "�J��"�_�C�A���O
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();
	if (ret == IDOK){
		BOOL bRet = m_pTextFile->Read(dlg.GetOFN().lpstrFile);	// �w�肳�ꂽ�t�@�C����ǂݍ���, �ǂݍ��񂾃o�C�g��𕶎��R�[�h�ϊ���, �e�L�X�g�Ƃ��Ď���.
		if (bRet){	// ����.
			// ���j���[���W�I�`�F�b�N�̕ύX.
			CMenu *pSubMenu0 = m_pMainMenu->GetSubMenu(0);
			// BOM.
			if (m_pTextFile->m_Bom == CTextFile::BOM_UTF16LE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16LE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Bom == CTextFile::BOM_UTF16BE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF16BE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Bom == CTextFile::BOM_UTF8){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_UTF8, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_BOM_NONE, ID_ITEM_BOM_UTF8, ID_ITEM_BOM_NONE, MF_BYCOMMAND);
			}
			// �����R�[�h.
			if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_16LE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF16LE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_16BE){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF16BE, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_UTF_8){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_UTF8, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_Encoding == CTextFile::ENCODING_SHIFT_JIS){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_SHIFTJIS, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_ENCODE_SHIFTJIS, ID_ITEM_ENCODE_EUCJP, ID_ITEM_ENCODE_EUCJP, MF_BYCOMMAND);
			}
			// ���s�R�[�h.
			if (m_pTextFile->m_NewLine == CTextFile::NEW_LINE_CR){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CR, MF_BYCOMMAND);
			}
			else if (m_pTextFile->m_NewLine == CTextFile::NEW_LINE_LF){
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_LF, MF_BYCOMMAND);
			}
			else{
				pSubMenu0->CheckMenuRadioItem(ID_ITEM_NEW_LINE_CRLF, ID_ITEM_NEW_LINE_CR, ID_ITEM_NEW_LINE_CRLF, MF_BYCOMMAND);
			}
			m_pEdit->SetWindowText(m_pTextFile->m_tstrText.c_str());	// m_tstrText��m_pEdit�ɃZ�b�g.
		}
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}

// ���O��t���ĕۑ����I�����ꂽ��.
int CMainWindow::OnFileSaveAs(WPARAM wParam, LPARAM lParam){

	// "���O��t���ĕۑ�"�_�C�A���O
	CFileDialog dlg(FALSE, NULL, NULL, OFN_OVERWRITEPROMPT, _T("Text Files(*.txt)|*.txt|All Files(*.*)|*.*||"));
	INT_PTR ret = dlg.DoModal();	
	if (ret == IDOK){
		tstring tstrText;
		m_pEdit->GetWindowText(tstrText);	// m_pEdit����擾.
		m_pTextFile->SetText(tstrText);	// tstrText��m_pTextFile�ɃZ�b�g.
		m_pTextFile->Write(dlg.GetOFN().lpstrFile);	// UTF-16LE�o�C�g��ɕϊ���, �o�b�t�@�ɃZ�b�g��, dlg.GetOFN().lpstrFile�ɏ�������.
	}

	// 0��Ԃ�.
	return 0;	// ���������̂�0.
	
}