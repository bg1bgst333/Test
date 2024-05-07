// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Win32FileUtility.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)

// �w��̃t�@�C������ǂݍ��񂾃o�C�g����R�[�h�y�[�W�ɏ]���ă}���`�o�C�g�����񂩂烏�C�h������ɕϊ�����std::wstring�Ɋi�[.
BOOL ReadMultiByteTextFileBinary(LPCSTR lpcszFileName, std::wstring& wstrWideText, UINT uiCodePage, LPDWORD lpdwLen) {

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
	char* pszText = new char[dwSize + 1];
	ZeroMemory(pszText, dwSize + 1);

	// �ǂݍ���
	DWORD dwRead;
	ReadFile(hFile, pszText, dwSize, &dwRead, NULL);
	CloseHandle(hFile);

	// �}���`�o�C�g����������C�h������ɕϊ�.
	int iLen = MultiByteToWideChar(uiCodePage, 0, pszText, -1, NULL, 0);	// MultiByteToWideChar�ŕK�v�ȃo�b�t�@�̒��������߂�.
	if (iLen <= 0) {
		delete[] pszText;
		return FALSE;
	}
	WCHAR* pwszBuf = new TCHAR[iLen];	// ����iLen��WCHAR�o�b�t�@���m�ۂ�, pwszBuf�Ɋi�[.
	*lpdwLen = MultiByteToWideChar(uiCodePage, 0, pszText, -1, pwszBuf, iLen);	// MultiByteToWideChar��pszText��pwszBuf�ɕϊ�.
	pwszBuf[*lpdwLen - 1] = '\0';
	wstrWideText = pwszBuf;

	// �I������
	delete[] pszText;
	delete[] pwszBuf;
	return TRUE;

}