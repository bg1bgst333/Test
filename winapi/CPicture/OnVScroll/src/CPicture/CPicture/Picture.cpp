// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Picture.h"	// CPicture

// �R���X�g���N�^CPicture
CPicture::CPicture() : CUserControl(){

	// �����o�̏�����.
	m_hDC = NULL;	// m_hDC��NULL�ŏ�����.
	m_hMemDC = NULL;	// m_hMemDC��NULL�ŏ�����.
	m_hBitmap = NULL;	// m_hBitmap��NULL�ŏ�����.
	m_hOldBitmap = NULL;	// m_hOldBitmap��NULL�ŏ�����.

}

// �f�X�g���N�^~CPicture
CPicture::~CPicture(){

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CPicture::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CPicture"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CPicture"��o�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CPicture::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X����"CPicture".
	return CUserControl::Create(_T("CPicture"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CPicture"���w��.
	
}

// �E�B���h�E�j���֐�Destroy
BOOL CPicture::Destroy(){

	// �ȑO�̃r�b�g�}�b�v�n���h���ɖ߂�.
	if (m_hOldBitmap != NULL){	// NULL�łȂ�.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObject��m_hMemDC��m_hOlbBitmap��I��.
		m_hOldBitmap = NULL;	// NULL���Z�b�g.
	}

	// �������f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hMemDC != NULL){	// NULL�łȂ�.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC��j��.
		m_hMemDC = NULL;	// NULL���Z�b�g.
	}

	// �f�o�C�X�R���e�L�X�g�̉��.
	if (m_hDC != NULL){	// NULL�łȂ�.
		ReleaseDC(m_hWnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
	}

	// �r�b�g�}�b�v�n���h���͊O���̃��m�Ȃ̂Ŕj������NULL�ɂ��邾��.
	if (m_hBitmap != NULL){
		m_hBitmap = NULL;	// NULL���Z�b�g.
	}

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �r�b�g�}�b�v�̃Z�b�gSetBitmap.
void CPicture::SetBitmap(HBITMAP hBitmap){

	// �r�b�g�}�b�v�n���h���̊i�[.
	m_hBitmap = hBitmap;	// m_hBitmap��hBitmap���i�[.

	// �r�b�g�}�b�v�I�u�W�F�N�g�̑I��.
	HBITMAP hOld = NULL;
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hMemDC��m_hBitmap��I��.
	if (m_hOldBitmap == NULL){	// m_hOldBitmap��NULL�̎�.
		m_hOldBitmap = hOld;	// SelectObject�̖߂�l���i�[,
	}

	// �N���C�A���g�̈��RECT���擾.
	RECT rc = {0};	// RECT�^rc��{0}�ŏ�����.
	GetClientRect(m_hWnd, &rc);	// �s�N�`���[�̃N���C�A���g�̈��RECT���擾.

	// �r�b�g�}�b�v���̎擾.
	BITMAP bitmap = {0};	// BITMAP�\���̕ϐ�bitmap��{0}�ŏ�����.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObject��bitmap���擾.

	// ���������X�N���[���o�[�̏�����.
	SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.nMin = 0;	// �ŏ��l��0.
	scrHorz.nMax = bitmap.bmWidth - 1;	// �ő�l��bitmap.bmWidth - 1.
	scrHorz.nPage = rc.right - rc.left;	// �y�[�W�T�C�Y��rc.right - rc.left.
	scrHorz.nPos = 0;	// ���݈ʒu��0.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// �X�N���[�������Z�b�g.

	// ���������X�N���[���o�[�̏�����.
	SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.nMin = 0;	// �ŏ��l��0.
	scrVert.nMax = bitmap.bmHeight - 1;	// �ő�l��bitmap.bmHeight - 1.
	scrVert.nPage = rc.bottom - rc.top;	// �y�[�W�T�C�Y��rc.bottom - rc.top.
	scrVert.nPos = 0;	// ���݈ʒu��0.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���Z�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &scrVert, TRUE);	// �X�N���[�������Z�b�g.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CPicture::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �f�o�C�X�R���e�L�X�g�̎擾.
	m_hDC = GetDC(hwnd);	// GetDC�ł��̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
	if (m_hDC == NULL){	// NULL�Ȃ玸�s.
		return -1;	// -1��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �������f�o�C�X�R���e�L�X�g�̐���.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDC��m_hDC�Ɍ݊����̂��郁�����f�o�C�X�R���e�L�X�g�𐶐�.
	if (m_hMemDC == NULL){	// NULL�Ȃ玸�s.
		ReleaseDC(hwnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
		return -2;	// -2��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �e�N���X��OnCreate���Ă�.
	return CUserControl::OnCreate(hwnd, lpCreateStruct);	// CUserControl::OnCreate�̒l��Ԃ�.

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CPicture::OnPaint(){

	// �r�b�g�}�b�v�̕`��.
	if (m_hBitmap != NULL){	// NULL�łȂ����.

		// �X�V�̈�̎擾.
		RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
		GetClientRect(m_hWnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
		RECT rcUpdate = {0};	// �X�V�̈�rcUpdate��{0}�ŏ�����.
		GetUpdateRect(m_hWnd, &rcUpdate, FALSE);	// GetUpdateRect�ōX�V�̈�rcUpdate���擾.

		// �X�N���[�����̎擾.
		SCROLLINFO siHorz = {0};	// ���������X�N���[�����siHorz.
		siHorz.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
		siHorz.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// �ʒu, �y�[�W, �����W.
		GetScrollInfo(m_hWnd, SB_HORZ, &siHorz);	// GetScrollInfo��siHorz�擾.
		SCROLLINFO siVert = {0};	// ���������X�N���[�����siVert.
		siVert.cbSize = sizeof(SCROLLINFO);	// sizeof(SCROLLINFO)
		siVert.fMask = SIF_POS | SIF_PAGE | SIF_RANGE;	// �ʒu, �y�[�W, �����W.
		GetScrollInfo(m_hWnd, SB_VERT, &siVert);	// GetScrollInfo��siVert�擾.

		// �`��J�n.
		PAINTSTRUCT ps = {0};	// PAINTSTRUCT�^ps��{0}�ŏ�����.
		HDC hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint��hDC�擾.

		// �`��.
		int x1 = 0;	// �]����x1��0�ŏ�����.
		int y1 = 0;	// �]����y1��0�ŏ�����.
		if (m_dx > 0){	// m_dx���v���X.
			x1 = siHorz.nPage + siHorz.nPos - (rcUpdate.right - rcUpdate.left);	// x1�̓y�[�W�� + �ʒu - 1 - (�ĕ`�悷��͈�).
		}
		else{	// dx��0�ȉ�.
			x1 = siHorz.nPos;	// x1�͈ʒu.
		}
		if (m_dy > 0){	// m_dy���v���X.
			y1 = siVert.nPage + siVert.nPos - (rcUpdate.bottom - rcUpdate.top);	// y1�̓y�[�W�� + �ʒu - 1 - (�ĕ`�悷��͈�).
		}
		else{	// m_dy��0�ȉ�.
			y1 = siVert.nPos;	// y1�͈ʒu.
		}
		BitBlt(hDC, rcUpdate.left, rcUpdate.top, rcUpdate.right - rcUpdate.left, rcUpdate.bottom - rcUpdate.top, m_hMemDC, x1, y1, SRCCOPY);	// BitBlt�œ]��.

		// �`��I��.
		EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

	}	

}

// ���������X�N���[���o�[�C�x���g��.
void CPicture::OnHScroll(UINT nSBCode, UINT nPos){

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrHorz = {0};	// ���������X�N���[�����scrHorz��{0}�ŏ�����.
	scrHorz.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrHorz.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_HORZ, &scrHorz);	// GetScrollInfo��scrHorz���擾.

	// �܂݂̍ő�ʒu���v�Z.
	int iMaxPos = scrHorz.nMax + 1 - scrHorz.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

	// �ω��ʂ�0�Ƀ��Z�b�g.
	m_dx = 0;	// m_dx��0�Ƀ��Z�b�g.

	// �ʒm�R�[�h����
	switch (nSBCode){	// nSBCode�ɍs��ꂽ����̒ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

		// 1�ԍ�
		case SB_LEFT:

			// 1�ԍ��ɃZ�b�g.
			scrHorz.nPos = scrHorz.nMin;	// ���݈ʒu��1�ԍ��ɃZ�b�g.
			break;	// ������.

		// 1�ԉE
		case SB_RIGHT:

			// 1�ԉE�ɃZ�b�g.
			scrHorz.nPos = scrHorz.nMax;	// ���݈ʒu��1�ԉE�ɃZ�b�g.
			break;	// ������.

		// 1��
		case SB_LINELEFT:

			// 1�񍶂ɖ߂�.
			if (scrHorz.nPos > scrHorz.nMin){	// scrHorz.nPos��scrHorz.nMin���傫���ꍇ.
				m_dx = -1;	// �ω���-1.
				scrHorz.nPos--;	// 1�߂�.
			}
			break;	// ������.

		// 1��E
		case SB_LINERIGHT:

			// 1��E�ɐi�߂�.
			if (scrHorz.nPos < iMaxPos){	// scrHorz.nPos��iMaxPos��菬�����ꍇ.
				m_dx = 1;	// �ω���1.
				scrHorz.nPos++;	// 1�i��.
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGELEFT:

			// SB_PAGELEFT�u���b�N.
			{

				// 1�y�[�W�߂�.
				int after = scrHorz.nPos - scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after >= scrHorz.nMin){	// �����𒴂��ĂȂ����.
					m_dx = -1 * scrHorz.nPage;	// 1�y�[�W���}�C�i�X.
					scrHorz.nPos -= scrHorz.nPage;	// 1�y�[�W���}�C�i�X.
				}
				else{	// �����𒴂�����.
					m_dx = -1 * (scrHorz.nPos - scrHorz.nMin);	// ���݈ʒu����ŏ��l�܂ł̍���-1�������ĕω��ʂƂ���.
					scrHorz.nPos = scrHorz.nMin;	// �ŏ��l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// 1�y�[�W�E
		case SB_PAGERIGHT:

			// SB_PAGERIGHT�u���b�N.
			{

				// 1�y�[�W�i��.
				int after = scrHorz.nPos + scrHorz.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after <= iMaxPos){	// ����𒴂��ĂȂ����.
					m_dx = scrHorz.nPage;	// 1�y�[�W���v���X.
					scrHorz.nPos += scrHorz.nPage;	// 1�y�[�W���v���X.
				}
				else{	// ����𒴂�����.
					m_dx = iMaxPos - scrHorz.nPos;	// iMaxPos���猻�݈ʒu�܂ł̍���ω��ʂƂ���.
					scrHorz.nPos = scrHorz.nMax;	// �ő�l��.
				}

			}

			// ������.
			break;	// break�Ŕ�����.

		// �X�N���[���܂݂������ꂽ��.
		case SB_THUMBPOSITION:


			// SB_THUMBPOSITION�u���b�N.
			{

				// �����ꂽ�ʒu���Z�b�g.
				int before = scrHorz.nPos;	// �ȑO.
				int after = nPos;	// �Ȍ�.
				m_dx = after - before;	// �ω��ʂ�after���傫����+, before���傫����-.
				scrHorz.nPos = after;	// HIWORD(wParam)�ɗ����ꂽ�ʒu���i�[����Ă���̂�scrHorz.nPos�ɃZ�b�g.

			}

			// ������.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// ������.
			break;	// break�Ŕ�����.

	}

	// scrHorz.nPos��m_hWnd��SB_HORZ�ɃZ�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &scrHorz, TRUE);	// SetScrollInfo�Ō��݂�scrHorz.nPos��m_hWnd�ɃZ�b�g.
	// �N���C�A���g�̈�̃X�N���[��.
	ScrollWindow(m_hWnd, -m_dx, 0, NULL, NULL);	// ScrollWindow��-m_dx���X�N���[��.
	// �����̈�̌v�Z.
	RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
	GetClientRect(m_hWnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
	RECT rcInvalidate = {0};	// �����̈�rcInvalidate��{0}�ŏ�����.
	if (m_dx < 0){	// m_dx���}�C�i�X�̎�.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right = -m_dx;	// ������-m_dx(�v���X)
		rcInvalidate.bottom = rcClient.bottom;	// �c.
	}
	else{	// m_dx��0���v���X�̎�.
		rcInvalidate.left = rcClient.right - m_dx;	// �E����-m_dx(�}�C�i�X)
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right= rcClient.right;	// ��.
		rcInvalidate.bottom = rcClient.bottom;	// �c.
	}
	// �����̈�̍쐬.
	InvalidateRect(m_hWnd, &rcInvalidate, FALSE);	// InvalidateRect�Ŗ����̈�rcInvalidate�쐬.
	// �E�B���h�E�̍X�V.
	UpdateWindow(m_hWnd);	// UpdateWinow��hwnd�̍X�V.

}

// ���������X�N���[���o�[�C�x���g��.
void CPicture::OnVScroll(UINT nSBCode, UINT nPos){

	// ���������X�N���[���o�[�����擾.
	SCROLLINFO scrVert = {0};	// ���������X�N���[�����scrVert��{0}�ŏ�����.
	scrVert.cbSize = sizeof(SCROLLINFO);	// sizeof�ō\���̃T�C�Y�w��.
	scrVert.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// �y�[�W, �����W, �ʒu���擾.
	GetScrollInfo(m_hWnd, SB_VERT, &scrVert);	// GetScrollInfo��scrVert���擾.

	// �܂݂̍ő�ʒu���v�Z.
	int iMaxPos = scrVert.nMax + 1 - scrVert.nPage;	// �Z�b�g�����ő�l + 1���傫����, ��������y�[�W����������, �܂݂̍ő�̈ʒu.

	// �ω��ʂ�0�Ƀ��Z�b�g.
	m_dy = 0;	// m_dy��0�Ƀ��Z�b�g.

	// �ʒm�R�[�h����
	switch (nSBCode){	// nSBCode�ɍs��ꂽ����̒ʒm�R�[�h���i�[����Ă���̂�, ����Ŕ��肷��.

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
			if (scrVert.nPos > scrVert.nMin){	// scrVert.nPos��scrVert.nMin���傫���ꍇ.
				m_dy = -1;	// �ω���-1.
				scrVert.nPos--;	// 1�߂�.
			}
			break;	// ������.

		// 1��
		case SB_LINEDOWN:

			// 1�񉺂ɐi�߂�.
			if (scrVert.nPos < iMaxPos){	// scrVert.nPos��iMaxPos��菬�����ꍇ.
				m_dy = 1;	// �ω���1.
				scrVert.nPos++;	// 1�i��.
			}
			break;	// ������.

		// 1�y�[�W��
		case SB_PAGEUP:

			// SB_PAGEUP�u���b�N.
			{

				// 1�y�[�W�߂�.
				int after = scrVert.nPos - scrVert.nPage;	// ���݈ʒu����1�y�[�W������.
				if (after >= scrVert.nMin){	// �����𒴂��ĂȂ����.
					m_dy = -1 * scrVert.nPage;	// 1�y�[�W���}�C�i�X.
					scrVert.nPos -= scrVert.nPage;	// 1�y�[�W���}�C�i�X.
				}
				else{	// �����𒴂�����.
					m_dy = -1 * (scrVert.nPos - scrVert.nMin);	// ���݈ʒu����ŏ��l�܂ł̍���-1�������ĕω��ʂƂ���.
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
				if (after <= iMaxPos){	// ����𒴂��ĂȂ����.
					m_dy = scrVert.nPage;	// 1�y�[�W���v���X.
					scrVert.nPos += scrVert.nPage;	// 1�y�[�W���v���X.
				}
				else{	// ����𒴂�����.
					m_dy = iMaxPos - scrVert.nPos;	// iMaxPos���猻�݈ʒu�܂ł̍���ω��ʂƂ���.
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
				m_dy = after - before;	// �ω��ʂ�after���傫����+, before���傫����-.
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
	// �N���C�A���g�̈�̃X�N���[��.
	ScrollWindow(m_hWnd, 0, -m_dy, NULL, NULL);	// ScrollWindow��-m_dy���X�N���[��.
	// �����̈�̌v�Z.
	RECT rcClient = {0};	// �N���C�A���g�̈�rcClient��{0}�ŏ�����.
	GetClientRect(m_hWnd, &rcClient);	// GetClientRect�Ō��݂̃N���C�A���g�̈��RECT�ł���rcClient���擾.
	RECT rcInvalidate = {0};	// �����̈�rcInvalidate��{0}�ŏ�����.
	if (m_dy < 0){	// m_dy���}�C�i�X�̎�.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.top;	// 0.
		rcInvalidate.right = rcClient.right;	// ��.
		rcInvalidate.bottom = -m_dy;	// �ォ��-m_dy(�v���X)
	}
	else{	// dy��0���v���X�̎�.
		rcInvalidate.left = rcClient.left;	// 0.
		rcInvalidate.top = rcClient.bottom - m_dy;	// ������-m_dy(�}�C�i�X)
		rcInvalidate.right= rcClient.right;	// ��.
		rcInvalidate.bottom = rcClient.bottom;	// �c.
	}
	// �����̈�̍쐬.
	InvalidateRect(m_hWnd, &rcInvalidate, FALSE);	// InvalidateRect�Ŗ����̈�rcInvalidate�쐬.
	// �E�B���h�E�̍X�V.
	UpdateWindow(m_hWnd);	// UpdateWinow��m_hWnd�̍X�V.

}