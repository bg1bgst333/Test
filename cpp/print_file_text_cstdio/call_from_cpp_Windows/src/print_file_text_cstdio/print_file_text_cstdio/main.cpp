// �w�b�_�t�@�C���̃C���N���[�h
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// C�W�����C�u����
#include <locale.h>	// ���P�[��

// main�֐�
int main() {

	// �z��̏�����.
	char ascii_str[] = "ABCDE\nFGHIJ\nKLMNO";	// '\n'���܂܂ꂽASCII������.
	char japanese_str[] = "����������\n����������\n����������";	// '\n'���܂܂ꂽ���{�ꕶ����.

	// ascii_str��"test1.txt"�ɏo��.
	print_file_text_cstdio("test1.txt", ascii_str);	// print_file_text_cstdio��ascii_str��"test1.txt"�ɏo��.

	// "Japanese_Japan.932"���P�[���̃Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");	// setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g.

	// japanese_str��"test2.txt"�ɏo��.
	print_file_text_cstdio("test2.txt", japanese_str);	// print_file_text_cstdio��japanese_str��"test2.txt"�ɏo��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}