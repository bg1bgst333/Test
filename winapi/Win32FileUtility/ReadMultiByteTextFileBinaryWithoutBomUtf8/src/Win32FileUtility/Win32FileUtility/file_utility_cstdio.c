/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* UTF-8��BOM�����邩���肷��. */
int is_file_bom_utf8(const char *path){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	size_t ret;	/* �ǂݍ��񂾃o�C�g��ret. */
	char bom[3] = {0};	/* char�^�z��bom(����3)��{0}�ŏ�����. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "rb");	/* fopen�Ńo�C�i���ǂݍ��݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

		/* �t�@�C������o�C�i����ǂݍ���. */
		ret = fread(bom, sizeof(char), 3, fp);	/* fread��fp������͂�bom�Ɋi�[, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* BOM��UTF-8������. */
		if (bom[0] == (char)0xef && bom[1] == (char)0xbb && bom[2] == (char)0xbf){	/* 0�Ԗڂ�0xef, 1�Ԗڂ�0xbb�Ȃ�, 2�Ԗڂ�0xbf�Ȃ�. */
			return 1;	/* 1��Ԃ�. */
		}
		else{	/* ����ȊO. */
			return 0;	/* 0��Ԃ�. */
		}

	}
	
	/* �t�@�C�����J���Ȃ��ꍇ��, 0��Ԃ�. */
	return 0;	/* return��0��Ԃ�. */

}