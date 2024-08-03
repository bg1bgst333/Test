// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EditCore.h"	// CEditCore

// �E�B���h�E�쐬�֐�Create.
BOOL CEditCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�"Edit"���w��.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ɃE�B���h�E�N���X��"Edit"���w��.

}

// �E�B���h�E�쐬�֐�Create(RECT�o�[�W����).
BOOL CEditCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�"Edit"���w��.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, rect, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ɃE�B���h�E�N���X��"Edit"���w��.

}