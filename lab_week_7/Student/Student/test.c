#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
    int id;
    int time;
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

void list_initialize(List *list);
void list_insert_rear(List *list, int id, int time);
const int node_get_id(node *node_ptr);
const int node_get_time(node *node_ptr);
void list_delete_front(List *list);
void list_destroy(List *list);

void queue_initialize(Queue *ptr_queue);
void queue_enqueue(Queue *ptr_queue, int id, int time);
void queue_dequeue(Queue *ptr_queue);
int queue_is_empty(Queue *ptr_queue);
void queue_peek(Queue *ptr_queue);
void queue_destroy(Queue *ptr_queue);
const int queue_find_person(Queue *ptr_queue, int t);

int main()
{
    Queue queue;
    queue_initialize(&queue);
    int choice, id, time, t;
    int loop = 1;
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            scanf("%d%d", &id, &time);
            queue_enqueue(&queue, id, time);
            break;

        case 1:
            queue_dequeue(&queue);
            break;

        case 2:
            queue_peek(&queue);
            break;

        case 3:
            scanf("%d", &t);
            queue_find_person(&queue, t);
            break;

        default:
            queue_destroy(&queue);
            loop = 0;
        }
    }
    return 0;
}

static node *create_node(int id, int time, node *link)
{
    link = (node *)malloc(sizeof(node));
    link->id = id;
    link->time = time;
    return link;
}
void list_initialize(List *ptr_list)
{
    ptr_list->head = NULL;
    ptr_list->tail = NULL;
    ptr_list->number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
    return (node_ptr->id);
}

const int node_get_time(node *node_ptr)
{
    return (node_ptr->time);
}

void list_insert_rear(List *ptr_list, int id, int time)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->id = id;
    temp->time = time;
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

void list_destroy(List *ptr_list)
{
    free(ptr_list->head);
    free(ptr_list->tail);
    free(ptr_list);
}

void queue_initialize(Queue *queue_list)
{
    queue_list->ptr_list = (List *)malloc(sizeof(List));
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
    list_insert_rear(ptr->ptr_list, id, time);
}

void queue_dequeue(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
    {
        printf("Empty Queue\n");
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

void queue_peek(Queue *ptr)
{
    if (ptr->ptr_list->number_of_nodes == 0)
    {
        printf("Empty Queue\n");
        return;
    }
    printf("%d %d\n", ptr->ptr_list->head->id, ptr->ptr_list->head->time);
}

void queue_destroy(Queue *ptr)
{
    free(ptr->ptr_list->head);
    free(ptr->ptr_list->tail);
    free(ptr->ptr_list);
    free(ptr);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
    int time = 0, total_time = 0, counter = 0;
    node *temp = ptr_queue->ptr_list->head;
    while (temp != NULL)
    {
        total_time = total_time + temp->time;
        temp = temp->link;
    }

    if (t >= total_time)
    {
        printf("\nEmpty Queue");
        return (-999);
    }

    temp = ptr_queue->ptr_list->head;
    while ((temp != NULL) && (t < (time + temp->time)))
    {
        /*if (t < (time + temp->time))
		{
			printf("%d\n", temp->id);
			return (-999);
		}*/
        counter++;
        time = time + temp->time;
        temp = temp->link;
    }

    for (int i = 0; i < counter - 1; i++)
    {
        queue_dequeue(ptr_queue);
    }

    if (temp != NULL)
    {
        printf("%d\n", temp->id);
        return (-999);
    }

    printf("\nEmpty Queue");
    return (-999);
}
