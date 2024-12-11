// 二重インクルード防止
#ifndef __BINARY_FILE_H__
#define __BINARY_FILE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "File.h"	// CFile

// バイナリファイルCBinaryFile
class CBinaryFile : public CFile {

	// publicメンバ
	public:

		// publicメンバ変数
		BYTE* m_pBytes;	// バイト列へのポインタ.
		DWORD m_dwSize;	// ファイルサイズ.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBinaryFile();	// コンストラクタCBinaryFile
		virtual ~CBinaryFile();	// デストラクタ~CBinaryFile
		// メンバ関数
		virtual BOOL Read(LPCTSTR lpctszFileName);	// 指定のバイナリファイルから全部一斉読み込み.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のバイナリファイルに全部一斉書き込み.
		virtual void Set(BYTE* pBytes, DWORD dwSize);	// 全部一斉に書き込むバッファのセット.
		virtual void Clear();	// バッファのクリア.

};

#endif