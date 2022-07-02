// 1588 - Kickdown

#include <cstdio>
#include <algorithm>
using namespace std;

//#define log(x...) printf(x)
#define log(x...)

int main(int argc, char	*argv[]) {
    bool master[101], driven[101];
    int m = 0, d = 0; // lengths
    int best = 0;
    bool first = true;
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            first = !first;
            if (first) {
                best = m + d;
                // left = position of the leftmost unit of the driven section
                // relatively to the leftmost unit of the master section
                for (int left = -d; left <= m; left++) {
                    // i = probe position on the master section
                    for (int i = 0; i < m; i++) {
                        if (i-left >= 0 && i-left < d && master[i] && driven[i-left]) { // wrong
                            break;
                        } else if (left + d - 1 < i || i == m - 1) { // accepted
                            log(" accepted, left = %d\n", left);
                            log("       old best = %d\n", best);
                            best = min(best, max(m, left + d) - min(0, left));
                            log("       new best = %d\n", best);
                            break;
                        }
                    }
                }
                printf("%d\n", best);
                m = d = 0;
            }
        } else if (first) {
            master[m++] = c == '2';
        } else {
            driven[d++] = c == '2';
        }
    }
    return 0;
}
