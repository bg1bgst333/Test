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
char* get_file_text_cstdio(const char* path, char* text, size_t buf_size);	/* �֐�get_file_text_cstdio�̐錾. */
int write_file_text_cstdio(const char* path, const char* text, size_t len);	/* �֐�write_file_text_cstdio�̐錾. */
size_t read_file_text_cstdio(const char* path, char* text, size_t len);	/* �֐�read_file_text_cstdio�̐錾. */
int write_file_binary_cstdio(const char* path, const void* bytes, size_t size);	/* �֐�write_file_binary_cstdio�̐錾. */
size_t read_file_binary_cstdio(const char* path, void* bytes, size_t size);	/* �֐�read_file_binary_cstdio�̐錾. */
int write_file_binary_cstdio_w(const wchar_t* path, const void* bytes, size_t size);	/* �֐�write_file_binary_cstdio_w�̐錾. */

#endif