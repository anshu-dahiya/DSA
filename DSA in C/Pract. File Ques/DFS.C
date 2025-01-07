#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
    int numNodes;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = n;
    for (int i = 0; i < n; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Depth-First Search traversal
void DFS(Graph* graph, int startNode) {
    graph->visited[startNode] = 1;
    printf("%d ", startNode);

    Node* temp = graph->adjacencyList[startNode];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);

    // Example graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Depth-First Search traversal starting from node 0:\n");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
