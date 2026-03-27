#include <stdio.h>
#include <limits.h>

#define MAX_TASKS 10

typedef struct {
    int pid;
    int burst;
    int deadline;
    int period;
} Task;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    Task tasks[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        tasks[i].pid = i + 1;

        printf("Enter Burst Time: ");
        scanf("%d", &tasks[i].burst);

        printf("Enter Deadline: ");
        scanf("%d", &tasks[i].deadline);

        printf("Enter Period: ");
        scanf("%d", &tasks[i].period);
    }

    int SIMULATION_TIME = tasks[0].period;
    for (int i = 1; i < n; i++) {
        SIMULATION_TIME = lcm(SIMULATION_TIME, tasks[i].period);
    }

    int remaining[MAX_TASKS] = {0};
    int next_release[MAX_TASKS] = {0};
    int abs_deadline[MAX_TASKS] = {0};
    int active[MAX_TASKS] = {0};

    printf("\nScheduling occurs for %d ms (LCM of periods)\n\n", SIMULATION_TIME);

    for (int t = 0; t < SIMULATION_TIME; t++) {

        // Release jobs
        for (int i = 0; i < n; i++) {
            if (t == next_release[i]) {
                remaining[i] = tasks[i].burst;
                abs_deadline[i] = t + tasks[i].deadline;
                next_release[i] += tasks[i].period;
                active[i] = 1;
            }
        }

        int chosen = -1;
        int earliest = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (active[i] && remaining[i] > 0) {
                if (abs_deadline[i] < earliest) {
                    earliest = abs_deadline[i];
                    chosen = i;
                }
            }
        }

        if (chosen != -1) {
            printf("%dms : Task %d is running.\n", t, tasks[chosen].pid);
            remaining[chosen]--;

            if (remaining[chosen] == 0) {
                active[chosen] = 0;
            }
        } else {
            printf("%dms : CPU is idle.\n", t);
        }
    }

    return 0;
}
