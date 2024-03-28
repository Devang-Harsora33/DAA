#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int edges;
    int matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void add_edge(Graph *graph, int src, int dest, int weight) {
    graph->matrix[src][dest] = weight;
    graph->matrix[dest][src] = weight;
}

void dijkstra(Graph *graph, int src, int dest, int *path_bandwidth) {
    int dist[MAX_VERTICES];
    int prev[MAX_VERTICES];
    int i, j, min;

    for (i = 0; i < graph->vertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (i = 0; i < graph->vertices - 1; i++) {
        min = INT_MAX;
        for (j = 0; j < graph->vertices; j++) {
            if (!(dist[j] == INT_MAX || dist[j] == 0) && dist[j] < min) {
                min = dist[j];
            }
        }

        for (j = 0; j < graph->vertices; j++) {
            if (graph->matrix[j][0] != 0 && dist[j] != INT_MAX && dist[j] + graph->matrix[j][0] < dist[0]) {
                dist[0] = dist[j] + graph->matrix[j][0];
                prev[0] = j;
            }
        }

        if (min == INT_MAX) {
            break;
        }

        for (j = 0; j < graph->vertices; j++) {
            if (graph->matrix[j][0] != 0 && dist[j] != INT_MAX && dist[j] + graph->matrix[j][0] < dist[0]) {
                dist[0] = dist[j] + graph->matrix[j][0];
                prev[0] = j;
            }
        }
    }

    *path_bandwidth = dist[dest];
}

int main() {
    Graph graph;
    int i, j, src, dest, path_bandwidth;

    printf("Enter the number of vertices: ");
    scanf("%d", &graph.vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &graph.edges);

    for (i = 0; i < graph.vertices; i++) {
        for (j = 0; j < graph.vertices; j++) {
            graph.matrix[i][j] = 0;
        }
    }

    for (i = 0; i < graph.edges; i++) {
        printf("Enter the source, destination, and weight of edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &path_bandwidth);
        add_edge(&graph, src, dest, path_bandwidth);
    }

    printf("Enter the source and destination vertices: ");
    scanf("%d %d", &src, &dest);

    dijkstra(&graph, src, dest, &path_bandwidth);

    printf("The maximum bandwidth path from vertex %d to vertex %d is: ", src, dest);
    if (path_bandwidth == INT_MAX) {
        printf("No path exists.\n");
    } else {
        printf("%d\n", path_bandwidth);
    }

    return 0;
}