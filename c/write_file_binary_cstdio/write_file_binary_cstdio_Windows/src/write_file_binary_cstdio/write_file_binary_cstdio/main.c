/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */

/* �֐��̃v���g�^�C�v�錾 */
int write_file_binary_cstdio(const char* path, const void* bytes, size_t size);	/* �֐�write_file_binary_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �z��̏�����. */
	char ascii_str[] = "ABC DE\nFGH\0IJ\nKLMNO";	/* ' '��'\n'��'\0'���܂܂ꂽASCII������. */
	char japanese_str[] = "������ ����\n������\0����\n����������";	/* ' '��'\n'��'\0'���܂܂ꂽ���{�ꕶ����. */

	/* ascii_str��"test1.txt"�ɏo��. */
	write_file_binary_cstdio("test1.txt", ascii_str, 19);	/* write_file_binary_cstdio��ascii_str��"test1.txt"�ɏo��. */

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* japanese_str��"test2.txt"�ɏo��. */
	write_file_binary_cstdio("test2.txt", japanese_str, 34);	/* write_file_binary_cstdio��japanese_str��"test2.txt"�ɏo��. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* C�W�����o�̓��C�u�����֐��Ńo�C�i���t�@�C���o��. */
int write_file_binary_cstdio(const char* path, const void* bytes, size_t size) {

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "wb");	/* fopen�Ńo�C�i���������݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀo�C�i������������. */
		ret = fwrite(bytes, sizeof(char), size, fp);	/* fwrite��fp��bytes���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}