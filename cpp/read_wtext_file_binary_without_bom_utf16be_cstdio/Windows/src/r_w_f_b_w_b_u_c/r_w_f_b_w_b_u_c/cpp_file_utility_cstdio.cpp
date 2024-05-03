// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// �w���wtext�Ƀo�C�i�����[�h��BOM�ȊO��ǂݍ��񂾃��C�h��������i�[����.
int read_wtext_file_binary_without_bom_utf16le_cstdio(const char *path, std::wstring &wtext){

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
	wchar_t *wbuf = new wchar_t[(file_size / 2) - 1 + 1];	// new�ŗv�f����(file_size / 2) - 1 + 1��wchar_t���I�z����m��.(BOM�̕�2�o�C�g(1���C�h����)����.)

	// �t�@�C�����J��.
	fp = fopen(path, "rb");	// fopen�Ńo�C�i���ǂݍ��݂ŊJ��.
	if (fp != NULL){	// fp��NULL�łȂ���.

		// �t�@�C�����烏�C�h�������ǂݍ���.
		fseek(fp, 2, SEEK_SET);	// fseek��2�o�C�g��ֈړ�.
		ret = fread(wbuf, sizeof(wchar_t), (file_size / 2) - 1, fp);	// fread��fp������͂��ꂽ�������wbuf�Ɋi�[��, �߂�l��ret�Ɋi�[.
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

// �w���wtext�Ƀo�C�i�����[�h��BOM�ȊO��ǂݍ���UTF-16BE���C�h�������UTF-16LE�ɕϊ��������̂��i�[����.
int read_wtext_file_binary_without_bom_utf16be_cstdio(const char *path, std::wstring &wtext){

	// BOM�ȊO�����o��.
	std::wstring src;
	read_wtext_file_binary_without_bom_utf16le_cstdio(path, src);

	// 16bit�G���f�B�A���ϊ�.
	char *converted = new char[src.length() * 2 + 2];
	convert_endian_16bit_byte_array((char *)src.c_str(), converted, src.length() * 2);
	converted[src.length() * 2] = '\0';
	converted[src.length() * 2 + 1] = '\0';
	wtext = (wchar_t *)converted;
	return wtext.length();

}