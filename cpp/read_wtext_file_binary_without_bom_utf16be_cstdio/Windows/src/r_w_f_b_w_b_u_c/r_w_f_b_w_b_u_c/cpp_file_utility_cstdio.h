// ��d�C���N���[�h�h�~
#ifndef __CPP_FILE_UTILITY_CSTDIO_H__
#define __CPP_FILE_UTILITY_CSTDIO_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <cstdio> // C�W�����o��
#include <cstring> // C�����񏈗�
#include <string> // std::string

// �֐��̃v���g�^�C�v�錾
int read_wtext_file_binary_without_bom_utf16le_cstdio(const char *path, std::wstring &wtext);	// �֐�read_wtext_file_binary_without_bom_utf16le_cstdio�̐錾.
int read_wtext_file_binary_without_bom_utf16be_cstdio(const char *path, std::wstring &wtext);	// �֐�read_wtext_file_binary_without_bom_utf16be_cstdio�̐錾.

#endif