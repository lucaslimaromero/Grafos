#include <stdio.h>
#include "graph.h"

int main() {

    Graph *G = MyGraph(8);

    add_edge(G, 1, 2, 1);
    add_edge(G, 1, 3, 4);
    add_edge(G, 1, 8, 3);

    add_edge(G,2,3,5);
    add_edge(G,2,4,6);
    add_edge(G,2,8,2);

    add_edge(G,3,4,9);
    add_edge(G,3,5,8);

    add_edge(G,4,5,7);
    add_edge(G,4,7,11);
    add_edge(G,4,6,10);
    
    printf("%d\n", exist_edge(G, 4, 5));
    // remove_edge(G, 4, 5);
    // printf("%d\n", exist_edge(G, 4, 5));
    
    print_info(G);
    printf("%d\n", max_neighbors(G));
    delete_graph(G);

    return 0;
}