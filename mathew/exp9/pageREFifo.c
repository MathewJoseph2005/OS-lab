#include <stdio.h>

int main() {
    int frames, pages, page_faults = 0, flag, pointer = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page_sequence[pages], frame[frames], status[pages];

    printf("Enter the page reference string:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &page_sequence[i]);
    }

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    // Print the table header
    printf("\n| Page No. | Frame 0 | Frame 1 | Frame 2 | Status |\n");
    printf("|----------|---------|---------|---------|--------|\n");

    // Process pages
    for (int i = 0; i < pages; i++) {
        flag = 0;

        // Check if page already in frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page_sequence[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found, do replacement
        if (flag == 0) {
            frame[pointer] = page_sequence[i];
            pointer = (pointer + 1) % frames; // FIFO logic
            page_faults++;
            status[i] = 0; // Miss
        } else {
            status[i] = 1; // Hit
        }

        // Print the page status in the table format
        printf("| %-8d |", page_sequence[i]);
        for (int f = 0; f < frames; f++) {
            if (frame[f] != -1) {
                printf(" %-7d |", frame[f]);
            } else {
                printf("    -    |");
            }
        }

        // Print hit or miss status
        if (status[i] == 1) {
            printf("   Hit  |\n");
        } else {
            printf("  Miss  |\n");
        }
    }

    // Print the summary of page faults
    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}

