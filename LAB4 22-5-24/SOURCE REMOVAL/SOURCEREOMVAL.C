#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void topologicalSort(int n, int graph[][MAX_VERTICES]);
int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nTopological sorting of vertices:\n");
    topologicalSort(n, graph);
    return 0;
}
void topologicalSort(int n, int graph[][MAX_VERTICES])
{
    int indegree[MAX_VERTICES] = {0};
    Queue q;
    q.front = -1;
    q.rear = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            enqueue(&q, i);
        }
    }
    while (!isEmpty(&q))
    {
        int vertex = dequeue(&q);
        printf("%d ", vertex);

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1)
            {
                if (--indegree[i] == 0)
                {
                    enqueue(&q, i);
                }
            }
        }
    }
    printf("\n");
}
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return item;
}
int isEmpty(Queue *q)
{
    if (q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
