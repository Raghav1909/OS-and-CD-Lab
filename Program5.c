// Implement the BEST FIT memory allocation technique.

#include <stdio.h>
#include <stdbool.h>

struct segment
{
    int id;
    int size;
    bool allocated;
} seg[10];

int n, m, p[100];

void best_fit(int pn, int request)
{
    int i, j, k, flag = 0, small, sid, temp[100];
    for (i = 0, k = 0; i < m; i++)
    {
        if (seg[i].size >= request && !seg[i].allocated)
        {
            temp[k] = i;
            k++;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Request memory %d is not allocated \n", request);
        return;
    }
    small = seg[temp[0]].size;
    sid = temp[0];
    for (j = 1; j < k; j++)
    {
        if (seg[temp[j]].size < small)
        {
            small = seg[temp[j]].size;
            sid = temp[j];
        }
    }
    printf("memory required %d is allocated to %d\n", request, small);
    seg[sid].allocated = true;
}

void main()
{
    int i;
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
        best_fit(i, p[i]);
    }
}