#include <stdio.h>
#include <stdlib.h>

// Function to compare tasks based on their finish times
int compare(const void *a, const void *b) {
    return *((int *)a + 1) - *((int *)b + 1);
}

// Function to find the maximum number of non-conflicting tasks
int maxTasks(int starts[], int finishes[], int n) {
    // Sort tasks based on their finish times
    qsort(finishes, n, sizeof(int), compare);

    int selected = 1; // Count of non-conflicting tasks
    int last_finish = finishes[0];

    // Iterate through the sorted tasks
    for (int i = 1; i < n; i++) {
        // If the current task doesn't conflict with the last selected task
        if (starts[i] >= last_finish) {
            selected++;
            last_finish = finishes[i];
        }
    }

    return selected;
}

int main() {
    int n;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    int *starts = malloc(n * sizeof(int));
    int *finishes = malloc(n * sizeof(int));

    // Input each task's start and finish times
    for (int i = 0; i < n; i++) {
        printf("Enter start time of task %d: ", i + 1);
        scanf("%d", &starts[i]);
        printf("Enter finish time of task %d: ", i + 1);
        scanf("%d", &finishes[i]);
    }

    int max = maxTasks(starts, finishes, n);
    printf("Maximum number of non-conflicting tasks: %d\n", max);

    free(starts); // Free dynamically allocated memory
    free(finishes);

    return 0;
}
