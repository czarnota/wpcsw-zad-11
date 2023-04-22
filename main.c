#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "rect.h"
#include "dice.h"
#include "calc.h"
#include "histogram.h"

int help(void)
{
	printf("Program v0.1.0\n");
	printf("\n");
	printf("- rect\n");
	printf("- calc\n");
	printf("- dice\n");
	printf("- histogram\n");
	printf("- help\n");
	printf("\n");
	return 0;
}

int main(void)
{
	help();

	while (1) {
		printf(">>> ");

		char line[1024];
		if (!fgets(line, sizeof(line), stdin)) {
			fprintf(stderr, "input error\n");
			return 1;
		}

		char option[1024];
		if (sscanf(line, "%1023s", option) != 1)
			continue;

		if (strcmp(option, "rect") == 0)
			rect();
		if (strcmp(option, "calc") == 0)
			calc();
		if (strcmp(option, "dice") == 0)
			dice();
		if (strcmp(option, "histogram") == 0)
			histogram();
		if (strcmp(option, "help") == 0)
			help();

	}

	return 0;
}
