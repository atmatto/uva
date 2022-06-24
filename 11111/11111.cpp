// 11111 - Generalized Matrioshkas
#include <cstdio>
#include <stack>
#include <vector>

//#define log(x...) printf(x)
#define log(x...)

using namespace std;
int main(int argc, char	*argv[]) {
    stack<int> toy;
    stack<int> sum({0});
    char c;
    int k, s;
    bool failure = false;
    while (scanf("%d%c", &k, &c) != EOF) {
        log("%d\n", k);
        if (!failure) {
            if (k < 0) { // push
                log("         T %d  S %d\n", toy.empty() ? 0 : toy.top(), sum.top());
                s = sum.top();
                sum.pop();
                sum.push(s - k);
                log("  CHANGE        %d\n", sum.top());
                if (!toy.empty() && sum.top() >= toy.top()) {
                    log("  failure: sum too big\n");
                    failure = true;
                }
                sum.push(0);
                toy.push(-k);
                log("  PUSH   T %d  S %d\n", toy.empty() ? 0 : toy.top(), sum.top());
            } else { // pop
                if (toy.empty() || toy.top() != k) {
                    log("  failure, toy %d\n", toy.empty() ? 0 : toy.top());
                    failure = true;
                } else {
                    log("         T %d  S %d\n", toy.top(), sum.top());
                    toy.pop();
                    sum.pop();
                    log("  POP    T %d  S %d\n", toy.empty() ? 0 : toy.top(), sum.top());
                }
            }
        }
        if (c == '\n') {
            if (failure || !toy.empty()) {
                printf(":-( Try again.\n");
            } else {
                printf(":-) Matrioshka!\n");
            }
            toy = stack<int>();
            sum = stack<int>({0});
            failure = false;
        }
    }
    return 0;
}
