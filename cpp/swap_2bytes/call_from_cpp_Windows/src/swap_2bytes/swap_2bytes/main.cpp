// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <cstdio>	// C�W�����o��
// �Ǝ��̃w�b�_
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// main�֐��̒�`
int main(void){

	// �ϐ��̏�����.
	char a = 'a';	// char�^�ϐ�a��'a'�ŏ�����.
	char b = 'b';	// char�^�ϐ�b��'b'�ŏ�����.

	// a��b�̏o��.
	printf("a = \'%c\'\n", a);	// a���o��.
	printf("b = \'%c\'\n", b);	// b���o��.

	// "-----"���o��.
	printf("-----\n");

	// �X���b�v
	swap_2bytes(&a, &b);	// swap_2bytes��a��b�̒l�����ւ���.

	// a��b�̏o��.
	printf("a = \'%c\'\n", a);	// a���o��.
	printf("b = \'%c\'\n", b);	// b���o��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}