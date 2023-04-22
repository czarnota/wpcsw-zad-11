#include <stdio.h>

static int read_number(int *a)
{
	char buf[64];
	if (!fgets(buf, sizeof(buf), stdin))
		return -1;

	if (sscanf(buf, "%d", a) != 1)
		return -1;
	return 0;
}

static int read_character(char *a)
{
	char buf[64];
	if (!fgets(buf, sizeof(buf), stdin))
		return -1;

	if (sscanf(buf, " %c", a) != 1)
		return -1;
	return 0;
}

int calc(void)
{
	int a;
	char c;
	int b;

	printf("first number: ");
	if (read_number(&a)) {
		printf("calc: bad number\n");
		return 1;
	}
	printf("operation: ");
	if (read_character(&c)) {
		printf("calc: bad operation\n");
		return 1;
	}
	printf("second number: ");
	if (read_number(&b)) {
		printf("calc: bad number\n");
		return 1;
	}

	if (c == '+') {
		printf("%d\n", a + b);
		return 0;
	}
	if (c == '-') {
		printf("%d\n", a - b);
		return 0;
	}
	if (c == '*') {
		printf("%d\n", a * b);
		return 0;
	}
	if (c == '/') {
		if (!b) {
			printf("calc: can't divide by zero\n");
			return 1;
		}

		float result = (float)a / b;
		printf("%f\n", result);
		return 0;
	}

	return 0;
}


