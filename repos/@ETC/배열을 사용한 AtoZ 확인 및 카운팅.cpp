#include <stdio.h>

int main() {

	char n[26];
	int i = 0;
	char ch;
	char enter;
	int cnt[100] = {0};
	int p = 0;

	// �� �迭�� A���� Z���� �ο� 
	for (ch = 65; ch <= 90; ch++) {
		n[i] = ch;
		printf("%c\n", n[i]);
		i++;
	}
	// �Է��ϰ� �迭�� �ִ°��� Ȯ��, ī����
	while (1) {
		scanf("%c", &enter); // A: 65

		if (enter < 65 || enter > 90)
			break;

		cnt[enter - 65]++;
		printf("%d\n", cnt[enter - 65]);
	}

}