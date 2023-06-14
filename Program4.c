// Implement the FIRST FIT memory allocation technique.

#include <stdio.h>
#include <stdbool.h>

struct segment
{
    int id;
    int size;
    bool allocated;
} seg[10];

int m, n;

void first_fit(int pn, int request)
{
    int i, flag = 0;
    for (i = 0; i < m; i++)
    {
        if (request <= seg[i].size && !seg[i].allocated)
        {
            seg[i].allocated = true;
            printf("\nprocess requirement %d is allocated to memory segment %d\n", request, seg[i].size);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("process requirement %d is not allocated \n", request);
}

void main()
{
    int i, p[100];
    printf("Enter the no of memory segments: ");
    scanf("%d", &n);

    printf("Enter the sizes of memory segments:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &seg[i].size);
        seg[i].id = i + 1;
        seg[i].allocated = false;
    }

    printf("Enter the no of processes: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
    {
        printf("Enter the request size of process P%d: ", i + 1);
        scanf("%d", &p[i]);
        first_fit(i, p[i]);
    }
}