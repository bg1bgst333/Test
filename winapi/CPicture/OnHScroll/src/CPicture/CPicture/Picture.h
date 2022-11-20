// ��d�C���N���[�h�h�~
#ifndef __PICTURE_H__
#define __PICTURE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl

// �s�N�`���[�N���XCPicture
class CPicture : public CUserControl {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CPicture();	// �R���X�g���N�^CPicture
		virtual ~CPicture();	// �f�X�g���N�^~CPicture
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual void SetBitmap(HBITMAP hBitmap);	// �r�b�g�}�b�v�̃Z�b�gSetBitmap.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g��.

	// private�����o
	private:

		// private�����o�ϐ�
		// �����o�ϐ�
		HDC m_hDC;	// HDC�^�f�o�C�X�R���e�L�X�g�n���h��m_hDC.
		HDC m_hMemDC;	// HDC�^�������f�o�C�X�R���e�L�X�g�n���h��m_hMemDC.
		HBITMAP m_hBitmap;	// HBITMAP�^�r�b�g�}�b�v�n���h��m_hBitmap.
		HBITMAP m_hOldBitmap;	// HBITMAP�^�̈ȑO�̃r�b�g�}�b�v�n���h��m_hOldBitmap.
		int m_dx;	// ���������̕ω���m_dx.

};

#endif