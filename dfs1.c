#include <stdio.h>
#include <string.h>

#define MAX_NODES 100
#define INF -1
#define NUL 0

typedef struct {
    char name[100];
} Node;

Node nodes[MAX_NODES] = {
    "A", "B", "C", "D", "E"
};

char colors[MAX_NODES][10];
int d[MAX_NODES];
int f[MAX_NODES];
int prev[MAX_NODES];
int numOfNodes = 5;
int time = 0;



void dfsVisit(int u, int adjMat[MAX_NODES][MAX_NODES]) {
    strcpy(colors[u], "GRAY");
    time++;
    d[u] = time;

    for (int v = 0; v < numOfNodes; v++) {
        if (adjMat[u][v] != 0 && strcmp(colors[v], "WHITE") == 0) {
            dfsVisit(v, adjMat);
        }
    }

    strcpy(colors[u], "BLACK");
    time++;
    f[u] = time;
}

void addEdge(int adjMat[MAX_NODES][MAX_NODES], int src, int dest) {
    adjMat[src][dest] = 1;
}

void dfs(int adjMat[MAX_NODES][MAX_NODES]) {
    for (int i = 0; i < numOfNodes; i++) {
        strcpy(colors[i], "WHITE");
        d[i] = -1;
        f[i] = -1;
    }
    time = 0;
    for (int i = 0; i < numOfNodes; i++) {
        if (strcmp(colors[i], "WHITE") == 0) {
            dfsVisit(i, adjMat);
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {0};
    int numEdges;
    char node1[100], node2[100];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4); 

    dfs(graph);

    printf("Node  Discovery  Finish\n");
    for (int i = 0; i < numOfNodes; i++) {
        printf("%s      %d        %d\n", nodes[i].name, d[i], f[i]);
    }

    return 0;
}
