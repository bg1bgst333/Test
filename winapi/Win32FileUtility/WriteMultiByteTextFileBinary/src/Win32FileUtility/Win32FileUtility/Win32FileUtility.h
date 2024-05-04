// 二重インクルード防止
#ifndef __WIN32_FILE_UTILITY_H__
#define __WIN32_FILE_UTILITY_H__

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI

// 関数のプロトタイプ宣言
BOOL WriteMultiByteTextFileBinary(LPCSTR lpcszFileName, LPCWSTR lpcwszWideText, UINT uiCodePage, LPDWORD lpdwLen);	// 関数WriteMultiByteTextFileBinaryの宣言.

#endif