// 13181 - Sleeping in hostels
// TODO: It can be solved without having to iterate twice over the bed array.
#include <cstdio>

using namespace std;
int main(int argc, char	*argv[])
{
    char beds[500010];
    int closest[500010];
    int size, right, best;
    int i = -1;
    while (scanf("%s", beds) != EOF) {
        i = -1;
        size = best = 0;
        while (beds[++i] != '\0') {
            size++;
            if (beds[i] == 'X') {
                closest[i] = -1;
            } else if (beds[i] == '.') {
                if(i == 0) {
                    closest[i] = 500010;
                } else {
                    closest[i] = closest[i - 1] + 1;
                }
            }
        }
        i = size;
        right = 500010;
        while (--i >= 0) {
            if (beds[i] == '.') {
                right++;
                if (right < closest[i]) closest[i] = right;
                if (closest[i] > best) best = closest[i];
            } else {
                right = -1;
            }
        }

        printf("%d\n", best);
    }
    return 0;
}
