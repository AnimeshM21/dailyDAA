#include <stdio.h>

#define MAX 10  

int g[MAX][MAX], inDegree[MAX], n;

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        int src = -1;
        for (int j = 0; j < n; j++)
            if (inDegree[j] == 0) { src = j; break; }

        if (src == -1) { printf("Cycle detected!\n"); return; }
        printf("%d ", src);
        inDegree[src] = -1;

        for (int j = 0; j < n; j++)
            if (g[src][j]) inDegree[j]--;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j]) inDegree[j]++;
        }
    }
    topologicalSort();
    return 0;
}