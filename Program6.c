// Implement the FIFO page replacement algorithm

#include <stdio.h>

int main()
{
    int i, j, k, frames = 0, count = 0, refStr[25], m[10], n, pageFaults = 0;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &refStr[i]);

    printf("Enter the no of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        m[i] = -1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < frames; j++)
        {
            if (refStr[i] == m[j])
                break;
        }

        if (j == frames)
        {
            m[count++] = refStr[i];
            pageFaults++;
        }

        for (k = 0; k < frames; k++)
            printf("%d\t", m[k]);

        if (j == frames)
            printf("Page fault %d", pageFaults);

        printf("\n");

        if (count == frames)
            count = 0;
    }

    printf("\nThe no of pages using FIFO: %d", pageFaults);
}