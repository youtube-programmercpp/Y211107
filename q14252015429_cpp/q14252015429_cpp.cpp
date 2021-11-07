#include <iostream>
#include <stdlib.h>
class equal_counter {
	int value;
	int n    ;
	friend std::ostream& operator<<(std::ostream& ostm, const equal_counter& r);
public:
	equal_counter(int value) noexcept
		: value(value)
		, n(1)
	{
	}
	bool increment_if_equal(int new_value)
	{
		if (value == new_value) {
			++n;
			return true;
		}
		else
			return false;
	}
};
std::ostream& operator<<(std::ostream& ostm, const equal_counter& r)
{
	return ostm << r.value << "を" << r.n << "回入力しました。\n";
}
int main()
{
	int value;
	if (std::cin >> value) {
		equal_counter r(value);
		int n = 1;
		for (;;) {
			if (std::cin >> value) {
				const auto final_input = ++n == 10;
				if (r.increment_if_equal(value)) {
					//同じ値が入力された
					if (final_input) {
						std::cout << r;
						return EXIT_SUCCESS;
					}
					else
						continue;
				}
				else {
					//異なる値が入力された
					std::cout << r;
					if (final_input) {
						std::cout << equal_counter(value);
						return EXIT_SUCCESS;
					}
					else {
						r = value;
						continue;
					}
				}
			}
			else {
				std::cout << r;
				std::cerr << "既定の回数に達する前に入力エラーが発生しました。\n";
				return EXIT_FAILURE;
			}
		}
	}
	else {
		std::cerr << "入力エラーが発生しました。\n";
		return EXIT_FAILURE;
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q14252015429
kis********さん

2021/11/4 19:53

0回答

キーボードから10個の整数や入力し、その入力整数の並びを、整数とその整数が連続する個数の組に変形して出力するプログラム

画像
C言語関連・30閲覧

1人が共感しています
*/
