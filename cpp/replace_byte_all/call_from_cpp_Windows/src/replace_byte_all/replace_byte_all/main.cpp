// �w�b�_�t�@�C���̃C���N���[�h
extern "C"{	// C����Ƃ��ĉ��߂���.
	#include "string_utility_cstring.h"	// �����񃆁[�e�B���e�B(C�����񏈗�)
}

// main�֐��̒�`
int main(){

	// �z��̏�����.
	char bytes[] = {0xa, 0xd, 0, 0xd, 0xd};

	// �݂������S�Ă�u��.
	int ret = replace_byte_all(bytes, 5, 0xd, 0);
	for (int i = 0;  i < 5; i++){
		printf("bytes[%d] = 0x%x\n", i, bytes[i]);
	}
	printf("ret = %d\n", ret);

	// �v���O�����̏I��.
	return 0;

}