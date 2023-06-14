// Given the list of processes and their CPU burst time, write a program to compute and print average waiting time and average turnaround time using round robin scheduling algorithm.

#include <stdio.h>

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int wait_time;
    int completed_time;
    int turnaround_time;
    int remaining_time;
} p[10];

void main()
{
    int i, j, n, total_wait_time = 0, total_turnaround_time = 0, average_wait_time, average_turnaround_time, time_slice, count = 0, allotted_time;

    printf("Enter the no of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].process_id = i + 1;
    }

    printf("Enter time slice: ");
    scanf("%d", &time_slice);

    i = 0;

    while (count < n)
    {
        if (p[i].remaining_time > 0)
        {
            allotted_time = p[i].remaining_time >= time_slice ? time_slice : p[i].remaining_time;

            p[i].remaining_time -= allotted_time;
            p[i].turnaround_time += allotted_time;

            for (j = 0; j < n; j++)
            {
                if (i != j && p[i].remaining_time != 0)
                {
                    p[i].wait_time += allotted_time;
                    p[i].turnaround_time += allotted_time;
                }
            }

            if (p[i].remaining_time == 0)
                count++;
        }

        i = (i + 1) % n;
    }

    printf("\n Process ID \t Burst Time \t Wait Time \t Turnaround Time \t \n");
    for (i = 0; i < n; i++)
    {
        printf("\n \tP%d \t\t %d \t\t %d \t\t %d \n", p[i].process_id, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
    }
    for (i = 0; i < n; i++)
    {
        total_wait_time = p[i].wait_time + total_wait_time;
        total_turnaround_time = p[i].turnaround_time + total_turnaround_time;
    }
    average_wait_time = total_wait_time / n;
    average_turnaround_time = total_turnaround_time / n;
    printf("\nAverage waiting time = %d\n", average_wait_time);
    printf("Average turnaround time = %d\n", average_turnaround_time);
}