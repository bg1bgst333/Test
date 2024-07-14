// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <shlwapi.h>	// �V�F��API
// �Ǝ��w�b�_
#include "File.h"	// CFile

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