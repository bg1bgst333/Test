// �w�b�_�t�@�C���̃C���N���[�h
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�W�����o��)
}

// main�֐�
int main() {

	// �ϐ��̐錾
	int ret;	// int�^�ϐ�ret.

	// test1.txt��UTF-16BE��BOM�����邩���肷��.
	ret = is_file_bom_utf16be("test1.txt");	// is_file_bom_utf16be��"test1.txt"��UTF-16BE��BOM�����邩���肷��.
	if (ret == 1) {	// ret��1.
		printf("UTF-16BE\n");	// "UTF-16BE"�Əo��.
	}
	else {	// ret��0.
		printf("Not UTF-16BE\n");	// "Not UTF-16BE"�Əo��.
	}


	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}