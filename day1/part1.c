#include <stdio.h>
#include <stdlib.h>

static char number[16];
static int numberIndex;

int parseNumber()
{
	number[numberIndex++] = '\0';
	int result = atoi(number);
	numberIndex = 0;
	return result;
}

int main()
{
	char c;
	char prev;
	int maxCalories = 0;
	int currentCalories = 0;
	while((c = fgetc(stdin)) != EOF) {
		if (c == '\n') {
			currentCalories += parseNumber();
			if (prev == '\n') {
				maxCalories = maxCalories > currentCalories ? maxCalories : currentCalories;
				currentCalories = 0;
			}
		} else {
			number[numberIndex++] = c;
		}
		prev = c;
	}
	printf("Max calories: %d\n", maxCalories);

	return 0;
}
