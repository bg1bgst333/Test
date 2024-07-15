// ヘッダファイルのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
// 独自のヘッダ
#include "File.h"		// CFile

// _tmain関数の定義
int _tmain(int argc, TCHAR* argv[]) {	// main関数のTCHAR版.

	// CFileオブジェクトの生成.
	CFile* pFile = new CFile();
	BOOL bRet = pFile->Open(_T("test.txt"), GENERIC_READ, OPEN_EXISTING);	// CFile::Openで"test.txt"を読み込みモード開く.
	if (bRet) {	// 成功.

		// 成功のメッセージ表示.
		printf("CFile::Open(test.txt) Success!\n");

		// 内容の読み込み.
		BYTE btBytes[1024] = { 0 };
		pFile->Read(btBytes, 5);	// CFile::Readで5バイト読み込む.
		printf("btBytes = %s\n", (char*)btBytes);

	}

	// CFileオブジェクトの破棄.
	delete pFile;

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}