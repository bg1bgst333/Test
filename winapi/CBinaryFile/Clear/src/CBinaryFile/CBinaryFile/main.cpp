// ヘッダファイルのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <stdio.h>		// 標準入出力
#include <string.h>		// 文字列処理
// 独自のヘッダ
#include "BinaryFile.h"		// CBinaryFile

// 構造体タグstruct_tag_profileの定義.
struct struct_tag_profile{	// 簡易名簿
	char name[32];	// 名前
	int age;	// 年齢
	char address[128];	// 住所
};

// _tmain関数の定義
int _tmain(int argc, TCHAR *argv[]){	// main関数のTCHAR版.

	// 構造体変数の宣言
	struct struct_tag_profile prof;	// struct_tag_profile型構造体変数prof.

	// CBinaryFileオブジェクトの生成l.
	CBinaryFile *pBinaryFile = new CBinaryFile();
	
	// 値のセット.
	strcpy(prof.name, "Taro");
	prof.age = 21;
	strcpy(prof.address, "Tokyo");
	pBinaryFile->Set((BYTE *)&prof, sizeof(prof));	// CBinaryFile::Setでバイナリとサイズをセット.

	// 書き込み.
	pBinaryFile->Write(_T("test.bin"));	// CBinaryFile::Writeで"test.bin"に書き込む.

	// クリア.
	pBinaryFile->Clear();	// CBinaryFile::Clearでバッファをクリア.

	// 終了処理.
	delete pBinaryFile;

	// プログラムの終了.
	return 0;	// 0を返して正常終了.

}