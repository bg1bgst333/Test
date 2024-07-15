// �w�b�_�t�@�C���̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
// �Ǝ��̃w�b�_
#include "File.h"		// CFile

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR* argv[]) {	// main�֐���TCHAR��.

	// CFile�I�u�W�F�N�g�̐���.
	CFile* pFile = new CFile();
	BOOL bRet = pFile->Open(_T("test.txt"), GENERIC_READ, OPEN_EXISTING);	// CFile::Open��"test.txt"��ǂݍ��݃��[�h�ŊJ��.
	if (bRet) {	// ����.

		// �����̃��b�Z�[�W�\��.
		printf("CFile::Open(test.txt) Success!\n");

		// �t�@�C���T�C�Y�̎擾.
		DWORD dwSize = pFile->GetFileSize();	// CFile::GetFileSize�Ńt�@�C���T�C�Y�擾.

		// ���e�̓ǂݍ���.
		BYTE* pbtBytes = new BYTE[dwSize + 1];
		ZeroMemory(pbtBytes, dwSize + 1);
		pFile->Read(pbtBytes, dwSize);	// CFile::Read��dwSize�ǂݍ���.
		printf("pbtBytes = %s\n", (char*)pbtBytes);
		delete[] pbtBytes;

	}

	// CFile�I�u�W�F�N�g�̔j��.
	delete pFile;

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��Đ���I��.

}