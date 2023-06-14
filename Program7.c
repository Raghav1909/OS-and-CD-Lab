// Implement the optimal page replacement algorithm

#include <stdio.h>

int main()
{
    int i, j, k, frames = 0, count = 0, refStr[25], m[10], counter[20], n, min, pageFaults = 0;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &refStr[i]);

    printf("Enter the no of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
    {
        counter[i] = 0;
        m[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < frames; j++)
        {
            if (refStr[i] == m[j])
            {
                counter[j]++;
                break;
            }
        }

        if (j == frames)
        {
            min = 0;
            for (k = 1; k < frames; k++)
            {
                if (counter[k] < counter[min])
                {
                    min = k;
                    m[min] = refStr[i];
                    counter[min] = 1;
                    pageFaults++;
                }
            }
        }

        printf("\n");

        for (k = 0; k < frames; k++)
            printf("%d\t", m[k]);

        if (j == frames)
            printf("Page fault %d", pageFaults);
    }

    printf("\nThe no of pages using optimal page replacement: %d", pageFaults);
}