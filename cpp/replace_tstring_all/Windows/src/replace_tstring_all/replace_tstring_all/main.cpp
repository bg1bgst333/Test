// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>	// TCHAR�^
#include <iostream>	// C++�W�����o��
// �Ǝ��̃w�b�_
#include "string_utility_cppstring.h"	// �����񃆁[�e�B���e�B(C++ std::string)

// main�֐��̒�`
int main() {

	// �I�u�W�F�N�g�̐錾
	tstring target = _T("AAAabcBBBabcCCCabc");	// �Ώ�
	tstring before = _T("abc");	// �ϊ��O
	tstring after = _T("xyz");	// �ϊ���

	// �݂������S�Ă�u��.
	int c = replace_tstring_all(target, before, after);	// replace_tstring_all�őS�Ēu��.
	std::wcout << _T("target = ") << target << std::endl;	// target���o��.
	std::wcout << _T("c = ") << c << std::endl;	// c���o��.

	// �v���O�����̏I��
	return 0;	// 0��Ԃ��Đ���I��.

}