/* ��d�C���N���[�h�h�~ */
#ifndef __FILE_UTILITY_CSTDIO_H__
#define __FILE_UTILITY_CSTDIO_H__

/* �֐��̃v���g�^�C�v�錾 */
/* ���̏ꍇ, ��������������������Ȃ��ƃR���p�C���G���[�ɂȂ�͗l. */
#ifdef __cplusplus
extern "C" {
#endif
	void swap_2bytes(char *byte1, char *byte2);	/* �֐�swap_2bytes�̐錾. */
	int convert_endian_16bit_byte_array(const char *src, char *dest, size_t len);	/* �֐�convert_endian_16bit_byte_array�̐錾. */
#ifdef __cplusplus
}
#endif
#endif