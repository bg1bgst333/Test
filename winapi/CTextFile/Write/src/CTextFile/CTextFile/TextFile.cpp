// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "TextFile.h"	// CTextFile

// �e�L�X�g�̃Z�b�g.
void CTextFile::SetText(tstring tstrText){

	// �����o�ɃZ�b�g.
	m_tstrText = tstrText;	// m_tstrText��tstrText���Z�b�g.

}

// �w��̃e�L�X�g�t�@�C���ɑS����ď�������.
BOOL CTextFile::Write(LPCTSTR lpctszFileName){

	// BOM�Ȃ�UTF-16LE�Ƃ��ď�������.
	Set((BYTE *)m_tstrText.c_str(), m_tstrText.length() * 2);	// CBinaryFile::Set�ŕ�������o�b�t�@�ɃZ�b�g(UTF-16LE�Ȃ̂Œ�����2�{.)
	BOOL bRet = CBinaryFile::Write(lpctszFileName);	// CBinaryFile::Write�ŏ�������.
	return bRet;	// bRet��Ԃ�.

}