#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int id;
    node *link;
};

typedef struct list
{
    node *head;
    node *tail;
    int number_of_nodes;
} List;

typedef struct queue
{
    List *ptr_list;
} Queue;

int check_path(int **graph, int n, int u, int v);

void list_initialize(List *list);
void list_insert_rear(List *list, int id);
void list_delete_front(List *list);
void queue_initialize(Queue *ptr_queue);
void queue_enqueue(Queue *ptr_queue, int id);
void queue_dequeue(Queue *ptr_queue);
int queue_is_empty(Queue *ptr_queue);
int queue_peek(Queue *ptr_queue);

int check_path(int **graph, int n, int v, int u)
{
    //TODO
    int *visited = (int *)calloc(n, sizeof(int));
    Queue queue;
    queue_initialize(&queue);
    queue_enqueue(&queue, v);
    while (!queue_is_empty(&queue))
    {
        for (int i = 0; i < n; i++)
        {
            if (graph[queue_peek(&queue)][i] == 1 && visited[i] == 0)
            {
                queue_enqueue(&queue, i);
            }
        }
        visited[queue_peek(&queue)] = 1;
        queue_dequeue(&queue);
    }
    if (visited[v] == 1 && visited[u] == 1)
    {
        return 1;
    }
    return 0;
}

void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->tail = NULL;
    ptr_list->number_of_nodes = 0;
}

void list_insert_rear(List *ptr_list, int id)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->id = id;
    temp->link = NULL;

    if (ptr_list->number_of_nodes == 0)
    {
        ptr_list->head = ptr_list->tail = temp;
    }
    else
    {
        ptr_list->tail->link = temp;
        ptr_list->tail = temp;
    }

    (ptr_list->number_of_nodes)++;
}

void list_delete_front(List *ptr_list)
{
    node *temp = ptr_list->head;
    ptr_list->head = ptr_list->head->link;
    free(temp);

    (ptr_list->number_of_nodes)--;
}

void queue_initialize(Queue *queue_list)
{
    queue_list->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id)
{
    list_insert_rear(ptr->ptr_list, id);
}

void queue_dequeue(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
    {
        return;
    }
    list_delete_front(ptr->ptr_list);
}

int queue_is_empty(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
    {
        return 0;
    }
}

int queue_peek(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
    {
        return 0;
    }
    return ptr->ptr_list->head->id;
}

int main()
{
    int n, q, u, v;
    scanf("%d %d", &n, &q);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &u, &v);
        if (check_path(graph, n, u - 1, v - 1))
            printf("YES\n");
        else
            printf("NO\n");
    }
    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);
    return 0;
}
