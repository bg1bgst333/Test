/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
/* ���̏ꍇ, ��������������������Ȃ��ƃR���p�C���G���[�ɂȂ�͗l. */
#ifdef __cplusplus
extern "C" {
#endif
	int write_file_bom_utf16le(const char* path);	/* �֐�write_file_bom_utf16le�̐錾. */
#ifdef __cplusplus
}
#endif
#endif