/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <stdio.h>	/* �W�����o�� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size(const char *path);	/* �֐�get_file_size�̐錾. */
size_t read_file_binary_cstdio(const char *path, void *bytes, size_t size);	/* �֐�read_file_binary_cstdio�̐錾. */

#endif