// ��d�C���N���[�h�h�~
#ifndef __BINARY_FILE_H__
#define __BINARY_FILE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "File.h"	// CFile

// �o�C�i���t�@�C��CBinaryFile
class CBinaryFile : public CFile {

	// public�����o
	public:

		// public�����o�ϐ�
		BYTE* m_pBytes;	// �o�C�g��ւ̃|�C���^.
		DWORD m_dwSize;	// �t�@�C���T�C�Y.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBinaryFile();	// �R���X�g���N�^CBinaryFile
		virtual ~CBinaryFile();	// �f�X�g���N�^~CBinaryFile
		// �����o�֐�
		virtual BOOL Read(LPCTSTR lpctszFileName);	// �w��̃o�C�i���t�@�C������S����ēǂݍ���.
		virtual BOOL Read(LPCTSTR lpctszFileName, DWORD dwPos, DWORD dwSize);	// �w��̃o�C�i���t�@�C�����w��̈ʒu����w��T�C�Y�ǂݍ���.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �w��̃o�C�i���t�@�C���ɑS����ď�������.
		virtual BOOL Write();	// �J���Ă���o�C�i���t�@�C���ւ̒ǉ���������.
		virtual void Set(BYTE* pBytes, DWORD dwSize);	// �S����Ăɏ������ރo�b�t�@�̃Z�b�g.
		virtual void Clear();	// �o�b�t�@�̃N���A.

};

#endif