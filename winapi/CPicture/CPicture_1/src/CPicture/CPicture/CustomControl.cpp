// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// static�����o�ϐ��̒�`
std::map<tstring, WNDPROC>	CCustomControl::m_mapBaseWindowProcMap;	// �x�[�X�E�B���h�E�v���V�[�W���}�b�vm_mapBaseWindowProcMap

// �R���X�g���N�^CCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// �f�X�g���N�^~CCustomControl
CCustomControl::~CCustomControl() {

}

// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
LRESULT CALLBACK CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �|�C���^�̏�����
	CWindow* pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow��NULL�ɏ�����.

	// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
	if (m_mapWindowMap.find(hwnd) != m_mapWindowMap.end()) {	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
		pWindow = m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
	}

	// �E�B���h�E�I�u�W�F�N�g���擾�ł��Ȃ��ꍇ.
	if (pWindow == NULL) {	// pWindow��NULL�̎�.

		// �z��̏�����
		TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

		// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
		GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

		// tszClassName��m_mapBaseWindowProcMap�̃L�[�ɂ����.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// �݂�������.

			// ����̃v���V�[�W���ɔC����.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc��, ���̃��b�Z�[�W��m_mapBaseWindowProcMap[tszClassName]�ɔC����.

		}
		else {	// �����ꍇ.

			// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̒l��Ԃ�.

		}

	}
	else {	// pWindow���������ꍇ.

		// ���̃E�B���h�E��DynamicWindowProc�ɔC����.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɓn��.

	}

}

// �E�B���h�E�쐬�֐�Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	BOOL bRet = CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.
	if (bRet) {	// bRet��TRUE.

		// ����̃E�B���h�E�v���V�[�W�����擾��, CCustomControl::StaticWindowProc�ɍ����ւ���.
		WNDPROC lpfnWndProc;	// ����̃v���V�[�W��lpfnWndProc
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLong�Ńv���V�[�W��lpfnWndProc���擾.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLong�Ńv���V�[�W��CCustomControl::StaticWindowProc��ݒ�.

		// OnCreate�͈ȍ~�͌Ă΂�Ȃ��̂�, �����ŌĂ�ł���.
		CREATESTRUCT cs;	// CREATESTRUCT���ꉞ�p��.
		cs.hInstance = hInstance;	// hInstance�͗v�邩������Ȃ��̂�, ����͓n����悤�ɂ��Ă���.
		if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreate��m_hWnd��cs��n��.

			// �߂�l��0�łȂ��ꍇ, �j��.
			Destroy();	// Destroy�Ŕj��.
			return FALSE;	// FALSE��Ԃ�.

		}

		// �}�b�v�̃L�[�ɃE�B���h�E�N���X�����Ȃ���Γo�^.
		if (m_mapBaseWindowProcMap.find(lpctszClassName) == m_mapBaseWindowProcMap.end()) {	// �}�b�v�ɖ�����.
			m_mapBaseWindowProcMap.insert(std::pair<LPCTSTR, WNDPROC>(lpctszClassName, lpfnWndProc));	// �v���V�[�W����o�^.
		}

		// WM_CREATE��ʂ�Ȃ��̂�, �E�B���h�E�}�b�v�̓o�^���s��.
		if (m_mapWindowMap.find(m_hWnd) == m_mapWindowMap.end()) {	// �E�B���h�E�}�b�v�ɂȂ����.
			m_mapWindowMap.insert(std::pair<HWND, CWindow*>(m_hWnd, this));	// �o�^����.
		}

	}
	return bRet;	// bRet��Ԃ�.

}

// �E�B���h�E�쐬�֐�Create(RECT�o�[�W����).
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT& rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// RECT�Ŏw�肳�ꂽ�T�C�Y��x, y, iWidth, iHeight�ɕϊ�.
	return CCustomControl::Create(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left + 1, rect.bottom - rect.top + 1, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃJ�X�^���R���g���[���̃E�B���h�E�쐬.

}

// �E�B���h�E�j���֐�Destroy
BOOL CCustomControl::Destroy() {

	// �e�N���X��Destroy���Ă�.
	return CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W�̏���
	switch (uMsg) {	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏����֌�����.

		// �E�B���h�E�̕`���v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// OnPaint�ɔC����.
				OnPaint();	// OnPaint���Ă�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏����֌�����.

	}

	// �z��̏�����
	TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

	// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
	GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

	// tszClassName��m_mapBaseWindowProcMap�̃L�[�ɂ����.
	if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// �݂�������.

		// ����̃v���V�[�W���ɔC����.
		return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc��, ���̃��b�Z�[�W��m_mapBaseWindowProcMap[tszClassName]�ɔC����.

	}
	else {	// �����ꍇ.

		// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̒l��Ԃ�.

	}

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CCustomControl::OnDestroy() {

	// �����̃E�B���h�E�n���h�����c���Ă�����}�b�v����폜.
	if (m_mapWindowMap.find(m_hWnd) != m_mapWindowMap.end()) {	// find�ł݂�������.
		m_mapWindowMap.erase(m_hWnd);	// m_mapWindowMap.erase�ō폜.
	}

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CCustomControl::OnPaint() {

	// �ϐ��̐錾.
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��hDC.
	PAINTSTRUCT ps;	// PAINTSTRUCT�\����ps.

	// ������̕`��.
	hDC = BeginPaint(m_hWnd, &ps);	// Win32API��BeginPaint��hDC���擾.
	TextOut(hDC, 0, 0, _T("CCustomControl"), (int)_tcslen(_T("CCustomControl")));	// Win32API��TextOut��"CCustomControl"�ƕ`��.
	EndPaint(m_hWnd, &ps);	// Win32API��EndPaint�ŕ`��I��.

}

// ���������X�N���[���o�[�C�x���g��.
void CCustomControl::OnVScroll(UINT nSBCode, UINT nPos) {

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrVert = { 0 };	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfo��scrVert���擾.

	// �܂݂̍ő�ʒu���v�Z.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

	// �ʒm�R�[�h����
	switch (nSBCode) {	// �ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

		// 1�ԏ�
		case SB_TOP:

			// 1�ԏ�ɃZ�b�g.
			scrVert.nPos = scrVert.nMin;	// ���݈ʒu��1�ԏ�ɃZ�b�g.
			break;	// ������.

		// 1�ԉ�
		case SB_BOTTOM:

			// 1�ԉ��ɃZ�b�g.
			scrVert.nPos = scrVert.nMax;	// ���݈ʒu��1�ԉ��ɃZ�b�g.
			break;	// ������.

		// 1���
		case SB_LINEUP:

			// 1���ɖ߂�.
			if (scrVert.nPos > scrVert.nMin) {	// scrVert.nPos��scrVert.nMin���傫���ꍇ.
				scrVert.nPos--;	// 1�߂�.
			}
			break;	// ������.

		// 1��
		case SB_LINEDOWN:

			// 1�񉺂ɐi�߂�.
			if (scrVert.nPos < iMaxPos) {	// scrVert.nPos��iMaxPos��菬�����ꍇ.
				scrVert.nPos++;	// 1�i��.
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGEUP:

			// SB_PAGEUP�u���b�N.
			{

				// 1�y�[�W�߂�.
				int after = scrVert.nPos - scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after >= scrVert.nMin) {	// �����𒴂��ĂȂ����.
					scrVert.nPos -= scrVert.nPage;	// 1�y�[�W���}�C�i�X.
				}
				else {	// �����𒴂�����.
					scrVert.nPos = scrVert.nMin;	// �ŏ��l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// 1�y�[�W��
		case SB_PAGEDOWN:

			// SB_PAGEDOWN�u���b�N.
			{

				// 1�y�[�W�i��.
				int after = scrVert.nPos + scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after <= iMaxPos) {	// ����𒴂��ĂȂ����.
					scrVert.nPos += scrVert.nPage;	// 1�y�[�W���v���X.
				}
				else {	// ����𒴂�����.
					scrVert.nPos = scrVert.nMax;	// �ő�l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X�N���[���܂݂������ꂽ��.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITION�u���b�N.
			{

				// �����ꂽ�ʒu���Z�b�g.
				int before = scrVert.nPos;	// �ȑO.
				int after = nPos;	// �Ȍ�.
				scrVert.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrVert.nPos�ɃZ�b�g.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// scrVert.nPos��hwnd��SB_VERT�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// SetScrollInfo�Ō��݂�scrVert.nPos��m_hWnd�ɃZ�b�g.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈���쐬.(NULL�Ȃ̂őS�̂������̈�.)
	UpdateWindow(m_hWnd);	// UpdateWindow�ŃE�B���h�E�̍X�V.

	// WM_VSCROLL�������������ɗ������Ƃ�����.
	HDC hDC = GetDC(m_hWnd);	// hDC�擾.
	static int j = 0;	// �X�^�e�B�b�N�ϐ�j��0�ŏ�����.
	TCHAR tszJ[16] = { 0 };	// ������o�b�t�@tszJ(����16)��{0}�ŏ�����.
	_stprintf(tszJ, _T("j = %d"), j);	// j�𕶎���tszJ�ɕϊ�.
	BOOL b = TextOut(hDC, 0, 0, tszJ, _tcslen(tszJ));	// tszJ��`��.
	j++;	// j���C���N�������g.
	ReleaseDC(m_hWnd, hDC);	// hDC���.

}