#include "../brainfuck-c-util/src/bigint.h"
#include "../brainfuck-c-util/src/util.h"

#define N 3

void insert_top3(int[] a, int[] b, int[] c, int[] new) {
    if (bigint_cmp(new, a, N) == 1) {
        memcpy(c, b, N);
        memcpy(b, a, N);
        memcpy(a, new, N);
    } else {
        if (bigint_cmp(new, b, N) == 1) {
            memcpy(c, b, N);
            memcpy(b, new, N);
        } else {
            if (bigint_cmp(new, c, N) == 1) {
                memcpy(c, new, N);
            }
        }
    }
}

void main() {
    int digitbuf[10];

    int a[] = {0, 0, 0};
    int acc[] = {0, 0, 0};
    int max1[] = {0, 0, 0};
    int max2[] = {0, 0, 0};
    int max3[] = {0, 0, 0};
    int buf[N];

    int s[10];

    int l = 0;

    bool done = false;

    while (!done) {
        memset(acc, 0, N);

        bool done2 = false;
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

        insert_top3(max1, max2, max3, acc);
    }

    bigint_add(max1, max2, N);
    bigint_add(max1, max3, N);

    bigint_write(max1, buf, digitbuf, N);
    write_char('\n');
}
