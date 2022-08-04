// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// static�����o�ϐ��̒�`
std::map<LPCTSTR, WNDPROC>	CCustomControl::m_mapBaseWindowProcMap;	// �x�[�X�E�B���h�E�v���V�[�W���}�b�vm_mapBaseWindowProcMap

// �R���X�g���N�^CCustomControl
CCustomControl::CCustomControl() : CWindow() {

}

// �f�X�g���N�^~CCustomControl
CCustomControl::~CCustomControl() {

}

// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
LRESULT CALLBACK CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// DefWindowProc�ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̒l��Ԃ�.

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

// �E�B���h�E�j���֐�Destroy
BOOL CCustomControl::Destroy() {

	// �e�N���X��Destroy���Ă�.
	return CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CCustomControl::OnDestroy() {

	// �����ł͉����Ă΂Ȃ�.

}