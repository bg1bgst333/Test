// ��d�C���N���[�h�h�~
#ifndef __PICTURE_H__
#define __PICTURE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StaticCore.h"	// CStaticCore

// �s�N�`���[�N���XCPicture
class CPicture : public CStaticCore {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture();	// �R���X�g���N�^CPicture
		virtual ~CPicture();	// �f�X�g���N�^~CPicture
		// �����o�֐�
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.

	// private�����o
	private:

		// private�����o�ϐ�
		// �����o�ϐ�
		HDC m_hDC;	// HDC�^�f�o�C�X�R���e�L�X�g�n���h��m_hDC.
		HDC m_hMemDC;	// HDC�^�������f�o�C�X�R���e�L�X�g�n���h��m_hMemDC.

};

#endif