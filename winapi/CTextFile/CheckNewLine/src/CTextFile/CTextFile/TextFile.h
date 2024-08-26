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
		// 改行コード
		typedef enum TAG_NEW_LINE {
			NEW_LINE_NONE,
			NEW_LINE_CRLF,
			NEW_LINE_LF,
			NEW_LINE_CR
		} NEW_LINE;

		// publicメンバ変数
		tstring m_tstrText;		// テキスト内容.
		ENCODING m_Encoding;	// 文字コード.
		BOM m_Bom;	// BOM.
		NEW_LINE m_NewLine;	// 改行コード.

		// publicメンバ関数
		void SetText(tstring tstrText);	// テキストのセット.
		void EncodeUtf16LE();	// テキストをUTF-16LEバイト列に変換してバッファにセット.
		void EncodeUtf16LEWithBom();	// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		BOOL EncodeShiftJis();	// テキストをShift_JISバイト列に変換に変換してバッファにセット.
		void ConvertNewLine(NEW_LINE dest, NEW_LINE src);	// 改行コードの変換.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のテキストファイルに全部一斉書き込み.
		BOM CheckBom();	// BOMのチェック.
		void DecodeUtf16LEWithBom();	// BOM付きUTF-16LEのバイト列をテキストにデコード.
		BOOL DecodeShiftJis();	// Shift_JISのバイト列をテキストにデコード.
		NEW_LINE CheckNewLine();	// 改行のチェック.
		virtual BOOL Read(LPCTSTR lpctszFileName);	// 指定のテキストファイルを全部一斉読み込み.
		virtual void Clear();	// バッファのクリア.

};

#endif