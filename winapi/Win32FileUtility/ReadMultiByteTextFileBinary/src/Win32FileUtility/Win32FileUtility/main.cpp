// �w�b�_�̃C���N���[�h
// ����̃w�b�_�t�@�C��
#include <locale.h>	// ���P�[��
// �Ǝ��̃w�b�_
#include "Win32FileUtility.h"	// Win32�t�@�C�����[�e�B���e�B

// main�֐��̒�`
int main(){

	// �ϐ��̐錾
	DWORD dwLen;	// �������񂾒���dwLen.

	// ���P�[���Z�b�g.
	setlocale(LC_ALL, "Japanese_Japan.932");

	// UTF-8(BOM�Ȃ�)�ǂݍ���.
	std::wstring wstr1;
	ReadMultiByteTextFileBinary("test1.txt", wstr1, CP_UTF8, &dwLen);
	printf("wstr1 = %ls\n", wstr1.c_str());

	// Shift_JIS�ǂݍ���.
	std::wstring wstr2;
	ReadMultiByteTextFileBinary("test2.txt", wstr2, CP_ACP, &dwLen);
	printf("wstr2 = %ls\n", wstr2.c_str());

	// EUC-JP(20932)�ǂݍ���.
	std::wstring wstr3;
	ReadMultiByteTextFileBinary("test3.txt", wstr3, 20932, &dwLen);
	printf("wstr3 = %ls\n", wstr3.c_str());

	// ISO-2022-JP(JIS)(50220)�ǂݍ���.
	std::wstring wstr4;
	ReadMultiByteTextFileBinary("test4.txt", wstr4, 50220, &dwLen);
	printf("wstr4 = %ls\n", wstr4.c_str());

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}