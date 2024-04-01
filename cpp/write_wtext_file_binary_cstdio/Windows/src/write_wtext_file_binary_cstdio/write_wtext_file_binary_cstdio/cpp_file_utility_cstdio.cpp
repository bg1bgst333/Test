// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// �w��̃��C�h��������o�C�i�����[�h�ŏ�������.
int write_wtext_file_binary_cstdio(const char* path, const wchar_t* wtext) {

	// �ϐ��E�\���̂̐錾�E������.
	FILE* fp = NULL;	// �t�@�C���|�C���^fp��NULL�ŏ�����.
	int ret;	// fwrite�̖߂�lret.

	// �t�@�C�����J��.
	fp = fopen(path, "wb");	// fopen�Ńo�C�i���������݂ŊJ��.
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