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
int main()
{
  AdjMatrixGraph *graph = create_adjmatrix_graph(4);
  add_adjmatrix_undirected_edge(graph, 0, 2);
  add_adjmatrix_undirected_edge(graph, 2, 3);
  add_adjmatrix_undirected_edge(graph, 3, 1);

  printf("Adjacency Matrix:\n");
  for (int i = 0; i < graph->vertex_count; i++)
  {
    for (int j = 0; j < graph->vertex_count; j++)
    {
      printf("%d ", graph->adj_matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  int is_graph_tree = is_adjmatrix_graph_tree(graph);
  if (is_graph_tree == 1)
  {
    printf("TREE!\n");
  }
  else
  {
    printf("NOT TREE\n");
  }


  PruferCode *prufer = to_prufer(graph);
  printf("Prufer code: ");

  if (is_graph_tree)
  {
    for (int i = 0; i < prufer->size; i++)
    {
      printf("%d ", prufer->sequence[i]);
    }
    print_edges_from_prufer(prufer->sequence, prufer->size);
  }
  else
  {
    printf("No prufer code for non-tree graphs");
  }


  free_prufer(prufer);
}