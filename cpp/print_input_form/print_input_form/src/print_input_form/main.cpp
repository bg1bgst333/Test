// ヘッダのインクルード
#include <iostream> // C++標準入出力
#include <string> // std::string

// 関数のプロトタイプ宣言
std::string print_input_form(const std::string& form_str); // 関数print_input_formの宣言.

// main関数
int main(){

  // 入力フォームを表示し, 入力文字列を取得したら, それも出力.
  std::cout << print_input_form("str: ") << std::endl; // print_input_formで入力フォームの表示と入力文字列の取得, そして入力文字列の出力.

  // プログラムの終了
  return 0; // 0を返して正常終了.

}

// 関数print_input_formの定義
std::string print_input_form(const std::string& form_str){ // 入力フォームを表示する関数print_input_form.

  // オブジェクトの宣言
  std::string input_str; // 入力文字列input_str.

  // 入力フォームを出力.
  std::cout << form_str; // 出力演算子でform_strを出力.

  // 入力文字列の取得.
  std::getline(std::cin, input_str); // std::getlineでstd::cinからの入力文字列をinput_strに格納.

  // 入力文字列を返す.
  return input_str; // returnでinput_strを返す.

} 
