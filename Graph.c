#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct Queue {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *, int);
int dequeue(Queue *);
int isEmpty(Queue *);
void readGraph();
void insert(int, int);
void DFS(int);
void BFS(int);

Node *G[MAX];
int n, visited[MAX];

void readGraph() {
    int i, vi, vj, edges;
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        G[i] = NULL;

    for (i = 0; i < n; i++) {
        printf("\nEnter number of edges: ");
        scanf("%d", &edges);

        for (i = 0; i < edges; i++) {
            printf("\nEnter an edge (u, v): ");
            scanf("%d %d", &vi, &vj);
            insert(vi, vj);
        }
    }
}

void insert(int vi, int vj) {
    Node *p, *q;
    q = (Node *)malloc(sizeof(Node));
    q->vertex = vj;
    q->next = NULL;

    if (G[vi] == NULL)
        G[vi] = q;
    else {
        p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

void DFS(int i) {
    Node *p;
    printf(" %d", i);
    p = G[i];
    visited[i] = 1;

    while (p != NULL) {
        i = p->vertex;
        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}

void BFS(int v) {
    int i, w;
    Queue q;
    Node *p;
    q.front = q.rear = -1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(&q, v);
    printf("\nVisit\t%d", v);
    visited[v] = 1;

    while (!isEmpty(&q)) {
        v = dequeue(&q);
        for (p = G[v]; p != NULL; p = p->next) {
            w = p->vertex;
            if (!visited[w]) {
                enqueue(&q, w);
                visited[w] = 1;
                printf("\nVisit\t%d", w);
            }
        }
    }
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int x) {
    if (q->rear == -1) {
        q->front = q->rear = 0;
        q->data[q->rear] = x;
    } else {
        q->rear++;
        q->data[q->rear] = x;
    }
}

int dequeue(Queue *q) {
    int x;
    x = q->data[q->front];
    
    if (q->rear == q->front) {
        q->rear = -1;
        q->front = -1;
    } else {
        q->front++;
    }
    
    return x;
}

int main() {
    int op;
    printf("Arya Joshi\n60019220020");

    do {
        printf("\n 1) Create  2) BFS  3) DFS 4) Quit\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("\n Enter starting node number: ");
                scanf("%d", &op);
                BFS(op);
                break;
            case 3:
                for (op = 0; op < n; op++)
                    visited[op] = 0;
                printf("\n Enter starting node number: ");
                scanf("%d", &op);
                DFS(op);
                break;
        }
    } while (op != 4);

    return 0;
}
