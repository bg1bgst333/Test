/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

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