// ヘッダのインクルード
// 独自のヘッダ
#include "Win32FileUtility.h"	// ファイルユーティリティ(C標準入出力)

// 指定のファイルから読み込んだバイト列をコードページに従ってマルチバイト文字列からワイド文字列に変換してstd::wstringに格納.
BOOL ReadMultiByteTextFileBinary(LPCSTR lpcszFileName, std::wstring& wstrWideText, UINT uiCodePage, LPDWORD lpdwLen) {

	// ファイルを開く
	HANDLE hFile = CreateFileA(lpcszFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでバイナリ読み込みで開く.
	if (hFile == INVALID_HANDLE_VALUE) {	// 失敗なら.
		return FALSE;	// FALSEを返す.
	}

	// ファイルサイズの取得
	DWORD dwSize = GetFileSize(hFile, NULL);
	if (dwSize <= 0) {
		CloseHandle(hFile);
		return FALSE;
	}

	// バッファ確保
	char* pszText = new char[dwSize + 1];
	ZeroMemory(pszText, dwSize + 1);

	// 読み込み
	DWORD dwRead;
	ReadFile(hFile, pszText, dwSize, &dwRead, NULL);
	CloseHandle(hFile);

	// マルチバイト文字列をワイド文字列に変換.
	int iLen = MultiByteToWideChar(uiCodePage, 0, pszText, -1, NULL, 0);	// MultiByteToWideCharで必要なバッファの長さを求める.
	if (iLen <= 0) {
		delete[] pszText;
		return FALSE;
	}
	WCHAR* pwszBuf = new TCHAR[iLen];	// 長さiLenのWCHARバッファを確保し, pwszBufに格納.
	*lpdwLen = MultiByteToWideChar(uiCodePage, 0, pszText, -1, pwszBuf, iLen);	// MultiByteToWideCharでpszTextをpwszBufに変換.
	pwszBuf[*lpdwLen - 1] = '\0';
	wstrWideText = pwszBuf;

	// 終了処理
	delete[] pszText;
	delete[] pwszBuf;
	return TRUE;

}