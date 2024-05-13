// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Win32FileUtility.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)

// �w��̃t�@�C������BOM�ȊO��ǂݍ���UTF-8�}���`�o�C�g�����񂩂烏�C�h������ɕϊ�����std::wstring�Ɋi�[.
BOOL ReadMultiByteTextFileBinaryWithoutBomUtf8(LPCSTR lpcszFileName, std::wstring& wstrWideText, LPDWORD lpdwLen) {

	// �t�@�C�����J��
	HANDLE hFile = CreateFileA(lpcszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�Ńo�C�i���ǂݍ��݂ŊJ��.
	if (hFile == INVALID_HANDLE_VALUE) {	// ���s�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �t�@�C���T�C�Y�̎擾
	DWORD dwSize = GetFileSize(hFile, NULL);
	if (dwSize <= 0) {
		CloseHandle(hFile);
		return FALSE;
	}

	// �o�b�t�@�m��
	DWORD dwTextSize = dwSize - 3;	// BOM��������.
	char* pszText = new char[dwTextSize + 1];
	ZeroMemory(pszText, dwTextSize + 1);

	// 3�o�C�g��Ɉړ�.
	SetFilePointer(hFile, 3, NULL, FILE_BEGIN);	// SetFilePointer��3�o�C�g��Ɉړ�.

	// �ǂݍ���
	DWORD dwRead;
	ReadFile(hFile, pszText, dwTextSize, &dwRead, NULL);
	CloseHandle(hFile);

	// UTF-8�}���`�o�C�g����������C�h������ɕϊ�.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, pszText, -1, NULL, 0);	// MultiByteToWideChar�ŕK�v�ȃo�b�t�@�̒��������߂�.
	if (iLen <= 0) {
		delete[] pszText;
		return FALSE;
	}
	WCHAR* pwszBuf = new TCHAR[iLen];	// ����iLen��WCHAR�o�b�t�@���m�ۂ�, pwszBuf�Ɋi�[.
	*lpdwLen = MultiByteToWideChar(CP_UTF8, 0, pszText, -1, pwszBuf, iLen);	// MultiByteToWideChar��pszText��pwszBuf�ɕϊ�.
	pwszBuf[*lpdwLen - 1] = '\0';
	wstrWideText = pwszBuf;

	// �I������
	delete[] pszText;
	delete[] pwszBuf;
	return TRUE;

}