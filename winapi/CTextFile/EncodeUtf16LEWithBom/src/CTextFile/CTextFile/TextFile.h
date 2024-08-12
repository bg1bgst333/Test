// 二重インクルード防止
#ifndef __TEXT_FILE_H__
#define __TEXT_FILE_H__

// ヘッダのインクルード
// 独自のヘッダ
#include "BinaryFile.h"	// CBinaryFile

// テキストファイルクラスCTextFile
class CTextFile : public CBinaryFile {

	// publicメンバ
	public:

		// 列挙型の定義
		// 文字コード
		typedef enum TAG_ENCODING {
			ENCODING_NONE,
			ENCODING_SHIFT_JIS,
			ENCODING_UTF_16LE
		} ENCODING;
		// BOM
		typedef enum TAG_BOM {
			BOM_NONE,
			BOM_UTF16LE
		} BOM;

		// publicメンバ変数
		tstring m_tstrText;		// テキスト内容.
		ENCODING m_Encoding;	// 文字コード.
		BOM m_Bom;	// BOM.

		// publicメンバ関数
		void SetText(tstring tstrText);	// テキストのセット.
		void EncodeUtf16LE();	// テキストをUTF-16LEバイト列に変換してバッファにセット.
		void EncodeUtf16LEWithBom();	// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		BOOL ConvertShiftJisBytes();	// テキストをShift_JISバイト列に変換に変換してバッファにセット.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のテキストファイルに全部一斉書き込み.

};

#endif