#include <stdio.h>
#include <stdlib.h>

static char numbers[4];
static char number[16];
static int number_size;

int parse_line()
{
    char c;
    int i = 0;

    while (1) {
        c = getchar();
        if (c == EOF) return 0;
        if (c == '-' || c == ',' || c == '\n') {
            number[number_size++] = '\0';
            numbers[i++] = atoi(number);
            number_size = 0;

            if (c == '\n') {
                return i == 4 ? 1 : 0;
            }
        } else {
            number[number_size++] = c;
        }
    }
}

int main()
{
    int count = 0;
    while(parse_line()) {
        if ((numbers[0] >= numbers[2] && numbers[0] <= numbers[3]) || 
            (numbers[1] >= numbers[2] && numbers[1] <= numbers[3]) || 
            (numbers[2] >= numbers[0] && numbers[2] <= numbers[1]) || 
            (numbers[3] >= numbers[0] && numbers[3] <= numbers[1])) {
            count += 1;
        }
    }
    printf("The count of overlapping pairs is: %d\n", count);
}
