// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// main�֐��̒�`
int main(){

	// "test.txt"��"����������\r\n����������\r\n����������"�����C�h�����e�L�X�g(UTF-16LE)�Ƃ��ăt�@�C���o��.
	write_wtext_file_binary_cstdio("test.txt", L"����������\r\n����������\r\n����������");	// write_wtext_file_binary_cstdio�Ńt�@�C���o��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}