// �w�b�_�t�@�C���̃C���N���[�h
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "string_utility_cstring.h"	// �����񃆁[�e�B���e�B(C�����񏈗�)
}

// main�֐��̒�`
int main() {

	// �ϐ��̐錾�E�z��̏�����.
	wchar_t wbytes[] = { L'A', L'|', L'C', L'|', L'|' };
	int ret;
	int i;

	// �݂������S�Ă�u��.
	ret = replace_wbyte_all(wbytes, 5, L'|', L'\0');
	for (i = 0; i < 5; i++) {
		wprintf(L"wbytes[%d] = 0x%x\n", i, wbytes[i]);
	}
	wprintf(L"ret = %d\n", ret);

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}