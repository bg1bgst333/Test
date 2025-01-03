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

		// �񋓌^�̒�`
		// �����R�[�h
		typedef enum TAG_ENCODING{
			ENCODING_NONE,
			ENCODING_SHIFT_JIS,
			ENCODING_UTF_16LE,
			ENCODING_UTF_16BE
		} ENCODING;
		// BOM
		typedef enum TAG_BOM{
			BOM_NONE,
			BOM_UTF16LE,
			BOM_UTF16BE
		} BOM;
		// ���s�R�[�h
		typedef enum TAG_NEW_LINE{
			NEW_LINE_NONE,
			NEW_LINE_CRLF,
			NEW_LINE_LF,
			NEW_LINE_CR
		} NEW_LINE;

		// public�����o�ϐ�
		tstring m_tstrText;		// �e�L�X�g���e.
		ENCODING m_Encoding;	// �����R�[�h.
		BOM m_Bom;	// BOM.
		NEW_LINE m_NewLine;	// ���s�R�[�h.

		// public�����o�֐�
		void SetText(tstring tstrText);	// �e�L�X�g�̃Z�b�g.
		void EncodeUtf16LE();	// �e�L�X�g��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		void EncodeUtf16LEWithBom();	// �e�L�X�g��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		void EncodeUtf16BE();	// �e�L�X�g��UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		void EncodeUtf16BEWithBom();	// �e�L�X�g��BOM�t��UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		BOOL EncodeShiftJis();	// �e�L�X�g��Shift_JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		void ConvertNewLine(NEW_LINE dest, NEW_LINE src);	// ���s�R�[�h�̕ϊ�.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
		BOM CheckBom();	// BOM�̃`�F�b�N.
		void DecodeUtf16LEWithBom();	// BOM�t��UTF-16LE�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
		void DecodeUtf16BEWithBom();	// BOM�t��UTF-16BE�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
		BOOL DecodeShiftJis();	// Shift_JIS�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
		NEW_LINE CheckNewLine();	// ���s�̃`�F�b�N.
		virtual BOOL Read(LPCTSTR lpctszFileName);	// �w��̃e�L�X�g�t�@�C����S����ēǂݍ���.
		virtual void Clear();	// �o�b�t�@�̃N���A.

};

#endif