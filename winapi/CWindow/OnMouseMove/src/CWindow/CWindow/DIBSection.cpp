// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "DIBSection.h"	// CDIBSection
#include "BinaryFile.h"	// CBinaryFile

// �R���X�g���N�^CDIBSection()
CDIBSection::CDIBSection() {

	// �����o�̏�����.
	m_hDIBSection = NULL;	// m_hDIBSection��NULL�ŏ�����.
	m_lpBitsPixel = NULL;	// m_lpBitsPixel��NULL�ŏ�����.

}

// �f�X�g���N�^~CDIBSection()
CDIBSection::~CDIBSection() {

	// �����o�̏I������.
	if (m_hDIBSection != NULL) {	// NULL�łȂ�.
		::DeleteObject(m_hDIBSection);	// DeleteObject�Ŕj��.
		m_hDIBSection = NULL;	// NULL���Z�b�g.
	}
	m_lpBitsPixel = NULL;	// ��������Ȃ̂�NULL���Z�b�g.

}

// DIB�Z�N�V�����쐬�֐�CreateDIBSection.
BOOL CDIBSection::CreateDIBSection(HWND hWnd, int iWidth, int iHeight) {

	// �ϐ��̐錾�E������
	HDC hDC = NULL;	// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h��hDC��NULL�ɏ�����.
	BITMAPINFO bi = { 0 };	// �r�b�g�}�b�v���BiTMAPINFO�\����bi��{0}�ŏ�����.
	m_iWidth = iWidth;	// �����Z�b�g.
	m_iHeight = iHeight;	// �������Z�b�g.

	// �E�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾.
	hDC = GetDC(hWnd);	// GetDC�ŃE�B���h�E�̃f�o�C�X�R���e�L�X�g�n���h�����擾��, hDC�Ɋi�[.
	if (hDC) {

		// �r�b�g�}�b�v���̃Z�b�g.
		bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bi.bmiHeader.biWidth = m_iWidth;
		bi.bmiHeader.biHeight = m_iHeight;
		bi.bmiHeader.biPlanes = 1;
		bi.bmiHeader.biBitCount = 24;
		bi.bmiHeader.biCompression = BI_RGB;

		// DIB�Z�N�V�����̍쐬.
		m_hDIBSection = ::CreateDIBSection(hDC, &bi, DIB_RGB_COLORS, (void**)&m_lpBitsPixel, NULL, 0);	// CreateDIBSection��DIB�Z�N�V�������쐬.

		// �f�o�C�X�R���e�L�X�g�̉��.
		ReleaseDC(hWnd, hDC);	// ReleaseDC�Ńf�o�C�X�R���e�L�X�g�����.

		// NULL����Ȃ���ΐ���.
		if (m_hDIBSection != NULL) {
			return TRUE;
		}

	}

	return FALSE;

}

// �r�b�g�}�b�v�ۑ��֐�SaveBitmap.
BOOL CDIBSection::SaveBitmap(HWND hWnd, LPCTSTR lpctszFileName) {

	// �ϐ��̏�����.
	BITMAPINFO bi = { 0 };	// BITMAPINFO�\���̕ϐ�bi��{0}�ŏ�����.
	BITMAPFILEHEADER bfh = { 0 };	// BITMAPFILEHEADER�\����bfh��{0}�ŏ�����.
	HDC hDC = NULL;	// hDC��NULL�ŏ�����.

	// �r�b�g�}�b�v���̃Z�b�g.
	bi.bmiHeader.biBitCount = 24;	// �ЂƂ܂�24bit�r�b�g�}�b�v�̂ݑΉ�.
	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);	// BITMAPINFOHEADER�̃T�C�Y���w�肵�Ă���.
	bi.bmiHeader.biWidth = m_iWidth;	// �����Z�b�g.
	bi.bmiHeader.biHeight = m_iHeight;	// �������Z�b�g.
	bi.bmiHeader.biPlanes = 1;	// 1���Z�b�g.
	bi.bmiHeader.biCompression = BI_RGB;	// RGB.

	// DDB����DIB�̏����擾.(�s�N�Z����͕s�v.)
	hDC = GetDC(hWnd);	// GetDC��hWnd�̃f�o�C�X�R���e�L�X�ghDC���擾.
	GetDIBits(hDC, m_hDIBSection, 0, m_iHeight, NULL, &bi, DIB_RGB_COLORS);	// GetDIBits�Ńs�N�Z����̃T�C�Y(bi.bmiHeader.biSizeImage)���擾.
	ReleaseDC(hWnd, hDC);	// hDC�������[�X.

	// �r�b�g�}�b�v�t�@�C�����̃Z�b�g.(24bit�r�b�g�}�b�v�̏ꍇ.)
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);	// �s�N�Z����ȊO�̃T�C�Y.(�܂�w�b�_�̃T�C�Y.)
	bfh.bfSize = bfh.bfOffBits + bi.bmiHeader.biSizeImage;	// �S�̂̃T�C�Y�̓w�b�_ + �s�N�Z����.
	bfh.bfType = 0x4d42;	// 0x4d42("BM")�̓r�b�g�}�b�v�ł���Ƃ����Ӗ�.
	bfh.bfReserved1 = 0;	// ������0���Z�b�g.
	bfh.bfReserved2 = 0;	// ������0���Z�b�g.

	// �r�b�g�}�b�v�o�C�i���̃t�@�C����������.
	CBinaryFile* pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�g���쐬��, �|�C���^��pBinaryFile�Ɋi�[.
	pBinaryFile->Set((BYTE*)&bfh, sizeof(BITMAPFILEHEADER));	// pBinaryFile->Set��BITMAPFILEHEADER��bfh���Z�b�g.
	pBinaryFile->Write(lpctszFileName);	// pBinaryFile->Write(�t�@�C������������o�[�W����)�Ńt�@�C�����J���ď�������.
	pBinaryFile->Set((BYTE*)&bi, sizeof(BITMAPINFOHEADER));	// pBinaryFile->Set��BITMAPINFOHEADER��bi(���m�ɂ�bi.bmiHeader)���Z�b�g.
	pBinaryFile->Write();	// pBinaryFile->Write(�t�@�C���������Ȃ��o�[�W����)�ŏ�������.
	pBinaryFile->Set(m_lpBitsPixel, sizeof(BYTE) * bi.bmiHeader.biSizeImage);	// pBinaryFile->Set��lpBitsPixel���Z�b�g.
	pBinaryFile->Write();	// pBinaryFile->Write(�t�@�C���������Ȃ��o�[�W����)�ŏ�������.
	delete pBinaryFile;	// pBinaryFile�����.

	return TRUE;

}

// �r�b�g�}�b�v�Ǎ��֐�LoadBitmap.
BOOL CDIBSection::LoadBitmap(LPCTSTR lpctszFileName, BOOL bLoad) {

	// �\���̂̏�����.
	BITMAPFILEHEADER bfh = { 0 };		// BITMAPFILEHEADER�\���̕ϐ�bfh��{0}}�ŏ�����.
	BITMAPINFO bi = { 0 };			// BITMAPINFO�\���̕ϐ�bi��{0}�ŏ�����.

	// �r�b�g�}�b�v�o�C�i���̃t�@�C���ǂݍ���.
	CBinaryFile* pBinaryFile1 = new CBinaryFile();
	pBinaryFile1->Read(lpctszFileName, 0, sizeof(bfh));
	CopyMemory(&bfh, pBinaryFile1->m_pBytes, sizeof(bfh));
	delete pBinaryFile1;
	CBinaryFile* pBinaryFile2 = new CBinaryFile();
	pBinaryFile2->Read(lpctszFileName, sizeof(bfh), sizeof(bi));
	CopyMemory(&bi, pBinaryFile2->m_pBytes, sizeof(bi));
	delete pBinaryFile2;

	// bLoad��FALSE�Ȃ畝�ƍ����̂ݎ擾, TRUE�̓s�N�Z����ǂݍ���.
	if (bLoad) {
		// �T�C�Y�����擾.
		CBinaryFile* pBinaryFile3 = new CBinaryFile();
		pBinaryFile3->Open(lpctszFileName, GENERIC_READ, OPEN_EXISTING);
		DWORD dwSize = pBinaryFile3->GetFileSize();
		delete pBinaryFile3;
		// �s�N�Z����ǂݍ���.
		CBinaryFile* pBinaryFile4 = new CBinaryFile();
		pBinaryFile4->Read(lpctszFileName, bfh.bfOffBits, dwSize - bfh.bfOffBits);
		CopyMemory(m_lpBitsPixel, pBinaryFile4->m_pBytes, dwSize - bfh.bfOffBits);
		delete pBinaryFile4;
	}
	else {
		// ���ƍ������擾.
		m_iWidth = bi.bmiHeader.biWidth;
		m_iHeight = bi.bmiHeader.biHeight;
	}

	return TRUE;

}

// �w��s�N�Z���ɐF���Z�b�g����֐�SetPixel.
void CDIBSection::SetPixel(int x, int y, BYTE r, BYTE g, BYTE b) {

	if (m_lpBitsPixel != NULL) {
		m_lpBitsPixel[(m_iWidth * 3 + (m_iWidth * 3) % 4) * (m_iHeight - (y + 1)) + x * 3] = b;
		m_lpBitsPixel[(m_iWidth * 3 + (m_iWidth * 3) % 4) * (m_iHeight - (y + 1)) + x * 3 + 1] = g;
		m_lpBitsPixel[(m_iWidth * 3 + (m_iWidth * 3) % 4) * (m_iHeight - (y + 1)) + x * 3 + 2] = r;
	}

}