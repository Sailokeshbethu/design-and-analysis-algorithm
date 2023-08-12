#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int n; 
int graph[MAX_VERTICES][MAX_VERTICES]; 
bool isSafe(int v, int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;  
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}
bool hamiltonianCircuitUtil(int path[], int pos) {
    if (pos == n) {   
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }
    for (int v = 1; v < n; v++) { 
        if (isSafe(v, path, pos)) {
            path[pos] = v;
            if (hamiltonianCircuitUtil(path, pos + 1))
                return true;
            path[pos] = -1; 
        }
    }
    return false;
}
void printHamiltonianCircuit(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); 
}
int main() {
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &n);
    printf("Enter the adjacency matrix (1 if the vertices are adjacent, 0 otherwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int path[MAX_VERTICES];
    for (int i = 0; i < n; i++) {
        path[i] = -1; 
    }
    path[0] = 0; 
    if (hamiltonianCircuitUtil(path, 1)) {
        printHamiltonianCircuit(path);
    } else {
        printf("No Hamiltonian Circuit exists for the given graph.\n");
    }
    return 0;
}
