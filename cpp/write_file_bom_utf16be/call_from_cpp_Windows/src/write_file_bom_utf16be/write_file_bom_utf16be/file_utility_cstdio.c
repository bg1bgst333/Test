/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

/* UTF-16BE��BOM����������. */
int write_file_bom_utf16be(const char* path) {

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	char bom[2] = { 0xfe, 0xff };	/* char�^�z��bom(����2)��{0xfe, 0xff}�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "wb");	/* fopen�Ńo�C�i���������݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀo�C�i������������. */
		ret = fwrite(bom, sizeof(char), 2, fp);	/* fwrite��fp��bom���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}