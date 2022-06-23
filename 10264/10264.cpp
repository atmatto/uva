// 10264 - The Most Potent Corner
#include <cstdio>
#include <array>
#include <cmath>

using namespace std;
int main(int argc, char	*argv[]) {
    int dimension, vertices;
    int weight[2<<14];
    int potency[2<<14];
    int max;
    while (scanf("%d", &dimension) != EOF) {
        vertices = pow(2, dimension);
        max = 0;
        for (int i = 0; i < vertices; i++) {
            scanf("%d", weight + i);
            potency[i] = 0;
        }
        // Loop over edges to set potencies
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < dimension; j++) {
                if ((1<<j & i) == 0) {
                    potency[i] += weight[i | (1<<j)];
                    potency[i | (1<<j)] += weight[i];
                }
            }
        }
        // Loop over edges to find the most potent edge
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < dimension; j++) {
                if ((1<<j & i) == 0) {
                    if (potency[i] + potency[i | (1 << j)] > max) {
                        max = potency[i] + potency[i | (1 << j)];
                    }
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
