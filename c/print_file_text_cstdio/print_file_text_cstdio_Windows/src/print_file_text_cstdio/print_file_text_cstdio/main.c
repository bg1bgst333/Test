/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */

/* �֐��̃v���g�^�C�v�錾 */
int print_file_text_cstdio(const char* path, const char* text);	/* �֐�print_file_text_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �z��̏�����. */
	char ascii_str[] = "ABCDE\nFGHIJ\nKLMNO"; /* '\n'���܂܂ꂽASCII������. */
	char japanese_str[] = "����������\n����������\n����������"; /* '\n'���܂܂ꂽ���{�ꕶ����. */

	/* ascii_str��"test1.txt"�ɏo��. */
	print_file_text_cstdio("test1.txt", ascii_str);	/* print_file_text_cstdio��ascii_str��"test1.txt"�ɏo��. */

	/* japanese_str��"test2.txt"�ɏo��. */
	print_file_text_cstdio("test2.txt", japanese_str);	/* print_file_text_cstdio��japanese_str��"test2.txt"�ɏo��. */

	/* "C"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "C");	/* setlocale��LC_ALL, "C"���Z�b�g. */

	/* japanese_str��"test3.txt"�ɏo��. */
	print_file_text_cstdio("test3.txt", japanese_str);	/* print_file_text_cstdio��japanese_str��"test3.txt"�ɏo��. */

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* japanese_str��"test4.txt"�ɏo��. */
	print_file_text_cstdio("test4.txt", japanese_str);	/* print_file_text_cstdio��japanese_str��"test4.txt"�ɏo��. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int print_file_text_cstdio(const char* path, const char* text) {

	/* �ϐ��E�\���̂̏�����. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret = 0;	/* �������񂾃o�C�g��ret��0�ɏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "w");	/* fopen�Ńe�L�X�g�������݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀe�L�X�g����������. */
		ret = fprintf(fp, "%s", text);	/* fprintf��fp��text���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* �������񂾃o�C�g��ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}