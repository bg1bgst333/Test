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
			ENCODING_UTF_16LE,
			ENCODING_UTF_16BE,
			ENCODING_UTF_8,
			ENCODING_EUC_JP,
			ENCODING_JIS
		} ENCODING;
		// BOM
		typedef enum TAG_BOM {
			BOM_NONE,
			BOM_UTF16LE,
			BOM_UTF16BE,
			BOM_UTF8
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
		BOOL m_bDetectEnc;	// 文字コード推測.

		// publicメンバ関数
		void SetText(tstring tstrText);	// テキストのセット.
		void EncodeUtf16LE();	// テキストをUTF-16LEバイト列に変換してバッファにセット.
		void EncodeUtf16LEWithBom();	// テキストをBOM付きUTF-16LEバイト列に変換してバッファにセット.
		void EncodeUtf16BE();	// テキストをUTF-16BEバイト列に変換してバッファにセット.
		void EncodeUtf16BEWithBom();	// テキストをBOM付きUTF-16BEバイト列に変換してバッファにセット.
		BOOL EncodeUtf8();	// テキストをUTF-8バイト列に変換してバッファにセット.
		BOOL EncodeUtf8WithBom();	// テキストをBOM付きUTF-8バイト列に変換してバッファにセット.
		BOOL EncodeShiftJis();	// テキストをShift_JISバイト列に変換してバッファにセット.
		BOOL EncodeEucJp();	// テキストをEUC-JPバイト列に変換してバッファにセット.
		BOOL EncodeJis();	// テキストをJISバイト列に変換してバッファにセット.
		void ConvertNewLine(NEW_LINE dest, NEW_LINE src);	// 改行コードの変換.
		virtual BOOL Write(LPCTSTR lpctszFileName);	// 指定のテキストファイルに全部一斉書き込み.
		BOM CheckBom();	// BOMのチェック.
		void DecodeUtf16LEWithBom();	// BOM付きUTF-16LEのバイト列をテキストにデコード.
		void DecodeUtf16BEWithBom();	// BOM付きUTF-16BEのバイト列をテキストにデコード.
		BOOL DecodeUtf8WithBom();	// BOM付きUTF-8のバイト列をテキストにデコード.
		BOOL DecodeShiftJis();	// Shift_JISのバイト列をテキストにデコード.
		BOOL DecodeUtf8();	// UTF-8のバイト列をテキストにデコード.
		BOOL DecodeEucJp();	// EUC-JPのバイト列をテキストにデコード.
		BOOL DecodeJis();	// JISのバイト列をテキストにデコード.
		BOOL DetectEncoding();	// バイト列から文字コードを推測.
		BOOL IsUtf8(const unsigned char* lpcszStr, size_t uiLen);	// UTF-8かどうか判定する.
		BOOL IsShiftJis(const unsigned char* lpcszStr, size_t uiLen);	// Shift_JISかどうか判定する.
		BOOL IsEucJp(const unsigned char* lpcszStr, size_t uiLen);	// EUC-JPかどうか判定する.
		BOOL IsJis(const unsigned char* lpcszStr, size_t uiLen);	// JISかどうか判定する.
		NEW_LINE CheckNewLine();	// 改行のチェック.
		virtual BOOL Read(LPCTSTR lpctszFileName);	// 指定のテキストファイルを全部一斉読み込み.
		virtual void Clear();	// バッファのクリア.

};

#endif
