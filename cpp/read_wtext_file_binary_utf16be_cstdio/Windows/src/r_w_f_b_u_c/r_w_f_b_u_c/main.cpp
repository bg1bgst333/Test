// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <locale>	// ���P�[��
// �Ǝ��̃w�b�_
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// main�֐��̒�`
int main(){

	// �I�u�W�F�N�g�̐錾
	std::wstring wstr;	// std::wstring�I�u�W�F�N�gwstr

	// ���P�[���Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// "test.txt"��ǂݍ���œ��e��wstr�Ɋi�[����.
	read_wtext_file_binary_utf16be_cstdio("test.txt", wstr);	// read_wtext_file_binary_utf16be_cstdio�Ńt�@�C������.

	// wstr�̏o��.
	printf("%ls\n", wstr.c_str());

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}