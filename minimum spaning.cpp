#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

void sortEdges(struct Graph *graph) {
	int i,j;
    for (i = 0; i < graph->numEdges; i++) {
        for ( j = i + 1; j < graph->numEdges; j++) {
            if (graph->edges[i].weight > graph->edges[j].weight) {
                struct Edge temp = graph->edges[i];
                graph->edges[i] = graph->edges[j];
                graph->edges[j] = temp;
            }
        }
    }
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSets(int parent[], int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

void kruskalMST(struct Graph *graph) {
	int i;
    int parent[MAX_VERTICES];
    for (i = 0; i < MAX_VERTICES; i++) {
        parent[i] = -1;
    }

    int mstEdges = 0;
    int mstWeight = 0;

    for (i = 0; i < graph->numEdges; i++) {
        int src = graph->edges[i].source;
        int dest = graph->edges[i].destination;
        int srcParent = findParent(parent, src);
        int destParent = findParent(parent, dest);

        if (srcParent != destParent) {
            mstWeight += graph->edges[i].weight;
            mstEdges++;
            unionSets(parent, src, dest);
            printf("Edge %d: %d - %d (Weight: %d)\n", mstEdges, src, dest, graph->edges[i].weight);
        }

        if (mstEdges == graph->numVertices - 1)
            break;
    }

    printf("Total MST Weight: %d\n", mstWeight);
}

int main() {
	int i;
    struct Graph graph;
    printf("Enter number of vertices: ");
    scanf("%d", &graph.numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &graph.numEdges);

    printf("Enter edge information (source destination weight):\n");
    for (i = 0; i < graph.numEdges; i++) {
        scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
    }

    sortEdges(&graph);
    printf("Minimum Spanning Tree Edges:\n");
    kruskalMST(&graph);

    return 0;
}
