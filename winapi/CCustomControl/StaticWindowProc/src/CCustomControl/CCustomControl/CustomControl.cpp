// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "CustomControl.h"	// CCustomControl

// static�����o�ϐ��̒�`
std::map<tstring, WNDPROC>	CCustomControl::m_mapBaseWindowProcMap;	// �x�[�X�E�B���h�E�v���V�[�W���}�b�vm_mapBaseWindowProcMap

// �R���X�g���N�^CCustomControl
CCustomControl::CCustomControl() : CWindow(){

}

// �f�X�g���N�^~CCustomControl
CCustomControl::~CCustomControl(){

}

// �X�^�e�B�b�N�E�B���h�E�v���V�[�W��StaticWindowProc.
LRESULT CALLBACK CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow��NULL�ɏ�����.

	// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
	if (m_mapWindowMap.find(hwnd) != m_mapWindowMap.end()){	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
		pWindow = m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
	}

	// �E�B���h�E�I�u�W�F�N�g���擾�ł��Ȃ��ꍇ.
	if (pWindow == NULL){	// pWindow��NULL�̎�.

		// �z��̏�����
		TCHAR tszClassName[256] = {0};	// tszClassName��0�ŏ�����.

		// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
		GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

		// tszClassName��m_mapBaseWindowProcMap�̃L�[�ɂ����.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()){	// �݂�������.

			// ����̃v���V�[�W���ɔC����.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc��, ���̃��b�Z�[�W��m_mapBaseWindowProcMap[tszClassName]�ɔC����.

		}
		else{	// �����ꍇ.

			// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�̒l��Ԃ�.

		}

	}
	else{	// pWindow���������ꍇ.

		// ���̃E�B���h�E��DynamicWindowProc�ɔC����.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɓn��.

	}

}

// �E�B���h�E�쐬�֐�Create.
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	BOOL bRet = CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ɃE�B���h�E�N���X��lpctszClassName���w��.
	if (bRet){	// bRet��TRUE.

		// ����̃E�B���h�E�v���V�[�W�����擾��, CCustomControl::StaticWindowProc�ɍ����ւ���.
		WNDPROC lpfnWndProc;	// ����̃v���V�[�W��lpfnWndProc
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLong�Ńv���V�[�W��lpfnWndProc���擾.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLong�Ńv���V�[�W��CCustomControl::StaticWindowProc��ݒ�.

		// �}�b�v�̃L�[�ɃE�B���h�E�N���X�����Ȃ���Γo�^.
		if (m_mapBaseWindowProcMap.find(lpctszClassName) == m_mapBaseWindowProcMap.end()){	// �}�b�v�ɖ�����.
			m_mapBaseWindowProcMap.insert(std::pair<LPCTSTR, WNDPROC>(lpctszClassName, lpfnWndProc));	// �v���V�[�W����o�^.
		}

		// WM_CREATE��ʂ�Ȃ��̂�, �E�B���h�E�}�b�v�̓o�^���s��.
		if (m_mapWindowMap.find(m_hWnd) == m_mapWindowMap.end()){	// �E�B���h�E�}�b�v�ɂȂ����.
			m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));	// �o�^����.
		}

	}
	return bRet;	// bRet��Ԃ�.

}

// �E�B���h�E�j���֐�Destroy
BOOL CCustomControl::Destroy(){

	// �e�N���X��Destroy���Ă�.
	return CWindow::Destroy();	// CWindow::Destroy���Ă�.

}

// �_�C�i�~�b�N�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W�̏���
	switch (uMsg){	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏����֌�����.


		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

			}

 			// ����̏����֌�����.
 			break;	// break�Ŕ�����, ����̏����֌�����.

	}

	// DefWindowProc�ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// ������DefWindowProc�ɓn��, �߂�l�����̂܂ܕԂ�.

}

// �E�B���h�E�̍쐬���J�n���ꂽ��.
int CCustomControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ��ɃE�B���h�E�쐬�ɐ���������̂Ƃ���.
	return 0;	// 0��Ԃ���, �E�B���h�E�쐬�ɐ��������Ƃ������ƂɂȂ�.

}

// �E�B���h�E���j�����ꂽ��.
void CCustomControl::OnDestroy(){

	// �����ł͉����Ă΂Ȃ�.

}