// �w�b�_�t�@�C���̃C���N���[�h
// �Ǝ��̃w�b�_�t�@�C��
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}
#include "Win32FileUtility.h"	// Win32�t�@�C�����[�e�B���e�B

// main�֐��̒�`
int main() {

	// �ϐ��̐錾
	DWORD dwLen;	// �������񂾒���dwLen.

	// test.txt��UTF-8��BOM����������.
	write_file_bom_utf8("test.txt");	// write_file_bom_utf8��test.txt��UTF-8��BOM����������.

	// UTF-8(BOM�Ȃ�)��������.
	AppendMultiByteTextFileBinary("test.txt", L"����������\r\n����������\r\n����������", CP_UTF8, &dwLen);

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}