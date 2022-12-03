#include <stdio.h>
#include <stdlib.h>

void fatal(char *msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

typedef enum {
    rock,
    paper,
    scissors,
} choice;

typedef enum {
    win,
    loss,
    draw,
} result;

choice parse_choice(char c)
{
    if (c == 'A' || c == 'X') {
        return rock;
    }

    if (c == 'B' || c == 'Y') {
        return paper;
    }

    if (c == 'C' || c == 'Z') {
        return scissors;
    }

    fatal("Invalid text to convert");
    return rock;
}

result parse_result(char c) {
    switch (c) {
        case 'X':
            return loss;
        case 'Y':
            return draw;
        case 'Z':
            return win;
        default:
            fatal("cannot parse result");
            return loss;
    }
}

int score(choice c, result r)
{
    int n = 0;

    if (c == rock) n += 1;
    if (c == paper) n += 2;
    if (c == scissors) n += 3;
    if (r == win) n += 6;
    if (r == draw) n += 3;

    return n;
}

choice what_to_play(choice opp, result want)
{
    if (want == draw) return opp;

    if (opp == rock) {
        if (want == win) {
            return paper;
        } else {
            return scissors;
        }
    } else if (opp == paper) {
        if (want == win) {
            return scissors;
        } else {
            return rock;
        }
    } else if (opp == scissors) {
        if (want == win) {
            return rock;
        } else {
            return paper;
        }
    }

    fatal("Invalid game state reached");
    return rock;
}

int main()
{
    int total_score = 0;
    char lhs, rhs;
    choice opp, me;
    result res;
    while (1) {
        lhs = getchar();
        if (lhs == EOF) break;
        getchar();
        rhs = getchar();
        getchar();

        opp = parse_choice(lhs);
        res = parse_result(rhs);
        me = what_to_play(opp, res);

        total_score += score(me, res);
    }

    printf("Total score: %d\n", total_score);
}
