// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <string.h>	// C�����񏈗�
// �Ǝ��̃w�b�_
extern "C" {	// C����Ƃ��ĉ��߂���.
	#include "string_utility_cstring.h"	// �����񃆁[�e�B���e�B(C�����񏈗�)
}
#include "FileDialog.h"	// CFileDialog

// �R���X�g���N�^CFileDialog()
CFileDialog::CFileDialog(BOOL bOpenFileDalog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName, DWORD dwFlags, LPCTSTR lpszFilter, CWindow* pParentWnd, DWORD dwSize) {

	// �����o�̏�����.
	m_bOpenFileDalog = bOpenFileDalog;
	memset(&m_ofn, 0, sizeof(OPENFILENAME));
	if (lpszDefExt != NULL) {
		_tcscpy(m_tszDefExt, lpszDefExt);
		m_ofn.lpstrDefExt = m_tszDefExt;
	}
	if (lpszFileName != NULL) {
		_tcscpy(m_tszFileName, lpszFileName);
	}
	else {
		memset(m_tszFileName, 0, sizeof(TCHAR) * 1024);
	}
	m_ofn.nMaxFile = 1024;
	m_ofn.lpstrFile = m_tszFileName;
	m_ofn.Flags = dwFlags;
	if (lpszFilter != NULL) {
		_tcscpy(m_tszFilter, lpszFilter);
		int len = _tcslen(m_tszFilter);
		replace_wbyte_all(m_tszFilter, len, _T('|'), _T('\0'));
		m_ofn.lpstrFilter = m_tszFilter;
	}
	if (pParentWnd != NULL) {
		m_ofn.hwndOwner = pParentWnd->m_hWnd;
	}
	if (dwSize == 0) {
		m_ofn.lStructSize = sizeof(OPENFILENAME);
	}
	else {
		m_ofn.lStructSize = dwSize;
	}

}

// ���[�_���\��.
INT_PTR CFileDialog::DoModal() {

	// �ǂ���̃t�@�C���I���_�C�A���O���J��������.
	if (m_bOpenFileDalog) {	// "�J��"
		BOOL bRet = GetOpenFileName(&m_ofn);
		if (bRet) {
			return IDOK;
		}
		else {
			return IDCANCEL;
		}
	}
	else {	// "���O��t���ĕۑ�"
		BOOL bRet = GetSaveFileName(&m_ofn);
		if (bRet) {
			return IDOK;
		}
		else {
			return IDCANCEL;
		}
	}

}

// OPENFILENAME�̎擾.
OPENFILENAME& CFileDialog::GetOFN() {

	// OPENFILENAME��Ԃ�.
	return m_ofn;

}