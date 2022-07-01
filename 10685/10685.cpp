// 10685 - Nature

#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//#define log(x...) printf(x)
#define log(x...)

vector<int> p, srank, ssize;
int maxSize;

int getSet(int e) {
    return (p[e] == e) ? e : p[e] = getSet(p[e]);
}

void join(int a, int b) {
    log("  Joining %d %d\n", a, b);
    a = getSet(a);
    b = getSet(b);
    log("      rep %d %d\n", a, b);
    log("        p %d %d\n", p[a], p[b]);
    log("        r %d %d\n", srank[a], srank[b]);
    log("        s %d %d\n", ssize[a], ssize[b]);
    log("\n");
    if (a == b) return;
    int &ra = srank[a], &rb = srank[b];
    if (ra > rb) {
        ssize[a] += ssize[b];
        maxSize = ssize[a] > maxSize ? ssize[a] : maxSize;
        p[b] = a;
    } else {
        ssize[b] += ssize[a];
        maxSize = ssize[b] > maxSize ? ssize[b] : maxSize;
        if (ra == rb) {
            ra++;
        }
        p[a] = b;
    }
    log("        p %d %d\n", p[a], p[b]);
    log("        r %d %d\n", srank[a], srank[b]);
    log("        s %d %d\n", ssize[a], ssize[b]);
}

int main(int argc, char	*argv[])
{
    int i = 0, c, r;
    unordered_map<string, int> m;
    char buf1[32], buf2[32];
    p = vector<int>();
    while (scanf("%d %d", &c, &r), c != 0) {
        p.clear();
        srank.clear();
        ssize.clear();
        m.clear();
        i = 0;
        maxSize = 1;
        while (c--) {
            scanf("%s", buf1);
            m[string(buf1)] = i++;
            p.push_back(i - 1);
            srank.push_back(0);
            ssize.push_back(1);
        }
        while (r--) {
            scanf("%s %s", buf1, buf2);
//            printf("%d %d", m[string(buf1)], m[string(buf2)]);
            join(m[string(buf1)], m[string(buf2)]);
        }
        printf("%d\n", maxSize);
    }
    return 0;
}
