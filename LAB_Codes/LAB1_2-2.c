#include <stdio.h>

#define V 5

void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++, printf("\n"))
        for (int j = 0; j < V; j++) printf("%d ", graph[i][j]);
}

int main() {
    int graph[V][V] = {0}, edges[][2] = {{0,1},{0,4},{1,2},{1,3},{1,4},{2,3},{3,4}};
    for (int i = 0; i < 7; i++)
        graph[edges[i][0]][edges[i][1]] = graph[edges[i][1]][edges[i][0]] = 1;

    printGraph(graph);
    return 0;
}