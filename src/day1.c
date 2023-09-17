#include "../brainfuck-c-util/src/bigint.h"
#include "../brainfuck-c-util/src/util.h"

#define N 3

void main() {
    int digitbuf[10];

    int a[] = {0, 0, 0};
    int acc[] = {0, 0, 0};
    int max[] = {0, 0, 0};
    int buf[N];

    int s[10];

    int l = 0;

    bool done = false;
    bool done2 = false;

    while (!done) {
        memset(acc, 0, N);

        done2 = false;
        while (!done2) {
            l = read_string_delim(s, '\n');
            if (l == 0) {
                done2 = true;
                if (s[0] == 0) {
                    done = true;
                }
            } else {
                memset(a, 0, N);
                bigint_parse(s, l, a, buf, N);

                bigint_add(acc, a, N);
            }
        }

        if (bigint_cmp(acc, max, N) == 1) {
            memcpy(max, acc, N);
        }
    }

    bigint_write(max, buf, digitbuf, 3);
    write_char('\n');
}
