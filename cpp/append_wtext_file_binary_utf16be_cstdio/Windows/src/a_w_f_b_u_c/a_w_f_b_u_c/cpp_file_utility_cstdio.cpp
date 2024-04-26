// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// �w��̃��C�h��������o�C�i�����[�h�Œǉ��������݂���.
int append_wtext_file_binary_cstdio(const char* path, const wchar_t* wtext) {

	// �ϐ��E�\���̂̐錾�E������.
	FILE* fp = NULL;	// �t�@�C���|�C���^fp��NULL�ŏ�����.
	int ret;	// fwrite�̖߂�lret.

	// �t�@�C�����J��.
	fp = fopen(path, "ab");	// fopen�Ńo�C�i���ǉ��������݂ŊJ��.
	if (fp != NULL) {	// fp��NULL�łȂ���.

		// �t�@�C���Ƀ��C�h���������������.
		ret = fwrite(wtext, sizeof(wchar_t), wcslen(wtext), fp);	// fwrite��fp��wtext���o�͂�, �߂�l��ret�Ɋi�[.

		// fp�����.
		fclose(fp);	// fclose��fp�����.

		// ret��Ԃ�.
		return ret;	// return��ret��Ԃ�.

	}

	// �t�@�C�����J���Ȃ��ꍇ��, -1��Ԃ�.
	return -1;	// return��-1��Ԃ�.

}

// �w��̃��C�h�������UTF-16BE�Ńo�C�i�����[�h�Œǉ��������݂���.
int append_wtext_file_binary_utf16be_cstdio(const char *path, const wchar_t *wtext){

	// 16bit�G���f�B�A���ϊ�.
	size_t wlen = wcslen(wtext);
	char *converted = new char[wlen * 2 + 2];
	convert_endian_16bit_byte_array((char *)wtext, converted, wlen * 2);
	converted[wlen * 2] = '\0';
	converted[wlen * 2 + 1] = '\0';

	// �t�@�C���ɏ�������.
	int ret = append_wtext_file_binary_cstdio(path, (wchar_t *)converted);
	delete [] converted;
	return ret;

}