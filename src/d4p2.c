#include "../brainfuck-c-util/src/bigint.h"
#include "../brainfuck-c-util/src/util.h"

void main() {
    int s[4];
    int ans[] = {0, 0};
    int digitbuf[10];

    bool done = false;
    while (!done) {
        int l = read_string_delim(s, '-');
        if (l != 0) {
            int a = parse_int(s, l);
            l = read_string_delim(s, ',');
            int b = parse_int(s, l);
            l = read_string_delim(s, '-');
            int c = parse_int(s, l);
            l = read_string_delim(s, '\n');
            int d = parse_int(s, l);

            if (a >= c && a <= d || b >= c && b <= d || c >= a && c <= b ||
                d >= a && d <= b) {
                bigint_add_small(ans, 1, 2);
            }
        } else {
            done = true;
        }
    }

    bigint_write_consume(ans, digitbuf, 2);
    write_char('\n');
}
