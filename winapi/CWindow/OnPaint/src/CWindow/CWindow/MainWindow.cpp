// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainWindow.h"	// CMainWindow

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CMainWindow".
	return CWindow::Create(_T("CMainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��"CMainWindow"���w��.

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CMainWindow::OnPaint(){

	// �ϐ��̐錾.
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT�\����ps.

	// ������̕`��.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32API��BeginPaint��hDC���擾.
	TextOut(hDC, 0, 0, _T("CWindow"), (int)_tcslen(_T("CWindow")));	// Win32API��TextOut��"CWindow"�ƕ`��.
	EndPaint(m_hWnd, &ps);	// Win32API��EndPaint�ŕ`��I��.

}