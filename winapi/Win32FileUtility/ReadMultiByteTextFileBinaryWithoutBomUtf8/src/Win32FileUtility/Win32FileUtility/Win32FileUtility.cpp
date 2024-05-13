// ヘッダのインクルード
// 独自のヘッダ
#include "Win32FileUtility.h"	// ファイルユーティリティ(C標準入出力)

// 指定のファイルからBOM以外を読み込んだUTF-8マルチバイト文字列からワイド文字列に変換してstd::wstringに格納.
BOOL ReadMultiByteTextFileBinaryWithoutBomUtf8(LPCSTR lpcszFileName, std::wstring& wstrWideText, LPDWORD lpdwLen) {

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
	DWORD dwTextSize = dwSize - 3;	// BOM分を引く.
	char* pszText = new char[dwTextSize + 1];
	ZeroMemory(pszText, dwTextSize + 1);

	// 3バイト先に移動.
	SetFilePointer(hFile, 3, NULL, FILE_BEGIN);	// SetFilePointerで3バイト先に移動.

	// 読み込み
	DWORD dwRead;
	ReadFile(hFile, pszText, dwTextSize, &dwRead, NULL);
	CloseHandle(hFile);

	// UTF-8マルチバイト文字列をワイド文字列に変換.
	int iLen = MultiByteToWideChar(CP_UTF8, 0, pszText, -1, NULL, 0);	// MultiByteToWideCharで必要なバッファの長さを求める.
	if (iLen <= 0) {
		delete[] pszText;
		return FALSE;
	}
	WCHAR* pwszBuf = new TCHAR[iLen];	// 長さiLenのWCHARバッファを確保し, pwszBufに格納.
	*lpdwLen = MultiByteToWideChar(CP_UTF8, 0, pszText, -1, pwszBuf, iLen);	// MultiByteToWideCharでpszTextをpwszBufに変換.
	pwszBuf[*lpdwLen - 1] = '\0';
	wstrWideText = pwszBuf;

	// 終了処理
	delete[] pszText;
	delete[] pwszBuf;
	return TRUE;

}