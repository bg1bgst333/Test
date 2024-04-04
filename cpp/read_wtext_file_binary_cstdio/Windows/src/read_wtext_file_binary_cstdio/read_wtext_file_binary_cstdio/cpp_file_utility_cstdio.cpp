// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// �w���wtext�Ƀo�C�i�����[�h�œǂݍ��񂾃��C�h��������i�[����.
int read_wtext_file_binary_cstdio(const char *path, std::wstring &wtext){

	// �ϐ��E�\���̂̐錾�E������.
	FILE *fp = NULL;	// �t�@�C���|�C���^fp��NULL�ŏ�����.
	int ret;	// fread�̖߂�l.

	// �t�@�C���T�C�Y�̎擾.
	size_t file_size = get_file_size(path);	// get_file_size��path��file_size���擾.

	// �t�@�C���T�C�Y����Ȃ�G���[.
	if (file_size % 2 != 0){	// 2�Ŋ������]�肪0�łȂ�.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// �o�b�t�@���m��.
	wchar_t *wbuf = new wchar_t[(file_size / 2) + 1];	// new�ŗv�f����(file_size / 2) + 1��wchar_t���I�z����m��.

	// �t�@�C�����J��.
	fp = fopen(path, "rb");	// fopen�Ńo�C�i���ǂݍ��݂ŊJ��.
	if (fp != NULL){	// fp��NULL�łȂ���.

		// �t�@�C�����烏�C�h�������ǂݍ���.
		ret = fread(wbuf, sizeof(wchar_t), (file_size / 2), fp);	// fread��fp������͂��ꂽ�������wbuf�Ɋi�[��, �߂�l��ret�Ɋi�[.
		wbuf[ret] = L'\0';	// NULL�I�[.

		// fp�����.
		fclose(fp);	// fclose��fp�����.

		// wbuf��wtext�ɑ��.
		wtext = wbuf;

		// wbuf�̉��.
		delete[] wbuf;	// delete[]��wbuf�����.

		// ret��Ԃ�.
		return ret;	// return��ret��Ԃ�.

	}

	// wbuf�̉��.
	delete[] wbuf;	// delete[]��wbuf�����.

	// -1��Ԃ�.
	return -1;	// return��-1��Ԃ�.

}