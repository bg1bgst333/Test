/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
void swap_2bytes(char *byte1, char *byte2);	/* �֐�swap_2bytes�̐錾. */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��̏�����. */
	char a = 'a';	/* char�^�ϐ�a��'a'�ŏ�����. */
	char b = 'b';	/* char�^�ϐ�b��'b'�ŏ�����. */

	/* a��b�̏o��. */
	printf("a = \'%c\'\n", a);	/* a���o��. */
	printf("b = \'%c\'\n", b);	/* b���o��. */

	/* "-----"���o��. */
	printf("-----\n");

	/* �X���b�v */
	swap_2bytes(&a, &b);	/* swap_2bytes��a��b�̒l�����ւ���. */

	/* a��b�̏o��. */
	printf("a = \'%c\'\n", a);	/* a���o��. */
	printf("b = \'%c\'\n", b);	/* b���o��. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* 2�̃o�C�g�l�����ւ���. */
void swap_2bytes(char *byte1, char *byte2){

	/* �ϐ��̐錾 */
	char temp;	/* char�^�ꎞ�ϐ�temp. */

	/* byte1�̎w���l��byte2�̎w���l�����ւ���. */
	temp = *byte1;	/* byte1�̎w���l��temp�ɑ��. */
	*byte1 = *byte2;	/* byte2�̎w���l��byte1�ɑ��. */
	*byte2 = temp;	/* temp�̒l��byte2�̎w���l�ɑ��. */

}