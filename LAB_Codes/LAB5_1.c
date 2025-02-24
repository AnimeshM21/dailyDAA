#include <stdio.h>

#define MAX 10  

int g[MAX][MAX], v[MAX], stack[MAX], top = -1, n;

void dfs(int x) {
    v[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] && !v[i]) dfs(i);
    stack[++top] = x;
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        if (!v[i]) dfs(i);
    while (top >= 0) printf("%d ", stack[top--]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    topologicalSort();
    return 0;
}