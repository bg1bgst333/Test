/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */
#include <sys/stat.h>	/* �t�@�C����� */
#include <wchar.h>	/* ���C�h���� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size(const char* path);	/* �֐�get_file_size�̐錾. */
wchar_t* wget_file_wtext_ccs_cstdio(const char* path, wchar_t* wtext, size_t buf_size, const char* ccs);	/* �֐�wget_file_wtext_ccs_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �ϐ��E�|�C���^�̐錾�E������. */
	size_t file_size_1;	/* size_t�^�ϐ�file_size_1. */
	size_t file_size_2;	/* size_t�^�ϐ�file_size_2. */
	size_t file_size_3;	/* size_t�^�ϐ�file_size_3. */
	size_t file_size_4;	/* sixe_t�^�ϐ�file_size_4. */
	wchar_t* buf1 = NULL;	/* wchar_t�^�|�C���^buf1��NULL�ŏ�����. */
	wchar_t* buf2 = NULL;	/* wchar_t�^�|�C���^buf2��NULL�ŏ�����. */
	wchar_t* buf3 = NULL;	/* wchar_t�^�|�C���^buf3��NULL�ŏ�����. */
	wchar_t* buf4 = NULL;	/* wchar_t�^�|�C���^buf4��NULL�ŏ�����. */
	int ret_1 = 0;
	int ret_2 = 0;
	int ret_3 = 0;
	int ret_4 = 0;

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* test1.txt�̃T�C�Y�擾. */
	file_size_1 = get_file_size("test1.txt");	/* get_file_size��"test1.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf1 = (wchar_t*)malloc((file_size_1 + 1) * sizeof(wchar_t));	/* malloc��((file_size_1 + 1) * sizeof(wchar_t))���̃������m��. */

	/* "test1.txt"����̓��͂�buf1�Ɋi�[. */
	wget_file_wtext_ccs_cstdio("test1.txt", buf1, file_size_1 + 1, NULL);	/* wget_file_wtext_ccs_cstdio��NULL��"test1.txt"��ǂݍ���. */
	ret_1 = wcslen(buf1);	/* ������ret_1�Ɋi�[. */
	buf1[ret_1] = L'\0';	/* NULL�I�[ */

	/* buf1���o��. */
	printf("buf1 = %ls\n", buf1);	/* printf��buf1���o��. */

	/* �������̉��. */
	free(buf1);	/* free��buf1�����. */

	/* test2.txt�̃T�C�Y�擾. */
	file_size_2 = get_file_size("test2.txt");	/* get_file_size��"test2.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf2 = (wchar_t*)malloc((file_size_2 + 1) * sizeof(wchar_t));	/* malloc��((file_size_2 + 1) * sizeof(wchar_t))���̃������m��. */

	/* "test2.txt"����̓��͂�buf2�Ɋi�[. */
	wget_file_wtext_ccs_cstdio("test2.txt", buf2, file_size_2 + 1, "");	/* wget_file_wtext_ccs_cstdio��""��"test2.txt"��ǂݍ���. */
	ret_2 = wcslen(buf2);	/* ������ret_2�Ɋi�[. */
	buf2[ret_2] = L'\0';	/* NULL�I�[ */

	/* buf2���o��. */
	printf("buf2 = %ls\n", buf2);	/* printf��buf2���o��. */

	/* �������̉��. */
	free(buf2);	/* free��buf2�����. */

	/* test3.txt�̃T�C�Y�擾. */
	file_size_3 = get_file_size("test3.txt");	/* get_file_size��"test3.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf3 = (wchar_t*)malloc((file_size_3 + 1) * sizeof(wchar_t));	/* malloc��((file_size_3 + 1) * sizeof(wchar_t))���̃������m��. */

	/* "test3.txt"����̓��͂�buf3�Ɋi�[. */
	wget_file_wtext_ccs_cstdio("test3.txt", buf3, file_size_3 + 1, "UNICODE");	/* wget_file_wtext_ccs_cstdio��"UNICODE"��"test3.txt"��ǂݍ���. */
	ret_3 = wcslen(buf3);	/* ������ret_3�Ɋi�[. */
	buf3[ret_3] = L'\0';	/* NULL�I�[ */

	/* buf3���o��. */
	printf("buf3 = %ls\n", buf3);	/* printf��buf3���o��. */

	/* �������̉��. */
	free(buf3);	/* free��buf3�����. */

	/* test4.txt�̃T�C�Y�擾. */
	file_size_4 = get_file_size("test4.txt");	/* get_file_size��"test4.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf4 = (wchar_t*)malloc((file_size_4 + 1) * sizeof(wchar_t));	/* malloc��((file_size_4 + 1) * sizeof(wchar_t))���̃������m��. */

	/* "test4.txt"����̓��͂�buf4�Ɋi�[. */
	wget_file_wtext_ccs_cstdio("test4.txt", buf4, file_size_4 + 1, "UTF-8");	/* wget_file_wtext_ccs_cstdio��"UTF-8"��"test4.txt"��ǂݍ���. */
	ret_4 = wcslen(buf4);	/* ������ret_4�Ɋi�[. */
	buf4[ret_4] = L'\0';	/* NULL�I�[ */

	/* buf4���o��. */
	printf("buf4 = %ls\n", buf4);	/* printf��buf4���o��. */

	/* �������̉��. */
	free(buf4);	/* free��buf4�����. */

	/* �v���O�����̏I�� */
	return 0; /* 0��Ԃ��Đ���I��. */

}

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size(const char* path) {

	/* �\���̂̏�����. */
	struct stat sst = { 0 };	/* stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	stat(path, &sst);	/* stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ń��C�h�����e�L�X�g�t�@�C������. */
wchar_t* wget_file_wtext_ccs_cstdio(const char* path, wchar_t* wtext, size_t buf_size, const char* ccs) {

	/* �\���́E�|�C���^�̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	wchar_t* ret;	/* �i�[����������|�C���^ret. */
	char mode[256] = "";	/* ���[�h��\��mode��""�ŏ�����. */

	/* �t�@�C�����J��. */
	if (ccs == NULL || strcmp(ccs, "") == 0) {	/* NULL�܂��͋�̏ꍇ. */
		strcpy(mode, "r");	/* strcpy��mode��"r"���Z�b�g. */
	}
	else {	/* ����ȊO. */
		strcpy(mode, "r, ccs=");	/* strcpy��mode��"r, ccs="���Z�b�g. */
		strcat(mode, ccs);	/* strcat��mode��ccs��A��. */
	}
	fp = fopen(path, mode);	/* fopen��mode�ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C�����烏�C�h�����e�L�X�g��ǂݍ���. */
		ret = fgetws(wtext, buf_size, fp);	/* fgetws��fp������͂�wtext�Ɋi�[, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, NULL��Ԃ�. */
	return NULL;	/* return��NULL��Ԃ�. */

}