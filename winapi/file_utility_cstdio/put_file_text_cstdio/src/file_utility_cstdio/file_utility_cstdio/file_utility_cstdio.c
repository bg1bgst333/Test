/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C���o��. */
int print_file_text_cstdio(const char* path, const char* text) {

	/* �ϐ��E�\���́E�|�C���^�̏����� */
	FILE* fp = NULL;	/* �t�@�C���|�C���^��NULL�ŏ�����. */
	int ret = 0;	/* �������񂾃o�C�g��ret��0�ŏ�����. */

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

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size(const char* path) {

	/* �\���̂̏�����. */
	struct _stat sst = { 0 };	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_stat(path, &sst);	/* _stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* C�W�����o�̓��C�u�����֐��Ńe�L�X�g�t�@�C������. */
int scan_file_text_cstdio(const char* path, char* text) {

	/* �ϐ��E�\���̂̏�����. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret = 0;	/* �i�[�����ϐ��̐�ret��0�ɏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "r");	/* fopen�Ńe�L�X�g�ǂݍ��݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

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