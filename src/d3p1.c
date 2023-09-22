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
    int l = 0;
    int s[64];
    int r[1];
    int ans[] = {0, 0};
    int digitbuf[10];

    bool done = false;

    while (!done) {
        l = read_string_delim(s, '\n');

        if (l == 0) {
            done = true;
        } else {
            r[0] = l;
            int l2 = divrem(r, 2);
            int i = 0;
            int k = 0;
            bool found = false;
            while (i < l2 && !found) {
                int j = l2;
                while (j < l && !found) {
                    if (s[i] == s[j]) {
                        k = s[i];
                        found = true;
                    }

                    j = j + 1;
                }
                i = i + 1;
            }

            int p = get_prio(k);

            bigint_add_small(ans, p, 2);
        }
    }

    bigint_write_consume(ans, digitbuf, 2);
    write_char('\n');
}
