#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> //大文字小文字判定など
#include <limits.h>
#include <stdlib.h>
int main()
{
	int 回数[UCHAR_MAX + 1] = { 0 };//宣言
	int 要求行数;
	if (scanf("%d", &要求行数) == 1) {
		if (要求行数 > 0) {
			int 入力済み行数 = -1;
			for (;;) {
				const int ch = getchar();// 入力された１文字のコード
				switch (ch) {
				case EOF ://全体終了 end-of-file
					return EXIT_FAILURE;
				case '\n'://１行の終わり
					if (++入力済み行数 == 要求行数) {
						for (int i = 0; i < _countof(回数); ++i) {
							const int n = 回数[i];
							if (n)
								printf("%c %d\n", i, n);
							else {
								//回数が 0 なので出力しない
							}
						}
						return EXIT_SUCCESS;
					}
					else
						continue;
				default  :
					//ch が英数字であるかどうかを見る
					if (isalnum((unsigned char)ch)) {
						++回数[toupper((unsigned char)ch)];
					}
					else {
						//英数字ではないのでカウントしない
					}
					break;
				}
				//ここに到達
			}
		}
		else {
			//要求行数が 0 以下
		}
	}
	else {
		//要求行数を受け取ることが出来なかった
	}
}
/*
数字大文字小文字が含まれる文字列の大文字小文字の区別をつけずに個数をカウントしたいのですが、どうすればいいのでしょうか？
自分のやり方としては小文字を大文字に変換してからカウントすると言うことをしたかったのですが、できそうにないです。
            数値
追加で最初に数字を入力してn行の行数を指定します。その後n行の文字列を入力し、最後のその入力した文字列にあるアルファベットの合計を同様に出力します。
*/

//　「数字」 numeric character … 文字  '0', '1', '2'
//　「数値」 0, 1, 2
//  「数字列」  "12345"
