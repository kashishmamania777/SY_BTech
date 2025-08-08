#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FRAMES 3

// Function to find the index of the page in frames array
int findPageIndex(int frames[], int n, int page) {
    int i;
    for (i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1; // Page not found in frames
}

// Function to implement LRU page replacement algorithm
void lruPageReplacement(int pages[], int n, int frames[], int frameCount) {
    int pageFaults = 0;
    int frameIndex = 0; // Index to keep track of the page to replace in frames

    // Initialize an array to store the time when each page was last used
    int pageLastUsed[n];
    int i;
    for (i = 0; i < n; i++) {
        pageLastUsed[i] = -1; // -1 indicates a page has not been used yet
    }

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int pageIndex = findPageIndex(frames, frameCount, page);

        if (pageIndex == -1) {
            // Page is not in frames, so it's a page fault
            pageFaults++;

            // Find the least recently used page in frames
            int lruPageIndex = 0;
            int j;
            for (j = 1; j < frameCount; j++) {
                if (pageLastUsed[j] < pageLastUsed[lruPageIndex]) {
                    lruPageIndex = j;
                }
            }

            // Replace the least recently used page with the new page
            frames[lruPageIndex] = page;
            pageLastUsed[lruPageIndex] = i; // Update last used time
        } else {
            // Page is already in frames, update its last used time
            pageLastUsed[pageIndex] = i;
        }

        // Print the current state of frames after processing this page
        printf("Page %d -> Frames: ", page);
        int j;
        for (j = 0; j < frameCount; j++) {
            if (frames[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7,0,1,2,0,3,0,4,2,3};
    int n = sizeof(pages) / sizeof(pages[0]);

    int frames[MAX_FRAMES];
    int i;
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames with -1 (indicating empty frame)
    }

    printf("LRU Page Replacement Algorithm:\n");
    lruPageReplacement(pages, n, frames, MAX_FRAMES);

    return 0;
}
