/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int print_file_text_cstdio(const char *path, const char *text){

	/* �ϐ��E�\���́E�|�C���^�̏����� */
	FILE *fp = NULL;	/* �t�@�C���|�C���^��NULL�ŏ�����. */
	int ret = 0;	/* �������񂾃o�C�g��ret��0�ŏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "w");	/* fopen�Ńe�L�X�g�������݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

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

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size(const char *path){

	/* �\���̂̏�����. */
	struct _stat sst = {0};	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_stat(path, &sst);	/* _stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C������. */
int scan_file_text_cstdio(const char *path, char *text){

	/* �ϐ��E�\���̂̏�����. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret = 0;	/* �i�[�����ϐ��̐�ret��0�ɏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "r");	/* fopen�Ńe�L�X�g�ǂݍ��݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

		/* �t�@�C������e�L�X�g��ǂݍ���. */
		ret = fscanf(fp, "%s", text);	/* fscanf��fp������͂�text�Ɋi�[, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* �i�[�����ϐ��̐�ret��Ԃ�. */
		return ret; /* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int put_file_text_cstdio(const char *path, const char *text){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fputs�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "w");	/* fopen�Ńe�L�X�g�������݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

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

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int write_file_text_cstdio(const char *path, const char *text, size_t len){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "w");	/* fopen�Ńe�L�X�g�������݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀe�L�X�g����������. */
		ret = fwrite(text, sizeof(char), len, fp);	/* fwrite��fp��text���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C������. */
size_t read_file_text_cstdio(const char *path, char *text, size_t len){

	/* �\���́E�|�C���^�̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	size_t ret;	/* �ǂݍ��񂾕�����ret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "r");	/* fopen�Ńe�L�X�g�ǂݍ��݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

		/* �t�@�C������e�L�X�g��ǂݍ���. */
		ret = fread(text, sizeof(char), len, fp);	/* fread��fp������͂�text�Ɋi�[, �߂�l��ret�Ɋi�[. */
		
		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */
	
	}

	/* �t�@�C�����J���Ȃ��ꍇ��, 0��Ԃ�. */
	return 0;	/* return��0��Ԃ�. */

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

/* C�W�����o�̓��C�u�����֐��Ńo�C�i���t�@�C���o��. */
int write_file_binary_cstdio_w(const wchar_t *path, const void *bytes, size_t size){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = _wfopen(path, L"wb");	/* _wfopen�Ńo�C�i���������݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

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