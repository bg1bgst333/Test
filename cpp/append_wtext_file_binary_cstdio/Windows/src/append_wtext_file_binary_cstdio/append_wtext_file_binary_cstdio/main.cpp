// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "cpp_file_utility_cstdio.h"	// C++�t�@�C�����[�e�B���e�B(C�W�����o��)

// main�֐��̒�`
int main() {

	// test.txt��UTF-16LE��BOM����������.
	write_file_bom_utf16le("test.txt");	// write_file_bom_utf16le��test.txt��UTF-16LE��BOM����������.

	// test.txt��"����������\r\n����������\r\n����������"�����C�h�����e�L�X�g(UTF-16LE)�Ƃ��ăt�@�C���ǋL.
	append_wtext_file_binary_cstdio("test.txt", L"����������\r\n����������\r\n����������");	// append_wtext_file_binary_cstdio�Ńt�@�C���ǋL.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}