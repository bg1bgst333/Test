/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
int write_file_bom_utf16le(const char *path);	/* �֐�write_file_bom_utf16le�̐錾. */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	char bytes[2] = {0x42, 0x30};	/* char�^�z��bytes(����2)��{0x42, 0x30}�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* test1.txt��UTF-16LE��BOM����������. */
	write_file_bom_utf16le("test1.txt");	/* write_file_bom_utf16le��test1.txt��UTF-16LE��BOM����������. */

	/* test1.txt��UTF16-LE��"��"��ǋL. */
	fp = fopen("test1.txt", "ab");	/* fopen��"test1.txt"���o�C�i���ǉ��������݂ŊJ��. */
	if (fp == NULL){	/* fp��NULL�̎�. */
		return -1;	/* return��-1��Ԃ�. */
	}
	ret = fwrite(bytes, sizeof(char), 2, fp);	/* fwrite��fp��bytes��ǋL��, �߂�l��ret�Ɋi�[. */
	fclose(fp);	/* fclose��fp�����. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* UTF-16LE��BOM����������. */
int write_file_bom_utf16le(const char *path){

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE *fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	char bom[2] = {0xff, 0xfe};	/* char�^�z��bom(����2)��{0xff, 0xfe}�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "wb");	/* fopen�Ńo�C�i���������݂ŊJ��. */
	if (fp != NULL){	/* fp��NULL�łȂ���. */

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