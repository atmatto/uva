// 1064 - Network

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

//#define log(x...) printf(x)
#define log(x...)

typedef tuple<int, int, int> iii;

int main(int argc, char	*argv[]) {
    int n, m; // messages, packets
    int c = 1;
    while (scanf("%d %d", &n, &m), n != 0) {
        log("CASE %d\n", c);
        int t1, t2, t3;
        vector<int> msgSize(n+1);
        vector<int> msgPermutation(n);
        vector<iii> packet(m); // msg, start, end
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t1);
            msgSize[i] = t1;
            msgPermutation[i - 1] = i;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &t1, &t2, &t3);
            packet[i] = {t1, t2, t3};
        }
        int currentMessage, waitingForPacket;
        int bCapacity, bSize, bBest = 1<<30;
        vector<bool> isInBuffer(m, false);
        bool nextFlag = false;
        do {
            log(" C%d order", c);
            for (int q = 0; q < n; q++) {
                log(" %d", msgPermutation[q]);
            }
            log("\n");
            currentMessage = 0;
            waitingForPacket = 1;
            bCapacity = bSize = 0;
            isInBuffer.clear();
            isInBuffer.assign(m, false);
            for (int p = 0; p < m; p++) {
                log("  p = %d\n", p);
                log("  m = %d, wp = %d\n", currentMessage, waitingForPacket);
                nextFlag = false;
            freeBuf:
                log("  buffer s = %d, c = %d\n   [", bSize, bCapacity);
                for (int i = 0; i < m; i++) { // TODO: could use something like a priority queue to speed up
                    if (isInBuffer[i])
                        log(" (%d %d %d)", get<0>(packet[i]), get<1>(packet[i]), get<2>(packet[i]));
                    if (isInBuffer[i] && get<0>(packet[i]) == msgPermutation[currentMessage] && get<1>(packet[i]) == waitingForPacket) {
                        log("!");
                        nextFlag = true;
                        waitingForPacket = get<2>(packet[i]) + 1;
                        bSize -= get<2>(packet[i]) - get<1>(packet[i]) + 1;
                        isInBuffer[i] = false;
                    }
                }
                log(" ]\n");
                if (nextFlag) {
                    if (waitingForPacket > msgSize[msgPermutation[currentMessage]]) {
                        currentMessage++;
                        waitingForPacket = 1;
                        log("  next: m = %d, wp = %d\n", currentMessage, waitingForPacket);
                    }
                    nextFlag = false;
                    goto freeBuf;
                }
                log("  packet %d %d %d\n", get<0>(packet[p]), get<1>(packet[p]), get<2>(packet[p]));
                if (get<0>(packet[p]) == msgPermutation[currentMessage] && get<1>(packet[p]) == waitingForPacket) {
                    log("  wanted this packet\n");
                    waitingForPacket = get<2>(packet[p]) + 1;
                    if (waitingForPacket > msgSize[msgPermutation[currentMessage]]) {
                        currentMessage++;
                        waitingForPacket = 1;
                        log("  next: m = %d, wp = %d\n", currentMessage, waitingForPacket);
                    }
                } else {
                    log("  packet goes to the buffer\n");
                    isInBuffer[p] = true;
                    bSize += get<2>(packet[p]) - get<1>(packet[p]) + 1;
                    bCapacity = max(bCapacity, bSize);
                }
                log("\n");
            }
            log(bBest > bCapacity ? " BETTER %d > %d\n" : " worse %d <= %d\n", bBest, bCapacity);
            bBest = min(bBest, bCapacity);
        } while (next_permutation(msgPermutation.begin(), msgPermutation.end()));
        printf("Case %d: %d\n\n", c++, bBest);
    }
}
