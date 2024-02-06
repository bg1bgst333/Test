// �w�b�_�t�@�C���̃C���N���[�h
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}
#include <cstdio>	// C�W�����o��
#include <iostream>	// C++�W�����o��
#include <locale.h>	// ���P�[��

// main�֐��̒�`
int main(){

	// test1.txt�̃T�C�Y�擾.
	size_t file_size_1 = get_file_size("test1.txt");	// get_file_size��"test1.txt"�̃T�C�Y�擾.

	// file_size_1���o��.
	std::cout << "file_size_1 = " << file_size_1 << std::endl;	// �o�͉��Z�q��file_size_1���o��.

	// �������̊m��.
	char *buf1 = new char[file_size_1 + 1];	// new��(file_size_1 + 1)���̃������m��.

	// "C"���P�[���̃Z�b�g.
	setlocale(LC_ALL, "C");	// setlocale��LC_ALL, "C"���Z�b�g.

	// "test1.txt"����̓��͂�buf1�Ɋi�[.
	int ret1 = read_file_text_cstdio("test1.txt", buf1, file_size_1 + 1);	// read_file_text_cstdio��"test1.txt"��ǂݍ���.
	buf1[ret1] = '\0';	// ������'\0'���Z�b�g.
	
	// buf1���o��.
	fwrite(buf1, sizeof(char), ret1, stdout);	// fwrite��buf1��(file_size_1 + 1)�̕�����stdout�ŏo��.
 
	// buf1�����.
	delete [] buf1;	// delete [] ��buf1�����.
	
	// ���s
	std::cout << std::endl;

	// test2.txt�̃T�C�Y�擾.
	size_t file_size_2 = get_file_size("test2.txt");	// get_file_size��"test2.txt"�̃T�C�Y�擾.

	// file_size_2���o��.
	std::cout << "file_size_2 = " << file_size_2 << std::endl;	// �o�͉��Z�q��file_size_2���o��.

	// �������̊m��.
	char *buf2 = new char[file_size_2 + 1];	// new��(file_size_2 + 1)���̃������m��.

	// "Japanese_Japan.932"���P�[���̃Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");	// setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g.
	
	// "test2.txt"����̓��͂�buf2�Ɋi�[.
	int ret2 = read_file_text_cstdio("test2.txt", buf2, file_size_2 + 1);	// read_file_text_cstdio��"test2.txt"��ǂݍ���.
	buf2[ret2] = '\0';	// ������'\0'���Z�b�g.

	// buf2���o��.
	//fwrite(buf2, sizeof(char), ret2, stdout);	// fwrite��buf2��ret2�̕�����stdout�ŏo��.
	fprintf(stdout, "%s", buf2);
	fprintf(stdout, " %s", buf2 + strlen(buf2) + 1);

	// buf2�����.
	delete [] buf2;	// delete [] ��buf2�����.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}