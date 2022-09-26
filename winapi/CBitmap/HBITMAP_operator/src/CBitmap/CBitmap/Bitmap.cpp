// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Bitmap.h"	// CBitmap

// �R���X�g���N�^CBitmap()
CBitmap::CBitmap() {

	// �����o�̏�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL�ŏ�����.

}

// �f�X�g���N�^~CBitmap()
CBitmap::~CBitmap() {

	// �����o�̏I������.
	if (m_hBitmap != NULL) {	// NULL�łȂ�.
		::DeleteObject(m_hBitmap);	// DeleteObject�Ŕj��.
		m_hBitmap = NULL;	// NULL���Z�b�g.
	}

}

// �r�b�g�}�b�v���\�[�X���[�h�֐�LoadBitmap.
BOOL CBitmap::LoadBitmap(HINSTANCE hInstance, LPCTSTR lpctszResourceName) {

	// �r�b�g�}�b�v���\�[�X�����[�h.
	m_hBitmap = ::LoadBitmap(hInstance, lpctszResourceName);	// LoadBitmap�Ŏw��̃r�b�g�}�b�v���\�[�X�����[�h.
	if (m_hBitmap != NULL) {	// NULL�łȂ�.
		return TRUE;	// TRUE��Ԃ�.
	}
	else {	// NULL.
		return FALSE;	// FALSE��Ԃ�.
	}

}

// HBITMAP���Z�q
CBitmap::operator HBITMAP() const {

	// �r�b�g�}�b�v�n���h����Ԃ�.
	return m_hBitmap;	// m_hBitmap��Ԃ�.

}