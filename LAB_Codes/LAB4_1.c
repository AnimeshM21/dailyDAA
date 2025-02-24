#include <stdio.h>
#include <limits.h>

#define N 3  // Change this for a larger problem

int minCost = INT_MAX, assigned[N], bestAssign[N];

void calculateCost(int costMatrix[N][N], int person, int currentCost) {
    if (person == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < N; i++) bestAssign[i] = assigned[i];
        }
        return;
    }
    for (int job = 0; job < N; job++) {
        int taken = 0;
        for (int i = 0; i < person; i++)
            if (assigned[i] == job) taken = 1;
        if (!taken) {
            assigned[person] = job;
            calculateCost(costMatrix, person + 1, currentCost + costMatrix[person][job]);
        }
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7},
        {6, 4, 3},
        {5, 8, 1}
    };
    
    calculateCost(costMatrix, 0, 0);

    printf("Minimum Cost: %d\nOptimal Assignment:\n", minCost);
    for (int i = 0; i < N; i++)
        printf("Person %d -> Job %d\n", i, bestAssign[i]);
    
    return 0;
}