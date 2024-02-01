/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size(const char *path);	/* �֐�get_file_size�̐錾. */
char * get_file_text_cstdio(const char *path, char *text, size_t buf_size);	/* �֐�get_file_text_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�|�C���^�̐錾�E������. */
	size_t file_size_1;	/* size_t�^�ϐ�file_size_1. */
	size_t file_size_2;	/* size_t�^�ϐ�file_size_2. */
	char *buf1 = NULL;	/* char�^�|�C���^buf1��NULL�ŏ�����. */
	char *buf2 = NULL;	/* char�^�|�C���^buf2��NULL�ŏ�����. */

	/* test1.txt�̃T�C�Y�擾. */
	file_size_1 = get_file_size("test1.txt");	/* get_file_size��"test1.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf1 = (char *)malloc((file_size_1 + 1) * sizeof(char));	/* malloc��(file_size_1 + 1)���̃������m��. */

	/* "C"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "C");	/* setlocale��LC_ALL, "C"���Z�b�g. */

	/* "test1.txt"����̓��͂�buf1�Ɋi�[. */
	get_file_text_cstdio("test1.txt", buf1, file_size_1 + 1);	/* get_file_text_cstdio��"test1.txt"��ǂݍ���. */

	/* buf1���o��. */
	printf("buf1 = %s\n", buf1);	/* printf��buf1���o��. */
 
	/* �������̉��. */
	free(buf1);	/* free��buf1�����. */

	/* test2.txt�̃T�C�Y�擾. */
	file_size_2 = get_file_size("test2.txt");	/* get_file_size��"test2.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf2 = (char *)malloc((file_size_2 + 1) * sizeof(char));	/* malloc��(file_size_2 + 1)���̃������m��. */

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* "test2.txt"����̓��͂�buf2�Ɋi�[. */
	get_file_text_cstdio("test2.txt", buf2, file_size_2 + 1);	/* get_file_text_cstdio��"test2.txt"��ǂݍ���. */
	
	/* buf2���o��. */
	printf("buf2 = %s\n", buf2);	/* printf��buf2���o��. */

	/* �������̉��. */
	free(buf2); /* free��buf2�����. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* �t�@�C���T�C�Y�̎擾 */
size_t get_file_size(const char *path){

	/* �\���̂̏�����. */
	struct _stat sst = {0};	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_stat(path, &sst);	/* _stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C������. */
char * get_file_text_cstdio(const char *path, char *text, size_t buf_size){

	/* �\���́E�|�C���^�̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	char *ret;	/* �i�[����������|�C���^ret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "r");	/* fopen�Ńe�L�X�g�ǂݍ��݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */
		
		/* �t�@�C������e�L�X�g��ǂݍ���. */
		ret = fgets(text, buf_size, fp);	/* fgets��fp������͂�text�Ɋi�[, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */
	
	}

	/* �t�@�C�����J���Ȃ��ꍇ��, NULL��Ԃ�. */
	return NULL;	/* return��NULL��Ԃ�. */

}