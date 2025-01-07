#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Structure to represent the graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    if (graph->edge == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return graph;
}

// Function to find the subset of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weights
int compare(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*)a;
    struct Edge* b_edge = (struct Edge*)b;
    return a_edge->weight - b_edge->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; // Stores the result MST
    int e = 0; // Index variable for result[]

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare); // Sort the edges

    // Allocate memory for V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    if (subsets == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is V-1
    while (e < V - 1 && graph->E > 0) {
        // Pick the smallest edge
        struct Edge next_edge = graph->edge[0];
        graph->edge[0] = graph->edge[graph->E - 1];
        graph->E--;

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result and increment the index
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree (MST) using Kruskal's algorithm:\n");
    for (int i = 0; i < e; i++)
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // Add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // Add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // Add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // Add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
