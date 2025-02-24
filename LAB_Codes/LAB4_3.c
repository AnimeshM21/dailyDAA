// Write a program for breadth-first search of a graph

#include <stdio.h>

#define MAX 10  

int g[MAX][MAX], v[MAX], n;

void bfs(int start) {
    int q[MAX], front = 0, rear = 0;
    q[rear++] = start, v[start] = 1;

    while (front < rear) {
        int x = q[front++];
        printf("%d ", x);
        for (int i = 0; i < n; i++)
            if (g[x][i] && !v[i]) q[rear++] = i, v[i] = 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    bfs(0);
    return 0;
}