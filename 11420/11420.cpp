// 11420 - Chest of Drawers
#include <cstdio>
#include <cstring>

using namespace std;

long memo[2][70][70];
int n, s;

// returns the number of ways
long dp(bool prev, int id, int numsec) {
    if (id > n) return numsec == s;
    long &ans = memo[prev][id][numsec];
    if (ans != -1) return ans;
    ans = numsec == s ? 1 : dp(false, id+1, numsec) + dp(true, id+1, numsec+prev);
    return ans;
}

int main(int argc, char	*argv[]) {
    while (scanf("%d %d", &n, &s), n >= 0 && s >= 0) {
        memset(memo, -1, sizeof memo);
        s++;
        printf("%ld\n", dp(true, 0, 0));
    }
    return 0;
}
