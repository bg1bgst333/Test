// �w�b�_�̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <locale.h>	// ���P�[��
// �Ǝ��̃w�b�_
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
#include "Win32FileUtility.h"	// Win32�t�@�C�����[�e�B���e�B

// main�֐��̒�`
int main(){

	// �ϐ��̐錾
	DWORD dwLen;	// �������񂾒���dwLen.
	int ret;	// int�^�ϐ�ret.

	// ���P�[���Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// test.txt��UTF-8��BOM�����邩���肷��.
	ret = is_file_bom_utf8("test.txt");	// is_file_bom_utf8��"test.txt"��UTF-8��BOM�����邩���肷��.
	if (ret == 1){	// ret��1.
		// BOM�ȊO�����o��.
		std::wstring wstr;
		ReadMultiByteTextFileBinaryWithoutBomUtf8("test.txt", wstr, &dwLen);	// ReadMultiByteTextFileBinaryWithoutBomUtf8��"test.txt"��BOM�ȊO��ǂݍ���.
		printf("%ls\n", wstr.c_str());
	}

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}