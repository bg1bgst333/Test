// ��d�C���N���[�h�h�~
#ifndef __CPP_FILE_UTILITY_CSTDIO_H__
#define __CPP_FILE_UTILITY_CSTDIO_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <cstdio>	// C�W�����o��
#include <cstring>	// C�����񏈗�

// �֐��̃v���g�^�C�v�錾
int append_wtext_file_binary_cstdio(const char *path, const wchar_t *wtext);	// �֐�append_wtext_file_binary_cstdio�̐錾.
int append_wtext_file_binary_utf16be_cstdio(const char *path, const wchar_t *wtext);	// �֐�append_wtext_file_binary_utf16be_cstdio�̐錾.

#endif