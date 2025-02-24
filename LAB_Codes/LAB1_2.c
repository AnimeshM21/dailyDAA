#include <stdio.h>
#include <stdlib.h>

struct Node { int dest; struct Node* next; };
struct Graph { int V; struct Node** array; };

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = calloc(V, sizeof(struct Node*));
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->dest = src;
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        printf("\n%d ->", v);
        for (struct Node* temp = graph->array[v]; temp; temp = temp->next)
            printf(" %d", temp->dest);
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    int edges[][2] = {{0,1},{0,4},{1,2},{1,3},{1,4},{2,3},{3,4}};
    for (int i = 0; i < 7; i++) addEdge(graph, edges[i][0], edges[i][1]);

    printGraph(graph);
    return 0;
}