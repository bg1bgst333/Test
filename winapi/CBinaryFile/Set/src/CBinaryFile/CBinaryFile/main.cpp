// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
// �Ǝ��̃w�b�_
#include "BinaryFile.h"		// CBinaryFile

// �\���̃^�Ostruct_tag_profile�̒�`.
struct struct_tag_profile{	// �ȈՖ���
	char name[32];	// ���O
	int age;	// �N��
	char address[128];	// �Z��
};

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �\���̕ϐ��̐錾
	struct struct_tag_profile prof;	// struct_tag_profile�^�\���̕ϐ�prof.

	// CBinaryFile�I�u�W�F�N�g�̐���l.
	CBinaryFile *pBinaryFile = new CBinaryFile();
	
	// �l�̃Z�b�g.
	strcpy(prof.name, "Taro");
	prof.age = 21;
	strcpy(prof.address, "Tokyo");
	pBinaryFile->Set((BYTE *)&prof, sizeof(prof));	// CBinaryFile::Set�Ńo�C�i���ƃT�C�Y���Z�b�g.

	// �I������.
	delete pBinaryFile;

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}