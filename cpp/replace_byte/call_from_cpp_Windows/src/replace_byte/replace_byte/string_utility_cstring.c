/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "string_utility_cstring.h"	/* �����񃆁[�e�B���e�B(C�����񏈗�) */

/* ����size�̃o�C�g��bytes�̍ŏ��ɂ݂�����before��after�ɒu��. */
int replace_byte(char* bytes, int size, char before, char after) {

	/* �ϐ��̐錾 */
	int i;

	/* before���݂���܂ŒT��. */
	for (i = 0; i < size; i++) {
		if (*(bytes + i) == before) {
			*(bytes + i) = after;	/* after�ɒu��. */
			return i;	/* i��Ԃ�. */
		}
	}

	/* �݂���Ȃ��ꍇ��-1. */
	return -1;

}