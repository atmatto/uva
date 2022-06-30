// 1203 Argus
#include <cstdio>
#include <queue>
#include <iostream>
#include <tuple>

//#define log(x...) printf(x)
#define log(x...)

using namespace std;

typedef tuple<int, int, int> iii;

int main(int argc, char	*argv[]) {
    priority_queue<iii, vector<iii>, greater<iii>> q;
    char str[64];
    int id, period, k;
    iii query; // {nextExecution, id, period}
    while(cin.getline(str, sizeof str), str[0] != '#' && (sscanf(str, "%*s %d %d", &id, &period))) {
        q.push({period, id, period});
    }
    scanf("%d", &k);
    while (k--) {
        query = q.top(); q.pop();
        printf("%d\n", get<1>(query));
        q.push(make_tuple(get<0>(query) + get<2>(query), get<1>(query), get<2>(query)));
    }
    return 0;
}