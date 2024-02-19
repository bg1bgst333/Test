/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <stdio.h>	/* �W�����o�� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size(const char* path);	/* �֐�get_file_size�̐錾. */
size_t read_file_binary_cstdio_w(const wchar_t* path, void* bytes, size_t size);	/* �֐�read_file_binary_cstdio_w�̐錾. */

#endif