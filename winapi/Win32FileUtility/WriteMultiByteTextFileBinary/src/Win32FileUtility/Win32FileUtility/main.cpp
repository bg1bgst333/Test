// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Win32FileUtility.h"	// Win32�t�@�C�����[�e�B���e�B

// main�֐��̒�`
int main(){

	// �ϐ��̐錾
	DWORD dwLen;	// �������񂾒���dwLen.

	// UTF-8(BOM�Ȃ�)��������.
	WriteMultiByteTextFileBinary("test1.txt", L"����������\r\n����������\r\n����������", CP_UTF8, &dwLen);

	// Shift_JIS��������.
	WriteMultiByteTextFileBinary("test2.txt", L"����������\r\n����������\r\n����������", CP_ACP, &dwLen);

	// EUC-JP(20932)��������.
	WriteMultiByteTextFileBinary("test3.txt", L"����������\r\n����������\r\n����������", 20932, &dwLen);

	// ISO-2022-JP(JIS)(50220)��������.
	WriteMultiByteTextFileBinary("test4.txt", L"����������\r\n����������\r\n����������", 50220, &dwLen);

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}