// ��d�C���N���[�h�h�~
#ifndef __MAIN_APPLICATION_H__
#define __MAIN_APPLICATION_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// ���C���A�v���P�[�V�����N���XCMainApplication
class CMainApplication : public CApplication{

	// public�����o
	public:

		// public�����o�ϐ�
		HBRUSH m_hBrush1;
		HBRUSH m_hBrush2;
		HBITMAP m_hBitmap1;
		HBITMAP m_hBitmap2;

		// public�����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �C���X�^���X�������֐�InitInstance.
		virtual int ExitInstance();	// �I�������֐�ExitInstance.

};

#endif