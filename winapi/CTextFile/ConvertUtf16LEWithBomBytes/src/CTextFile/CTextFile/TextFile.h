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

		// 列挙型の定義
		// BOM
		typedef enum TAG_BOM{
			BOM_NONE,
			BOM_UTF16LE
		} BOM;

		// publicメンバ変数
		tstring m_tstrText;		// テキスト内容.
		BOM m_Bom;	// BOM.

		// publicメンバ関数
		void SetText(tstring tstrText);	// テキストのセット.
		void ConvertUtf16LEBytes();	// テキストをUTF-16LEバイト列に変換してバッファにセット.
		void ConvertUtf16LEWithBomBytes();	// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のテキストファイルに全部一斉書き込み.

};

#endif