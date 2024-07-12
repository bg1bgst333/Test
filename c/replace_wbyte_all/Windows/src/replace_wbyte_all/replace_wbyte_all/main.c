/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
int replace_wbyte_all(wchar_t* wbytes, int wblen, wchar_t before, wchar_t after);	/* �֐�replace_wbyte_all�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �ϐ��̐錾�E�z��̏�����. */
	wchar_t wbytes[] = { L'A', L'|', L'C', L'|', L'|' };
	int ret;
	int i;

	/* �݂������S�Ă�u�� */
	ret = replace_wbyte_all(wbytes, 5, L'|', L'\0');
	for (i = 0; i < 5; i++) {
		wprintf(L"wbytes[%d] = 0x%x\n", i, wbytes[i]);
	}
	wprintf(L"ret = %d\n", ret);

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

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