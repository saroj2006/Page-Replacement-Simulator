#include <iostream>
using namespace std;

#define MAX_FRAMES 10
#define MAX_PAGES 100

class PageReplacement {
private:
    int frames[MAX_FRAMES], numFrames, recent[MAX_FRAMES];
public:
    PageReplacement(int n) {
        numFrames = n;
        for (int i = 0; i < numFrames; i++) {
            frames[i] = -1;
            recent[i] = -1;
        }
    }
    void LRU(int pages[], int n);
};

void PageReplacement::LRU(int pages[], int n) {
    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                recent[j] = i;
                break;
            }
        }
        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < numFrames; j++)
                if (recent[j] < recent[lruIndex]) lruIndex = j;

            frames[lruIndex] = pages[i];
            recent[lruIndex] = i;
            pageFaults++;
        }
    }
    cout << "LRU Page Faults: " << pageFaults << endl;
}

int main() {
    int numFrames, numPages, pages[MAX_PAGES];
    cout << "Enter number of frames: ";
    cin >> numFrames;
    cout << "Enter number of pages: ";
    cin >> numPages;

    cout << "Enter page sequence: ";
    for (int i = 0; i < numPages; i++)
        cin >> pages[i];

    PageReplacement simulator(numFrames);
    simulator.LRU(pages, numPages);

    return 0;
}
