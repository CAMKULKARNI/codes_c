typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void display(Node *);

void insert_start(Node **);
void insert_end(Node **);
void delete_start(Node **);
void delete_end(Node **);
void insert_at_pos(Node **);
int num_of_nodes(Node **);
void delete_at_pos(Node **);
void reverse(Node **);

// void insert_before(Node **);
// void insert_after(Node **);

// void delete_before(Node **);
// void delete_after(Node **);

// void swap_node_data(Node **);
