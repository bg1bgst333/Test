// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <shlwapi.h>	// �V�F��API
// �Ǝ��w�b�_
#include "File.h"	// CFile

// �R���X�g���N�^
CFile::CFile() {

	// �����o�̏�����.
	m_hFile = NULL;	// m_hFile��NULL���Z�b�g.
	m_tstrFilePath.clear();	// m_tstrFilePath.clear�ŃN���A.

}

// �f�X�g���N�^
CFile::~CFile() {

	// �����o�̏I������.
	Close();	// Close�ŕ���.

}

// �t�@�C�����J��.
BOOL CFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition) {

	// �^����ꂽ�����̃p�X�����΃p�X���ǂ����`�F�b�N.
	BOOL bRet = PathIsRelative(lpctszFileName);	// PathIsRelative�ő��΃p�X���`�F�b�N.
	if (bRet) {
		// ��΃p�X�̎擾.
		TCHAR tszFullPath[1024] = { 0 };
		TCHAR* ptszFilePart = NULL;
		DWORD dwRet = GetFullPathName(lpctszFileName, 1024, tszFullPath, &ptszFilePart);	// GetFullPathName�Ńt���p�X���擾.
		if (dwRet) {
			m_tstrFilePath = tszFullPath;
			// �t�@�C���n���h���̎擾.
			m_hFile = CreateFile(m_tstrFilePath.c_str(), dwDesiredAccess, FILE_SHARE_READ, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�ŊJ��.
			if (m_hFile == INVALID_HANDLE_VALUE) {	// ���s.
				m_hFile = NULL;
				m_tstrFilePath.clear();
				return FALSE;
			}
			else {	// ����.
				return TRUE;
			}
		}
		else {
			return FALSE;
		}
	}
	else {
		m_tstrFilePath = lpctszFileName;
		// �t�@�C���n���h���̎擾.
		m_hFile = CreateFile(m_tstrFilePath.c_str(), dwDesiredAccess, FILE_SHARE_READ, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�ŊJ��.
		if (m_hFile == INVALID_HANDLE_VALUE) {	// ���s.
			m_hFile = NULL;
			m_tstrFilePath.clear();
			return FALSE;
		}
		else {	// ����.
			return TRUE;
		}
	}

}

// �t�@�C�������.
void CFile::Close() {

	// �t�@�C���n���h�������.
	if (m_hFile != NULL) {	// �n���h�����c���Ă�����.
		CloseHandle(m_hFile);	// CloseHandle��m_hFile�����.
		m_hFile = NULL;	// m_hFile��NULL���Z�b�g.
	}

	// �t�@�C�����Ȃǂ̏����N���A.
	m_tstrFilePath.clear();

}

// �t�@�C�����e�̓ǂݍ���.
DWORD CFile::Read(LPVOID lpBuf, DWORD dwBytes) {

	// �ϐ��̏�����.
	DWORD dwReadBytes = 0;	// �ǂݍ��񂾃o�C�g��dwReadBytes��0�ɏ�����.

	// �t�@�C����ǂݍ���.
	ReadFile(m_hFile, lpBuf, dwBytes, &dwReadBytes, NULL);	// ReadFile�œǂݍ���.

	// �ǂݍ��񂾃o�C�g����Ԃ�.
	return dwReadBytes;	// dwReadBytes��Ԃ�.

}

// �t�@�C�����e�̏�������.
DWORD CFile::Write(LPVOID lpBuf, DWORD dwBytes) {

	// �ϐ��̏�����.
	DWORD dwWrittenBytes = 0;	// �������񂾃o�C�g��dwWrittenBytes��0�ɏ�����.

	// �t�@�C���ɏ�������.
	WriteFile(m_hFile, lpBuf, dwBytes, &dwWrittenBytes, NULL);	// WriteFile�ŏ�������.

	// �������񂾃o�C�g����Ԃ�.
	return dwWrittenBytes;	// dwWrittenBytes��Ԃ�.

}

// �t�@�C���T�C�Y(32bit)���擾.
DWORD CFile::GetFileSize() {

	// �t�@�C���T�C�Y(32bit)��Ԃ�.
	return ::GetFileSize(m_hFile, NULL);	// Win32API��GetFileSize��32bit���Ԃ�.

}

// �t�@�C���|�C���^(32bit)�̐ݒ�Ǝ擾.
DWORD CFile::SetFilePointer(LONG lDistanceToMove, DWORD dwMoveMethod) {

	// �ړ�����o�C�g���ƈړ��̊J�n�_��n��.
	return ::SetFilePointer(m_hFile, lDistanceToMove, NULL, dwMoveMethod);	// Win32API��SetFilePointer�ňʒu�̐ݒ��擾������.

}