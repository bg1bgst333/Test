/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* 2�̃o�C�g�l�����ւ���. */
void swap_2bytes(char *byte1, char *byte2){

	/* �ϐ��̐錾 */
	char temp;	/* char�^�ꎞ�ϐ�temp. */

	/* byte1�̎w���l��byte2�̎w���l�����ւ���. */
	temp = *byte1;	/* byte1�̎w���l��temp�ɑ��. */
	*byte1 = *byte2;	/* byte2�̎w���l��byte1�ɑ��. */
	*byte2 = temp;	/* temp�̒l��byte2�̎w���l�ɑ��. */

}