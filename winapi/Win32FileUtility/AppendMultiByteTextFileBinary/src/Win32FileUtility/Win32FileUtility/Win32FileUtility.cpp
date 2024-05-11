// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Win32FileUtility.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)

// �w��̃��C�h��������w��̃R�[�h�y�[�W�̃}���`�o�C�g������ɕϊ���, �o�C�i�����[�h�Œǉ���������.
BOOL AppendMultiByteTextFileBinary(LPCSTR lpcszFileName, LPCWSTR lpcwszWideText, UINT uiCodePage, LPDWORD lpdwLen){

	// ���C�h�������}���`�o�C�g�����ɕϊ�����.
	int iBufLen = WideCharToMultiByte(uiCodePage, 0, lpcwszWideText, -1, NULL, 0, NULL, NULL);	// �܂��͒������擾.
	if (iBufLen < 0){	// ���̒l.
		return FALSE;	// FALSE��Ԃ�
	}
	char *pszBuf = new char[iBufLen];	// iBufLen��char�^�o�b�t�@���m��.
	iBufLen = WideCharToMultiByte(uiCodePage, 0, lpcwszWideText, -1, pszBuf, iBufLen, NULL, NULL);	// �ϊ�.
	pszBuf[iBufLen - 1] = '\0';	// NULL�I�[.

	// �t�@�C����������
	HANDLE hFile = CreateFileA(lpcszFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�Ńo�C�i���������݂ŊJ��.
	if (hFile == INVALID_HANDLE_VALUE){	// ���s�Ȃ�.
		delete [] pszBuf;
		return FALSE;	// FALSE��Ԃ�.
	}
	SetFilePointer(hFile, 0, NULL, FILE_END);	// SetFilePointer�Ńt�@�C���|�C���^�𖖔��Ɉړ�.
	WriteFile(hFile, pszBuf, iBufLen - 1, lpdwLen, NULL);	// WriteFile�ŏ�������.
	CloseHandle(hFile);

	// �I������
	delete [] pszBuf;	// ���������.
	return TRUE;	// TRUE��Ԃ�.

}