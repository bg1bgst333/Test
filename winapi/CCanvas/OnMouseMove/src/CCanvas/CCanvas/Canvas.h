// ��d�C���N���[�h�h�~
#ifndef __CANVAS_H__
#define __CANVAS_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// CUserControl
#include "DIBSection.h"	// CDIBSection

// �L�����o�X�N���XCCanvas
class CCanvas : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		HDC m_hDC;	// HDC�^�f�o�C�X�R���e�L�X�g�n���h��m_hDC.
		HDC m_hMemDC;	// HDC�^�������f�o�C�X�R���e�L�X�g�n���h��m_hMemDC.
		HBITMAP m_hOldBitmap;	// HBITMAP�^�̈ȑO�̃r�b�g�}�b�v�n���h��m_hOldBitmap.
		CDIBSection* m_pDIBSection;	// CDIBSection�I�u�W�F�N�g�|�C���^m_pDIBSection.
		RGBQUAD m_rgbqCurrentColor;	// RGBQUAD�\���̕ϐ�m_rgbqCurrentColor.
		HPEN m_hPen;	// HPEN�^�y���n���h��m_hPen.
		HPEN m_hOldPen;	// HPEN�^�̈ȑO�̃y���n���h��m_hOldPen.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CCanvas();	// �R���X�g���N�^CCanvas
		virtual ~CCanvas();	// �f�X�g���N�^~CCanvas
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		static BOOL RegisterClass(HINSTANCE hInstance, int i);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�F�w��o�[�W����.)
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create.(�E�B���h�E�N���X���ȗ��o�[�W����.)
		virtual BOOL Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual void SetBitmap(CDIBSection* pDIBSection);	// �r�b�g�}�b�v�̃Z�b�gSetBitmap(CDIBSection�|�C���^).
		virtual void SetCurrentColor(BYTE r, BYTE g, BYTE b);	// ���݂̐F���Z�b�g����֐�SetCurrentColor.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�̍쐬���J�n���ꂽ��.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ��.
		virtual void OnMouseMove(UINT nFlags, POINT pt);	// �}�E�X���ړ����Ă��鎞.
		virtual void OnLButtonDown(UINT nFlags, POINT pt);	// �}�E�X�̍��{�^���������ꂽ��.
		virtual void OnLButtonUp(UINT nFlags, POINT pt);	// �}�E�X�̍��{�^���������ꂽ��.

};

#endif