#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

int main() {

    int option;
    int N, x, y, w;
    
    // Auxiliar variables
    int res;
    int *res_vec = NULL;
    int last_op = -1;

    bool print_status = 1;

    // Graph data structure
    Graph *G = NULL;

    scanf("%d", &option);  // operação
    while(option != -1)
    {
        switch(option) {

        case 0:
            // a) Instanciar um grafo
            scanf("%d", &N);       
            G = MyGraph(N);
            break;

        case 1:

            // b) Criar aresta
            scanf("%d %d %d", &x, &y, &w);
            add_edge(G, x, y, w);
            break;

        case 2:
            // c) Verificar se aresta existe
            
            scanf("%d %d", &x, &y);
            res = exist_edge(G, x, y);
            last_op = 2;
            print_status = 0; // Vamos printar apenas no final
            break;

        case 3:
            // d) Array de vértices adjacentes a v
            scanf("%d", &x);
            
            if(res_vec != NULL)
                free(res_vec);

            res_vec = neighbors(G, x);
            last_op = 3;
            print_status = 0; // Vamos printar apenas no final

            break;

        case 4:
            scanf("%d %d", &x, &y);
            

            if(!exist_edge(G, x, y)){
                print_status = 0;
                res = -1;
                last_op = 4;
            }
            else {
                remove_edge(G, x, y);
                print_status = 1;
            }
                
            break;

        case 5:
            last_op = 5;
            print_status = 0;
            break;


        default:
            printf("unrecognized option %d!\n", option);
        }

        scanf("%d\n", &option); // Analisar esse /n
    }

    if(option == -1 && G != NULL){
        if(print_status)
            print_info(G);
        else
            if(last_op == 2) {
                printf("%d\n", res);
        }
        else if(last_op == 3) {

            for(int i = 0; i < G->num_vertices; i++) {
                if(res_vec[i] == 1) {
                    printf("%d ", i + 1);
                }
            }
            // printf("\n");
            free(res_vec);
        }
        else if(last_op == 4) {
            printf("%d\n", res);
        }
        else if (last_op == 5) {
            adjacency_matrix(G);
        }
    }
    
    
    delete_graph(G);

    return 0;
}