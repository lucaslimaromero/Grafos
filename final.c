#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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



static int to_internal_index(Graph *G, int v){
    if(v < 1 || v > G->num_vertices){
        return -1;
    }

    return v - 1;
}

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

    int iv1 = to_internal_index(G, v1);
    int iv2 = to_internal_index(G, v2);

    // Checking whether the vertices are valid
    if(iv1 == -1 || iv2 == -1){
        printf("Invalid vertice!\n");
        return;
    }

    // If the vertices are valid
    G->adj_matrix[iv1][iv2] = weight;
    G->adj_matrix[iv2][iv1] = weight;
}

// Verify if an edge exists between vertices v1 and v2
int exist_edge(Graph *G, int v1, int v2){
    int iv1 = to_internal_index(G, v1);
    int iv2 = to_internal_index(G, v2);

    if(iv1 == -1 || iv2 == -1){
        return 0;
    }
    
    if(G->adj_matrix[iv1][iv2] == -1) // This edge does not exist!
        return 0;
    
    return 1;
}

int *neighbors(Graph *G, int v){
    int *neighbors = (int *) malloc(G->num_vertices * sizeof(int));
    int iv = to_internal_index(G, v);

    // if(iv == -1){
    //     for(int i = 0; i < G->num_vertices; i++){
    //         neighbors[i] = 0;
    //     }

    //     return neighbors;
    // }

    for(int i = 0; i < G->num_vertices; i++)
        neighbors[i] = G->adj_matrix[iv][i] == -1 ? 0 : 1;

    return neighbors;
}

void remove_edge(Graph *G, int v1, int v2){
    int iv1 = to_internal_index(G, v1);
    int iv2 = to_internal_index(G, v2);

    if(iv1 == -1 || iv2 == -1){
        printf("Invalid vertice!\n");
        return;
    }

    G->adj_matrix[iv1][iv2] = G->adj_matrix[iv2][iv1] = -1;
}

void print_info(Graph *G){
    printf("Vertices:\n");
    for(int i = 1; i <= G->num_vertices; i++) {
        printf("%d ", i);
    }

    printf("\n\nEdges:\n");

    for(int i = 0; i < G->num_vertices; i++) {
        for(int j = i; j < G->num_vertices; j++) {

            if(G->adj_matrix[i][j] != -1) {
                printf("%d --- %d (%d)\n",
                       i+1, j+1, G->adj_matrix[i][j]); // 1-based correction
            }
        }
    }    
}

int max_neighbors(Graph *G){
    int max_neighbor_index = 0;
    int max_count = 0; // The value of the vertices of the vertice with max vertices
    int count = 0;

    for(int i = 0; i < G->num_vertices; i++){
        count = 0;
        // For each vertice i, we run throughout all its connections and count
        for(int j = 0; j < G->num_vertices; j++){
            if(G->adj_matrix[i][j] != -1){ // If there is an edge
                count++;
            }
        }

        // After that, we compare with the current max count
        if(count > max_count) {
            max_count = count;
            max_neighbor_index = i;
        }
    }

    // Internal index is 0-based; return as 1-based.
    return max_neighbor_index + 1;
}

// Print the graph
void adjacency_matrix(Graph *G){
    printf("Number of vertices: %d\n", G->num_vertices);
    printf("Adjacency Matrix:\n");

    //
    for(int i = 0; i < G->num_vertices; i++){
        for(int j = 0; j < G->num_vertices; j++){
            printf("%2d ", G->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Free graph memory
void delete_graph(Graph *G){

    for(int i = 0; i < G->num_vertices; i++){
        free(G->adj_matrix[i]);
    }

    free(G->adj_matrix);
    free(G);
}

int main() {

    int option;
    int N, x, y, w;
    Graph *G = NULL;

    scanf("%d", &N);       // número de vértices
    scanf("%d", &option);  // operação

    switch(option) {

        case 0:
            G = MyGraph(N);
            break;

        case 1:
            G = MyGraph(N);

            // lê 4 arestas (igual exemplo do enunciado)
            for(int i = 0; i < 4; i++){
                scanf("%d %d %d", &x, &y, &w);
                add_edge(G, x, y, w);
            }
            break;

        case 2:
            G = MyGraph(N);
            scanf("%d %d %d", &x, &y, &w);
            add_edge(G, x, y, w);
            printf("%d\n", exist_edge(G, x, y));
            break;

        default:
            printf("unrecognized option\n");
    }

    if(G != NULL){
        print_info(G);   
        delete_graph(G);
    }

    return 0;
}