// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// CApplication

// �C���X�^���X�������֐�InitInstance.
BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�\���̂̐錾
	HWND hWnd;	// HWND�^�E�B���h�E�n���h��hWnd.
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc.

	// �E�B���h�E�N���X�\����wc�Ƀp�����[�^���Z�b�g.
	wc.lpszClassName = _T("CApplication");	// �E�B���h�E�N���X���͂Ƃ肠����"CApplication"�Ƃ���.
	wc.style = CS_HREDRAW | CS_VREDRAW;	// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW�Ƃ���.
	wc.lpfnWndProc = WindowProc;	// �E�B���h�E�v���V�[�W���ɂ͉��Œ�`����WindowProc���w�肷��.
	wc.hInstance = hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h���͈�����hInstance���g��.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// LoadIcon�ŃA�v���P�[�V��������̃A�C�R�������[�h.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	// LoadCursor�ŃA�v���P�[�V��������̃J�[�\�������[�h.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// GetStockObject�Ŕ��u���V��w�i�Ƃ���.
	wc.lpszMenuName = NULL;	// ���j���[�͂Ȃ�, �Ȃ̂�NULL.
	wc.cbClsExtra = 0;	// �Ƃ肠����0���w��.
	wc.cbWndExtra = 0;	// �Ƃ肠����0���w��.

	// �E�B���h�E�N���X�̓o�^.
	if (!RegisterClass(&wc)) {	// RegisterClass�ŃE�B���h�E�N���X��o�^����.

		// �߂�l��0�Ȃ�o�^���s�Ȃ̂ŃG���[����.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�̍쐬.
	hWnd = CreateWindow(wc.lpszClassName, _T("CApplication"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow�ŃE�B���h�E�N���X����"CApplication"�ȃE�B���h�E"CApplication"���쐬.
	if (hWnd == NULL) {	// hWnd��NULL�Ȃ�E�B���h�E�쐬���s.

		// hWnd��NULL�Ȃ�E�B���h�E�쐬���s�Ȃ̂ŃG���[����.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow�ŃE�B���h�E��\��.

	// TRUE��Ԃ�.
	return TRUE;	// return��TRUE��Ԃ�.

}

// ���b�Z�[�W���[�v�����֐�Run.
int CApplication::Run() {

	// �\���̂̐錾
	MSG msg;	// MSG�^�\����msg.

	// ���b�Z�[�W���[�v�̏���
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�ŃE�B���h�E���b�Z�[�W���擾��, msg�Ɋi�[.(0�ȉ��Ȃ炱���𔲂���.)

		// ���b�Z�[�W�̕ϊ��Ƒ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�.
		DispatchMessage(&msg);	// DispatchMessage�Ń��b�Z�[�W���E�B���h�E�v���V�[�W��WindowProc�ɑ��o.

	}

	// ExitInstance�̒l��Ԃ�.
	return ExitInstance();	// return��ExitInstance�̒l��Ԃ�.

}

// �I�������֐�ExitInstance.
int CApplication::ExitInstance() {

	// ����͏��0��Ԃ�.
	return 0;	// return��0��Ԃ�.

}

// �E�B���h�E�v���V�[�W��WindowProc�֐��̒�`
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W�̏���.
	switch (uMsg) {	// uMsg�̒l���Ƃɏ�����U�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �E�B���h�E�쐬�𐬌��Ƃ�����ɂ�0��Ԃ�.
				return 0;	// 0��Ԃ�.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// �A�v���P�[�V�������I�����������̂�, �I�����b�Z�[�W�̑��M.
				PostQuitMessage(0);	// PostQuitMessage�ŏI���R�[�h��0�Ƃ���, WM_QUIT���b�Z�[�W�𑗐M.

			}

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

		// ��L�ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// break�Ŕ�����, ����̏���(DefWindowProc)�֌�����.

	}

	// ���Ƃ͊���̏����ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// �߂�l���܂߂�DefWindowProc�Ɋ���̏�����C����.

}