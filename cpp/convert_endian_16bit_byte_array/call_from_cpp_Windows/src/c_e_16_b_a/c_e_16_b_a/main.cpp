// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <cstdio>	// C�W�����o��
// �Ǝ��̃w�b�_
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// main�֐��̒�`
int main(void){

	// �ϐ��E�z��E�\���̂̐錾�E������
	char japanese_str_converted[11];	// �ϊ����char�^���{�ꕶ���z��(����11)japanese_str_converted.
	char bom_utf16be[2] = {0xfe, 0xff};
	FILE *fp = NULL;

	// ���{�ꕶ�����16bit�G���f�B�A���ϊ�.
	convert_endian_16bit_byte_array((const char *)L"����������", japanese_str_converted, 10);	// convert_endian_16bit_byte_array��16bit�G���f�B�A���ϊ�.
	japanese_str_converted[10] = '\0';	// NULL�I�[.

	// ���{���japanese_str_converted��ۑ�.
	fp = fopen("test.txt", "wb");
	if (fp == NULL){
		return -1;
	}
	fwrite(bom_utf16be, sizeof(char), 2, fp);
	fwrite(japanese_str_converted, sizeof(char), 10, fp);
	fclose(fp);

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}