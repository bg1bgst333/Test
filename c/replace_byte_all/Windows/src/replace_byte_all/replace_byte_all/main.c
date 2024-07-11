/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */

/* �֐��̃v���g�^�C�v�錾 */
int replace_byte_all(char* bytes, int size, char before, char after);	/* �֐�replace_byte_all�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �z��̏�����. */
	char bytes1[] = "ABBCB";
	char bytes2[] = { 0xa, 0xd, 0, 0xd, 0xd };
	int ret1;
	int ret2;
	int i;

	/* �݂������S�Ă�u��. */
	ret1 = replace_byte_all(bytes1, 5, 'B', 'X');
	printf("bytes1 = %s\n", bytes1);
	printf("ret1 = %d\n", ret1);

	/* �o�C�g�񂾂��當���񂶂�Ȃ��Ă��ł���. */
	ret2 = replace_byte_all(bytes2, 5, 0xd, 0);
	for (i = 0; i < 5; i++) {
		printf("bytes2[%d] = 0x%x\n", i, bytes2[i]);
	}
	printf("ret2 = %d\n", ret2);

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

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