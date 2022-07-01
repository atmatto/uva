// 12049 - Just prune the list

#include <cstdio>
#include <unordered_set>

using namespace std;
int main(int argc, char	*argv[])
{
    int T; scanf("%d", &T);
    int n, m, i;
    unordered_multiset<int> a, b;
    unordered_multiset<int>::iterator pos;
    while (T--) {
        scanf("%d %d", &n, &m);
        while (n--) {
            scanf("%d", &i);
            a.insert(i);
        }
        while (m--) {
            scanf("%d", &i);
            if (pos = a.find(i), pos != a.end()) {
                a.erase(pos);
            } else {
                b.insert(i);
            }
        }
        printf("%lu\n", a.size() + b.size());
        a.clear();
        b.clear();
    }
    return 0;
}
