// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ButtonCore.h"	// CButtonCore

// �E�B���h�E�쐬�֐�Create.
BOOL CButtonCore::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�"Button"���w��.
	return CCustomControl::Create(_T("Button"), lpctszWindowName, dwStyle | BS_PUSHBUTTON, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ɃE�B���h�E�N���X��"Button"���w��.

}