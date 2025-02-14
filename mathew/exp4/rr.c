#include <stdio.h>

struct Process {
    int index, bt, remaining_bt, wt, tat, ct;
};

void roundRobin(struct Process p[], int n, int timeQuantum, float *avgWT, float *avgTAT) {
    int time = 0, completed = 0, totalWT = 0, totalTAT = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0) {
                if (p[i].remaining_bt > timeQuantum) {
                    time += timeQuantum;
                    p[i].remaining_bt -= timeQuantum;
                } else {
                    time += p[i].remaining_bt;
                    p[i].remaining_bt = 0;
                    p[i].ct = time;
                    p[i].tat = p[i].ct;
                    p[i].wt = p[i].tat - p[i].bt;
                    totalWT += p[i].wt;
                    totalTAT += p[i].tat;
                    completed++;
                }
            }
        }
    }

    *avgWT = (float)totalWT / n;
    *avgTAT = (float)totalTAT / n;
}

void printGanttChart(struct Process p[], int n, int timeQuantum) {
    int time = 0, remaining_bt[n], processQueue[100], processTimes[100], queueIndex = 0;

    for (int i = 0; i < n; i++) {
        remaining_bt[i] = p[i].bt;
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0;
                processQueue[queueIndex] = p[i].index;
                processTimes[queueIndex++] = time;
               
                if (remaining_bt[i] > timeQuantum) {
                    time += timeQuantum;
                    remaining_bt[i] -= timeQuantum;
                } else {
                    time += remaining_bt[i];
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
    processTimes[queueIndex] = time;

    printf("\nGantt Chart:\n |");
    for (int i = 0; i < queueIndex; i++) {
        printf(" T%d |", processQueue[i]);
    }
    printf("\n ");

    for (int i = 0; i <= queueIndex; i++) {
        printf("%d     ", processTimes[i]);
    }
    printf("\n");
}

void display(struct Process p[], int n) {
    printf("\nTask\tBT\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++) {
        printf("T%d\t%d\t%d\t%d\t%d\n", p[i].index, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
    }
}

int main() {
    int n, timeQuantum;
    float avgWT, avgTAT;

    printf("Enter number of tasks: ");
    scanf("%d", &n);
   
    struct Process p[n];

    printf("Enter Burst Time for each task:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: ", i + 1);
        p[i].index = i + 1;
        scanf("%d", &p[i].bt);
        p[i].remaining_bt = p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(p, n, timeQuantum, &avgWT, &avgTAT);
    display(p, n);
    printGanttChart(p, n, timeQuantum);

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
