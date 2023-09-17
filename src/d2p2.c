#include "../brainfuck-c-util/src/bigint.h"
#include "../brainfuck-c-util/src/util.h"

#define N 2

void main() {
    int digitbuf[10];

    int score[] = {0, 0};
    int buf[N];

    bool done = false;
    while (!done) {
        int a = read_char();
        if (a == 0) {
            done = true;
        } else {
            int space = read_char();
            int b = read_char();
            int newline = read_char();

            a = a - 'A';
            b = b - 'X';

            int tmp[] = {b + a + 2};
            int q = divrem(tmp, 3);

            int new_score = tmp[0] + b * 3 + 1;

            bigint_add_small(score, new_score, N);
        }
    }

    bigint_write(score, buf, digitbuf, N);
    write_char('\n');
}
