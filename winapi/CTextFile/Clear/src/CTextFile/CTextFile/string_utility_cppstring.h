// ��d�C���N���[�h�h�~
#ifndef __STRING_UTILITY_CPPSTRING_H__
#define __STRING_UTILITY_CPPSTRING_H__

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string>	// std::string

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �֐��̃v���g�^�C�v�錾
int replace_tstring_all(tstring &target, const tstring &before, const tstring &after);	// tstring������target�̕���������before��S��after�ɒu��.

#endif