#include <stdio.h>

int graph[10][10], visited[10], n;
int topo[10], idx;   // For topological order

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);  // DFS Traversal print

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void topoDFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            topoDFS(i);
        }
    }

    topo[idx--] = v;   // Add node after exploring (post-order)
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }

    int start;
    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    DFS(start);

    // Prepare for Topological Sort
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    idx = n - 1; // Topo array index starts from end

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            topoDFS(i);
        }
    }

    printf("\nTopological Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo[i]);
    }

    return 0;
}

