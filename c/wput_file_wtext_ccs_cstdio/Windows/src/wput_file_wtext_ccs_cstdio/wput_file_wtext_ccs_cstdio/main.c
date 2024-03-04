/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <locale.h>	/* ���P�[�� */
#include <string.h>	/* �����񏈗� */
#include <wchar.h>	/* ���C�h���� */

/* �֐��̃v���g�^�C�v�錾 */
int wput_file_wtext_ccs_cstdio(const char* path, const wchar_t* wtext, const char* ccs);	/* �֐�wput_file_wtext_ccs_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �z��̏�����. */
	wchar_t japanese_wstr[] = L"����������\n����������\n����������";	/* '\n'���܂܂ꂽ���{�ꕶ����. */

	/* ���P�[��"Japanese_Japan.932"�̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* japanese_wstr��NULL��"test1.txt"�ɏo��. */
	wput_file_wtext_ccs_cstdio("test1.txt", japanese_wstr, NULL);	/* wput_file_wtext_ccs_cstdio��japanese_wstr��NULL��"test1.txt"�ɏo��. */

	/* japanese_wstr��""��"test2.txt"�ɏo��. */
	wput_file_wtext_ccs_cstdio("test2.txt", japanese_wstr, "");	/* wput_file_wtext_ccs_cstdio��japanese_wstr��""��"test2.txt"�ɏo��. */

	/* japanese_wstr��"UNICODE"��"test3.txt"�ɏo��. */
	wput_file_wtext_ccs_cstdio("test3.txt", japanese_wstr, "UNICODE");	/* wput_file_wtext_ccs_cstdio��japanese_wstr��"UNICODE"��"test3.txt"�ɏo��. */

	/* japanese_wstr��"UTF-8"��"test4.txt"�ɏo��. */
	wput_file_wtext_ccs_cstdio("test4.txt", japanese_wstr, "UTF-8");	/* wput_file_wtext_ccs_cstdio��japanese_wstr��"UTF-8"��"test4.txt"�ɏo��. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int wput_file_wtext_ccs_cstdio(const char* path, const wchar_t* wtext, const char* ccs) {

	/* �ϐ��E�\���̂̏�����. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret = 0;	/* ret��0�ɏ�����. */
	char mode[256] = "";	/* ���[�h��\��mode��""�ŏ�����. */

	/* �t�@�C�����J��. */
	if (ccs == NULL || strcmp(ccs, "") == 0) {	/* NULL�܂��͋�̏ꍇ. */
		strcpy(mode, "w");	/* strcpy��mode��"w"���Z�b�g. */
	}
	else { /* ����ȊO. */
		strcpy(mode, "w, ccs=");	/* strcpy��mode��"w, ccs="���Z�b�g. */
		strcat(mode, ccs);	/* strcat��mode��ccs��A��. */
	}
	fp = fopen(path, mode);	/* fopen��mode�ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀ��C�h�����e�L�X�g����������. */
		ret = fputws(wtext, fp);	/* fputws��fp��wtext���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}