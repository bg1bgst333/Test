// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "string_utility_cppstring.h"	// �����񃆁[�e�B���e�B(C++ std::string)

// tstring������target�̕���������before��S��after�ɒu��.
int replace_tstring_all(tstring& target, const tstring& before, const tstring& after) {

	// tstring�̕�����S�u��
	int c = 0;	// ��c��0�ŏ�����.
	tstring::size_type pos = target.find(before);	// target�ōŏ���before�����������ʒu��pos�Ɋi�[.
	while (pos != tstring::npos) {	// ������Ȃ����܂ő�����.
		c++;	// ��c��1���₷.
		target.replace(pos, before.size(), after);	// target��before����after�ɒu��.
		pos = target.find(before, pos + after.size());	// ����pos��T��.
	}
	return c;	// ��c��Ԃ�.

}