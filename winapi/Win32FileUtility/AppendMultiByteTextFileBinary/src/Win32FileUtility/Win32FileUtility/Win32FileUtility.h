// ��d�C���N���[�h�h�~
#ifndef __WIN32_FILE_UTILITY_H__
#define __WIN32_FILE_UTILITY_H__

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI

// �֐��̃v���g�^�C�v�錾
BOOL AppendMultiByteTextFileBinary(LPCSTR lpcszFileName, LPCWSTR lpcwszWideText, UINT uiCodePage, LPDWORD lpdwLen);	// �֐�AppendMultiByteTextFileBinary�̐錾.

#endif