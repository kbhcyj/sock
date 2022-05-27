#include <stdio.h>

int main() {

	char n[26];
	int i = 0;
	char ch;
	char enter;
	int cnt[100] = {0};
	int p = 0;

	// 각 배열에 A부터 Z까지 부여 
	for (ch = 65; ch <= 90; ch++) {
		n[i] = ch;
		printf("%c\n", n[i]);
		i++;
	}
	// 입력하고 배열에 있는건지 확인, 카운팅
	while (1) {
		scanf("%c", &enter); // A: 65

		if (enter < 65 || enter > 90)
			break;

		cnt[enter - 65]++;
		printf("%d\n", cnt[enter - 65]);
	}

}