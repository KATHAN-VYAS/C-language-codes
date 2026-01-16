#include <stdio.h>

struct Process
{
    int arrival_time;
    int burst_time;
    int process_id;
};

struct SJFScheduler
{
    int total_processes;
    struct Process proc[100];
    int waiting_time[100];
    int turnaround_time[100];
    int start_time[100];
    int complete_time[100];
};

void init(struct SJFScheduler *scheduler, int arrival_time[], int burst_time[], int total_processes)
{
    scheduler->total_processes = total_processes;

    for (int i = 0; i < scheduler->total_processes; i++)
    {
        scheduler->proc[i].arrival_time = arrival_time[i];
        scheduler->proc[i].burst_time = burst_time[i];
        scheduler->proc[i].process_id = i + 1;
    }

    // Sorting based on arrival time and burst time
    for (int i = 0; i < scheduler->total_processes; i++)
    {
        for (int j = i + 1; j < scheduler->total_processes; j++)
        {
            if (scheduler->proc[i].arrival_time > scheduler->proc[j].arrival_time ||
                (scheduler->proc[i].arrival_time == scheduler->proc[j].arrival_time &&
                 scheduler->proc[i].burst_time > scheduler->proc[j].burst_time))
            {
                struct Process temp = scheduler->proc[i];
                scheduler->proc[i] = scheduler->proc[j];
                scheduler->proc[j] = temp;
            }
        }
    }

    for (int i = 0; i < scheduler->total_processes; i++)
    {
        scheduler->waiting_time[i] = 0;
        scheduler->turnaround_time[i] = 0;
        scheduler->start_time[i] = 0;
        scheduler->complete_time[i] = 0;
    }
}

void schedule(struct SJFScheduler *scheduler)
{
    int service[100];
    service[0] = scheduler->proc[0].arrival_time;
    scheduler->waiting_time[0] = 0;

    for (int i = 1; i < scheduler->total_processes; i++)
    {
        service[i] = service[i - 1] + scheduler->proc[i - 1].burst_time;
        scheduler->waiting_time[i] = service[i] - scheduler->proc[i].arrival_time;
        if (scheduler->waiting_time[i] < 0)
        {
            scheduler->waiting_time[i] = 0;
        }
    }

    for (int i = 0; i < scheduler->total_processes; i++)
    {
        scheduler->turnaround_time[i] = scheduler->proc[i].burst_time + scheduler->waiting_time[i];
    }

    scheduler->start_time[0] = scheduler->proc[0].arrival_time;
    scheduler->complete_time[0] = scheduler->start_time[0] + scheduler->turnaround_time[0];

    for (int i = 1; i < scheduler->total_processes; i++)
    {
        scheduler->start_time[i] = scheduler->complete_time[i - 1];
        scheduler->complete_time[i] = scheduler->start_time[i] + scheduler->turnaround_time[i];
    }

    printf("Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");
    for (int i = 0; i < scheduler->total_processes; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", scheduler->proc[i].process_id,
               scheduler->start_time[i], scheduler->complete_time[i],
               scheduler->turnaround_time[i], scheduler->waiting_time[i]);
    }

    float avg_tat = 0, avg_waiting_time = 0;
    for (int i = 0; i < scheduler->total_processes; i++)
    {
        avg_tat += scheduler->turnaround_time[i];
        avg_waiting_time += scheduler->waiting_time[i];
    }
    avg_tat /= scheduler->total_processes;
    avg_waiting_time /= scheduler->total_processes;

    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}

int main()
{
    int n;
    int arrival_time[];
    int burst_time[n];

    printf("Total Process : ");
    scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Arrival Time A%d :  ", i + 1);
    //     scanf("%d", &arrival_time[i]);

    //     printf("Brust Time A%d :  ", i + 1);
    //     scanf("%d", &burst_time[i]);
    // }
    int total_processes = sizeof(arrival_time) / sizeof(arrival_time[0]);

    struct SJFScheduler scheduler;
    init(&scheduler, arrival_time, burst_time, total_processes);
    schedule(&scheduler);

    return 0;
}
