struct product
{
    char *name;
    float cost;
    int quantity;
};
void bill(struct product *s);
void print_bill(struct product *s);