#include "../brainfuck-c-util/src/bigint.h"
#include "../brainfuck-c-util/src/util.h"

int get_prio(int c) {
    int ans = 0;

    if (c >= 'a') {
        ans = c - 'a' + 1;
    } else {
        ans = c - 'A' + 27;
    }

    return ans;
}

void main() {
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int s1[64];
    int s2[64];
    int s3[64];

    int s12[64];
    int l12 = 0;

    int ans[] = {0, 0};
    int digitbuf[10];

    bool done = false;

    while (!done) {
        l1 = read_string_delim(s1, '\n');
        if (l1 != 0) {
            l2 = read_string_delim(s2, '\n');
            l3 = read_string_delim(s3, '\n');

            l12 = 0;

            int i = 0;
            while (i < l1) {
                int j = 0;
                while (j < l2) {
                    if (s1[i] == s2[j]) {
                        s12[l12] = s1[i];
                        l12 = l12 + 1;
                    }

                    j = j + 1;
                }

                i = i + 1;
            }

            bool found = false;
            int k = 0;
            i = 0;
            while (i < l12 && !found) {
                int j = 0;
                while (j < l3 && !found) {
                    if (s12[i] == s3[j]) {
                        k = s12[i];
                        found = true;
                    }

                    j = j + 1;
                }

                i = i + 1;
            }

            int p = get_prio(k);

            bigint_add_small(ans, p, 2);
        } else {
            done = true;
        }
    }

    bigint_write_consume(ans, digitbuf, 2);
    write_char('\n');
}
