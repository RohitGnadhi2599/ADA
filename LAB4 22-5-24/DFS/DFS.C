digraph using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->vertices[++s->top] = value;
}

int pop(Stack *s) {
    return s->vertices[s->top--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void topologicalSortUtil(int v, int visited[], Stack *stack, int graph[][MAX_VERTICES], int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i]) {
            topologicalSortUtil(i, visited, stack, graph, n);
        }
    }
    push(stack, v);
}
void topologicalSort(int n, int graph[][MAX_VERTICES]) {
    Stack stack;
    stack.top = -1;
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, &stack, graph, n);
        }
    }
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nTopological sorting of vertices:\n");
    topologicalSort(n, graph);

    return 0;
}
