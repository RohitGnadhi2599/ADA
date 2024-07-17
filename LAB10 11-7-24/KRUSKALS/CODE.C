#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 20
struct Edge
{
    int src, dest, weight;
};
void Union(int parent[], int rank[], int x, int y);
int find(int parent[], int i);
void KruskalMST(struct Edge *edges, int V, int E);
int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}
void Union(int parent[], int rank[], int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
int compareEdges(const void *a, const void *b)
{
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;
    return edge1->weight - edge2->weight;
}
void KruskalMST(struct Edge *edges, int V, int E)
{
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    int parent[V];
    int rank[V];
    for (int v = 0; v < V; ++v)
    {
        parent[v] = v;
        rank[v] = 0;

    while (e < V - 1 && i < E)
    {
        struct Edge next_edge = edges[i++];
        int u = find(parent, next_edge.src);
        int v = find(parent, next_edge.dest);
        if (u != v)
        {
            result[e++] = next_edge;
            Union(parent, rank, u, v);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
    {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}
int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Edge edges[E];
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; ++i)
    {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    KruskalMST(edges, V, E);
    return 0;
}
