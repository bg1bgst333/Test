// ヘッダファイルのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
// 独自のヘッダ
#include "BinaryFile.h"		// CBinaryFile

// 構造体タグstruct_tag_profileの定義.
struct struct_tag_profile {	// 簡易名簿
	char name[32];	// 名前
	int age;	// 年齢
	char address[128];	// 住所
};

// _tmain関数の定義
int _tmain(int argc, TCHAR* argv[]) {	// main関数のTCHAR版.

	// CBinaryFileオブジェクトの生成l.
	CBinaryFile* pBinaryFile = new CBinaryFile();

	// 読み込み.
	pBinaryFile->Read(_T("test.bin"));	// CBinaryFile::Readで"test.bin"から読み込む.

	// 出力.
	printf("name: %s\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->name);
	printf("age: %d\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->age);
	printf("address: %s\n", ((struct struct_tag_profile*)pBinaryFile->m_pBytes)->address);

	// クリア.
	pBinaryFile->Clear();	// CBinaryFile::Clearでバッファをクリア.

	// 閉じる.
	pBinaryFile->Close();	// CFile::Closeで閉じる.

	// 終了処理.
	delete pBinaryFile;

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}