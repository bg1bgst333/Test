// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile

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
BOOL CTextFile::ConvertShiftJisBytes(){

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

// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

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
		BOOL bRet = ConvertShiftJisBytes();	// ConvertShiftJisBytes��m_tstrText��Shift_JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		if (!bRet){	// ���s
			Close();	// ����.
			Clear();	// �o�b�t�@���N���A.
			return FALSE;	// FALSE��Ԃ�.
		}
	}
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Write�ŏ�������.
	Close();	// ����.
	Clear();	// �o�b�t�@���N���A.
	return bRet;	// bRet��Ԃ�.

}