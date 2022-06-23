// 1062 - Containers
#include <cstdio>

//#define INF (1<<30)
//#define stackExists(ch) (stacks & (1 << ((ch) - 'A')))
//// len is the current index in the container string, not the length
//#define stackUnlocked(ch, len) ((len) <= ships[ch-'A'])
//#define log(x...) printf(x)
////#define log(x...)
//
//using namespace std;
//int main(int argc, char	*argv[]) {
//    char containers[1001];
//    int ships[26]; // Contains the index of the last container to load from every ship
//    int stacks; // Existing stacks, bitmask (1<<(ship-'A'))
//    int ans; // Number of stacks
//    int len;
//    char s;
//    bool found;
//    int caseN = 0;
//    while (scanf("%s", containers), containers[0] != 'e') {
//        for (int i = 0; i < 26; i++) {
//            ships[i] = -INF;
//        }
//        stacks = 0;
//        ans = 0;
//        len = -1;
//        while (containers[++len] != '\0') {
//            if (ships[containers[len]-'A'] == -INF) {
//                ships[containers[len]-'A'] = len;
//            }
//        }
//        while (len--) {
//            s = containers[len];
//            found = false;
//            log("%c\n", s);
//            for (char i = s; i >= 'A'; i--) {
//                log("  %c exists %d unlocked %d\n", i, stackExists(i), stackUnlocked(i, len));
//                if (stackExists(i) && (stackUnlocked(i, len) || i == s)) {
//                    stacks = stacks ^ (1<<(i-'A')) ^ (1<<(s-'A'));
//                    found = true;
//                    log("  found %d -> %d\n", stackExists(i), stackExists(i));
//                    break;
//                }
//            }
//            if (!found) {
//                ans++;
//                stacks = stacks | (1<<(s-'A'));
//                log("  created %c exists %d\n", s, stackExists(s));
//            }
//        }
//        printf("Case %d: %d\n", ++caseN, ans);
//    }
//    return 0;
//}

// After searching for some hints, it turned out to require a simple greedy solution...

#define stackExists(ch) (stacks & (1 << ((ch) - 'A')))
//#define log(x...) printf(x)
#define log(x...)

using namespace std;
int main(int argc, char	*argv[]) {
    char containers[1001];
    int stacks; // Existing stacks, bitmask (1<<(ship-'A'))
    int ans; // Number of stacks
    int j;
    char s;
    bool found;
    int caseN = 0;
    while (scanf("%s", containers), containers[0] != 'e') {
        stacks = 0;
        ans = 0;
        j = -1;
        while (containers[++j] != '\0') {
            s = containers[j];
            found = false;
            log("%c\n", s);
            for (char i = s; i <= 'Z'; i++) {
                if (stackExists(i)) {
                    stacks = stacks ^ (1<<(i-'A')) ^ (1<<(s-'A'));
                    found = true;
                    log("  found %c -> %c\n", i, s);
                    break;
                }
            }
            if (!found) {
                ans++;
                stacks = stacks | (1<<(s-'A'));
                log("  created %c exists %d\n", s, stackExists(s));
            }
        }
        printf("Case %d: %d\n", ++caseN, ans);
    }
    return 0;
}