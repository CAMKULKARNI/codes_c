#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

int main()
{
    Node *list = NULL;

    int choice = -1;

    while (choice != 0)
    {
        printf("\n0.  Exit");
        printf("\n1.  Insert at given position");
        printf("\n2.  Insert before a given Node");
        printf("\n3.  Insert after a given Node");
        printf("\n4.  Insert at start of the list");
        printf("\n5.  Insert at the end of the list");
        printf("\n6.  Delete At given position");
        printf("\n7.  Delete before a given Node");
        printf("\n8.  Delete after a given Node");
        printf("\n9.  Delete at the start of the list");
        printf("\n10. Delete at the end of the list");
        printf("\n11. Reverse the list");
        printf("\n12. Number of Nodes in the list");
        printf("\n13. Display");
        printf("\n14. Swap data of two Nodes");

        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_at_pos(&list);
            break;
        case 2:
            insert_before(&list);
            break;
        case 3:
            insert_after(&list);
            break;
        case 4:
            insert_start(&list);
            break;
        case 5:
            insert_end(&list);
            break;
        case 6:
            delete_at_pos(&list);
            break;
        case 7:
            delete_before(&list);
            break;
        case 8:
            delete_after(&list);
            break;
        case 9:
            delete_start(&list);
            break;
        case 10:
            delete_end(&list);
            break;
        case 11:
            reverse(&list);
            break;
        case 12:
            printf("\nThe number of nodes in the linked list is %d", num_of_nodes(&list));
            break;
        case 13:
            display(list);
            break;
        case 14:
            swap_node_data(&list);
            break;
        default:
            printf("Wrong Choice!! Enter another number");
            break;
        }
    }

    return 0;
}