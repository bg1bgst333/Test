// �w�b�_�̃C���N���[�h
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
	m_pUserControl = NULL;	// m_pUserControl��NULL�ŏ�����.

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
	if (m_pUserControl != NULL) {	// NULL�łȂ����.
		bRet = m_pUserControl->Destroy();	// m_pUserControl->Destroy�ŃE�B���h�E��j��.
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// NULL���Z�b�g.
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

	// HandlerConditions�̐����ƒǉ�.
	HandlerConditions *pCond = new HandlerConditions();	// HandlerConditions�I�u�W�F�N�g���쐬��, �|�C���^��pCond�Ɋi�[.
	pCond->m_nID = ID_ITEM_1_1;	// pCond->m_nID��ID_ITEM_1_1���i�[.
	pCond->m_nCode = 0;	// pCond->m_nCode��0���i�[.
	pCond->m_fpHandler = (int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnItem1_1;	// pCond->m_fpHandler��(int(CWindow::*)(WPARAM, LPARAM))&CMainWindow::OnItem1_1���i�[.
	m_mapHandlerMap.insert(std::pair<DWORD, HandlerConditions *>((DWORD)MAKEWPARAM(ID_ITEM_1_1, 0), pCond));	// m_mapHandlerMap.insert��ID_ITEM_1_1, 0��MAKEWPARAM�������̂��L�[, pCond��l�Ƃ��ēo�^.

	// ���[�U�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pUserControl = new CUserControl();	// new��CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.

	// �E�B���h�E�N���X��"UC1"�̃��[�U�R���g���[���̃E�B���h�E�쐬.
	m_pUserControl->Create(_T("UC1"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// Create�ŃE�B���h�E�N���X��"UC1"��CUserControl�E�B���h�E���쐬.

	// �e�N���X��OnCreate���Ă�.
	return CWindow::OnCreate(hwnd, lpCreateStruct);	// CWindow::OnCreate���Ă�, �߂�l��Ԃ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMainWindow::OnDestroy(){

	// �n���h���}�b�v����w��̃n���h�������폜.
	HandlerConditions *pCond = NULL;	// HandlerConditions�I�u�W�F�N�g�|�C���^pCond��NULL�ɏ�����.
	std::map<DWORD, HandlerConditions *>::iterator itor = m_mapHandlerMap.find((DWORD)(MAKEWPARAM(ID_ITEM_1_1, 0)));	// find�ŃL�[��(DWORD)(MAKEWPARAM(ID_ITEM_1_1, 0))�Ƃ���HandlerConditions�I�u�W�F�N�g�|�C���^�̃C�e���[�^���擾.
	if (itor != m_mapHandlerMap.end()){	// ����������.
		pCond = m_mapHandlerMap[(DWORD)(MAKEWPARAM(ID_ITEM_1_1, 0))];	// (DWORD)(MAKEWPARAM(ID_ITEM_1_1, 0))���g���ăn���h���}�b�v����HandlerConditions�I�u�W�F�N�g�|�C���^�������o��.
		delete pCond;	// HandlerConditions�I�u�W�F�N�g��j��.
		m_mapHandlerMap.erase(itor);	// itor�̎w���v�f���폜.
	}

	// CWindow��OnDestroy���Ă�.
	CWindow::OnDestroy();	// CWindow::OnDestroy���Ă�.

}

// �E�B���h�E�������鎞.
int CMainWindow::OnClose(){

	// ���b�Z�[�W�{�b�N�X��"Close CMainWindow OK?"�ƕ\��.
	int iRet = MessageBox(m_hWnd, _T("Close CMainWindow OK?"), _T("HandlerConditions"), MB_OKCANCEL);	// MessageBox��"Close CMainWindow OK?"�ƕ\����, �߂�l��iRet�Ɋi�[.
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

	// ���b�Z�[�W�{�b�N�X��\��.
	MessageBox(NULL, _T("Item1-1"), _T("HandlerConditions"), MB_OK);	// MessageBox��"Item1-1"�ƕ\��.
							
	// 0��Ԃ�.
	return 0;	// ���������̂�0.

}