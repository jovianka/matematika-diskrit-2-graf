#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Adjacency List Public Types
// typedef struct ListVertex
// {
//   int value;
//   struct ListVertex *next_neighbor;
// } ListVertex;

// typedef struct ListGraph
// {
//   int vertex_count;
//   ListVertex **adj_lists;
// } ListGraph;

// Adjacency Matrix Public Types
typedef struct AdjMatrixGraph
{
  int vertex_count;
  int edge_count;
  int **adj_matrix;
} AdjMatrixGraph;

// typedef struct VertexDegree
// {
//   int undirected_degree;
//   int directed_outdegree;
//   int directed_indegree;
// } VertexDegree;

typedef struct PruferCode {
  int* sequence;
  int size;
} PruferCode;

AdjMatrixGraph *create_adjmatrix_graph(int vertex_count);
void free_adjmatrix_graph(AdjMatrixGraph *graph);
int add_adjmatrix_directed_edge(AdjMatrixGraph *graph, int src, int dest);
int add_adjmatrix_undirected_edge(AdjMatrixGraph *graph, int src, int dest);
int remove_adjmatrix_undirected_edge(AdjMatrixGraph *graph, int src, int dest);
// VertexDegree *find_adjmatrix_vertex_degree(AdjMatrixGraph *graph, int vertex); // Make sure to free the pointer after use.
int find_adjmatrix_vertex_degree(AdjMatrixGraph *graph, int vertex);
void dfs_adjmatrix(AdjMatrixGraph *graph, int start, int *visited);
int is_adjmatrix_graph_connected(AdjMatrixGraph *graph);
int is_adjmatrix_graph_tree(AdjMatrixGraph *graph);
PruferCode *to_prufer(AdjMatrixGraph *graph);
void print_edges_from_prufer(int* prufer, int m);
void free_prufer(PruferCode* prufer_code);