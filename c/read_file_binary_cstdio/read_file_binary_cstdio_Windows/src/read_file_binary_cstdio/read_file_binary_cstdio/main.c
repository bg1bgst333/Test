/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <stdlib.h>	/* �W�����[�e�B���e�B */
#include <string.h>	/* �����񏈗� */
#include <locale.h>	/* ���P�[�� */
#include <sys/stat.h>	/* �t�@�C����� */

/* �֐��̃v���g�^�C�v�錾 */
size_t get_file_size(const char *path);	/* �֐�get_file_size�̐錾. */
size_t read_file_binary_cstdio(const char *path, void *bytes, size_t size);	/* �֐�read_file_binary_cstdio�̐錾. */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�|�C���^�̐錾�E������. */
	size_t file_size_1;	/* size_t�^�ϐ�file_size_1. */
	size_t file_size_2;	/* size_t�^�ϐ�file_size_2. */
	char *buf1 = NULL;	/* char�^�|�C���^buf1��NULL�ŏ�����. */
	char *buf2 = NULL;	/* char�^�|�C���^buf2��NULL�ŏ�����. */
	int ret1;
	int ret2;

	/* test1.txt�̃T�C�Y�擾. */
	file_size_1 = get_file_size("test1.txt");	/* get_file_size��"test1.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf1 = (char *)malloc((file_size_1 + 1) * sizeof(char));	/* malloc��(file_size_1 + 1)���̃������m��. */

	/* "C"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "C");	/* setlocale��LC_ALL, "C"���Z�b�g. */

	/* "test1.txt"����̓��͂�buf1�Ɋi�[. */
	ret1 = read_file_binary_cstdio("test1.txt", buf1, file_size_1 + 1);	/* read_file_binary_cstdio��"test1.txt"��ǂݍ���. */
	buf1[ret1] = '\0';	/* ������'\0'���Z�b�g. */

	/* buf1���o��. */
	fwrite(buf1, sizeof(char), ret1, stdout);	/* fwrite��buf1��ret1�̕�����stdout�ŏo��. */
 
	/* �������̉��. */
	free(buf1);	/* free��buf1�����. */

	/* ���s�o��. */
	printf("\n"); /* printf��"\n"���o��. */

	/* test2.txt�̃T�C�Y�擾. */
	file_size_2 = get_file_size("test2.txt");	/* get_file_size��"test2.txt"�̃T�C�Y�擾. */

	/* �������̊m��. */
	buf2 = (char *)malloc((file_size_2 + 1) * sizeof(char));	/* malloc��(file_size_2 + 1)���̃������m��. */

	/* "Japanese_Japan.932"���P�[���̃Z�b�g. */
	setlocale(LC_ALL, "Japanese_Japan.932");	/* setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g. */

	/* "test2.txt"����̓��͂�buf2�Ɋi�[. */
	ret2 = read_file_binary_cstdio("test2.txt", buf2, file_size_2 + 1);	/* read_file_binary_cstdio��"test2.txt"��ǂݍ���. */
	buf2[ret2] = '\0';	/* ������'\0'���Z�b�g. */

	/* buf2���o��. */
	/* fwrite(buf2, sizeof(char), ret2, stdout); */	/* fwrite��buf2��ret2�̕�����stdout�ŏo��. */
	fprintf(stdout, "%s", buf2);
	fprintf(stdout, " %s", buf2 + strlen(buf2) + 1);

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

/* C�W�����o�̓��C�u�����֐��Ńo�C�i���t�@�C������. */
size_t read_file_binary_cstdio(const char *path, void *bytes, size_t size){

	/* �\���́E�|�C���^�̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	size_t ret;	/* �ǂݍ��񂾕�����ret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "rb");	/* fopen�Ńo�C�i���ǂݍ��݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

		/* �t�@�C������o�C�i����ǂݍ���. */
		ret = fread(bytes, sizeof(char), size, fp);	/* fread��fp������͂�bytes�Ɋi�[, �߂�l��ret�Ɋi�[. */
		
		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */
	
	}

	/* �t�@�C�����J���Ȃ��ꍇ��, 0��Ԃ�. */
	return 0;	/* return��0��Ԃ�. */

}