// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StaticCore.h"	// CStaticCore

// �E�B���h�E�쐬�֐�Create.
BOOL CStaticCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�"Static"���w��.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ɃE�B���h�E�N���X��"Static"���w��.

}

// �E�B���h�E�쐬�֐�Create(RECT�o�[�W����).
BOOL CStaticCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�"Static"���w��.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, rect, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ɃE�B���h�E�N���X��"Static"���w��.

}