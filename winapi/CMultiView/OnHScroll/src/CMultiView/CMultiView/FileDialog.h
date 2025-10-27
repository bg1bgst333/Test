// ��d�C���N���[�h�h�~
#ifndef __FILE_DIALOG_H__
#define __FILE_DIALOG_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// CWindow

// �t�@�C���I���_�C�A���OCFileDialog
class CFileDialog {

	// private�����o
	private:

		// private�����o�ϐ�
		BOOL m_bOpenFileDalog;
		TCHAR m_tszDefExt[16];
		TCHAR m_tszFileName[1024];
		TCHAR m_tszFilter[1024];

	// protected�����o
	protected:

		// protected�����o�ϐ�
		OPENFILENAME m_ofn;	// OPENFILENAME�\����m_ofn.

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CFileDialog(BOOL bOpenFileDalog, LPCTSTR lpszDefExt = NULL, LPCTSTR lpszFileName = NULL, DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, LPCTSTR lpszFilter = NULL, CWindow* pParentWnd = NULL, DWORD dwSize = 0);	// �R���X�g���N�^CFileDialog
		// �����o�֐�
		INT_PTR DoModal();	// ���[�_���\��.
		OPENFILENAME& GetOFN();	// OPENFILENAME�̎擾.

};

#endif