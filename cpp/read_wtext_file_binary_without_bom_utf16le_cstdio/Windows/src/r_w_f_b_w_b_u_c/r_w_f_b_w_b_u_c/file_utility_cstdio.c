/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* �t�@�C���T�C�Y�̎擾. */
size_t get_file_size(const char* path) {

	/* �\���̂̏�����. */
	struct _stat sst = { 0 };	/* _stat�\����sst��{0}�ŏ�����. */

	/* �t�@�C�����̎擾. */
	_stat(path, &sst);	/* _stat��path�Ŏ����ꂽ�t�@�C���̏���sst�Ɋi�[. */

	/* �t�@�C���T�C�Y��Ԃ�. */
	return sst.st_size;	/* return��sst.st_size��Ԃ�. */

}

/* UTF-16LE��BOM�����邩���肷��. */
int is_file_bom_utf16le(const char* path) {

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	size_t ret;	/* �ǂݍ��񂾃o�C�g��ret. */
	char bom[2] = { 0 };	/* char�^�z��bom(����2)��{0}�ŏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "rb");	/* fopen�Ńo�C�i���ǂݍ��݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C������o�C�i����ǂݍ���. */
		ret = fread(bom, sizeof(char), 2, fp);	/* fread��fp������͂�bom�Ɋi�[, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* BOM��UTF-16LE������. */
		if (bom[0] == (char)0xff && bom[1] == (char)0xfe) {	/* 0�Ԗڂ�0xff, 1�Ԗڂ�0xfe�Ȃ�. */
			return 1;	/* 1��Ԃ�. */
		}
		else {	/* ����ȊO. */
			return 0;	/* 0��Ԃ�. */
		}

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, 0��Ԃ�. */
	return 0;	/* return��0��Ԃ�. */

}