#include <stdio.h>


struct process {
    int pid, at, bt, p, rt, ct, wt, tat;
};

int main() {
    int n, time = 0, completed = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time, burst time, priority: ");
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].p);
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        int idx = -1, highest = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].p < highest) {
                    highest = p[i].p;
                    idx = i;
                }
            }
        }
        if (idx != -1) {
            p[idx].rt--;
            time++;
            if (p[idx].rt == 0) {
                completed++;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        } else {
            time++;
        }
    }

    float totalwt = 0, totaltat = 0;
    printf("\nPid\tAt\tBt\tP\tCt\tTat\tWt\n");
    for (int i = 0; i < n; i++) {
        totalwt += p[i].wt;
        totaltat += p[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].p,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage waiting time : %.2f", totalwt / n);
    printf("\nAverage turnaround time : %.2f\n", totaltat / n);

    return 0;
}
