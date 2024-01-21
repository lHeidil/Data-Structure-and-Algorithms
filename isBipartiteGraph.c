#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10000
#define RED 1
#define BLUE 0
#define TRUE 1
#define FALSE 0

typedef struct Graph_Vertex
{
  int value;
  char visited;
  char color;
  struct Vertex_Adjacency* adjacent;
} Vertex;

typedef struct Vertex_Adjacency
{
  struct Graph_Vertex* vertex;
  struct Vertex_Adjacency* prev;
  struct Vertex_Adjacency* next;
} VertexAdjacent;

Vertex graph[MAX_VERTEX];
Vertex* queue[MAX_VERTEX];

void init_graph ()
{
  int i;
  for (i = 0; i < MAX_VERTEX; i++)
    {
      graph[i].value = i + 1;
      graph[i].visited = FALSE;
      graph[i].adjacent = NULL;
    }
}

void addEdge (int u, int v)
{
    VertexAdjacent* adjacent;
    VertexAdjacent* adjacent_aux;
    if (graph[u - 1].adjacent == NULL)
    {
      graph[u - 1].adjacent =
      (VertexAdjacent*) (malloc (sizeof(VertexAdjacent)));
      graph[u - 1].adjacent->vertex = &graph[v - 1];
      graph[u - 1].adjacent->next = NULL;
      graph[u - 1].adjacent->prev = NULL;
    }
    else
    {
      // Sorted
      adjacent = graph[u - 1].adjacent;
      if (v < graph[u - 1].adjacent->vertex->value)
      {
          graph[u - 1].adjacent = (VertexAdjacent*) (malloc (sizeof(VertexAdjacent)));
          graph[u - 1].adjacent->vertex = &graph[v - 1];
          graph[u - 1].adjacent->next = adjacent;
          graph[u - 1].adjacent->prev = NULL;
          graph[u - 1].adjacent->next->prev = graph[u - 1].adjacent;
      }
      else
      {
         while (adjacent->next != NULL && adjacent->next->vertex->value < v)
         {
             adjacent = adjacent->next;
         }
         if (adjacent->next == NULL || adjacent->next->vertex->value != v)
         {
             adjacent_aux = adjacent->next;
             adjacent->next = (VertexAdjacent*) (malloc (sizeof(VertexAdjacent)));
             adjacent->next->vertex = &graph[v - 1];
             adjacent->next->prev = adjacent;
             adjacent->next->next = adjacent_aux;

             if (adjacent->next->next != NULL)
             {
                 adjacent->next->next->prev = adjacent->next;
             }
         }
      }
    }
}

int main ()
{

    int N, E, u, v, c, init_queue, end_queue;
    char bipartite;
    VertexAdjacent* adjacent;
    init_graph ();
    scanf ("%d %d", &N, &E);

  if (N != 0 || E != 0)
  {
      bipartite = TRUE;
      init_queue = 0;
      end_queue = 0;
      for (c = 0; c < E; c++)
      {
          scanf ("%d %d", &u, &v);
          addEdge (u, v);
          addEdge (v, u);
      }
      queue[end_queue++] = &graph[init_queue];
      graph[init_queue].color = RED;
      graph[init_queue].visited = TRUE;

      while (bipartite && init_queue != end_queue)
      {
          adjacent = queue[init_queue]->adjacent;
          while (bipartite && adjacent != NULL)
          {
              if (!adjacent->vertex->visited)
              {
                  if (queue[init_queue]->color == RED)
                  {
                      adjacent->vertex->color = BLUE;
                  }
                  else
                  {
                      adjacent->vertex->color = RED;
                  }
                  adjacent->vertex->visited = TRUE;
                  queue[end_queue++] = adjacent->vertex;
              }
              if (adjacent->vertex->color == queue[init_queue]->color)
              {
                  bipartite = FALSE;
                  break;
              }
              adjacent = adjacent->next;
         }
         init_queue ++;
      }
      if (bipartite)
      {
          printf("Yes");
      }
      else
      {
          printf("No");
      }
    }
    else
    {
        exit(0);
    }
}
