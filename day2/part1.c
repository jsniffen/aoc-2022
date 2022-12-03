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

result run_game(choice me, choice opp) {
    if (me == opp) {
        return draw;
    }

    if (me == rock) {
        if (opp == paper) {
            return loss;
        } else if (opp == scissors) {
            return win;
        }
    } else if (me == paper) {
        if (opp == rock) {
            return win;
        } else if (opp == scissors) {
            return loss;
        }
    } else if (me == scissors) {
        if (opp == rock) {
            return loss;
        } else if (opp == paper) {
            return win;
        }
    }

    fatal("Invalid game state reached");
    return loss;
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
        me = parse_choice(rhs);

        res = run_game(me, opp);
        total_score += score(me, res);
    }

    printf("Total score: %d\n", total_score);
}
