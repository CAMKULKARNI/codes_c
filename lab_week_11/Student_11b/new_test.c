#include <stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
    if (v == u)
        return 1;
    int visit[n], queue[n], front, rear, del, i;
    for (i = 0; i < n; i++)
        visit[i] = 0;
    visit[v] = 1;
    front = rear = 0;
    queue[rear] = v;
    while (front != -1 && rear != -1)
    {
        del = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = front + 1;
        for (i = 0; i < n; i++)
        {
            if ((graph[del][i] == 1) && (visit[i] == 0))
            {
                if (i == u)
                    return 1;
                visit[i] = 1;
                if (front == -1 && rear == -1)
                {
                    front = rear = 0;
                    queue[rear] = i;
                }
                else
                {
                    queue[++rear] = i;
                }
            }
        }
    }
    return 0;
}