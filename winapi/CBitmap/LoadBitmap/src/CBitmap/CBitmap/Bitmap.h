// ��d�C���N���[�h�h�~
#ifndef __BITMAP_H__
#define __BITMAP_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI

// �r�b�g�}�b�v�N���XCBitmap
class CBitmap{

	// public�����o
	public:

		// public�����o�ϐ�
		// �����o�ϐ�
		HBITMAP m_hBitmap;	// HBITMAP�^�r�b�g�}�b�v�n���h��m_hBitmap.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBitmap();	// �R���X�g���N�^CBitmap()
		virtual ~CBitmap();	// �f�X�g���N�^~CBitmap()
		// �����o�֐�
		virtual BOOL LoadBitmap(HINSTANCE hInstance, LPCTSTR lpctszResourceName);	// �r�b�g�}�b�v���\�[�X���[�h�֐�LoadBitmap.

};

#endif