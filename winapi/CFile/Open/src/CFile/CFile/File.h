// ��d�C���N���[�h�h�~
#ifndef __FILE_H__
#define __FILE_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <string>		// std::string

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �t�@�C��CFile
class CFile {

	// public�����o
	public:

		// public�����o�ϐ�
		HANDLE m_hFile;	// �t�@�C���n���h��
		tstring m_tstrFilePath;	// �t�@�C���p�X

		// public�����o�֐�
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// �t�@�C�����J��.

};

#endif