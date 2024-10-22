#include <stdio.h>

void waitTime(int process[], int burst_size[], int n, int wt[]) {
  wt[0] = 0;
  for (int i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + burst_size[i - 1];
  }
}
void turnaroundTime(int process[], int burst_size[], int n, int tat[],
                    int wt[]) {
  for (int i = 0; i < n; i++) {
    tat[i] = wt[i] + burst_size[i];
  }
}

void avgTime(int process[], int burst_size[], int n) {
  int wt[n], tat[n], i, total_wt = 0, total_bt = 0;
  waitTime(process, burst_size, n, wt);
  turnaroundTime(process, burst_size, n, tat, wt);

  printf("Process BurstTime Waiting Time Turnaround Time\n");
  for (int i = 0; i < n; i++) {
    total_wt = total_wt + wt[i];
    total_bt = total_bt + burst_size[i];
    printf(" %d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_size[i], wt[i], tat[i]);
  }

  printf("Average waiting time: %.2lf\n", (float)total_wt / (float)n);
  printf("Average burst time: %.2lf\n", (float)total_bt / (float)n);
}
int main() {
  int process[] = {1, 2, 3};
  int n = sizeof(process) / sizeof(process[0]);
  int burst_size[] = {10, 5, 8};
  avgTime(process, burst_size, n);

  return 0;
}