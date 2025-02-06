// ��d�C���N���[�h�h�~
#ifndef __DIBSECTION_H__
#define __DIBSECTION_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI

// DIB�Z�N�V�����N���XCDIBSection
class CDIBSection {

	// public�����o
	public:

		// public�����o�ϐ�
		HBITMAP m_hDIBSection;	// HBITMAP�^DIB�Z�N�V�����n���h��m_hDIBSection.
		LPBYTE m_lpBitsPixel;	// LPBYTE�^DIB�Z�N�V�����s�N�Z����m_lpBitsPixel.
		int m_iWidth;	// int�^��m_iWidth
		int m_iHeight;	// int�^����m_iHeight

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CDIBSection();	// �R���X�g���N�^CDIBSection()
		virtual ~CDIBSection();	// �f�X�g���N�^~CDIBSection()
		// �����o�֐�
		virtual BOOL CreateDIBSection(HWND hWnd, int iWidth, int iHeight);	// DIB�Z�N�V�����쐬�֐�CreateDIBSection.
		virtual BOOL SaveBitmap(HWND hWnd, LPCTSTR lpctszFileName);	// �r�b�g�}�b�v�ۑ��֐�SaveBitmap.
		virtual BOOL LoadBitmap(LPCTSTR lpctszFileName, BOOL bLoad);	// �r�b�g�}�b�v�Ǎ��֐�LoadBitmap.
		virtual void SetPixel(int x, int y, BYTE r, BYTE g, BYTE b);	// �w��s�N�Z���ɐF���Z�b�g����֐�SetPixel.

};

#endif