#include <stdio.h>
#include <stdlib.h>

static char number[16];
static int numberIndex;
static int topThree[3];

void testCalories(int calories)
{
	int i, small_i;
	small_i = 0;
	for (i = 1; i < 3; ++i) {
		if (topThree[i] < topThree[small_i]) {
			small_i = i;
		}
	}

	if (calories > topThree[small_i]) {
		topThree[small_i] = calories;
	}
}

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
	int currentCalories = 0;
	while((c = fgetc(stdin)) != EOF) {
		if (c == '\n') {
			currentCalories += parseNumber();
			if (prev == '\n') {
				testCalories(currentCalories);
				currentCalories = 0;
			}
		} else {
			number[numberIndex++] = c;
		}
		prev = c;
	}
	testCalories(currentCalories);

	printf("The total calories is: %d\n", topThree[0] + topThree[1] + topThree[2]);

	return 0;
}
