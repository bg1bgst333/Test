/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <stdio.h>	/* �W�����o�� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
/* ���̏ꍇ, ��������������������Ȃ��ƃR���p�C���G���[�ɂȂ�͗l. */
#ifdef __cplusplus
extern "C" {
#endif
	size_t get_file_size(const char *path);	/* �֐�get_file_size�̐錾. */
#ifdef __cplusplus
}
#endif
#endif