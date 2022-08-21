#include <stdio.h>

int getNum(char str[], int& idx) {
	int res = 0, stIdx = idx;
	while (str[idx] <= '9' && str[idx] >= '0') {
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	if (stIdx == idx) return -1;
	return res;
}

int oprPriority(char opr) {
	if (opr == '*' || opr == '/') return 1;
	if (opr == '+' || opr == '-') return 0;
	return 2;
}

int  numStack[100];
int numLen = 0;
char oprStack[100];
int oprLen = 0;

void calc() {
	int n0 = numStack[numLen - 2];
	int n1 = numStack[numLen - 1];
	char opr = oprStack[oprLen - 1];
	int res;
	if (opr == '+') res = n0 + n1;
	if (opr == '-') res = n0 - n1;
	if (opr == '*') res = n0 * n1;
	numStack[numLen - 2] = res;
	numLen--;
	oprLen--;
}

int main() {
	char str[1000];
	int idx = 0;
	int error = 0;

	scanf("%s", str);
	while (true) {
		int num = getNum(str, idx);
		if (num < 0) {
			error = 1;
			break;
		}
		numStack[numLen++] = num;
		if (!str[idx]) break;
		if (str[idx] != '+' && str[idx] != '-' && str[idx] != '*') {
			error = 1;
			break;
		}
		while (oprLen > 0 && oprPriority(str[idx]) <= oprPriority(oprStack[oprLen - 1])) {
			calc();
		}
		oprStack[oprLen++] = str[idx++];
	}
	if (error) {
		printf("0\n");
	} else {
		while (oprLen > 0) {
			calc();
		}
		printf("%d\n", numStack[0]);
	}
	return 0;
}
/*
10-3+5*2-6*2*1-3
10a
a
112+58-98+65-147+83
24-58-147+3
29+ab-87
*/