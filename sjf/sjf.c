#include <stdio.h>

void sjf(int process[], int burst_time[], int n) {
  int total_waiting = 0, total_turnaround = 0, shortest_job_index,
      waiting_time[n], turnaround_time[n];

  for (int i = 0; i < n; i++) {
    waiting_time[i] = 0;
    turnaround_time[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    shortest_job_index = i;

    for (int j = i + 1; j < n; j++) {
      if (burst_time[j] < burst_time[shortest_job_index]) {
        shortest_job_index = j;
      }
    }

    int temp = burst_time[i];
    burst_time[i] = burst_time[shortest_job_index];
    burst_time[shortest_job_index] = temp;

    if (i == 0) {
      waiting_time[i] = 0;
    } else {
      waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }
    turnaround_time[i] = waiting_time[i] + burst_time[i];

    total_waiting += waiting_time[i];
    total_turnaround += turnaround_time[i];
  }

  // Print the results
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i],
           turnaround_time[i]);
  }

  printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting / (float)n);
  printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / (float)n);
}

int main() {
  int process[] = {5, 4, 3, 2, 1};
  int burst_time[] = {9, 3, 5, 7, 2};

  int n = sizeof(process) / sizeof(process[0]);

  sjf(process, burst_time, n);
}