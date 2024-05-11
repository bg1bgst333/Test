// ヘッダのインクルード
// 独自のヘッダ
#include "Win32FileUtility.h"	// ファイルユーティリティ(C標準入出力)

// 指定のワイド文字列を指定のコードページのマルチバイト文字列に変換し, バイナリモードで追加書き込み.
BOOL AppendMultiByteTextFileBinary(LPCSTR lpcszFileName, LPCWSTR lpcwszWideText, UINT uiCodePage, LPDWORD lpdwLen){

	// ワイド文字をマルチバイト文字に変換する.
	int iBufLen = WideCharToMultiByte(uiCodePage, 0, lpcwszWideText, -1, NULL, 0, NULL, NULL);	// まずは長さを取得.
	if (iBufLen < 0){	// 負の値.
		return FALSE;	// FALSEを返す
	}
	char *pszBuf = new char[iBufLen];	// iBufLenのchar型バッファを確保.
	iBufLen = WideCharToMultiByte(uiCodePage, 0, lpcwszWideText, -1, pszBuf, iBufLen, NULL, NULL);	// 変換.
	pszBuf[iBufLen - 1] = '\0';	// NULL終端.

	// ファイル書き込み
	HANDLE hFile = CreateFileA(lpcszFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFileでバイナリ書き込みで開く.
	if (hFile == INVALID_HANDLE_VALUE){	// 失敗なら.
		delete [] pszBuf;
		return FALSE;	// FALSEを返す.
	}
	SetFilePointer(hFile, 0, NULL, FILE_END);	// SetFilePointerでファイルポインタを末尾に移動.
	WriteFile(hFile, pszBuf, iBufLen - 1, lpdwLen, NULL);	// WriteFileで書き込み.
	CloseHandle(hFile);

	// 終了処理
	delete [] pszBuf;	// メモリ解放.
	return TRUE;	// TRUEを返す.

}