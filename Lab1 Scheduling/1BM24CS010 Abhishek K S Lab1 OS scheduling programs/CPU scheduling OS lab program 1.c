#include <stdio.h>
#include <stdlib.h>

struct process {
    int id, at, bt, ct, tat, wt, rt;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time for P%d: ", p[i].id);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time for P%d: ", p[i].id);
        scanf("%d", &p[i].bt);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int timepassed = 0, sumtat = 0, sumwt = 0, sumrt = 0;
    for (int i = 0; i < n; i++) {
        if (timepassed < p[i].at) {
            timepassed = p[i].at;
        }
        p[i].ct = timepassed + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        timepassed += p[i].bt;

        sumtat += p[i].tat;
        sumwt += p[i].wt;

    }
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct,
               p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT: %.2f\n", (float)sumtat / n);
    printf("Average WT: %.2f\n", (float)sumwt / n);

    return 0;
}
