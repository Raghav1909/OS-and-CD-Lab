// Given the list of processes and their CPU burst time, write a program to compute and print average waiting time and average turnaround time using FCFS scheduling algorithm.

#include <stdio.h>

struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int wait_time;
    int completed_time;
    int turnaround_time;
} p[10];

void main()
{
    int bt, i, n, average_wait_time, average_turnaround_time, total_turnaround_time = 0, total_wait_time = 0;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time of process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].process_id = i + 1;
    }
    p[0].wait_time = 0;
    p[0].turnaround_time = p[0].burst_time + p[0].wait_time;
    for (i = 1; i < n; i++)
    {
        p[i].wait_time = p[i - 1].wait_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].wait_time + p[i].burst_time;
    }
    printf("\n Process ID \t Burst Time \t Wait Time \t Turnaround Time \t \n");
    for (i = 0; i < n; i++)
    {
        printf("\n \t%d \t\t %d \t\t %d \t\t %d \n", p[i].process_id, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
    }
    for (i = 0; i < n; i++)
    {
        total_wait_time = p[i].wait_time + total_wait_time;
        total_turnaround_time = p[i].turnaround_time + total_turnaround_time;
    }
    average_wait_time = total_wait_time / n;
    average_turnaround_time = total_turnaround_time / n;
    printf("\nAverage waiting time = %d\n", average_wait_time);
    printf("Average turnaround time = %d", average_turnaround_time);
}