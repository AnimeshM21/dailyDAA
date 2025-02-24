#include <stdio.h>

#define MAX 10  

int g[MAX][MAX], v[MAX], n;

void dfs(int x) {
    printf("%d ", x);
    v[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] && !v[i]) dfs(i);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    dfs(0);
    return 0;
}