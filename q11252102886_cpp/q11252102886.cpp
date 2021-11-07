#include <limits.h>
#include <ostream>
class char_counter {
	unsigned char 番号[UCHAR_MAX + 1];
	char          文字[37           ];
	int           回数[sizeof 文字  ];
	friend std::ostream& operator<<(std::ostream& ostm, const char_counter& r);
public:
	char_counter() noexcept
		: 番号{}
		, 回数{}
	{
		番号[文字[ 0] = '0']             =  0 + 1;
		番号[文字[ 1] = '1']             =  1 + 1;
		番号[文字[ 2] = '2']             =  2 + 1;
		番号[文字[ 3] = '3']             =  3 + 1;
		番号[文字[ 4] = '4']             =  4 + 1;
		番号[文字[ 5] = '5']             =  5 + 1;
		番号[文字[ 6] = '6']             =  6 + 1;
		番号[文字[ 7] = '7']             =  7 + 1;
		番号[文字[ 8] = '8']             =  8 + 1;
		番号[文字[ 9] = '9']             =  9 + 1;
		番号[文字[10] = 'A'] = 番号['a'] = 10 + 1;
		番号[文字[11] = 'B'] = 番号['b'] = 11 + 1;
		番号[文字[12] = 'C'] = 番号['c'] = 12 + 1;
		番号[文字[13] = 'D'] = 番号['d'] = 13 + 1;
		番号[文字[14] = 'E'] = 番号['e'] = 14 + 1;
		番号[文字[15] = 'F'] = 番号['f'] = 15 + 1;
		番号[文字[16] = 'G'] = 番号['g'] = 16 + 1;
		番号[文字[17] = 'H'] = 番号['h'] = 17 + 1;
		番号[文字[18] = 'I'] = 番号['i'] = 18 + 1;
		番号[文字[19] = 'J'] = 番号['j'] = 19 + 1;
		番号[文字[20] = 'K'] = 番号['k'] = 20 + 1;
		番号[文字[21] = 'L'] = 番号['l'] = 21 + 1;
		番号[文字[22] = 'M'] = 番号['m'] = 22 + 1;
		番号[文字[23] = 'N'] = 番号['n'] = 23 + 1;
		番号[文字[24] = 'O'] = 番号['o'] = 24 + 1;
		番号[文字[25] = 'P'] = 番号['p'] = 25 + 1;
		番号[文字[26] = 'Q'] = 番号['q'] = 26 + 1;
		番号[文字[27] = 'R'] = 番号['r'] = 27 + 1;
		番号[文字[28] = 'S'] = 番号['s'] = 28 + 1;
		番号[文字[29] = 'T'] = 番号['t'] = 29 + 1;
		番号[文字[31] = 'U'] = 番号['u'] = 31 + 1;
		番号[文字[32] = 'V'] = 番号['v'] = 32 + 1;
		番号[文字[33] = 'W'] = 番号['w'] = 33 + 1;
		番号[文字[34] = 'X'] = 番号['x'] = 34 + 1;
		番号[文字[35] = 'Y'] = 番号['y'] = 35 + 1;
		番号[文字[36] = 'Z'] = 番号['z'] = 36 + 1;
	}
	void increment(char ch) noexcept
	{
		if (const auto n = 番号[ch])
			++回数[n - 1];
	}

};
std::ostream& operator<<(std::ostream& ostm, const char_counter& r)
{
	for (int i = 0; i < sizeof r.文字; ++i) {
		if (const auto n = r.回数[i])
			ostm << r.文字[i] << ' ' << n << '\n';
	}
	return ostm;
}
#include <iostream>
int main()
{
	unsigned 要求行数;
	if (std::cin >> 要求行数 && std::cin.ignore(SIZE_MAX, '\n')) {
		if (要求行数) {
			char_counter c;
			for (unsigned 入力済み行数 = 0;;) {
				char ch;
				if (std::cin.read(&ch, 1)) {
					if (ch == '\n') {
						if (++入力済み行数 == 要求行数) {
							std::cout << c;
							break;
						}
					}
					else
						c.increment(ch);
				}
				else
					break;
			}
		}
	}
}
/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11252102886
gsq********さん

2021/11/6 16:51

3回答

数字大文字小文字が含まれる文字列の大文字小文字の区別をつけずに個数をカウントしたいのですが、どうすればいいのでしょうか？
自分のやり方としては小文字を大文字に変換してからカウントすると言うことをしたかったのですが、できそうにないです。
＜例＞
入力
wE are JaPanese peopleS.

出力
A 3
E 2
J 1
L 1
N 1...

このように出力は入力にある文字をアルファベット順に文字列内の個数と一緒に並べます。

C

#include <stdio.h>
#include <string.h>

int main(void) {
char c[30];
char d[30];
scanf("%s",c);

for(int n = 0; n < strlen(c); n++){

if('番号' <= n && n <= 'z'){
n = n - ('番号' - 'A');
strcpy(d,n);
}
}
printf("%s",d);
return 0;
}

C言語関連・49閲覧・100
*/
