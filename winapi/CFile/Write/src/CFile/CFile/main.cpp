// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
// �Ǝ��̃w�b�_
#include "File.h"		// CFile

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// CFile�I�u�W�F�N�g�̐���.
	CFile *pFile = new CFile();
	BOOL bRet = pFile->Open(_T("test.txt"), GENERIC_WRITE, CREATE_ALWAYS);	// CFile::Open��"test.txt"���������݃��[�h�ŊJ��.
	if (bRet){	// ����.

		// �����̃��b�Z�[�W�\��.
		printf("CFile::Open(test.txt) Success!\n");

		// �e�L�X�g�̏�������.
		pFile->Write((LPVOID)"ABCDE", 5);	// CFile::Write��"ABCDE"����������.

	}

	// CFile�I�u�W�F�N�g�̔j��.
	delete pFile;

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}