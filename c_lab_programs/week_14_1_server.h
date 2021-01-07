struct linked_list
{
    int data;
    struct linked_list *link;
};
void display(struct linked_list *l);
void insert_front(struct linked_list **l);
void insert_end(struct linked_list **l);
void sum_alternate(struct linked_list *l);
void sum(struct linked_list *l);
void sum_even_odd(struct linked_list *l);
