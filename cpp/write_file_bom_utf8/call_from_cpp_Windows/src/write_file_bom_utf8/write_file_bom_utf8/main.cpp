// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <string.h>	// �����񏈗�
// �Ǝ��̃w�b�_�t�@�C��
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// main�֐��̒�`
int main(void){

	// �ϐ��̐錾�E������
	FILE *fp = NULL;	// �t�@�C���|�C���^fp��NULL�ŏ�����.
	int ret;	// fwrite�̖߂�lret.
	char str[] = {0xe3, 0x81, 0x82, 0x00};	// char�^�z��str[]��{0xe3, 0x81, 0x82, 0x00}(UTF-8��"��")�ŏ�����.

	// test1.txt��UTF-8��BOM����������.
	write_file_bom_utf8("test1.txt");	// write_file_bom_utf8��test1.txt��UTF-8��BOM����������.

	// test1.txt��UTF8��"��"��ǋL.
	fp = fopen("test1.txt", "ab");	// fopen��"test1.txt"���o�C�i���ǉ��������݂ŊJ��.
	if (fp == NULL){	// fp��NULL�̎�.
		return -1;	// return��-1��Ԃ�.
	}
	ret = fwrite(str, sizeof(char), strlen(str), fp);	// fwrite��fp��str��ǋL��, �߂�l��ret�Ɋi�[.
	fclose(fp);	// fclose��fp�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}