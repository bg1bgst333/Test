/* �w�b�_�t�@�C���̃C���N���[�h */
/* ����̃w�b�_�t�@�C�� */
#include <sys/stat.h>	/* �t�@�C����� */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size(const char* path) {

	/* �\���̂̏�����. */
	struct _stat sst = { 0 };	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_stat(path, &sst);	/* _stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* 2�̃o�C�g�l�����ւ���. */
void swap_2bytes(char* byte1, char* byte2) {

	/* �ϐ��̐錾 */
	char temp;	/* char�^�ꎞ�ϐ�temp. */

	/* byte1�̎w���l��byte2�̎w���l�����ւ���. */
	temp = *byte1;	/* byte1�̎w���l��temp�ɑ��. */
	*byte1 = *byte2;	/* byte2�̎w���l��byte1�ɑ��. */
	*byte2 = temp;	/* temp�̒l��byte2�̎w���l�ɑ��. */

}

/* �o�C�g��̃G���f�B�A���ϊ�(big�Ȃ�little, little�Ȃ�big.) */
int convert_endian_16bit_byte_array(const char* src, char* dest, size_t len) {

	/* �ϐ��̏����� */
	int half = 0;	/* �����̔���harf��0�ŏ�����. */
	int i = 0;	/* ���[�v�p�ϐ�i��0�ŏ�����. */
	int a, b;	/* ����ւ��p�ꎞ�ϐ�a, b. */

	/* ��������̏ꍇ�̓G���[. */
	if (len % 2) {	/* �. */
		return -1;	/* -1��Ԃ�. */
	}

	/* �G���f�B�A���ϊ� */
	half = len / 2;	/* len�̔����̒�����half�ɑ��. */
	for (i = 0; i < half; i++) {	/* half�̑O�܂ŌJ��Ԃ�. */
		*(dest + 2 * i) = *(src + 2 * i);
		*(dest + 2 * i + 1) = *(src + 2 * i + 1);
		swap_2bytes(dest + 2 * i, dest + 2 * i + 1);
	}

	/* ����I�� */
	return 0;	/* 0��Ԃ�. */

}