// 12662 - Good Teacher
#include <cstdio>
#include <cstring>

using namespace std;
int main(int argc, char	*argv[])
{
    int n; scanf("%d", &n);
    char names[4*100]; memset(names, 0, sizeof names);
    int i = 0;
    char c;
    while (scanf("%s%c", names + (4 * i++), &c), c != '\n');

    int q; scanf("%d", &q);
    int p;

    while (q--) {
        scanf("%d", &p);
        p--; // 0-based

        if (names[4*p] != '?') {
            printf("%s\n", names + 4*p);
            continue;
        }

        int diff = 0, left = -1, right = -1;
        while (++diff) {
            if (p-diff >= 0 && left == -1 && names[4*(p-diff)] != '?') {
                left = p-diff;
            }
            if (p+diff < n && right == -1 && names[4*(p+diff)] != '?') {
                right = p+diff;
            }
            if (left+1) {
                if (right+1) {
                    printf("middle of %s and %s\n", names + 4*left, names + 4*right);
                    break;
                } else {
                    while (diff--) printf("right of ");
                    printf("%s\n", names + 4*left);
                    break;
                }
            } else if (right+1) {
                while (diff--) printf("left of ");
                printf("%s\n", names + 4*right);
                break;
            }
        }
    }

    return 0;
}
