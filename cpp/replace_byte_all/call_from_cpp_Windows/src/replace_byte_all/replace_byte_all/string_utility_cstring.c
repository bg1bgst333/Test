/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "string_utility_cstring.h"	/* �����񃆁[�e�B���e�B(C�����񏈗�) */

/* ����size�̃o�C�g��bytes�݂̂������S�Ă�before��after�ɒu��. */
int replace_byte_all(char* bytes, int size, char before, char after) {

	/* �ϐ��̐錾�E������. */
	int i;
	int total = 0;

	/* �Ō�܂ŒT��. */
	for (i = 0; i < size; i++) {
		if (*(bytes + i) == before) {
			*(bytes + i) = after;	/* after�ɒu��. */
			total++;
		}
	}

	/* �݂���������Ԃ�. */
	return total;

}