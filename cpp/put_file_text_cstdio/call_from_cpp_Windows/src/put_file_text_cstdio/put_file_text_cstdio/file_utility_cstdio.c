/* �w�b�_�t�@�C���̃C���N���[�h */
/* �Ǝ��̃w�b�_�t�@�C�� */
#include "file_utility_cstdio.h"	/* �t�@�C�����[�e�B���e�B(C�W�����o��) */

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