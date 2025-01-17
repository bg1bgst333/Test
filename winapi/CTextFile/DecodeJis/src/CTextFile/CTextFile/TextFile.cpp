// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile
#include "string_utility_cppstring.h"	// �����񃆁[�e�B���e�B(C++�����񏈗�)
#include "file_utility_cstdio.h"	// �t�@�C�����[�e�B���e�B(C�t�@�C������)

// �e�L�X�g�̃Z�b�g.
void CTextFile::SetText(tstring tstrText) {

	// �����o�ɃZ�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���Z�b�g.

}

// �e�L�X�g��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16LE() {

	// UTF-16LE�o�C�g����o�b�t�@�ɃZ�b�g.
	Set((BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Set�ŕ�������o�b�t�@�ɃZ�b�g(UTF-16LE�Ȃ̂Œ�����2�{.)

}

// �e�L�X�g��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16LEWithBom() {

	// BOM�t��UTF-16LE�o�C�g����o�b�t�@�ɃZ�b�g.
	BYTE* pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ���C�h�����Ȃ̂�2�{ + BOM��2�o�C�g.
	pByteWithBOM[0] = 0xff;	// 0�Ԗڂ�0xff.
	pByteWithBOM[1] = 0xfe;	// 1�Ԗڂ�0xfe.
	memcpy(pByteWithBOM + 2, (BYTE*)m_tstrText.c_str(), m_tstrText.length() * 2);	// pByteWithBOM + 2�ȍ~�ɃR�s�[.
	Set(pByteWithBOM, (m_tstrText.length() + 1) * 2);	// pByteWithBOM���Z�b�g.(�T���Q�[�g�y�A�Ȃǔ�Ή�.)
	delete[] pByteWithBOM;	// delete��pByteWithBOM�����.

}

// �e�L�X�g��UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16BE() {

	// �o�C�g������ւ���.
	BYTE* pByte = new BYTE[m_tstrText.length() * 2];
	convert_endian_16bit_byte_array((char*)m_tstrText.c_str(), (char*)pByte, m_tstrText.length() * 2);
	Set(pByte, m_tstrText.length() * 2);
	delete[] pByte;

}

// �e�L�X�g��BOM�t��UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
void CTextFile::EncodeUtf16BEWithBom() {

	// BOM�t��UTF-16BE�o�C�g����o�b�t�@�ɃZ�b�g.
	BYTE* pByteWithBOM = new BYTE[m_tstrText.length() * 2 + 2];	// ���C�h�����Ȃ̂�2�{ + BOM��2�o�C�g.
	pByteWithBOM[0] = 0xfe;	// 0�Ԗڂ�0xfe.
	pByteWithBOM[1] = 0xff;	// 1�Ԗڂ�0xff.
	convert_endian_16bit_byte_array((char*)m_tstrText.c_str(), (char*)pByteWithBOM + 2, m_tstrText.length() * 2);
	Set(pByteWithBOM, m_tstrText.length() * 2 + 2);
	delete[] pByteWithBOM;

}

// �e�L�X�g��UTF-8�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeUtf8() {

	// UTF-8�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytes��0�Ŗ��߂�.
	iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytes��iLen - 1���Z�b�g.
	delete[] pBytes;	// delete [] ��pBytes�����.
	return TRUE;

}

// �e�L�X�g��BOM�t��UTF-8�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeUtf8WithBom() {

	// BOM�t��UTF-8�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen + 3];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes + 3, sizeof(BYTE) * iLen);	// pBytes + 3�̈ʒu����0�Ŗ��߂�.
	iLen = WideCharToMultiByte(CP_UTF8, 0, m_tstrText.c_str(), -1, (char*)(pBytes + 3), iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	pBytes[0] = 0xef;	// BOM1������(0xEF)
	pBytes[1] = 0xbb;	// BOM2������(0xBB)
	pBytes[2] = 0xbf;	// BOM3������(0xBF)
	Set(pBytes, iLen - 1 + 3);	// pBytes��iLen - 1 + 3���Z�b�g.
	delete[] pBytes;	// delete [] ��pBytes�����.
	return TRUE;

}

// �e�L�X�g��Shift_JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeShiftJis() {

	// Shift_JIS�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytes��0�Ŗ��߂�.
	iLen = WideCharToMultiByte(CP_ACP, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytes��iLen - 1���Z�b�g.
	delete[] pBytes;	// delete [] ��pBytes�����.
	return TRUE;

}

// �e�L�X�g��EUC-JP�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeEucJp() {

	// EUC-JP�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(20932, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytes��0�Ŗ��߂�.
	iLen = WideCharToMultiByte(20932, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytes��iLen - 1���Z�b�g.
	delete[] pBytes;	// delete [] ��pBytes�����.
	return TRUE;

}

// �e�L�X�g��JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
BOOL CTextFile::EncodeJis() {

	// JIS�o�C�g����o�b�t�@�ɃZ�b�g.
	int iLen = WideCharToMultiByte(50220, 0, m_tstrText.c_str(), -1, NULL, 0, NULL, NULL);	// �ϊ��ɕK�v�ȃo�b�t�@�̒������擾.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	BYTE* pBytes = new BYTE[iLen];	// �o�C�g����i�[����z��pBytes.
	ZeroMemory(pBytes, sizeof(BYTE) * iLen);	// pBytes��0�Ŗ��߂�.
	iLen = WideCharToMultiByte(50220, 0, m_tstrText.c_str(), -1, (char*)pBytes, iLen, NULL, NULL);	// ���C�h��������}���`�o�C�g�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] pBytes;	// delete [] ��pBytes�����.
		return FALSE;
	}
	Set(pBytes, iLen - 1);	// pBytes��iLen - 1���Z�b�g.
	delete[] pBytes;	// delete [] ��pBytes�����.
	return TRUE;

}

// ���s�R�[�h�̕ϊ�.
void CTextFile::ConvertNewLine(NEW_LINE dest, NEW_LINE src) {

	// ���s�R�[�h��u��������.
	tstring before;	// �u���Obefore.
	if (src == CTextFile::NEW_LINE_CRLF) {	// CRLF
		before = _T("\r\n");	// before��"\r\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_LF) {	// LF
		before = _T("\n");	// before��"\n"���Z�b�g.
	}
	else if (src == CTextFile::NEW_LINE_CR) {	// CR
		before = _T("\r");	// before��"\r"���Z�b�g.
	}
	tstring after;	// �u����after.
	if (dest == CTextFile::NEW_LINE_CRLF) {	// CRLF
		after = _T("\r\n");	// after��"\r\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_LF) {	// LF
		after = _T("\n");	// after��"\n"���Z�b�g.
	}
	else if (dest == CTextFile::NEW_LINE_CR) {	// CR
		after = _T("\r");	// after��"\r"���Z�b�g.
	}
	if (before != after) {	// before��after���Ⴄ��.
		replace_tstring_all(m_tstrText, before, after);	// replace_tstring_all�Œu��.
	}

}

// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
BOOL CTextFile::Write(LPCTSTR lpctszFileName) {

	// ���s�R�[�h�̃`�F�b�N.(CRLF�Ȃ�ύX���Ȃ�.)
	if (m_NewLine == NEW_LINE_CR) {	// CR.
		ConvertNewLine(NEW_LINE_CR, NEW_LINE_CRLF);	// ConverNewLine��CRLF����CR�ɕϊ�.
	}
	else if (m_NewLine == NEW_LINE_LF) {	// LF.
		ConvertNewLine(NEW_LINE_LF, NEW_LINE_CRLF);	// ConverNewLine��CRLF����LF�ɕϊ�.
	}

	// �����R�[�h�𔻒f���ď�������.
	if (m_Encoding == CTextFile::ENCODING_UTF_16LE) {	// UTF-16LE�Ȃ�.
		// BOM�̗L���𔻒f���ď�������.
		if (m_Bom == CTextFile::BOM_UTF16LE) {	// UTF-16LE��BOM�Ȃ�.
			EncodeUtf16LEWithBom();	// EncodeUtf16LEWithBom��m_tstrText��BOM�t��UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
		else {	// BOM�����Ȃ�.
			EncodeUtf16LE();	// EncodeUtf16LE��m_tstrText��BOM����UTF-16LE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_UTF_16BE) {	// UTF-16BE�Ȃ�.
		// BOM�̗L���𔻒f���ď�������.
		if (m_Bom == CTextFile::BOM_UTF16BE) {	// UTF-16BE��BOM�Ȃ�.
			EncodeUtf16BEWithBom();	// EncodeUtf16BEWithBom��m_tstrText��BOM�t��UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
		else {	// BOM�����Ȃ�.
			EncodeUtf16BE();	// EncodeUtf16BE��m_tstrText��BOM����UTF-16BE�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_UTF_8) {	// UTF-8�Ȃ�.
		// BOM�̗L���𔻒f���ď�������.
		if (m_Bom == CTextFile::BOM_UTF8) {	// UTF-8��BOM�Ȃ�.
			BOOL bRet = EncodeUtf8WithBom();	// EncodeUtf8WithBom��m_tstrText��BOM�t��UTF-8�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
			if (!bRet) {	// ���s
				Close();	// ����.
				Clear();	// �o�b�t�@���N���A.
				return FALSE;	// FALSE��Ԃ�.
			}
		}
		else {	// BOM�����Ȃ�.
			BOOL bRet = EncodeUtf8();	// EncodeUtf8��m_tstrText��UTF-8�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
			if (!bRet) {	// ���s
				Close();	// ����.
				Clear();	// �o�b�t�@���N���A.
				return FALSE;	// FALSE��Ԃ�.
			}
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_SHIFT_JIS) {	// Shift_JIS�Ȃ�.
		// Shift_JIS�ɂ���.
		BOOL bRet = EncodeShiftJis();	// EncodeShiftJis��m_tstrText��Shift_JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		if (!bRet) {	// ���s
			Close();	// ����.
			Clear();	// �o�b�t�@���N���A.
			return FALSE;	// FALSE��Ԃ�.
		}
	}
	else if (m_Encoding == CTextFile::ENCODING_EUC_JP) {	// EUC-JP�Ȃ�.
		// EUC-JP�ɂ���.
		BOOL bRet = EncodeEucJp();	// EncodeEucJp��m_tstrText��EUC-JP�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		if (!bRet) {	// ���s
			Close();	// ����.
			Clear();	// �o�b�t�@���N���A.
			return FALSE;	// FALSE��Ԃ�.
		}
	}
	else {	// ����ȊO.
		// �ŏI�I��JIS�ɂ���.
		BOOL bRet = EncodeJis();	// EncodeJis��m_tstrText��JIS�o�C�g��ɕϊ����ăo�b�t�@�ɃZ�b�g.
		if (!bRet) {	// ���s
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

// BOM�̃`�F�b�N.
CTextFile::BOM CTextFile::CheckBom() {

	// BOM�̔���.
	if (m_dwSize >= 3 && m_pBytes[0] == 0xef && m_pBytes[1] == 0xbb && m_pBytes[2] == 0xbf) {	// UTF-8�̏ꍇ.
		m_Bom = BOM_UTF8;	// BOM_UTF8���Z�b�g.
	}
	else if (m_dwSize >= 2 && m_pBytes[0] == 0xff && m_pBytes[1] == 0xfe) {	// UTF-16LE�̏ꍇ.
		m_Bom = BOM_UTF16LE;	// BOM_UTF16LE���Z�b�g.
	}
	else if (m_dwSize >= 2 && m_pBytes[0] == 0xfe && m_pBytes[1] == 0xff) {	// UTF-16BE�̏ꍇ.
		m_Bom = BOM_UTF16BE;	// BOM_UTF16BE���Z�b�g.
	}
	else {	// ����ȊO��BOM�Ȃ�.
		m_Bom = BOM_NONE;	// BOM_NONE���Z�b�g.
	}
	return m_Bom;	// m_Bom��Ԃ�.

}

// BOM�t��UTF-16LE�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
void CTextFile::DecodeUtf16LEWithBom() {

	// BOM�t��UTF-16LE�`���̃o�C�g���tstring�ɕϊ�.
	int iWithOutBom = m_dwSize - 2;	// BOM2�o�C�g��������.
	if (iWithOutBom <= 0) {	// 0�o�C�g�ȉ�.
		m_tstrText = _T("");	// �󕶎���ɂȂ�.
	}
	else {	// 1�����ȏ�(2�o�C�g�ȏ�ŕK�������o�C�g.)�͂���.
		TCHAR* ptszText = new TCHAR[iWithOutBom / 2 + 1];	// iWithOutBom��0�ȏ�̋����ɂȂ�.
		wmemset(ptszText, _T('\0'), iWithOutBom / 2 + 1);	// wmemset��ptszText��_T('\0')�Ŗ��߂�.
		wmemcpy(ptszText, ((wchar_t*)m_pBytes) + 1, iWithOutBom / 2);	// 1����(2�o�C�g��)��납��(iWithOutBom / 2)�̕��R�s�[.
		m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
		delete[] ptszText;	// delete[]��ptsztext�����.
	}

}

// BOM�t��UTF-16BE�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
void  CTextFile::DecodeUtf16BEWithBom() {

	// BOM�t��UTF-16BE�`���̃o�C�g���tstring�ɕϊ�.
	int iWithOutBom = m_dwSize - 2;	// BOM2�o�C�g��������.
	if (iWithOutBom <= 0) {	// 0�o�C�g�ȉ�.
		m_tstrText = _T("");	// �󕶎���ɂȂ�.
	}
	else {	// 1�����ȏ�(2�o�C�g�ȏ�ŕK�������o�C�g.)�͂���.
		BYTE* pReversed = new BYTE[m_dwSize];	// ����ւ����o�C�g��p�������m��.
		convert_endian_16bit_byte_array((const char*)m_pBytes, (char*)pReversed, m_dwSize);	// �G���f�B�A������ւ�.
		TCHAR* ptszText = new TCHAR[iWithOutBom / 2 + 1];	// iWithOutBom��0�ȏ�̋����ɂȂ�.
		wmemset(ptszText, _T('\0'), iWithOutBom / 2 + 1);	// wmemset��ptszText��_T('\0')�Ŗ��߂�.
		wmemcpy(ptszText, ((wchar_t*)pReversed) + 1, iWithOutBom / 2);	// 1����(2�o�C�g��)��납��(iWithOutBom / 2)�̕��R�s�[.
		m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
		delete[] ptszText;	// delete[]��ptsztext�����.
		delete[] pReversed;	// delete[]��pReversed�����.
	}

}

// BOM�t��UTF-8�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
BOOL CTextFile::DecodeUtf8WithBom() {

	// BOM�t��UTF-8�o�C�g����e�L�X�g�ɕϊ�.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)(m_pBytes + 3), -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���iLen�����߂�.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLen�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), iLen);	// wmemset��ptszText��_T('0')�Ŗ��߂�.
	iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)(m_pBytes + 3), -1, ptszText, iLen);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] ptszText;	// delete [] ��ptszText�����.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete[] ptszText;	// delete [] ��ptszText�����.
	return TRUE;

}

// Shift_JIS�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
BOOL CTextFile::DecodeShiftJis() {

	// Shift_JIS�o�C�g����e�L�X�g�ɕϊ�.
	int iLen = MultiByteToWideChar(CP_ACP, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���iLen�����߂�.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLen�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), iLen);	// wmemset��ptszText��_T('0')�Ŗ��߂�.
	iLen = MultiByteToWideChar(CP_ACP, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] ptszText;	// delete [] ��ptszText�����.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete[] ptszText;	// delete [] ��ptszText�����.
	return TRUE;

}

// UTF-8�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
BOOL CTextFile::DecodeUtf8() {

	// UTF-8�o�C�g����e�L�X�g�ɕϊ�.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���iLen�����߂�.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLen�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), iLen);	// wmemset��ptszText��_T('0')�Ŗ��߂�.
	iLen = MultiByteToWideChar(CP_UTF8, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] ptszText;	// delete [] ��ptszText�����.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete[] ptszText;	// delete [] ��ptszText�����.
	return TRUE;

}

// EUC-JP�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
BOOL CTextFile::DecodeEucJp() {

	// EUC-JP�o�C�g����e�L�X�g�ɕϊ�.
	int iLen = MultiByteToWideChar(20932, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���iLen�����߂�.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLen�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), iLen);	// wmemset��ptszText��_T('0')�Ŗ��߂�.
	iLen = MultiByteToWideChar(20932, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] ptszText;	// delete [] ��ptszText�����.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete[] ptszText;	// delete [] ��ptszText�����.
	return TRUE;

}

// JIS�̃o�C�g����e�L�X�g�Ƀf�R�[�h.
BOOL CTextFile::DecodeJis() {

	// JIS�o�C�g����e�L�X�g�ɕϊ�.
	int iLen = MultiByteToWideChar(50220, 0, (char*)m_pBytes, -1, NULL, NULL);	// MultiByteToWideChar�Ńo�C�g��̕ϊ��ɕK�v�ȃo�b�t�@�̒���iLen�����߂�.
	if (iLen <= 0) {	// ���s.
		return FALSE;
	}
	TCHAR* ptszText = new TCHAR[iLen];	// iLen�̕���TCHAR���I�z���p�ӂ�, �|�C���^��ptszText�Ɋi�[.
	wmemset(ptszText, _T('\0'), iLen);	// wmemset��ptszText��_T('0')�Ŗ��߂�.
	iLen = MultiByteToWideChar(50220, 0, (char*)m_pBytes, -1, ptszText, iLen);	// MultiByteToWideChar�Ń}���`�o�C�g�������烏�C�h�����ւ̕ϊ�.
	if (iLen <= 0) {	// ���s.
		delete[] ptszText;	// delete [] ��ptszText�����.
		return FALSE;
	}
	m_tstrText = ptszText;	// m_tstrText��ptszText���Z�b�g.
	delete[] ptszText;	// delete [] ��ptszText�����.
	return TRUE;

}

// UTF-8���ǂ������肷��.
BOOL CTextFile::IsUtf8(const unsigned char* lpcszStr, size_t uiLen) {

	// UTF-8�̕����R�[�h�͈͂Ɋ�Â���1�������`�F�b�N.
	size_t i = 0;
	while (i < uiLen) {
		if ((lpcszStr[i] & 0x80) == 0) {	// 1�o�C�g����.(ASCII)
			i++;	// 1�i��.
		}
		else if ((lpcszStr[i] & 0xe0) == 0xc0) {	// 2�o�C�g����.
			if (i + 1 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80) {
				return FALSE;	// �͈͊O.
			}
			i += 2;	// 2�i��.
		}
		else if ((lpcszStr[i] & 0xf0) == 0xe0) {	// 3�o�C�g����.
			if (i + 2 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80 || (lpcszStr[i + 2] & 0xc0) != 0x80) {
				return FALSE;	// �͈͊O.
			}
			i += 3;	// 3�i��.
		}
		else if ((lpcszStr[i] & 0xf8) == 0xf0) {	// 4�o�C�g����.
			if (i + 3 >= uiLen || (lpcszStr[i + 1] & 0xc0) != 0x80 || (lpcszStr[i + 2] & 0xc0) != 0x80 || (lpcszStr[i + 3] & 0xc0) != 0x80) {
				return FALSE;	// �͈͊O.
			}
			i += 4;	// 4�i��.
		}
		else {	// ����ȊO.
			return FALSE;	// �͈͊O.
		}
	}
	return TRUE;	// �S�Ĕ͈͓�.

}

// Shift_JIS���ǂ������肷��.
BOOL CTextFile::IsShiftJis(const unsigned char* lpcszStr, size_t uiLen) {

	// Shift_JIS�̕����R�[�h�͈͂Ɋ�Â���1�������`�F�b�N.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] <= 0x7f) {	// 1�o�C�g����.(ASCII)
			i++;	// 1�i��.
		}
		else if (lpcszStr[i] >= 0x81 && lpcszStr[i] <= 0x9f) {	// Shift_JIS�m��.
			if (i + 1 >= uiLen) {
				return FALSE;	// ����.
			}
			unsigned char next = lpcszStr[i + 1];
			if ((next >= 0x40 && next <= 0x7e) || (next >= 0x80 && next <= 0xfc)) {	//	2�o�C�g�ڂ�Shift_JIS�͈̔�.
				i += 2;	// 2�i��.
			}
			else {
				return FALSE;	// �͈͊O.
			}
		}
		else if (lpcszStr[i] >= 0xa1 && lpcszStr[i] <= 0xfe) {	// ���m��.
			if (i + 1 >= uiLen) {
				return FALSE;	// ����.
			}
			unsigned char next = lpcszStr[i + 1];
			if (next >= 0xa1 && next <= 0xfe) {	// EUC-JP��2�o�C�g�ڂȂ̂Ŗ���.
				return FALSE;
			}
			else if ((next >= 0x40 && next <= 0x7e) || (next >= 0x80 && next <= 0xfc)) {	//	2�o�C�g�ڂ�Shift_JIS�͈̔�.
				i += 2;	// 2�i��.
			}
			else {
				return FALSE;	// �͈͊O.
			}
		}
		else {	// ����ȊO.
			return FALSE;	// �͈͊O.
		}
	}
	return TRUE;	// �S�Ĕ͈͓�.

}

// EUC-JP���ǂ������肷��.
BOOL CTextFile::IsEucJp(const unsigned char* lpcszStr, size_t uiLen) {

	// EUC-JP�̕����R�[�h�͈͂Ɋ�Â���1�������`�F�b�N.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] <= 0x7f) {	// 1�o�C�g����.(ASCII)
			i++;	// 1�i��.
		}
		else if (lpcszStr[i] == 0x8e) {	// 2�o�C�g����.(���p�J�^�J�i)
			if (i + 1 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xdf)) {
				return FALSE;
			}
			i += 2;
		}
		else if (lpcszStr[i] == 0x8f) {	// 3�o�C�g����.(JIS�⏕����)
			if (i + 2 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xfe) || (lpcszStr[i + 2] < 0xa1 || lpcszStr[i + 2] > 0xfe)) {
				return FALSE;
			}
			i += 3;
		}
		else if (lpcszStr[i] >= 0xa1 && lpcszStr[i] <= 0xfe) {	// 2�o�C�g����.(�S�p)
			if (i + 1 >= uiLen || (lpcszStr[i + 1] < 0xa1 || lpcszStr[i + 1] > 0xfe)) {
				return FALSE;
			}
			i += 2;
		}
		else {
			return FALSE;	// �͈͊O.
		}
	}
	return TRUE;	// �S�Ĕ͈͓�.

}

// JIS���ǂ������肷��.
BOOL CTextFile::IsJis(const unsigned char* lpcszStr, size_t uiLen) {

	// JIS�̕����R�[�h�͈͂Ɋ�Â���1�������`�F�b�N.
	size_t i = 0;
	while (i < uiLen) {
		if (lpcszStr[i] == 0x1b) {	// �G�X�P�[�v�����̌��o.
			if (i + 2 >= uiLen) {
				return FALSE;	// ����.
			}
			if ((lpcszStr[i + 1] == '(' && (lpcszStr[i + 2] == 'B' || lpcszStr[i + 2] == 'J'))
				|| (lpcszStr[i + 1] == '$' && (lpcszStr[i + 2] == '@' || lpcszStr[i + 2] == 'B'))
				|| (lpcszStr[i + 1] == '(' && lpcszStr[i + 2] == 'I')) {
				i += 3;
				continue;	// �L���ȃG�X�P�[�v�V�[�P���X���X�L�b�v.
			}
			else {
				return FALSE;	// ����.
			}
		}
		if (lpcszStr[i] <= 0x7f) {	// ASCII�����͂��̂܂ܐi�߂�.
			i++;
		}
		else {
			return FALSE;	// ����.
		}
	}
	return TRUE;	// �S�Ĕ͈͓�.

}

// ���s�̃`�F�b�N.
CTextFile::NEW_LINE CTextFile::CheckNewLine() {

	// �܂�CR('\r')��T��.
	size_t f = m_tstrText.find_first_of(_T('\r'));	// '\r'�̈ʒu��f�Ɋi�[.
	if (f != -1) {	// f('\r')�����������ꍇ.
		if (f == m_tstrText.length() - 1) {	// �Ōオ'\r'.
			m_NewLine = NEW_LINE_CR;	// NEW_LINE_CR���Z�b�g.
		}
		else {	// �Ō�łȂ�.
			if (m_tstrText[f + 1] == '\n') {	// ����'\n'�̏ꍇ.
				m_NewLine = NEW_LINE_CRLF;	// NEW_LINE_CRLF���Z�b�g.
			}
			else {	// '\r'����.
				m_NewLine = NEW_LINE_CR;	// NEW_LINE_CR���Z�b�g.
			}
		}
	}
	else {	// '\r'�͂Ȃ��̂�, '\n'��T��.
		f = m_tstrText.find_first_of(_T('\n'));	// '\n'�̈ʒu��f�Ɋi�[.
		if (f != -1) {	// f('\n')�����������ꍇ.
			m_NewLine = NEW_LINE_LF;	// NEW_LINE_LF���Z�b�g.
		}
		else {	// '\n'���Ȃ�.
			m_NewLine = NEW_LINE_NONE;	// NEW_LINE_NONE���Z�b�g.
		}
	}

	// ���s�R�[�h��Ԃ�.
	return m_NewLine;	// m_NewLine��Ԃ�.

}

// �w��̃e�L�X�g�t�@�C����S����ēǂݍ���.
BOOL CTextFile::Read(LPCTSTR lpctszFileName) {

	// �t�@�C�������.
	Close();

	// �o�b�t�@�̃N���A.
	Clear();

	// �w�肳�ꂽ�t�@�C�����̃t�@�C����ǂݍ���.
	BOOL bRet = CBinaryFile::Read(lpctszFileName);
	if (bRet) {	// ����.

		// �t�@�C�������.
		Close();
		// BOM�̃`�F�b�N.
		CheckBom();
		if (m_Bom == BOM_UTF16LE) {	// UTF-16LE��BOM�̏ꍇ.
			m_Encoding = ENCODING_UTF_16LE;
			DecodeUtf16LEWithBom();	// BOM�t��UTF-16LE���e�L�X�g�Ƀf�R�[�h.
		}
		else if (m_Bom == BOM_UTF16BE) {	// UTF-16BE��BOM�̏ꍇ.
			m_Encoding = ENCODING_UTF_16BE;
			DecodeUtf16BEWithBom();	// BOM�t��UTF-16BE���e�L�X�g�Ƀf�R�[�h.
		}
		else if (m_Bom == BOM_UTF8) {	// UTF-8��BOM�̏ꍇ.
			m_Encoding = ENCODING_UTF_8;
			DecodeUtf8WithBom();	// BOM�t��UTF-8���e�L�X�g�Ƀf�R�[�h.
		}
		else {	// ����ȊO.
			// JIS���ǂ�������.
			BOOL bJis = IsJis(m_pBytes, m_dwSize);	// IsUtf8��JIS���ǂ�������.
			if (bJis) {	// TRUE.
				// JIS�Ƃ��ĕϊ�.
				m_Encoding = ENCODING_JIS;
				DecodeJis();	// JIS���e�L�X�g�Ƀf�R�[�h.
			}
			else {
				// UTF-8���ǂ�������.
				BOOL bUtf8 = IsUtf8(m_pBytes, m_dwSize);	// IsUtf8��UTF-8���ǂ�������.
				if (bUtf8) {	// TRUE.
					// UTF-8�Ƃ��ĕϊ�.
					m_Encoding = ENCODING_UTF_8;
					DecodeUtf8();	// UTF-8���e�L�X�g�Ƀf�R�[�h.
				}
				else {	// FALSE.
					// Shift_JIS���ǂ�������.
					BOOL bShiftJis = IsShiftJis(m_pBytes, m_dwSize);	// IsShiftJis��Shift_JIS���ǂ�������.
					if (bShiftJis) {	// TRUE.
						// Shift_JIS�Ƃ��ĕϊ�.
						m_Encoding = ENCODING_SHIFT_JIS;
						DecodeShiftJis();	// Shift_JIS���e�L�X�g�Ƀf�R�[�h.
					}
					else {	// FALSE.
						// EUC-JP���ǂ�������.
						BOOL bEucJp = IsEucJp(m_pBytes, m_dwSize);	// IsEucJp��EUC-JP���ǂ�������.
						if (bEucJp) {	// TRUE.
							// EUC-JP�Ƃ��ĕϊ�.
							m_Encoding = ENCODING_EUC_JP;
							DecodeEucJp();	// EUC-JP���e�L�X�g�Ƀf�R�[�h.
						}
						else {	// FALSE.
							MessageBox(NULL, _T("Unknown"), _T("CTextFile"), MB_OK);	// "Unknown"�ƕ\��.
							return FALSE;	// �����ŏI��.
						}
					}
				}
			}
		}
		CheckNewLine();	// ���s�R�[�h�̃`�F�b�N.
		if (m_NewLine != NEW_LINE_NONE || m_NewLine != NEW_LINE_CRLF) {	// ���s�����ł͂Ȃ� or CRLF�ł͂Ȃ��ꍇ.
			ConvertNewLine(CTextFile::NEW_LINE_CRLF, m_NewLine);	// CRLF�ɕϊ�.
		}
		CBinaryFile::Clear();	// �o�b�t�@�N���A.
		return TRUE;	// TRUE��Ԃ�.

	}

	// FALSE��Ԃ�.
	CBinaryFile::Clear();	// �o�b�t�@�N���A.
	return FALSE;

}

// �o�b�t�@�̃N���A.
void CTextFile::Clear() {

	// �����o�̏I������.
	m_tstrText.clear();	// �N���A.

	// �e�N���X��Clear���Ă�.
	CBinaryFile::Clear();	// �o�b�t�@�N���A.

}