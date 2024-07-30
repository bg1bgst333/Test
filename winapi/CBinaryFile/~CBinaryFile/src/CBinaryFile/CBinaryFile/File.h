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
		// �R���X�g���N�^�E�f�X�g���N�^
		CFile();	// �R���X�g���N�^
		virtual ~CFile();	// �f�X�g���N�^
		// �����o����
		virtual BOOL Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition);	// �t�@�C�����J��.
		virtual void Close();	// �t�@�C�������.
		virtual DWORD Read(LPVOID lpBuf, DWORD dwBytes);	// �t�@�C�����e�̓ǂݍ���.
		virtual DWORD Write(LPVOID lpBuf, DWORD dwBytes);	// �t�@�C�����e�̏�������.
		virtual DWORD GetFileSize();	// �t�@�C���T�C�Y(32bit)���擾.
		virtual DWORD SetFilePointer(LONG lDistanceToMove, DWORD dwMoveMethod);	// �t�@�C���|�C���^(32bit)�̐ݒ�Ǝ擾.

};

#endif