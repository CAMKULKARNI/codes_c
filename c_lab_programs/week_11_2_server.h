struct student
{
    char *name;
    int roll_num;
    float phy_marks, math_marks, ec_marks, pswc_marks, mech_marks, total, average;
};
void read_student_details(struct student *s);
void print_student_details(struct student *s);
