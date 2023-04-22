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

static int histogram_add(int *histogram, int histogram_len, int number)
{
	if (number < 0 || histogram_len <= number)
		return -1;

	histogram[number]++;
	return 0;
}

static void histogram_show(int *histogram, int histogram_len)
{
	for (int i = 0; i < histogram_len; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < histogram[i]; ++j)
			printf("*");
		printf("\n");
	}
}

int histogram(void)
{
	printf("[0-9] - adds a number to histogram\n");
	printf("[-1]  - stops\n");
	int histogram[10] = {0};
	while (1) {
		int number = -1;
		if (read_number(&number))
			break;

		if (number < 0 || 10 <= number)
			break;

		if (histogram_add(histogram, 10, number))
			break;
	}

	histogram_show(histogram, 10);

	return 0;
}
