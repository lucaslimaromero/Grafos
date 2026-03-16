#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Graph *MyGraph(int num_vertices){
    Graph *G = (Graph *) malloc(sizeof(Graph));
    G->num_vertices = num_vertices;

    // First we allocate a list of pointers
    G->adj_matrix = (int **) malloc(num_vertices * sizeof(int*)); // Then, we allocate a vector for each pointer of this list, leading to a bidimensional matrix

    for(int i = 0; i < num_vertices; i++){
       G->adj_matrix[i] = (int *) malloc(num_vertices * sizeof(int));

       for(int j = 0; j < num_vertices; j++){
            G->adj_matrix[i][j] = -1; // We initialize with -1 (indicating no edge between vertices i and j)
       }
    }

    return G;
}

// Add an edge: given a graph G, the function creates an edge between vertices v1 and v2 with the specified weight.
void add_edge(Graph *G, int v1, int v2, int weight){

    // Checking whether the vertices are valid
    if(v1 >= G->num_vertices || v1 < 0 || v2 >= G->num_vertices || v2 < 0){
        printf("Invalid vertice!\n");
        return;
    }

    // If the vertices are valid
    G->adj_matrix[v1][v2] = weight;
    G->adj_matrix[v2][v1] = weight;
}

// Verify if an edge exists between vertices v1 and v2
int exist_edge(Graph *G, int v1, int v2){
    
    if(G->adj_matrix[v1][v2] == -1) // This edge does not exist!
        return 0;
    
    return 1;
}

int *neighbors(Graph *G, int v){
    int *neighbors = (int *) malloc(G->num_vertices * sizeof(int));

    for(int i = 0; i < G->num_vertices; i++)
        neighbors[i] = G->adj_matrix[v][i] == -1 ? 0 : 1;

    return neighbors;
}

// Free graph memory
void free_graph(Graph *G){
    for(int i = 0; i < G->num_vertices; i++){
        free(G->adj_matrix[i]);
    }

    free(G->adj_matrix);
    free(G);
}