// �w�b�_�t�@�C���̃C���N���[�h
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// main�֐�
int main() {

	// �ϐ��E�\���̂̐錾�E������.
	FILE* fp = NULL;	// �t�@�C���|�C���^fp��NULL�ŏ�����.
	char bytes[2] = { 0x42, 0x30 };	// char�^�z��bytes(����2)��{0x42, 0x30}�ŏ�����.
	int ret;	// fwrite�̖߂�lret.

	// test1.txt��UTF-16LE��BOM����������.
	write_file_bom_utf16le("test1.txt");	// write_file_bom_utf16le��test1.txt��UTF-16LE��BOM����������.

	// test1.txt��UTF16-LE��"��"��ǋL.
	fp = fopen("test1.txt", "ab");	// fopen��"test1.txt"���o�C�i���ǉ��������݂ŊJ��.
	if (fp == NULL) {	// fp��NULL�̎�.
		return -1;	// return��-1��Ԃ�.
	}
	ret = fwrite(bytes, sizeof(char), 2, fp);	// fwrite��fp��bytes��ǋL��, �߂�l��ret�Ɋi�[.
	fclose(fp);	// fclose��fp�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}