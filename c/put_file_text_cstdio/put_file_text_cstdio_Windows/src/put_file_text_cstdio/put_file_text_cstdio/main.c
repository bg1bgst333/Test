/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */

/* �֐��̃v���g�^�C�v�錾 */
int put_file_text_cstdio(const char* path, const char* text);	/* �֐�put_file_text_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �z��̏�����. */
	char ascii_str[] = "ABC DE\nFGH\0IJ\nKLMNO";	/* ' '��'\n'��'\0'���܂܂ꂽASCII������. */
	char japanese_str[] = "������ ����\n������\0����\n����������";	/* ' '��'\n'��'\0'���܂܂ꂽ���{�ꕶ����. */

	/* ascii_str��"test1.txt"�ɏo��. */
	put_file_text_cstdio("test1.txt", ascii_str);	/* put_file_text_cstdio��ascii_str��"test1.txt"�ɏo��. */

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* japanese_str��"test2.txt"�ɏo��. */
	put_file_text_cstdio("test2.txt", japanese_str);	/* put_file_text_cstdio��japanese_str��"test2.txt"�ɏo��. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int put_file_text_cstdio(const char* path, const char* text) {

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fputs�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "w");	/* fopen�Ńe�L�X�g�������݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀe�L�X�g����������. */
		ret = fputs(text, fp);	/* fputs��fp��text���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* fputs�������Ȃ�ret��0. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}