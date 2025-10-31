// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MultiView.h"	// CMultiView
#include "resource.h"

// static�����o�ϐ��̐錾.
HBRUSH CMultiView::s_hBrush;	// ���̃E�B���h�E�N���X�̔w�i�u���Vs_hBrush.

// �R���X�g���N�^CMultiView
CMultiView::CMultiView() : CUserControl(){

	// �����o�ϐ��̏�����.
	m_pMultiViewItemsPanel = NULL;	// m_pMultiViewItemsPanel��NULL�ŏ�����.
	m_iHScrollPos = 0;	// m_iHScrollPos��0�ŏ�����.
	m_iVScrollPos = 0;	// m_iVScrollPos��0�ŏ�����.

}

// �f�X�g���N�^~CMultiView
CMultiView::~CMultiView(){

	// �����o�̏I������.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CMultiView::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"));	// CUserControl::RegisterClass�œo�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�n���h���w��o�[�W����.)
BOOL CMultiView::RegisterClass(HINSTANCE hInstance, HBRUSH hbrBackground){

	// �E�B���h�E�N���X���ɂ�lpctszClassName, �w�i�u���V�n���h���ɂ�hbrBackground���w��.
	s_hBrush = hbrBackground;	// �w�i�u���V�n���h�����X�^�e�B�b�N�ϐ��ɃZ�b�g.
	return CUserControl::RegisterClass(hInstance, _T("CMultiView"), hbrBackground);	// CUserControl::RegisterClass�œo�^.

}

// �E�B���h�E�쐬�֐�Create.
BOOL CMultiView::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.(WS_CLIPCHILDREN�Ŏq�E�B���h�E�������ĕ`�悵�Ȃ��Ȃ�.)
	return CUserControl::Create(_T("CMultiView"), lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ō쐬.

}

// �E�B���h�E�j���֐�Destroy
BOOL CMultiView::Destroy(){

	// �}���`�r���[�A�C�e���Y�p�l���̔j��.
	if (m_pMultiViewItemsPanel != NULL){
		m_pMultiViewItemsPanel->Destroy();
		delete m_pMultiViewItemsPanel;
		m_pMultiViewItemsPanel = NULL;
	}

	// �e�N���X��Destroy���Ă�.
	return CUserControl::Destroy();	// CUserControl::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CMultiView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �}���`�r���[�A�C�e���Y�p�l���̍쐬.
	m_pMultiViewItemsPanel = new CMultiViewItemsPanel();

	// �}���`�r���[�A�C�e���Y�p�l���̃E�B���h�E����.
	m_pMultiViewItemsPanel->Create(_T(""), 0, 0, 0, 640, 480, hwnd, (HMENU)IDC_MULTIVIEWITEMSPANEL, lpCreateStruct->hInstance);	// m_pMultiViewItemsPanel->Create�ŃE�B���h�E����.

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CMultiView::OnDestroy(){

	// �e�N���X��OnDestroy���Ă�.
	CUserControl::OnDestroy();	// CUserControl::OnDestroy���Ă�.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
void CMultiView::OnSize(UINT nType, int cx, int cy){

	// �N���C�A���g�G���A���.
	RECT clientRC = {0};
	GetClientRect(m_hWnd, &clientRC);

	// �A�C�e���Y�p�l�����.
	RECT mvitemsPanelRC = {0};
	GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &mvitemsPanelRC);

	// �X�N���[���o�[�ݒ�.
	// ��������.
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	m_ScrollInfo.nPage = clientRC.right - clientRC.left;
	m_ScrollInfo.nMin = 0;
	m_ScrollInfo.nMax = (mvitemsPanelRC.right - mvitemsPanelRC.left) - 1;
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// ��������.
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	m_ScrollInfo.nPage = clientRC.bottom - clientRC.top;
	m_ScrollInfo.nMin = 0;
	m_ScrollInfo.nMax = (mvitemsPanelRC.bottom - mvitemsPanelRC.top) - 1;
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

}

// �w�i������v�����ꂽ��.
int CMultiView::OnEraseBkgnd(){

	// �w�i�u���V�̍ĕ`��.
	HDC hDC = GetDC(m_hWnd);
	RECT rc = {0};
	GetClientRect(m_hWnd, &rc);
	HBRUSH hOld = (HBRUSH)SelectObject(hDC, s_hBrush);
	Rectangle(hDC, rc.left, rc.top, rc.right, rc.bottom);
	SelectObject(hDC, hOld);
	ReleaseDC(m_hWnd, hDC);

	// �w�i�����ς݂Ƃ���1.
	return 1;

}

// ���������X�N���[���o�[�C�x���g��.
void CMultiView::OnHScroll(UINT nSBCode, UINT nPos){

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԍ�
		case SB_LEFT:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉE
		case SB_RIGHT:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1��
		case SB_LINELEFT:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1��E
		case SB_LINERIGHT:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGELEFT:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W�E
		case SB_PAGERIGHT:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);
	// �����o�ɂ��Z�b�g.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// �A�C�e���Y�p�l���̈ړ�.
	RECT rcItemsPanelRC = {0};
	::GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &rcItemsPanelRC);
	m_pMultiViewItemsPanel->MoveWindow(0 - m_iHScrollPos, 0 - m_iVScrollPos, rcItemsPanelRC.right - rcItemsPanelRC.left, rcItemsPanelRC.bottom - rcItemsPanelRC.top);	// MoveWindow�ňړ�.
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}

// ���������X�N���[���o�[�C�x���g��.
void CMultiView::OnVScroll(UINT nSBCode, UINT nPos){

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԏ�
		case SB_TOP:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉ�
		case SB_BOTTOM:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1�s��
		case SB_LINEUP:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1�s��
		case SB_LINEDOWN:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGEUP:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W��
		case SB_PAGEDOWN:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:
	
			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);
	// �����o�ɂ��Z�b�g.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// �A�C�e���Y�p�l���̈ړ�.
	RECT rcItemsPanelRC = {0};
	::GetClientRect(m_pMultiViewItemsPanel->m_hWnd, &rcItemsPanelRC);
	m_pMultiViewItemsPanel->MoveWindow(0 - m_iHScrollPos, 0 - m_iVScrollPos, rcItemsPanelRC.right - rcItemsPanelRC.left, rcItemsPanelRC.bottom - rcItemsPanelRC.top);	// MoveWindow�ňړ�.
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}