// ヘッダのインクルード
// 独自のヘッダ
#include "string_utility_cppstring.h"	// 文字列ユーティリティ(C++ std::string)

// tstring文字列targetの部分文字列beforeを全てafterに置換.
int replace_tstring_all(tstring& target, const tstring& before, const tstring& after) {

	// tstringの文字列全置換
	int c = 0;	// 個数cを0で初期化.
	tstring::size_type pos = target.find(before);	// targetで最初にbeforeが見つかった位置をposに格納.
	while (pos != tstring::npos) {	// 見つからない時まで続ける.
		c++;	// 個数cを1増やす.
		target.replace(pos, before.size(), after);	// targetをbeforeからafterに置換.
		pos = target.find(before, pos + after.size());	// 次のposを探す.
	}
	return c;	// 個数cを返す.

}