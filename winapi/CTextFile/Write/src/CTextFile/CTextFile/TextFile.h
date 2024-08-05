// 二重インクルード防止
#ifndef __TEXT_FILE_H__
#define __TEXT_FILE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

// テキストファイルクラスCTextFile
class CTextFile : public CBinaryFile{

	// publicメンバ
	public:

		// publicメンバ変数
		tstring m_tstrText;		// テキスト内容.

		// publicメンバ関数
		void SetText(tstring tstrText);	// テキストのセット.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のテキストファイルに全部一斉書き込み.

};

#endif