struct student
{
    int roll_num, marks;
    char *name;
};
void read_details(struct student *s);
void print_details(struct student *s);
void sort_details(struct student *s, int n);
