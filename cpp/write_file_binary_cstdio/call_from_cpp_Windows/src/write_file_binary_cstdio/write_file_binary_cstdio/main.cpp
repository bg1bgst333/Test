// �w�b�_�t�@�C���̃C���N���[�h
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// C�W�����C�u����
#include <locale.h>	// ���P�[��

// main�֐�
int main(){

	// �z��̏�����.
	char ascii_str[] = "ABC DE\nFGH\0IJ\nKLMNO";	// ' '��'\n'��'\0'���܂܂ꂽASCII������.
	char japanese_str[] = "������ ����\n������\0����\n����������";	// ' '��'\n'��'\0'���܂܂ꂽ���{�ꕶ����.

	/* ascii_str��"test1.txt"�ɏo��. */
	write_file_binary_cstdio("test1.txt", ascii_str, 19);	/* write_file_binary_cstdio��ascii_str��"test1.txt"�ɏo��. */

	// "Japanese_Japan.932"���P�[���̃Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");	// setlocale��LC_ALL, "Japanese_Japan.932"���Z�b�g.

	/* japanese_str��"test2.txt"�ɏo��. */
	write_file_binary_cstdio("test2.txt", japanese_str, 34);	/* write_file_binary_cstdio��japanese_str��"test2.txt"�ɏo��. */
	
	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}