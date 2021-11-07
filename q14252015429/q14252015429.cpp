#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void report(int a, int m)
{
	printf("%dを%d回入力しました。\n", a, m);
}
int main()
{
	int a;
	if (scanf("%d", &a) == 1) {
		int n = 1;
		int m = 1;
		for (;;) {
			int b;
			if (scanf("%d", &b) == 1) {
				if (a == b)
					++m;
				else {
					report(a, m);
					a = b;
					m = 1;
				}
				if (++n == 10) {
					report(a, m);
					return EXIT_SUCCESS;
				}
				else
					continue;
			}
			else {
				report(a, m);
				fprintf(stderr, "既定の回数に達する前に入力エラーが発生しました。\n");
				return EXIT_FAILURE;
			}
		}
	}
	else {
		fprintf(stderr, "入力エラーが発生しました。\n");
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
