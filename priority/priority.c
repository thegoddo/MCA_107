#include <stdio.h>

void priority_scheduling(int process[], int burst_time[], int priority[],
                         int n) {
  int waiting_time[n], turnaround_time[n], total_waiting_time = 0,
                                           total_turnaround_time = 0;

  for (int i = 0; i < n; i++) {
    waiting_time[i] = 0;
    turnaround_time[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (priority[i] < priority[j]) {
        int temp = process[i];
        process[i] = process[j];
        process[j] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;

        temp = priority[i];
        priority[i] = priority[j];
        priority[j] = temp;
      }
    }
  }

  waiting_time[0] = 0;
  for (int i = 1; i < n; i++) {
    waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
  }

  for (int i = 0; i < n; i++) {
    turnaround_time[i] = waiting_time[i] + burst_time[i];
  }

  for (int i = 0; i < n; i++) {
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnaround_time[i];
  }

  printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i],
           priority[i], waiting_time[i], turnaround_time[i]);
  }
  printf("\nAverage Waiting Time: %.2f\n",
         (float)total_waiting_time / (float)n);
  printf("Average Turnaround Time: %.2f\n",
         (float)total_turnaround_time / (float)n);
}

int main() {
  int process[] = {1, 2, 3, 4};
  int burst_time[] = {5, 3, 9, 2};
  int priority[] = {3, 1, 4, 2};

  int n = sizeof(process) / sizeof(process[0]);

  priority_scheduling(process, burst_time, priority, n);
  return 0;
}