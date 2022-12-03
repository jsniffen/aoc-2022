#include <stdio.h>
#include <stdlib.h>

static char line[256];

int parse_line()
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

char find_dup_item(char *line, int size)
{
    int half = size/2;
    int i, j;
    for (i = 0; i < half; ++i) {
        for (j = half; j < size; ++j) {
            if (line[i] == line[j]) return line[i];
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
    int size;
    while ((size = parse_line()) != 0) {
        char item = find_dup_item(line, size);
        total_priority += get_item_priority(item);
    }
    printf("The total priority is: %d\n", total_priority);
}
