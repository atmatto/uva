// 1610 - Party Games
#include <cstdio>
#include <cstring>
#include <array>
#include <algorithm>

using namespace std;
int main(int argc, char	*argv[]) {
    int n;
    char names[1000*31];
    char ans[31];
    array<int, 1000> order; // contains indices to names in the right order
    int count;
    while (scanf("%d", &n), n != 0) {
        count = n;
        while (n--) {
            order[n] = n;
            scanf("%s", names + n*31);
        }
        sort(order.begin(), order.begin()+count, [names](int a, int b) {
            return strcmp(names + 31*a, names + 31*b) < 0;
        });

//        for (int i = 0; i < 31; i++) {
//            if (names[31*order[(count/2 - 1)] + i] == '\0') {
//                ans[i] = '\0';
//                break;
//            } else if (names[31*order[(count/2)] + i] == '\0') {
////                ans[i] = names[31*order[(count/2 - 1)] + i];
//                ans[i/*+1*/] = '\0';
//                break;
//            } else if (names[31*order[(count/2 - 1)] + i] == names[31*order[(count/2)] + i]//) {
//                    || names[31*order[(count/2 - 1)] + i] + 1 == names[31*order[(count/2)] + i]) {
//                ans[i] = names[31*order[(count/2 - 1)] + i];
//            } else {
//                ans[i] = names[31*order[(count/2 - 1)] + i] + 1;
//                ans[i+1] = '\0';
//                break;
//            }
//        }
        int less = 31*order[(count/2 - 1)]; // less or equal
        int more = 31*order[(count/2)]; // greater

        // TODO

        for (int i = 0; i < 31; i++) {
            if (names[less + i] == names[more + i]) {
                ans[i] = names[less + i];
            } else if (names[less + i] + 1 == names[more + i]) {
                ans[i] = names[less + i];
                ans[i + 1] = '\0';
                break;
            } else if (names[less + i] == '\0') {
                ans[i + 1] = '\0';
                break;
            } else if (names[more + i] == '\0') {
                printf("%s, %s\n", names + less, names + less + i);
                --i;
                while (names[less + (++i)] != '\0') {
                    ans[i] = names[less + i];
                }
                ans[i+1] = '\0';
                break;
            } else {
                ans[i] = names[less + i] + 1;
                if (names[less + i + 1] == '\0') {
                    ans[i] = names[less + i];
                }
                ans[i+1] = '\0';
                break;
            }
        }

        printf("%s\n", ans);
    }

    return 0;
}
