// ��d�C���N���[�h�h�~
#ifndef __WIN32_FILE_UTILITY_H__
#define __WIN32_FILE_UTILITY_H__

// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <windows.h>	// �W��WindowsAPI
#include <string>	// std::string

// �֐��̃v���g�^�C�v�錾
BOOL ReadMultiByteTextFileBinary(LPCSTR lpcszFileName, std::wstring &wstrWideText, UINT uiCodePage, LPDWORD lpdwLen);	// �֐�ReadMultiByteTextFileBinary�̐錾.

#endif