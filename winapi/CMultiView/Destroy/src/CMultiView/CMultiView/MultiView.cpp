// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MultiView.h"	// CMultiView
#include "resource.h"

// �R���X�g���N�^CMultiView
CMultiView::CMultiView() : CUserControl() {

	// �����o�ϐ��̏�����.
	m_pMultiViewItemsPanel = NULL;	// m_pMultiViewItemsPanel��NULL�ŏ�����.

}

// �f�X�g���N�^~CMultiView
CMultiView::~CMultiView() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMultiView::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"));	// CUserControl::RegisterClass�œo�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�n���h���w��o�[�W����.)
BOOL CMultiView::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground) {

	// �E�B���h�E�N���X���ɂ�lpctszClassName, �w�i�u���V�n���h���ɂ�hbrBackground���w��.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"), hbrBackground);	// CUserControl::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CMultiView::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬.
	return CUserControl::Create(_T("CMultiView"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ō쐬.

}

// �E�B���h�E�j���֐�Destroy
BOOL CMultiView::Destroy() {

	// �}���`�r���[�A�C�e���Y�p�l���̔j��.
	if (m_pMultiViewItemsPanel != NULL) {
		m_pMultiViewItemsPanel->Destroy();
		delete m_pMultiViewItemsPanel;
		m_pMultiViewItemsPanel = NULL;
	}

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �}���`�r���[�A�C�e���Y�p�l���̍쐬.
	m_pMultiViewItemsPanel = new CMultiViewItemsPanel();

	// �}���`�r���[�A�C�e���Y�p�l���̃E�B���h�E����.
	m_pMultiViewItemsPanel->Create(_T(""), 0, 10, 10, 320, 240, hwnd, (HMENU)IDC_MULTIVIEWITEMSPANEL, lpCreateStruct->hInstance);	// m_pMultiViewItemsPanel->Create�ŃE�B���h�E����.

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMultiView::OnDestroy() {

	// �e�N���X��OnDestroy���Ă�.
	CUserControl::OnDestroy();	// CUserControl::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMultiView::OnSize(UINT nType, int cx, int cy) {

}