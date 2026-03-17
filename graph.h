#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    int num_vertices;
    int **adj_matrix;
} Graph;

// Graph Constructor
Graph *MyGraph(int num_vertices);

// Add an edge: vertices are 1-based in the public API (1..num_vertices).
void add_edge(Graph *G, int v1, int v2, int weight);

// Verify if an edge exists between vertices v1 and v2 (1-based).
int exist_edge(Graph *G, int v1, int v2);

// Given a vertex (1-based), returns an array with all its neighbors
int *neighbors(Graph *G, int v);

// Given two vertices, we remove the edge between them (if it exists)
void remove_edge(Graph *G, int v1, int v2);

// Print the graph
void print_info(Graph *G);

// Return the vertice with max degree
int max_neighbors(Graph *G);

// Free graph memory
void delete_graph(Graph *G); 

// Adjacency matrix print
void adjacency_matrix(Graph *G);

#endif // GRAPH_H

