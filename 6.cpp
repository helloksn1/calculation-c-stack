#include <stdio.h>
#include <string.h>

char txt[10000];
char res[10000];
char word[1000];
char rep[1000];

int main() {
	gets(txt);
	gets(word);
	gets(rep);
	char* pos;
	char* mv;
	char* stpos = txt;
	int resLen = 0;
	int wordLen = strlen(word);
	int repLen = strlen(rep);
	// pos: txt中word的位置
	//ex: aaabcabcaaaaabcaaa
	//pos: 3, 6, 13 + word的开始地址
	int found = 0;
	for (pos = strstr(stpos, word); pos; pos = strstr(stpos, word)) {
		found = 1;
		// stpos ~ pos是分别为 aaa(0 ~ 3), a(5), aaaaa(8 ~ 13), aaa(15 ~ 18)
		// 这个要直接复制
		for (mv = stpos; mv < pos; mv++) {
			res[resLen++] = *mv;
		}
		strcat(res, rep);
		resLen += repLen;
		stpos = pos + wordLen;
	}
	for (mv = stpos; *mv; mv++) {
		res[resLen++] = *mv;
	}
	if (!found) puts("未找到指定字符串");
	puts(res);
	return 0;
}
/*
abcdefabcdabcsdf
abc
aa
aaaaaaaaaaaaaaaa
bbbb
ccc
aaaaaaaaabbb
bbb
dddd
*/