#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
bool pageExists(int page, int frames[], int numFrames) {
    int i;
 for (i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
         return true;
        }
    }
    return false;
}
int main() {
    int pageReferences[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,1,2,0,1,7};
    int numPages = sizeof(pageReferences) / sizeof(pageReferences[0]);
    int frames[MAX_FRAMES];
    int numFrames;
    int pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
      if (numFrames <= 0 || numFrames > MAX_FRAMES) {
        printf("Invalid number of frames. Please choose a value between 1 and %d.\n", MAX_FRAMES);
        return 1;
          }
          int i;
    for (i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }
      int frameIndex = 0;

    printf("Page Replacement Order:\n");
    for (i = 0; i < numPages; i++) {
        int page = pageReferences[i];
        printf("Page %d -> ", page);

        if (!pageExists(page, frames, numFrames)) {
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % numFrames;
            pageFaults++;
            int j;
            for (j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    printf("Empty ");
                } else {
                    printf("%d ", frames[j]);
                }
            }
            printf("Page Fault\n");
        } else {
            int j;
            for (j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    printf("Empty ");
                } else {
                    printf("%d ", frames[j]);
                }
            }
            printf("No Page Fault\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
