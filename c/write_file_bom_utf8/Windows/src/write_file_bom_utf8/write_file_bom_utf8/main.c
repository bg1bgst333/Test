/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */
#include <string.h>	/* �����񏈗� */

/* �֐��̃v���g�^�C�v�錾 */
int write_file_bom_utf8(const char* path);	/* �֐�write_file_bom_utf8�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �ϐ��̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */
	char str[] = { 0xe3, 0x81, 0x82, 0x00 };	/* char�^�z��str[]��{0xe3, 0x81, 0x82, 0x00}(UTF-8��"��")�ŏ�����. */

	/* test1.txt��UTF-8��BOM����������. */
	write_file_bom_utf8("test1.txt");	/* write_file_bom_utf8��test1.txt��UTF-8��BOM����������. */

	/* test1.txt��UTF8��"��"��ǋL. */
	fp = fopen("test1.txt", "ab");	/* fopen��"test1.txt"���o�C�i���ǉ��������݂ŊJ��. */
	if (fp == NULL) {	/* fp��NULL�̎�. */
		return -1;	/* return��-1��Ԃ�. */
	}
	ret = fwrite(str, sizeof(char), strlen(str), fp);	/* fwrite��fp��str��ǋL��, �߂�l��ret�Ɋi�[. */
	fclose(fp);	/* fclose��fp�����. */

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* UTF-8��BOM����������. */
int write_file_bom_utf8(const char* path) {

	/* �ϐ��E�\���̂̐錾�E������. */
	FILE* fp = NULL;	/* �t�@�C���|�C���^fp��NULL�ŏ�����. */
	char bom[3] = { 0xef, 0xbb, 0xbf };	/* char�^�z��bom(����3)��{0xef, 0xbb, 0xbf}�ŏ�����. */
	int ret;	/* fwrite�̖߂�lret. */

	/* �t�@�C�����J��. */
	fp = fopen(path, "wb");	/* fopen�Ńo�C�i���������݂ŊJ��. */
	if (fp != NULL) {	/* fp��NULL�łȂ���. */

		/* �t�@�C���Ƀo�C�i������������. */
		ret = fwrite(bom, sizeof(char), 3, fp);	/* fwrite��fp��bom���o�͂�, �߂�l��ret�Ɋi�[. */

		/* fp�����. */
		fclose(fp);	/* fclose��fp�����. */

		/* ret��Ԃ�. */
		return ret;	/* return��ret��Ԃ�. */

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�. */
	return -1;	/* return��-1��Ԃ�. */

}