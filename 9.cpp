#include <stdio.h>

int main() {
	char str[1000];
	int i, j, k, max = 0;
	int st, ed;

	gets(str);

	for (i = 0; str[i]; i++) {
		for (j = i; str[j]; j++) {
			for (k = i; k < j; k++) {
				if (str[k] == str[j]) break;
			}
			if (k < j) break;
		}
		if (j - i > max) {
			max = j - i;
			st = i;
			ed = j;
		}
	}

	printf("%d\n", max);
	for (i = st; i < ed; i++)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
/*
abcdabcd
aaaaaaaaab
*/