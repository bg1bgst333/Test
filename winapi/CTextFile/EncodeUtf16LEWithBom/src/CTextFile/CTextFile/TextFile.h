// ��d�C���N���[�h�h�~
#ifndef __TEXT_FILE_H__
#define __TEXT_FILE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile

// �e�L�X�g�t�@�C���N���XCTextFile
class CTextFile : public CBinaryFile {

	// public�����o
	public:

		// �񋓌^�̒�`
		// �����R�[�h
		typedef enum TAG_ENCODING {
			ENCODING_NONE,
			ENCODING_SHIFT_JIS,
			ENCODING_UTF_16LE
		} ENCODING;
		// BOM
		typedef enum TAG_BOM {
			BOM_NONE,
			BOM_UTF16LE
		} BOM;

		// public�����o�ϐ�
		tstring m_tstrText;		// �e�L�X�g���e.
		ENCODING m_Encoding;	// �����R�[�h.
		BOM m_Bom;	// BOM.

		// public�����o�֐�
		void SetText(tstring tstrText);	// �e�L�X�g�̃Z�b�g.
		void EncodeUtf16LE();	// �e�L�X�g��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		void EncodeUtf16LEWithBom();	// �e�L�X�g��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		BOOL ConvertShiftJisBytes();	// �e�L�X�g��Shift_JIS�o�C�g��ɕϊ��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.

};

#endif