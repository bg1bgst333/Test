// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <locale.h>	// ���P�[��
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// main�֐��̒�`
int main() {

	// �ϐ��̐錾
	int ret;	// int�^�ϐ�ret.
	std::wstring wtext;	// std::wstring�I�u�W�F�N�gwtext.

	// ���P�[���Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// test.txt��UTF-16BE��BOM�����邩���肷��.
	ret = is_file_bom_utf16be("test.txt");	// is_file_bom_utf16be��"test.txt"��UTF-16BE��BOM�����邩���肷��.
	if (ret == 1) {	// ret��1.
		// BOM�ȊO�����o��.
		read_wtext_file_binary_without_bom_utf16be_cstdio("test.txt", wtext);	// read_wtext_file_binary_without_bom_utf16be_cstdio��"test.txt"��ǂݍ���.
		// wtext�̏o��.
		printf("%ls\n", wtext.c_str());
	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}