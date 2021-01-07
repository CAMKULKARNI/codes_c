struct linked_list
{
    int data;
    struct linked_list *link;
};
void display(struct linked_list *l);
void delete_front(struct linked_list **l);
void delete_end(struct linked_list **l);
void search_element(struct linked_list *l);
void product_nodes(struct linked_list *l);
