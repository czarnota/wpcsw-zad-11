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

int rect(void)
{
	int a;
	int b;

	printf("width: ");
	if (read_number(&a)) {
		printf("bad width\n");
		return 1;
	}
	if (a < 0) {
		printf("bad width\n");
		return 1;
	}

	printf("height: ");
	if (read_number(&b)) {
		printf("bad height\n");
		return 1;
	}
	if (b < 0) {
		printf("bad height\n");
		return 1;
	}

	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			printf("*");
		}
		printf("*\n");
	}

	return 0;
}
