#include <stdio.h>

struct process {
    int id, at, bt, pr, ct, tat, wt, d;
};

int main() {
    int n, t = 0, c = 0, h;
    float tw = 0, tt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d\n", p[i].id);
        printf("Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Burst time: ");
        scanf("%d", &p[i].bt);
        printf("Priority: ");
        scanf("%d", &p[i].pr);
        p[i].d = 0;
    }

    while (c != n) {
        h = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].d == 0) {
                if (h == -1 || p[i].pr < p[h].pr) {
                    h = i;
                }
            }
        }

        if (h == -1) {
            t++;
        } else {
            t += p[h].bt;
            p[h].ct = t;
            p[h].tat = p[h].ct - p[h].at;
            p[h].wt = p[h].tat - p[h].bt;
            tw += p[h].wt;
            tt += p[h].tat;
            p[h].d = 1;
            c++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f", tt / n);
    printf("\nAverage Waiting Time: %.2f\n", tw / n);

    return 0;
}
