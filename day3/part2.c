#include <stdio.h>
#include <stdlib.h>

static char line_one[256];
static char line_two[256];
static char line_three[256];

int parse_line(char *line)
{
    int size = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            return size;
        } else {
            line[size++] = c;
        }
    }
    return size;
}

char find_dup_items(int size_one, int size_two, int size_three)
{
    int i, j, k;
    for (i = 0; i < size_one; ++i) {
        for (j = 0; j < size_two; ++j) {
            for (k = 0; k < size_three; ++k) {
                if (line_one[i] == line_two[j] && line_one[i] == line_three[k]) {
                    return line_one[i];
                }
            }
        }
    }
    return '\0';
}

int get_item_priority(char item)
{
    if (item >= 65 && item <= 90) {
        return item - 'A' + 27;
    }
    return item - 'a' + 1;
}

int main()
{
    int total_priority = 0;
    int size_one, size_two, size_three;
    while ((size_one = parse_line(line_one)) != 0) {
        size_two = parse_line(line_two);
        size_three = parse_line(line_three);
        char item = find_dup_items(size_one, size_two, size_three);
        total_priority += get_item_priority(item);
    }
    printf("The total priority is: %d\n", total_priority);
}
