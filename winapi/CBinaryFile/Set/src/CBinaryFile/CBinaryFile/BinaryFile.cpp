// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile

// �S����Ăɏ������ރo�b�t�@�̃Z�b�g.
void CBinaryFile::Set(BYTE* pBytes, DWORD dwSize) {

	// �����o�ɃZ�b�g.
	m_dwSize = dwSize;	// m_deSize��dwSize���Z�b�g.

	// �o�b�t�@�̍쐬.
	m_pBytes = new BYTE[m_dwSize + 1];	// new��m_dwSize + 1�̃o�C�g����쐬��, �|�C���^��m_pBytes�Ɋi�[.
	ZeroMemory(m_pBytes, m_dwSize + 1);	// ZeroMemory��m_pBytes��(m_dwSize + 1)��, 0�Ŗ��߂�.

	// �f�[�^���R�s�[.
	CopyMemory(m_pBytes, pBytes, m_dwSize);	// CopyMemory�ŃR�s�[.

}