/* �w�b�_�t�@�C���̃C���N���[�h */
#include <stdio.h>	/* �W�����o�� */

/* �֐��̃v���g�^�C�v�錾 */
void swap_2bytes(char *byte1, char *byte2);	/* �֐�swap_2bytes�̐錾. */
int convert_endian_16bit_byte_array(const char *src, char *dest, size_t len);	/* �֐�convert_endian_16bit_byte_array�̐錾. */

/* main�֐��̒�` */
int main(void){

	/* �ϐ��E�z��E�\���̂̐錾�E������ */
	char japanese_str_converted[11];	/* �ϊ����char�^���{�ꕶ���z��(����11)japanese_str_converted. */
	char bom_utf16be[2] = {0xfe, 0xff};
	FILE *fp = NULL;

	/* ���{�ꕶ�����16bit�G���f�B�A���ϊ�. */
	convert_endian_16bit_byte_array(L"����������", japanese_str_converted, 10);	/* convert_endian_16bit_byte_array��16bit�G���f�B�A���ϊ�. */
	japanese_str_converted[10] = '\0'; /* NULL�I�[. */

	/* ���{���japanese_str_converted��ۑ�. */
	fp = fopen("test.txt", "wb");
	if (fp == NULL){
		return -1;
	}
	fwrite(bom_utf16be, sizeof(char), 2, fp);
	fwrite(japanese_str_converted, sizeof(char), 10, fp);
	fclose(fp);

	/* �v���O�����̏I�� */
	return 0;	/* 0��Ԃ��Đ���I��. */

}

/* 2�̃o�C�g�l�����ւ���. */
void swap_2bytes(char *byte1, char *byte2){

	/* �ϐ��̐錾 */
	char temp;	/* char�^�ꎞ�ϐ�temp. */

	/* byte1�̎w���l��byte2�̎w���l�����ւ���. */
	temp = *byte1;	/* byte1�̎w���l��temp�ɑ��. */
	*byte1 = *byte2;	/* byte2�̎w���l��byte1�ɑ��. */
	*byte2 = temp;	/* temp�̒l��byte2�̎w���l�ɑ��. */

}

/* �o�C�g��̃G���f�B�A���ϊ�(big�Ȃ�little, little�Ȃ�big.) */
int convert_endian_16bit_byte_array(const char *src, char *dest, size_t len){

	/* �ϐ��̏����� */
	int half = 0;	/* �����̔���harf��0�ŏ�����. */
	int i = 0;	/* ���[�v�p�ϐ�i��0�ŏ�����. */
	int a, b;	/* ����ւ��p�ꎞ�ϐ�a, b. */

	/* ��������̏ꍇ�̓G���[. */
	if (len % 2){	/* �. */
		return -1;	/* -1��Ԃ�. */
	}

	/* �G���f�B�A���ϊ� */
	half = len / 2;	/* len�̔����̒�����half�ɑ��. */
	for (i = 0; i < half; i++){	/* half�̑O�܂ŌJ��Ԃ�. */
		*(dest + 2 * i) = *(src + 2 * i);
		*(dest + 2 * i + 1) = *(src + 2 * i + 1);
		swap_2bytes(dest + 2 * i, dest + 2 * i + 1);
	}

	/* ����I�� */
	return 0;	/* 0��Ԃ�. */

}