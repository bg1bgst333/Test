// ��d�C���N���[�h�h�~
#ifndef __PICTURE_H__
#define __PICTURE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
//#include "StaticCore.h"	// CStaticCore
#include "UserControl.h"	// CUserControl

// �s�N�`���[�N���XCPicture
class CPicture : public CUserControl/*CStaticCore*/ {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture();	// �R���X�g���N�^CPicture
		virtual ~CPicture();	// �f�X�g���N�^~CPicture
		// �����o�֐�
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual void SetBitmap(HBITMAP hBitmap);	// �r�b�g�}�b�v�̃Z�b�gSetBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.

	// private�����o
	private:

		// private�����o�ϐ�
		// �����o�ϐ�
		HDC m_hDC;	// HDC�^�f�o�C�X�R���e�L�X�g�n���h��m_hDC.
		HDC m_hMemDC;	// HDC�^�������f�o�C�X�R���e�L�X�g�n���h��m_hMemDC.
		HBITMAP m_hBitmap;	// HBITMAP�^�r�b�g�}�b�v�n���h��m_hBitmap.
		HBITMAP m_hOldBitmap;	// HBITMAP�^�̈ȑO�̃r�b�g�}�b�v�n���h��m_hOldBitmap.

};

#endif