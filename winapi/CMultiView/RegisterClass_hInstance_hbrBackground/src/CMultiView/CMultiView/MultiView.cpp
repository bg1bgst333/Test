// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MultiView.h"	// CMultiView

// �R���X�g���N�^CMultiView
CMultiView::CMultiView() : CUserControl() {

}

// �f�X�g���N�^~CMultiView
CMultiView::~CMultiView() {

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

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

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