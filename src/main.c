#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Konektivitas graf dan derajat
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(4);
//   add_adjmatrix_undirected_edge(graph, 0, 1);
//   add_adjmatrix_undirected_edge(graph, 0, 2);
//   add_adjmatrix_undirected_edge(graph, 1, 2);

//   VertexDegree *degree_0 = find_adjmatrix_vertex_degree(graph, 0);

//   if (degree_0 != NULL)
//   {
//     printf("undirected_degrees: %d\n", degree_0->undirected_degree);
//     printf("directed_outdegrees: %d\n", degree_0->directed_outdegree);
//     printf("directed_indegrees: %d\n", degree_0->directed_indegree);
//   }

//   int is_graph_connected = is_adjmatrix_graph_connected(graph);

//   if (is_graph_connected == 1)
//   {
//     printf("ok, connected");
//   }
//   else
//   {
//     printf("NOT CONNECTED");
//   }

//   free(degree_0);
//   free_adjmatrix_graph(graph);
// }

// Pengkodean tree
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(4);
//   add_adjmatrix_undirected_edge(graph, 0, 2);
//   add_adjmatrix_undirected_edge(graph, 2, 3);
//   add_adjmatrix_undirected_edge(graph, 3, 1);

//   printf("Adjacency Matrix:\n");
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     for (int j = 0; j < graph->vertex_count; j++)
//     {
//       printf("%d ", graph->adj_matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");

//   int is_graph_tree = is_adjmatrix_graph_tree(graph);
//   if (is_graph_tree == 1)
//   {
//     printf("TREE!\n");
//   }
//   else
//   {
//     printf("NOT TREE\n");
//   }

//   PruferCode *prufer = to_prufer(graph);
//   printf("Prufer code: ");

//   if (is_graph_tree)
//   {
//     for (int i = 0; i < prufer->size; i++)
//     {
//       printf("%d ", prufer->sequence[i]);
//     }
//     print_edges_from_prufer(prufer->sequence, prufer->size);
//   }
//   else
//   {
//     printf("No prufer code for non-tree graphs");
//   }

//   free_prufer(prufer);
// }

// MST (Minimal Spanning Tree)
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(7);
//   add_weighted_adjmatrix_undirected_edge(graph, 0, 1, 2);
//   add_weighted_adjmatrix_undirected_edge(graph, 0, 2, 3);
//   add_weighted_adjmatrix_undirected_edge(graph, 0, 3, 3);
//   add_weighted_adjmatrix_undirected_edge(graph, 1, 2, 4);
//   add_weighted_adjmatrix_undirected_edge(graph, 1, 4, 3);
//   add_weighted_adjmatrix_undirected_edge(graph, 2, 3, 5);
//   add_weighted_adjmatrix_undirected_edge(graph, 2, 4, 1);
//   add_weighted_adjmatrix_undirected_edge(graph, 2, 5, 6);
//   add_weighted_adjmatrix_undirected_edge(graph, 3, 5, 7);
//   add_weighted_adjmatrix_undirected_edge(graph, 4, 5, 8);
//   add_weighted_adjmatrix_undirected_edge(graph, 5, 6, 9);

//   printf("Adjacency Matrix:\n");
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     for (int j = 0; j < graph->vertex_count; j++)
//     {
//       printf("%d ", graph->adj_matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");

//   printf("Prim's Algorithm :\n");
//   prim_mst(graph);

//   printf("\nKruskal's Algorithm :\n");
//   kruskal_mst(graph);
// }

// Dijkstra's Algorithm
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(7);
//   add_weighted_adjmatrix_directed_edge(graph, 0, 2, 3);
//   add_weighted_adjmatrix_directed_edge(graph, 0, 5, 2);
//   add_weighted_adjmatrix_undirected_edge(graph, 2, 5, 2);
//   add_weighted_adjmatrix_directed_edge(graph, 2, 4, 1);
//   add_weighted_adjmatrix_directed_edge(graph, 5, 4, 3);
//   add_weighted_adjmatrix_directed_edge(graph, 5, 6, 5);
//   add_weighted_adjmatrix_directed_edge(graph, 5, 1, 6);
//   add_weighted_adjmatrix_directed_edge(graph, 4, 1, 2);
//   add_weighted_adjmatrix_directed_edge(graph, 2, 3, 4);
//   add_weighted_adjmatrix_directed_edge(graph, 3, 1, 1);
//   add_weighted_adjmatrix_directed_edge(graph, 6, 1, 2);

//   printf("Adjacency Matrix:\n");
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     for (int j = 0; j < graph->vertex_count; j++)
//     {
//       printf("%d\t", graph->adj_matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
//   printf("Dijkstra\n");

//   dijkstra(graph, 0, 1);
// }

// Bellman-Ford's Algorithm
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(6);
//   add_weighted_adjmatrix_directed_edge(graph, 0, 5, 8);
//   add_weighted_adjmatrix_directed_edge(graph, 0, 1, 10);
//   add_weighted_adjmatrix_directed_edge(graph, 5, 4, 1);
//   add_weighted_adjmatrix_directed_edge(graph, 4, 1, -4);
//   add_weighted_adjmatrix_directed_edge(graph, 4, 3, -1);
//   add_weighted_adjmatrix_directed_edge(graph, 1, 3, 2);
//   add_weighted_adjmatrix_directed_edge(graph, 3, 2, -2);
//   add_weighted_adjmatrix_directed_edge(graph, 2, 1, 1);

//   printf("Adjacency Matrix:\n");
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     for (int j = 0; j < graph->vertex_count; j++)
//     {
//       printf("%d\t", graph->adj_matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
//   printf("Bellman Ford\n");

//   bellman_ford(graph, 0, 1);
// }

// Floyd Warshall Algorithm
// int main()
// {
//   AdjMatrixGraph *graph = create_adjmatrix_graph(4);
//   add_weighted_adjmatrix_directed_edge(graph, 0, 2, -2);
//   add_weighted_adjmatrix_directed_edge(graph, 1, 2, 3);
//   add_weighted_adjmatrix_directed_edge(graph, 1, 0, 4);
//   add_weighted_adjmatrix_directed_edge(graph, 2, 3, 2);
//   add_weighted_adjmatrix_directed_edge(graph, 3, 1, -1);

//   printf("Adjacency Matrix:\n");
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     for (int j = 0; j < graph->vertex_count; j++)
//     {
//       printf("%d\t", graph->adj_matrix[i][j]);
//     }
//     printf("\n");
//   }
//   printf("\n");
//   printf("Floyd Warshall\n");

//   floyd_warshall(graph);
// }