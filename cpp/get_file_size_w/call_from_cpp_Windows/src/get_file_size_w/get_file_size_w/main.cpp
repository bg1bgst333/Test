// �w�b�_�t�@�C���̃C���N���[�h
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}
#include <iostream>	// C++�W�����o��

// main�֐��̒�`
int main() {

	// �t�@�C���T�C�Y�̎擾.
	size_t file_size = get_file_size_w(L"test.txt");	// get_file_size_w��"test.txt"�̃t�@�C���T�C�Y���擾.

	// file_size���o��.
	std::cout << "file_size = " << file_size << std::endl;	// �o�͉��Z�q��file_size���o��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}