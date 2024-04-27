/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
int is_file_bom_utf16be(const char* path);	/* �֐�is_file_bom_utf16be�̐錾. */

/* main�֐��̒�` */
int main(void) {

	/* �ϐ��̐錾 */
	int ret;	/* int�^�ϐ�ret. */

	/* test1.txt��UTF-16BE��BOM�����邩���肷��. */
	ret = is_file_bom_utf16be("test1.txt");	/* is_file_bom_utf16be��"test1.txt"��UTF-16BE��BOM�����邩���肷��. */
	if (ret == 1) {	/* ret��1. */
		printf("UTF-16BE\n");	/* "UTF-16BE"�Əo��. */
	}
	else {	/* ret��0. */
		printf("Not UTF-16BE\n");	/* "Not UTF-16BE"�Əo��. */
	}

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* UTF-16BE��BOM�����邩���肷��. */
int is_file_bom_utf16be(const char* path) {

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

		/* BOM��UTF-16BE������. */
		if (bom[0] == (char)0xfe && bom[1] == (char)0xff) {	/* 0�Ԗڂ�0xfe, 1�Ԗڂ�0xff�Ȃ�. */
			return 1;	/* 1��Ԃ�. */
		}
		else {	/* ����ȊO. */
			return 0;	/* 0��Ԃ�. */
		}

	}

	/* �t�@�C�����J���Ȃ��ꍇ��, 0��Ԃ�. */
	return 0;	/* return��0��Ԃ�. */

}