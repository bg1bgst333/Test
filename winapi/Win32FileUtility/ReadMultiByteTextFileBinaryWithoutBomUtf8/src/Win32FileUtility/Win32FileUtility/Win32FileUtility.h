// 二重インクルード防止
#ifndef __WIN32_FILE_UTILITY_H__
#define __WIN32_FILE_UTILITY_H__

// ヘッダファイルのインクルード
// 既定のヘッダファイル
#include <windows.h>	// 標準WindowsAPI
#include <string>	// std::string

// 関数のプロトタイプ宣言
BOOL ReadMultiByteTextFileBinaryWithoutBomUtf8(LPCSTR lpcszFileName, std::wstring& wstrWideText, LPDWORD lpdwLen);	// 関数ReadMultiByteTextFileBinaryWithoutBomUtf8の宣言.

#endif