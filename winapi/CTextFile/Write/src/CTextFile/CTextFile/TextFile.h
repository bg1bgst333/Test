// ��d�C���N���[�h�h�~
#ifndef __TEXT_FILE_H__
#define __TEXT_FILE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile

// �e�L�X�g�t�@�C���N���XCTextFile
class CTextFile : public CBinaryFile{

	// public�����o
	public:

		// public�����o�ϐ�
		tstring m_tstrText;		// �e�L�X�g���e.

		// public�����o�֐�
		void SetText(tstring tstrText);	// �e�L�X�g�̃Z�b�g.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.

};

#endif