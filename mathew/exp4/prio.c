#include <stdio.h>

struct Process {
    int index, bt, priority, wt, tat, ct;
};

void sortByPriority(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void calculateTimes(struct Process p[], int n, float *avgWT, float *avgTAT) {
    int time = 0, totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        p[i].wt = time;
        p[i].tat = p[i].wt + p[i].bt;
        p[i].ct = time + p[i].bt;
        time = p[i].ct;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    *avgWT = (float)totalWT / n;
    *avgTAT = (float)totalTAT / n;
}

void printGanttChart(struct Process p[], int n) {
    printf("\nGantt Chart:\n ");

    for (int i = 0; i < n; i++) {
        printf("----");
    }

    printf("\n|");
    for (int i = 0; i < n; i++) {
        printf(" T%d |", p[i].index);
    }

    printf("\n ");
    for (int i = 0; i < n; i++) {
        printf("----");
    }

    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf("   %d", p[i].ct);
    }
    printf("\n");
}

void display(struct Process p[], int n) {
    printf("\nTask\tBT\tPriority\tWT\tTAT\tCT\n");
    for (int i = 0; i < n; i++) {
        printf("T%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].index, p[i].bt, p[i].priority, p[i].wt, p[i].tat, p[i].ct);
    }
}

int main() {
    int n;
    float avgWT, avgTAT;

    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    struct Process p[n];

    printf("Enter Burst Time and Priority for each task:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: ", i + 1);
        p[i].index = i + 1;
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    sortByPriority(p, n);
    calculateTimes(p, n, &avgWT, &avgTAT);
    display(p, n);
    printGanttChart(p, n);

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
