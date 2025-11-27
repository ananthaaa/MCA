#include <stdio.h>

#define INF 999

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int parent[], int x, int y) {
    parent[x] = y;
}

int main() {
    int n, i, j;
    int adj[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                adj[i][j] = INF;
        }
    }

    int parent[10];
    for (i = 0; i < n; i++)
        parent[i] = i;

    int ne = 0, mincost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n - 1) {
        int min = INF, a = -1, b = -1;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj[i][j] < min) {
                    min = adj[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int x = find(parent, a);
        int y = find(parent, b);

        if (x != y) {
            printf("Edge %d -- %d  cost = %d\n", a, b, min);
            unionSet(parent, x, y);
            mincost += min;
            ne++;
        }

        adj[a][b] = adj[b][a] = INF;  
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}

