#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int num_vertices;
    int **adj_matrix;
} Graph;

// Graph Constructor
Graph *MyGraph(int num_vertices);

// Add an edge: given a graph G, the function creates an edge between vertices v1 and v2 with the specified weight.
void add_edge(Graph *G, int v1, int v2, int weight);

// Verify if an edge exists between vertices v1 and v2
int exist_edge(Graph *G, int v1, int v2);

// Given a vertice, it returns an array with all its neighbors
int *neighbors(Graph *G, int v);

// Free graph memory
void free_graph(Graph *G); 

#endif // GRAPH_H

