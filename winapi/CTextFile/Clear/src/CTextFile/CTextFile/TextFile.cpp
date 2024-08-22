// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile
#include "string_utility_cppstring.h"	// �����񃆁[�e�B���e�B(C++�����񏈗�)

// �e�L�X�g�̃Z�b�g.
void CTextFile::SetText(tstring tstrText){

	// �����o�ɃZ�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���Z�b�g.

}

// �e�L�X�g��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16LE(){

	// UTF-16LE�o�C�g����o�b�t�@�ɃZ�b�g.
	Set((BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Set�ŕ�������o�b�t�@�ɃZ�b�g(UTF-16LE�Ȃ̂Œ�����2�{.)

}

// �e�L�X�g��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16LEWithBom(){

	// BOM�t��UTF-16LE�o�C�g����o�b�t�@�ɃZ�b�g.
	BYTE *pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ���C�h�����Ȃ̂�2�{ + BOM��2�o�C�g.
	pByteWithBOM[0] = 0xff;	// 0�Ԗڂ�0xff.
	pByteWithBOM[1] = 0xfe;	// 1�Ԗڂ�0xfe.
	memcpy(pByteWithBOM + 2, (BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// pByteWithBOM + 2�ȍ~�ɃR�s�[.
	Set(pByteWithBOM, (m_tstrText.length() + 1) * 2);	// pByteWithBOM���Z�b�g.(�T���Q�[�g�y�A�Ȃǔ�Ή�.)
	delete[] pByteWithBOM;	// delete��pByteWithBOM�����.

}

// �e�L�X�g��Shift_JIS�o�C�g��ɕϊ��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeShiftJis(){

	// Shift_JIS�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0){	// ���s.
		return FALSE;
	}
	BYTE *pBytes = new BYTE[iLen];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytes��0�Ŗ��߂�.
	iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, (char *)pBytes, iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0){	// ���s.
		delete [] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytes��iLen - 1���Z�b�g.
	delete [] pBytes;	// delete [] ��pBytes�����.
	return TRUE;
	
}

// ���s�R�[�h�̕ϊ�.
void CTextFile::ConvertNewLine(NEW_LINE dest, NEW_LINE src){

	// ���s�R�[�h��u��������.
	tstring before;	// �u���Obefore.
	if (src == CTextFile::NEW_LINE_CRLF){	// CRLF
		before = _T("\r\n");	// before��"\r\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_LF){	// LF
		before = _T("\n");	// before��"\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_CR){	// CR
		before = _T("\r");	// before��"\r"���Z�b�g.
	}
	tstring after;	// �u����after.
	if (dest == CTextFile::NEW_LINE_CRLF){	// CRLF
		after = _T("\r\n");	// after��"\r\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_LF){	// LF
		after = _T("\n");	// after��"\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_CR){	// CR
		after = _T("\r");	// after��"\r"���Z�b�g.
	}
	if (before != after){	// before��after���Ⴄ��.
		replace_tstring_all(m_tstrText, before, after);	// replace_tstring_all�Œu��.
	}

}

// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// ���s�R�[�h�̃`�F�b�N.(CRLF�Ȃ�ύX���Ȃ�.)
	if (m_NewLine == NEW_LINE_CR){	// CR.
		ConvertNewLine(NEW_LINE_CR, NEW_LINE_CRLF);	// ConverNewLine��CRLF����CR�ɕϊ�.
	}
	else if (m_NewLine == NEW_LINE_LF){	// LF.
		ConvertNewLine(NEW_LINE_LF, NEW_LINE_CRLF);	// ConverNewLine��CRLF����LF�ɕϊ�.
	}

	// �����R�[�h�𔻒f���ď�������.
	if (m_Encoding == CTextFile::ENCODING_UTF_16LE){	// UTF-16LE�Ȃ�.
		// BOM�̗L���𔻒f���ď�������.
		if (m_Bom == CTextFile::BOM_UTF16LE){	// UTF-16LE��BOM�Ȃ�.
			EncodeUtf16LEWithBom();	// EncodeUtf16LEWithBom��m_tstrText��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
		else{	// BOM�����Ȃ�.
			EncodeUtf16LE();	// EncodeUtf16LE��m_tstrText��BOM����UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
	}
	else{	// ����ȊO.
		// �ŏI�I��Shift_JIS�ɂ���.
		BOOL bRet = EncodeShiftJis();	// EncodeShiftJis��m_tstrText��Shift_JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		if (!bRet){	// ���s
			Close();	// ����.
			Clear();	// �o�b�t�@���N���A.
			return FALSE;	// FALSE��Ԃ�.
		}
	}

	// ��������.
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Write�ŏ�������.
	Close();	// ����.
	Clear();	// �o�b�t�@���N���A.
	return bRet;	// bRet��Ԃ�.

}

// �w��̃e�L�X�g�t�@�C����S����ēǂݍ���.
BOOL CTextFile::Read(LPCTSTR lpctszFileName){

	// �t�@�C�������.
	Close();

	// �o�b�t�@�̃N���A.
	Clear();

	// �w�肳�ꂽ�t�@�C�����̃t�@�C����ǂݍ���.
	BOOL bRet = CBinaryFile::Read(lpctszFileName);

	// bRet��Ԃ�.
	return bRet;

}

// �o�b�t�@�̃N���A.
void CTextFile::Clear(){

	// �����o�̏I������.
	m_tstrText.clear();	// �N���A.
	m_Encoding = ENCODING_NONE;	// �G���R�[�h����.
	m_Bom = BOM_NONE;	// BOM����.

	// �e�N���X��Clear���Ă�.
	CBinaryFile::Clear();	// �o�b�t�@�N���A.

}