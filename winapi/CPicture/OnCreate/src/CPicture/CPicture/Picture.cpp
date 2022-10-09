// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �R���X�g���N�^CPicture
CPicture::CPicture() : CStaticCore(){

	// �����o�̏�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.

}

// �f�X�g���N�^~CPicture
CPicture::~CPicture(){

}

// �E�B���h�E�j���֐�Destroy
BOOL CPicture::Destroy(){

	// �������f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hMemDC != NULL){	// NULL�łȂ�.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC��j��.
		m_hMemDC = NULL;	// NULL���Z�b�g.
	}

	// �f�o�C�X�R���e�L�X�g�̉��.
	if (m_hDC != NULL){	// NULL�łȂ�.
		ReleaseDC(m_hWnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
	}

	// �e�N���X��Destroy���Ă�.
	return CStaticCore::Destroy();	// CStaticCore::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CPicture::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �f�o�C�X�R���e�L�X�g�̎擾.
	m_hDC = GetDC(hwnd);	// GetDC�ł��̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
	if (m_hDC == NULL){	// NULL�Ȃ玸�s.
		return -1;	// -1��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �������f�o�C�X�R���e�L�X�g�̐���.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDC��m_hDC�Ɍ݊����̂��郁�����f�o�C�X�R���e�L�X�g�𐶐�.
	if (m_hMemDC == NULL){	// NULL�Ȃ玸�s.
		ReleaseDC(hwnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
		return -2;	// -2��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �e�N���X��OnCreate���Ă�.
	return CStaticCore::OnCreate(hwnd, lpCreateStruct);	// CStaticCore::OnCreate�̒l��Ԃ�.

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CPicture::OnPaint(){

	// �ϐ��̐錾.
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT�\����ps.

	// ������̕`��.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32API��BeginPaint��hDC���擾.
	TextOut(hDC, 0, 0, _T("CPicture"), (int)_tcslen(_T("CPicture")));	// Win32API��TextOut��"CPicture"�ƕ`��.
	TCHAR tszBuf1[64] = {0};	// TCHAR�o�b�t�@tszBuf1(����64)��{0}�ŏ�����.
	_stprintf(tszBuf1, _T("m_hDC = 0x%08x"), m_hDC);	// _stprintf��m_hDC�𕶎���ɕϊ�.
	TextOut(hDC, 0, 50, tszBuf1, (int)_tcslen(tszBuf1));	// Win32API��TextOut��tszBuf1��`��.
	TCHAR tszBuf2[64] = {0};	// TCHAR�o�b�t�@tszBuf2(����64)��{0}�ŏ�����.
	_stprintf(tszBuf2, _T("m_hMemDC = 0x%08x"), m_hMemDC);	// _stprintf��m_hMemDC�𕶎���ɕϊ�.
	TextOut(hDC, 0, 100, tszBuf2, (int)_tcslen(tszBuf2));	// Win32API��TextOut��tszBuf2��`��.
	EndPaint(m_hWnd, &ps);	// Win32API��EndPaint�ŕ`��I��.

}