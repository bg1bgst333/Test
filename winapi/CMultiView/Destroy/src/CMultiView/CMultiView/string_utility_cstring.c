/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "string_utility_cstring.h"	/* �����񃆁[�e�B���e�B(C�����񏈗�) */

/* ����wblen�̃��C�h�o�C�g��wbytes�݂̂������S�Ă�before��after�ɒu��. */
int replace_wbyte_all(wchar_t* wbytes, int wblen, wchar_t before, wchar_t after) {

	/* �ϐ��̐錾�E������. */
	int i;
	int total = 0;

	/* �Ō�܂ŒT��. */
	for (i = 0; i < wblen; i++) {
		if (*(wbytes + i) == before) {
			*(wbytes + i) = after;	/* after�ɒu��. */
			total++;
		}
	}

	/* �݂���������Ԃ�. */
	return total;

}