// 二重インクルード防止
#ifndef __BINARY_FILE_H__
#define __BINARY_FILE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "File.h"	// CFile

// バイナリファイルCBinaryFile
class CBinaryFile : public CFile{

	// publicメンバ
	public:
	
		// publicメンバ変数
		BYTE *m_pBytes;	// バイト列へのポインタ.
		DWORD m_dwSize;	// ファイルサイズ.

		// publicメンバ関数
		// メンバ関数
		virtual void Set(BYTE *pBytes, DWORD dwSize);

};

#endif
