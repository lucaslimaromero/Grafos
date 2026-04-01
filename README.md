# 🧠 Graph ADT in C

Implementação de um Tipo Abstrato de Dados (TAD) de Grafos em C utilizando matriz de adjacência, desenvolvida para a disciplina SCC-0216 — Modelagem Computacional em Grafos (ICMC-USP).

---

## 🚀 Funcionalidades

- Criar grafo (MyGraph)
- Adicionar aresta (add_edge)
- Verificar aresta (exist_edge)
- Listar vizinhos (neighbors)
- Remover aresta (remove_edge)
- Imprimir grafo (print_info)
- Vértice com mais vizinhos (max_neighbors)
- Imprimir matriz de adjacência (adjacency_matrix)
- Liberar memória (delete_graph)

---

## 🧩 Estrutura

main.c   → leitura de comandos  
graph.c  → implementação  
graph.h  → interface  

---

## ⚙️ Execução

Compilar:
gcc main.c graph.c -o graph

Rodar com entrada:
./graph < input.in

Comparar saída:
./graph < input.in > out.txt
diff out.txt expected.out

---

## 📄 Formato de Entrada

0 N          → cria grafo  
1 v1 v2 w    → adiciona aresta  
2 v1 v2      → verifica aresta  
3 v          → vizinhos  
4 v1 v2      → remove aresta  
5            → matriz de adjacência  
6            → max_neighbors  
7            → print_info  
-1           → fim  

---

## ⚠️ Observações

- Grafo não-direcionado (matriz simétrica)
- Índices externos 1-based, internos 0-based
- -1 representa ausência de aresta (impresso como 0)
- Saída deve ser exatamente igual ao esperado (sensível a espaços)

---

## 👨‍💻 Autor

Lucas Lima Romero - 13676325
Marcelo Eduardo Reginato - 13676965
