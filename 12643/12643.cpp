#include <cstdio>

using namespace std;
int main(int argc, char	*argv[])
{
    int N, i, j;
    int x, y, r;
    while (scanf("%d %d %d", &N, &i, &j) != EOF) {
        x = i-1;
        y = j-1;
        r = 0;
        while (x != y) {
            r++;
            x = x / 2;
            y = y / 2;
        }
        printf("%d\n", r);
    }
    return 0;
}
