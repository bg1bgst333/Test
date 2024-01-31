/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
int print_file_text_cstdio(const char* path, const char* text);	/* �֐�print_file_text_cstdio�̐錾 */
size_t get_file_size(const char* path);	/* �֐�get_file_size�̐錾. */
int scan_file_text_cstdio(const char* path, char* text);	/* �֐�scan_file_text_cstdio�̐錾. */
int put_file_text_cstdio(const char* path, const char* text);	/* �֐�put_file_text_cstdio�̐錾. */

#endif