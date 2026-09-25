#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = V;

    graph->adjacencyMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph->adjacencyMatrix[i] = (int*)calloc(V, sizeof(int));
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
}

void DFS(struct Graph* graph, int startVertex) {
    int color[MAX_VERTICES] = { 0 }; // WHITE = 0, GRAY = 1, BLACK = 2
    int startTime[MAX_VERTICES] = { 0 };
    int finishTime[MAX_VERTICES] = { 0 };
    int time = 0;

    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = startVertex;
    color[startVertex] = 1; // GRAY
    startTime[startVertex] = ++time;

    while (top != -1) {
        int currentVertex = stack[top--];

        for (int i = 0; i < graph->numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && color[i] == 0) { // WHITE
                stack[++top] = i;
                color[i] = 1; // GRAY
                startTime[i] = ++time;
            }
        }
        color[currentVertex] = 2; // BLACK
        finishTime[currentVertex] = ++time;
    }

    
    printf("\nvertex: ");
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d ", i);
    }

    // Print discovery times
    printf("\nd     : ");
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d ", startTime[i]);
    }

    // Print finish times
    printf("\nf     : ");
    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d ", finishTime[i]);
    }

    printf("\n");
}


int main() {
    int V = 6; // Number of vertices
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    int startVertex = 0; // Starting vertex for DFS
    printf("DFS starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex);

    return 0;
}