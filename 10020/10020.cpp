// 10020 - Minimal coverage
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

int main(int argc, char	*argv[]) {
    int cases; scanf("%d", &cases);
    int M;
    int l, r;
    int ans, covered, n;
    vector<ii> segments;
    vector<int> used;
    segments.reserve(100010);
    used.reserve(100010);
    while (cases--) {
        ans = covered = n = 0;
        segments.clear();
        used.clear();
        scanf("%d", &M);
        while (scanf("%d %d", &l, &r), l != 0 || r != 0) {
            segments.push_back({l, r});
            n++;
        }
        sort(segments.begin(), segments.end(), [](const ii l, const ii r) {
            return l < r;
        });
        for (int i = 0; i < n; i++) {
            if (segments[i].second < 0 || segments[i].second <= covered) continue;
            if (segments[i].first > M || segments[i].first > covered) break;
            int furthest = -1;
            int best = -1;
            for (int j = i; j < n && segments[j].first <= covered; j++) {
                if (segments[j].second > furthest) {
                    furthest = segments[j].second;
                    best = j;
                }
            }
            if (best == -1) break;
            i = best;
            covered = furthest;
            ans++;
            used.push_back(best);
            if (covered >= M) break;
        }

        if (covered >= M) {
            printf("%d\n", ans);
            for (const auto& i : used) {
                printf("%d %d\n", segments[i].first, segments[i].second);
            }
        } else {
            printf("0\n");
        }
        if (cases != 0) {
            printf("\n");
        }
    }
    return 0;
}
