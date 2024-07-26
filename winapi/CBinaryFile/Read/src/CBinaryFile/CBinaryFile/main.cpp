// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
// �Ǝ��̃w�b�_
#include "BinaryFile.h"		// CBinaryFile

// �\���̃^�Ostruct_tag_profile�̒�`.
struct struct_tag_profile {	// �ȈՖ���
	char name[32];	// ���O
	int age;	// �N��
	char address[128];	// �Z��
};

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR* argv[]) {	// main�֐���TCHAR��.

	// CBinaryFile�I�u�W�F�N�g�̐���l.
	CBinaryFile* pBinaryFile = new CBinaryFile();

	// �ǂݍ���.
	pBinaryFile->Read(_T("test.bin"));	// CBinaryFile::Read��"test.bin"����ǂݍ���.

	// �o��.
	printf("name: %s\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->name);
	printf("age: %d\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->age);
	printf("address: %s\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->address);

	// �N���A.
	pBinaryFile->Clear();	// CBinaryFile::Clear�Ńo�b�t�@���N���A.

	// ����.
	pBinaryFile->Close();	// CFile::Close�ŕ���.

	// �I������.
	delete pBinaryFile;

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}