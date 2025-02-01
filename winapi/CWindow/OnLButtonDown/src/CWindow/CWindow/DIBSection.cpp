// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "DIBSection.h"	// CDIBSection

// �R���X�g���N�^CDIBSection()
CDIBSection::CDIBSection(){

	// �����o�̏�����.
	m_hDIBSection = NULL;	// m_hDIBSection��NULL�ŏ�����.
	m_lpBitsPixel = NULL;	// m_lpBitsPixel��NULL�ŏ�����.

}

// �f�X�g���N�^~CDIBSection()
CDIBSection::~CDIBSection(){

	// �����o�̏I������.
	if (m_hDIBSection != NULL){	// NULL�łȂ�.
		::DeleteObject(m_hDIBSection);	// DeleteObject�Ŕj��.
		m_hDIBSection = NULL;	// NULL���Z�b�g.
	}
	m_lpBitsPixel = NULL;	// ��������Ȃ̂�NULL���Z�b�g.

}

// DIB�Z�N�V�����쐬�֐�CreateDIBSection.
BOOL CDIBSection::CreateDIBSection(HWND hWnd, int iWidth, int iHeight){

	// �ϐ��̐錾�E������
	HDC hDC = NULL;	// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	BITMAPINFO bi = {0};	// �r�b�g�}�b�v���BiTMAPINFO�\����bi��{0}�ŏ�����.

	// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
	hDC = GetDC(hWnd);	// GetDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾��, hDC�Ɋi�[.
	if (hDC){

		// �r�b�g�}�b�v���̃Z�b�g.
		bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bi.bmiHeader.biWidth = iWidth;
		bi.bmiHeader.biHeight = iHeight;
		bi.bmiHeader.biPlanes = 1;
		bi.bmiHeader.biBitCount = 24;
		bi.bmiHeader.biCompression = BI_RGB;

		// DIB�Z�N�V�����̍쐬.
		m_hDIBSection = ::CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void **)&m_lpBitsPixel, NULL, 0);	// CreateDIBSection��DIB�Z�N�V�������쐬.

		// �f�o�C�X�R���e�L�X�g�̉��.
		ReleaseDC(hWnd, hDC);	// ReleaseDC�Ńf�o�C�X�R���e�L�X�g�����.

		// NULL����Ȃ���ΐ���.
		if (m_hDIBSection != NULL){
			return TRUE;
		}

	}

	return FALSE;

}