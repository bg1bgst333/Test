// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �E�B���h�E�̕`���v�����ꂽ��.
void CPicture::OnPaint() {

	// �ϐ��̐錾.
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT�\����ps.

	// ������̕`��.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32API��BeginPaint��hDC���擾.
	TextOut(hDC, 0, 0, _T("CPicture"), (int)_tcslen(_T("CPicture")));	// Win32API��TextOut��"CPicture"�ƕ`��.
	EndPaint(m_hWnd, &ps);	// Win32API��EndPaint�ŕ`��I��.

}