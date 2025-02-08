// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <stdio.h>	// C�W�����o��
// �Ǝ��̃w�b�_
#include "Canvas.h"	// CCanvas

// �R���X�g���N�^CCanvas
CCanvas::CCanvas() : CUserControl() {

	// �����o�̏�����.
	m_hDC = NULL;
	m_hMemDC = NULL;
	m_hOldBitmap = NULL;
	m_pDIBSection = NULL;
	ZeroMemory(&m_rgbqCurrentColor, sizeof(RGBQUAD));
	m_hPen = NULL;
	m_hOldPen = NULL;

}

// �f�X�g���N�^~CCanvas
CCanvas::~CCanvas() {

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CCanvas"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�F�w��o�[�W����.)
BOOL CCanvas::RegisterClass(HINSTANCE hInstance, int i) {

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CCanvas"), i);	// CUserControl::RegisterClass�ŃE�B���h�E�N���X��"CCanvas"��o�^.

}

// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
BOOL CCanvas::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�N���X����"CCanvas".
	return CUserControl::Create(_T("CCanvas"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ɃE�B���h�E�N���X��"CCanvas"���w��.

}

// �E�B���h�E�j���֐�Destroy
BOOL CCanvas::Destroy() {

	// �y���I�u�W�F�N�g�̔j��.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

	// �ȑO�̃r�b�g�}�b�v�n���h���ɖ߂�.
	if (m_hOldBitmap != NULL) {	// NULL�łȂ�.
		SelectObject(m_hMemDC, m_hOldBitmap);	// SelectObject��m_hMemDC��m_hOlbBitmap��I��.
		m_hOldBitmap = NULL;	// NULL���Z�b�g.
	}

	// �������f�o�C�X�R���e�L�X�g�̔j��.
	if (m_hMemDC != NULL) {	// NULL�łȂ�.
		DeleteDC(m_hMemDC);	// DeleteDC��m_hMemDC��j��.
		m_hMemDC = NULL;	// NULL���Z�b�g.
	}

	// �f�o�C�X�R���e�L�X�g�̉��.
	if (m_hDC != NULL) {	// NULL�łȂ�.
		ReleaseDC(m_hWnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
	}

	// m_pDIBSection�͊O���̃��m�Ȃ̂Ŕj������NULL�ɂ��邾��.
	if (m_pDIBSection != NULL) {
		m_pDIBSection = NULL;	// NULL���Z�b�g.
	}

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �r�b�g�}�b�v�̃Z�b�gSetBitmap(CDIBSection�|�C���^).
void CCanvas::SetBitmap(CDIBSection* pDIBSection) {

	// �|�C���^�̊i�[.
	m_pDIBSection = pDIBSection;	// m_pDIBSection��pDIBSection���i�[.

	// �r�b�g�}�b�v�I�u�W�F�N�g�̑I��.
	HBITMAP hOld = NULL;
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_pDIBSection->m_hDIBSection);	// SelectObject��m_hMemDC��m_pDIBSection->m_hDIBSection��I��.
	if (m_hOldBitmap == NULL) {	// m_hOldBitmap��NULL�̎�.
		m_hOldBitmap = hOld;	// SelectObject�̖߂�l���i�[,
	}

	// �y���I�u�W�F�N�g�̔j��.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

	// �y���I�u�W�F�N�g�̍쐬.
	m_hPen = CreatePen(PS_SOLID, 1, RGB(m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue));

	// �y���I�u�W�F�N�g�̑I��.
	m_hOldPen = (HPEN)SelectObject(m_hMemDC, m_hPen);

}

// ���݂̐F���Z�b�g����֐�SetCurrentColor.
void CCanvas::SetCurrentColor(BYTE r, BYTE g, BYTE b) {

	// �w��̐F���Z�b�g.
	m_rgbqCurrentColor.rgbRed = r;
	m_rgbqCurrentColor.rgbGreen = g;
	m_rgbqCurrentColor.rgbBlue = b;

	// �y���I�u�W�F�N�g�̔j��.
	if (m_hPen != NULL) {
		SelectObject(m_hMemDC, m_hOldPen);
		DeleteObject(m_hPen);
		m_hPen = NULL;
	}

	// �y���I�u�W�F�N�g�̍쐬.
	m_hPen = CreatePen(PS_SOLID, 1, RGB(m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue));

	// �y���I�u�W�F�N�g�̑I��.
	m_hOldPen = (HPEN)SelectObject(m_hMemDC, m_hPen);

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CCanvas::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �f�o�C�X�R���e�L�X�g�̎擾.
	m_hDC = GetDC(hwnd);	// GetDC�ł��̃E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
	if (m_hDC == NULL) {	// NULL�Ȃ玸�s.
		return -1;	// -1��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �������f�o�C�X�R���e�L�X�g�̐���.
	m_hMemDC = CreateCompatibleDC(m_hDC);	// CreateCompatibleDC��m_hDC�Ɍ݊����̂��郁�����f�o�C�X�R���e�L�X�g�𐶐�.
	if (m_hMemDC == NULL) {	// NULL�Ȃ玸�s.
		ReleaseDC(hwnd, m_hDC);	// ReleaseDC��m_hDC�����.
		m_hDC = NULL;	// NULL���Z�b�g.
		return -2;	// -2��Ԃ��ăE�B���h�E�쐬���s�Ƃ���.
	}

	// �e�N���X��OnCreate���Ă�.
	return CUserControl::OnCreate(hwnd, lpCreateStruct);	// CUserControl::OnCreate�̒l��Ԃ�.

}

// �E�B���h�E�̕`���v�����ꂽ��.
void CCanvas::OnPaint() {

	// DIBSection�̕`��.
	if (m_pDIBSection != NULL) {	// NULL�łȂ����.

		// �`��J�n.
		PAINTSTRUCT ps = { 0 };	// PAINTSTRUCT�^ps��{0}�ŏ�����.
		HDC hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint��hDC�擾.

		// �`��.
		if (m_pDIBSection != NULL) {
			BitBlt(hDC, 0, 0, m_pDIBSection->m_iWidth, m_pDIBSection->m_iHeight, m_hMemDC, 0, 0, SRCCOPY);	// BitBlt�œ]��.
		}

		// �`��I��.
		EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

	}

}

// �}�E�X���ړ����Ă��鎞.
void CCanvas::OnMouseMove(UINT nFlags, POINT pt) {

	// �}�E�X�_�E���t���O�������Ă��鎞.
	if (nFlags == MK_LBUTTON) {	// ���{�^����������Ă��鎞.

		// �ړ����͌��݂̐F�̐�������.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			LineTo(m_hMemDC, pt.x, pt.y);
			MoveToEx(m_hMemDC, pt.x, pt.y, NULL);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}
	else {	// ���{�^����������Ă��Ȃ���.

		// �n�_���ړ�.
		MoveToEx(m_hMemDC, pt.x, pt.y, NULL);

	}

}

// �}�E�X�̍��{�^���������ꂽ��.
void CCanvas::OnLButtonDown(UINT nFlags, POINT pt) {

	// �}�E�X�_�E���t���O�������Ă��鎞.
	if (nFlags == MK_LBUTTON) {	// ���{�^����������Ă��鎞.

		// �����������Ɍ��݂̐F���Z�b�g.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}

}

// �}�E�X�̍��{�^���������ꂽ��.
void CCanvas::OnLButtonUp(UINT nFlags, POINT pt) {

	// �}�E�X�_�E���t���O�������Ă��鎞.
	if (nFlags == MK_LBUTTON) {	// ���{�^����������Ă��鎞.

		// �����������Ɍ��݂̐F���Z�b�g.
		if (m_pDIBSection != NULL) {
			m_pDIBSection->SetPixel(pt.x, pt.y, m_rgbqCurrentColor.rgbRed, m_rgbqCurrentColor.rgbGreen, m_rgbqCurrentColor.rgbBlue);
			InvalidateRect(m_hWnd, NULL, TRUE);
		}

	}

}