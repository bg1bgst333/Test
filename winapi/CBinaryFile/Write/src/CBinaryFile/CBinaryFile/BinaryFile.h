// ��d�C���N���[�h�h�~
#ifndef __BINARY_FILE_H__
#define __BINARY_FILE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "File.h"	// CFile

// �o�C�i���t�@�C��CBinaryFile
class CBinaryFile : public CFile{

	// public�����o
	public:
	
		// public�����o�ϐ�
		BYTE *m_pBytes;	// �o�C�g��ւ̃|�C���^.
		DWORD m_dwSize;	// �t�@�C���T�C�Y.

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �w��̃o�C�i���t�@�C���ɑS����ď�������.
		virtual void Set(BYTE *pBytes, DWORD dwSize);	// �S����Ăɏ������ރo�b�t�@�̃Z�b�g.

};

#endif
