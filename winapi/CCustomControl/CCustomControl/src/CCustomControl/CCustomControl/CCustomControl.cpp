// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// �R���X�g���N�^CCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// �f�X�g���N�^~CCustomControl
CCustomControl::~CCustomControl() {

}

// �E�B���h�E�쐬�֐�Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CCustomControl::Destroy() {

	// �e�N���X��Destroy���Ă�.
	return CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CCustomControl::OnDestroy() {

	// �����ł͉����Ă΂Ȃ�.

}