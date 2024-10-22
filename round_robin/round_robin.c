#include <stdio.h>

void round_robin(int burst_time[], int n) {
  int waiting_time[n], turnararound_time[n], total_waiting_time = 0,
                                             total_turnaround_time = 0;
  int remaining_time[n], time_quantum = 2, time = 0, completed = 0;

  for (int i = 0; i < n; i++) {
    remaining_time[i] = burst_time[i];
  }

  while (completed < n) {
    for (int i = 0; i < n; i++) {
      if (remaining_time[i] > 0) {
        if (remaining_time[i] <= time_quantum) {
          time += remaining_time[i];
          waiting_time[i] = time - burst_time[i];
          turnararound_time[i] = time;
          remaining_time[i] = 0;
          completed++;
        } else {
          time += time_quantum;
          remaining_time[i] -= time_quantum;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    total_waiting_time += waiting_time[i];
    total_turnaround_time += turnararound_time[i];
  }

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i],
           turnararound_time[i]);
  }

  printf("\nAverage Waiting Time: %.2f\n",
         (float)total_waiting_time / (float)n);
  printf("Average Turnaround Time: %.2f\n",
         (float)total_turnaround_time / (float)n);
}

int main() {
  int n = 4;
  int burst_time[] = {5, 3, 9, 2};

  round_robin(burst_time, n);
  return 0;
}