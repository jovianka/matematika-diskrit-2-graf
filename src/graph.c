#include "graph.h"

// // Adjacency List
// ListVertex *create_list_vertex(int val)
// {
//   ListVertex *new_vertex = (ListVertex *)malloc(sizeof(ListVertex));
//   new_vertex->value = val;
//   new_vertex->next_neighbor = NULL;

//   return new_vertex;
// }

// ListGraph *create_list_graph(int vertex_count)
// {
//   ListGraph *new_graph = (ListGraph *)malloc(sizeof(ListGraph));
//   new_graph->vertex_count = vertex_count;

//   new_graph->adj_lists = (ListVertex **)malloc(vertex_count * sizeof(ListVertex *));

//   for (int i = 0; i < vertex_count; i++)
//   {
//     ListVertex *head_vertex = create_list_vertex(i);
//     new_graph->adj_lists[i] = head_vertex;
//   }

//   return new_graph;
// }

// int add_adjlist_graph_directed_edge(ListGraph *graph, int src, int dest)
// {
//   ListVertex *new_vertex;
//   ListVertex *temp;

//   // Check if src is already linked to dest.
//   new_vertex = create_list_vertex(dest);
//   temp = graph->adj_lists[src];
//   while (temp != NULL)
//   {
//     if (temp->value == new_vertex->value)
//     {
//       printf("edge from %d to %d already exists, skipping...", src, dest);
//       temp = temp->next_neighbor;
//       return 0;
//     }
//   }

//   // Create edge from src to dest.
//   new_vertex->next_neighbor = graph->adj_lists[src]->next_neighbor;
//   graph->adj_lists[src]->next_neighbor = new_vertex;

//   return 1;
// }

// void add_adjlist_graph_undirected_edge(ListGraph *graph, int va, int vb)
// {
//   add_adjlist_graph_directed_edge(graph, va, vb);
//   add_adjlist_graph_directed_edge(graph, vb, va);
// }

// int is_list_graph_connected(ListGraph *graph_a, ListGraph *graph_b)
// {
// }

// ADJACENCY MATRIX

AdjMatrixGraph *create_adjmatrix_graph(int vertex_count)
{
  AdjMatrixGraph *graph = malloc(sizeof(AdjMatrixGraph));
  graph->vertex_count = vertex_count;
  graph->edge_count = 0;
  graph->adj_matrix = (int **)malloc(vertex_count * sizeof(int *));

  for (int i = 0; i < vertex_count; i++)
  {
    graph->adj_matrix[i] = (int *)calloc(vertex_count, sizeof(int));
  }

  return graph;
}

void free_adjmatrix_graph(AdjMatrixGraph *graph)
{
  for (int i = graph->vertex_count - 1; i >= 0; i--)
  {
    free(graph->adj_matrix[i]);
  }
  free(graph->adj_matrix);
  free(graph);
}

int add_adjmatrix_directed_edge(AdjMatrixGraph *graph, int src, int dest)
{
  graph->adj_matrix[src][dest] = 1;

  return 1;
}

int add_adjmatrix_undirected_edge(AdjMatrixGraph *graph, int src, int dest)
{
  graph->adj_matrix[src][dest] = 1;
  graph->adj_matrix[dest][src] = 1;
  graph->edge_count += 1;

  return 1;
}

int remove_adjmatrix_undirected_edge(AdjMatrixGraph *graph, int src, int dest)
{
  graph->adj_matrix[src][dest] = 0;
  graph->adj_matrix[dest][src] = 0;
  graph->edge_count -= 1;

  return 1;
}

int find_adjmatrix_vertex_degree(AdjMatrixGraph *graph, int vertex)
{
  int degree = 0;
  for (int i = 0; i < graph->vertex_count; i++)
  {
    if (graph->adj_matrix[vertex][i] == 1 && graph->adj_matrix[i][vertex] == 1)
    {
      degree += 1;
    }
  }

  return degree;
}

// This one's for graphs with directed edges.
// VertexDegree *find_adjmatrix_vertex_degree(AdjMatrixGraph *graph, int vertex)
// {
//   VertexDegree *degrees = (VertexDegree *)calloc(1, sizeof(VertexDegree));
//   for (int i = 0; i < graph->vertex_count; i++)
//   {
//     if (graph->adj_matrix[vertex][i] == 1 && graph->adj_matrix[i][vertex] == 1)
//     {
//       degrees->undirected_degree += 1;
//       continue;
//     }
//     if (graph->adj_matrix[vertex][i] == 1)
//     {
//       degrees->directed_outdegree += 1;
//       continue;
//     }
//     if (graph->adj_matrix[i][vertex] == 1)
//     {
//       degrees->directed_indegree += 1;
//     }
//   }

//   return degrees;
// }

void dfs_adjmatrix(AdjMatrixGraph *graph, int start, int *visited)
{
  visited[start] = 1;

  for (int i = 0; i < graph->vertex_count; i++)
  {
    if (graph->adj_matrix[start][i] == 1 && visited[i] != 1)
    {
      dfs_adjmatrix(graph, i, visited);
    }
  }
}

int is_adjmatrix_graph_connected(AdjMatrixGraph *graph)
{
  int *visited = (int *)calloc(graph->vertex_count, sizeof(int));
  dfs_adjmatrix(graph, 0, visited);

  for (int i = 0; i < graph->vertex_count; i++)
  {
    if (visited[i] != 1)
    {
      free(visited);
      return 0;
    }
  }
  free(visited);

  return 1;
}

// PENGKODEAN TREE

/**
 * @brief
 *
 * Check if a graph is a tree.
 *
 * @param graph
 * @return int
 */
int is_adjmatrix_graph_tree(AdjMatrixGraph *graph)
{
  if (is_adjmatrix_graph_connected(graph) && graph->edge_count == graph->vertex_count - 1)
  {
    return 1;
  }

  return 0;
}

PruferCode *to_prufer(AdjMatrixGraph *graph)
{
  PruferCode *prufer_code;
  prufer_code->sequence = calloc(graph->vertex_count - 2, sizeof(int));
  prufer_code->size = graph->vertex_count - 2;

  int prufer_graph_size = graph->vertex_count;
  int current_prufer_index = 0;

  if (is_adjmatrix_graph_tree(graph) == 0)
  {
    printf("Graph is a not a tree\n");
    return prufer_code;
  }

  while (prufer_graph_size > 2)
  {
    int smallest_leaf = 999;
    for (int i = 0; i < graph->vertex_count; i++)
    {
      if (find_adjmatrix_vertex_degree(graph, i) == 1 && i < smallest_leaf) // Find a leaf
      {
        smallest_leaf = i;
      }
    }

    // Remove the smallest valued leaf.
    for (int j = 0; j < graph->vertex_count; j++)
    {
      if (graph->adj_matrix[smallest_leaf][j] == 1)
      {
        prufer_code->sequence[current_prufer_index] = j;
        current_prufer_index += 1;
        prufer_graph_size -= 1;
        remove_adjmatrix_undirected_edge(graph, smallest_leaf, j);
      }
    }
  }

  free_adjmatrix_graph(graph);

  return prufer_code;
}

void free_prufer(PruferCode* prufer_code){
  free(prufer_code->sequence);
}

void print_edges_from_prufer(int *prufer, int m)
{
  int vertices = m + 2;
  int *vertex_set = (int *)calloc(vertices, sizeof(int));

  // Jumlah kemunculan verteks
  for (int i = 0; i < vertices - 2; i++)
    vertex_set[prufer[i]] += 1;

  printf("\nHimpunan edge E(G) is :\n");

  // Cari label terkecil yang tidak ada dalam Prufer
  int j = 0;
  for (int i = 0; i < vertices - 2; i++)
  {
    for (j = 0; j < vertices; j++)
    {
      // Jika j+1 tidak ada
      if (vertex_set[j] == 0)
      {
        // Hapus dari (himpunan Prufer dan cetak
        vertex_set[j] = -1;
        printf("(%d, %d)  ", j, prufer[i]);
        vertex_set[prufer[i]]--;
        break;
      }
    }
  }
  j = 0;

  // Untuk elemen terakhir
  for (int i = 0; i < vertices; i++)
  {
    if (vertex_set[i] == 0 && j == 0)
    {
      printf("(%d, ", i);
      j++;
    }
    else if (vertex_set[i] == 0 && j == 1)
      printf("%d)\n", i);
  }

  free(vertex_set);
}